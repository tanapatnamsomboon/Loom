#include "EditorLayer.h"
#include <imgui.h>

EditorLayer::EditorLayer()
    : Layer("EditorLayer")
{
}

void EditorLayer::OnAttach()
{
    ImGuiIO& io = ImGui::GetIO();

    io.Fonts->Clear();

    io.Fonts->AddFontFromFileTTF("assets/fonts/Fredoka/Fredoka.ttf");
    // io.Fonts->AddFontFromFileTTF("assets/fonts/Inter-Regular.ttf");
    // io.Fonts->AddFontFromFileTTF("assets/fonts/Sarabun-Regular.ttf");

    Loom::FramebufferSpecification spec = { 1900, 600 };
    m_Framebuffer = Loom::Framebuffer::Create(spec);

    float vertices[3 * 3] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    uint32_t indices[3] = { 0, 1, 2 };

    m_VertexArray = Loom::VertexArray::Create();
    auto vb = Loom::VertexBuffer::Create(vertices, sizeof(vertices));
    m_VertexArray->AddVertexBuffer(vb);

    auto ib = Loom::IndexBuffer::Create(indices, 3);
    m_VertexArray->SetIndexBuffer(ib);

    std::string vertexSrc = R"(
        #version 460 core
        layout(location = 0) in vec3 aPosition;
        void main()
        {
            gl_Position = vec4(a_Position, 1.0);
        }
    )";

    std::string fragmentSrc = R"(
        #version 460 core
        out vec4 FragColor;
        void main()
        {
            FragColor = vec4(0.2, 0.7, 0.3, 1.0);
        }
    )";

    m_Shader = Loom::Shader::Create(vertexSrc, fragmentSrc);

    m_Scene = Loom::CreateRef<Loom::Scene>();
    auto entityA = m_Scene->CreateEntity("Camera");
    auto entityB = m_Scene->CreateEntity("Light");
    auto entityC = m_Scene->CreateEntity("Player");

    m_SceneHierarchyPanel.SetContext(m_Scene);
}

void EditorLayer::OnDetach()
{
}

void EditorLayer::OnUpdate()
{
    m_Framebuffer->Bind();

    Loom::RenderCommand::SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    Loom::RenderCommand::Clear();

    Loom::Renderer::BeginScene();
    Loom::Renderer::Submit(m_Shader, m_VertexArray);
    Loom::Renderer::EndScene();

    m_Scene->OnUpdate();

    m_Framebuffer->Unbind();
}

void EditorLayer::OnImGuiRender()
{
    DockspaceUI();

    m_SceneHierarchyPanel.OnImGuiRender();

    ImGui::Begin("Console");
    ImGui::Text("Logs will appear here.");
    ImGui::End();

    ImGui::Begin("Viewport");
    uint32_t texID = m_Framebuffer->GetColorAttachmentRendererID();
    ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
    ImGui::Image((void*)(intptr_t)texID, viewportPanelSize, ImVec2(0, 1), ImVec2(1, 0));
    ImGui::End();
}

void EditorLayer::DockspaceUI()
{
    static bool dockspaceOpen = true;
    static bool opt_fullscreen = true;
    static bool opt_padding = false;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }

    if (!opt_padding)
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin("Dockspace Demo", &dockspaceOpen, window_flags);

    if (!opt_padding)
        ImGui::PopStyleVar();

    if (opt_fullscreen)
        ImGui::PopStyleVar(2);

    // Dockspace
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }

    // Menu bar example
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Exit"))
            {
                Loom::Application::Get().Close();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::End();
}
