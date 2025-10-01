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

    m_Shader = Loom::Shader::Create("assets/shaders/Basic.glsl");

    m_EditorScene = Loom::CreateRef<Loom::Scene>();

    auto cameraEntity = m_EditorScene->CreateEntity("Camera");
    cameraEntity.AddComponent<Loom::CameraComponent>().Primary = true;

    auto playerEntity = m_EditorScene->CreateEntity("Player");

    m_ActiveScene = m_EditorScene;

    m_SceneHierarchyPanel.SetContext(m_EditorScene);
}

void EditorLayer::OnDetach()
{
}

void EditorLayer::OnUpdate(Loom::Timestep ts)
{
    m_EditorCamera.OnUpdate(ts);

    m_Framebuffer->Bind();
    Loom::RenderCommand::SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    Loom::RenderCommand::Clear();

    if (m_Runtime)
    {
        m_ActiveScene->OnUpdateRuntime(ts);
    }
    else
    {
        m_EditorScene->OnUpdateEditor(ts, m_EditorCamera);
    }

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
    ImVec2 viewportSize = ImGui::GetContentRegionAvail();
    if (m_ViewportSize.x != viewportSize.x || m_ViewportSize.y != viewportSize.y)
    {
        m_ViewportSize = { viewportSize.x, viewportSize.y };
        m_Framebuffer->Resize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
        m_EditorCamera.SetViewportSize(m_ViewportSize.x, m_ViewportSize.y);
    }
    uint32_t textureID = m_Framebuffer->GetColorAttachmentRendererID();
    ImGui::Image(textureID, ImVec2{ m_ViewportSize.x, m_ViewportSize.y }, ImVec2(0, 1), ImVec2(1, 0));
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
