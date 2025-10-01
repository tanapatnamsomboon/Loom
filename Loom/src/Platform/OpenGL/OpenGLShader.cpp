#include "Platform/OpenGL/OpenGLShader.h"
#include <imgui_impl_opengl3_loader.h>
#include <glm/gtc/type_ptr.hpp>

namespace Loom
{
    static GLenum ShaderTypeFromString(const std::string& type)
    {
        if (type == "vertex") return GL_VERTEX_SHADER;
        if (type == "fragment" || type == "pixel") return GL_FRAGMENT_SHADER;

        LOOM_CORE_ASSERT(false, "Unknown shader type!");
        return 0;
    }

    OpenGLShader::OpenGLShader(const std::string& filepath)
    {
        std::string source = ReadFile(filepath);
        auto shaderSource = PreProcess(source);
        Compile(shaderSource);
    }

    OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        std::unordered_map<GLenum, std::string> sources;
        sources[GL_VERTEX_SHADER] = vertexSrc;
        sources[GL_FRAGMENT_SHADER] = fragmentSrc;
        Compile(sources);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_RendererID);
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_RendererID);
    }

    void OpenGLShader::Unbind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& value)
    {
        GLint loc = glGetUniformLocation(m_RendererID, name.c_str());
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
    }

    std::string OpenGLShader::ReadFile(const std::string& filepath)
    {
        std::ifstream in(filepath, std::ios::in | std::ios::binary);
        std::stringstream ss;
        ss << in.rdbuf();
        return ss.str();
    }

    std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& source)
    {
        std::unordered_map<GLenum, std::string> shaderSources;

        const char* typeToken = "#type";
        size_t pos = source.find(typeToken, 0);
        while (pos != std::string::npos)
        {
            size_t eol = source.find_first_of("\r\n", pos);
            size_t begin = pos + strlen(typeToken) + 1;
            std::string type = source.substr(begin, eol - begin);

            size_t nextLinePos = source.find_first_not_of("\r\n", eol);
            pos = source.find(typeToken, nextLinePos);

            shaderSources[ShaderTypeFromString(type)] =
                (pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
        }

        return shaderSources;
    }

    void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSources)
    {
        GLuint program = glCreateProgram();
        std::vector<GLuint> shaderIDs;

        for (auto& kv : shaderSources)
        {
            GLenum type = kv.first;
            const std::string& src = kv.second;

            GLuint shader = glCreateShader(type);
            const char* srcC = src.c_str();
            glShaderSource(shader, 1, &srcC, nullptr);
            glCompileShader(shader);

            GLint compiled;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
            if (!compiled)
            {
                char log[1024];
                glGetShaderInfoLog(shader, 1024, nullptr, log);
                LOOM_CORE_ERROR("Shader compile error: {}", log);
            }

            glAttachShader(program, shader);
            shaderIDs.push_back(shader);
        }

        glLinkProgram(program);

        GLint linked;
        glGetProgramiv(program, GL_LINK_STATUS, &linked);
        if (!linked)
        {
            char log[1024];
            glGetProgramInfoLog(program, 1024, nullptr, log);
            LOOM_CORE_ERROR("Shader link error: {}", log);
        }

        for (auto id : shaderIDs)
        {
            glDetachShader(program, id);
            glDeleteShader(id);
        }

        m_RendererID = program;
    }
} // namespace Loom
