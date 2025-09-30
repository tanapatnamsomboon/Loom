#include "Platform/OpenGL/OpenGLShader.h"
#include "imgui_impl_opengl3_loader.h"

namespace Loom
{
    OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const char* src = vertexSrc.c_str();
        glShaderSource(vertexShader, 1, &src, nullptr);
        glCompileShader(vertexShader);

        GLint compiled;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            char log[512];
            glGetShaderInfoLog(vertexShader, 512, nullptr, log);
            LOOM_CORE_ERROR("Vertex shader compile error: {}", log);
        }

        GLuint fragmentShader = glCreateShader(GL_VERTEX_SHADER);
        src = fragmentSrc.c_str();
        glShaderSource(fragmentShader, 1, &src, nullptr);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            char log[512];
            glGetShaderInfoLog(fragmentShader, 512, nullptr, log);
            LOOM_CORE_ERROR("Fragment shader compile error: {}", log);
        }

        m_RendererID = glCreateProgram();
        glAttachShader(m_RendererID, vertexShader);
        glAttachShader(m_RendererID, fragmentShader);
        glLinkProgram(m_RendererID);

        GLint linked;
        glGetProgramiv(m_RendererID, GL_LINK_STATUS, &linked);
        if (!linked)
        {
            char log[512];
            glGetProgramInfoLog(m_RendererID, 512, nullptr, log);
            LOOM_CORE_ERROR("Shader link error: {}", log);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
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
} // namespace Loom
