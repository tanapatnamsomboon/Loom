#pragma once

// Core
#include "Loom/Core/Base.h"
#include "Loom/Core/Application.h"
#include "Loom/Core/Layer.h"
#include "Loom/Core/Log.h"
#include "Loom/Core/Input.h"
#include "Loom/Core/KeyCode.h"
#include "Loom/Core/MouseCode.h"

// Events
#include "Loom/Events/Event.h"
#include "Loom/Events/ApplicationEvent.h"
#include "Loom/Events/KeyEvent.h"
#include "Loom/Events/MouseEvent.h"

// ImGui
#include "ImGui/ImGuiLayer.h"

// Renderer
#include "Loom/Renderer/RendererAPI.h"
#include "Loom/Renderer/RenderCommand.h"
#include "Loom/Renderer/GraphicsContext.h"
#include "Loom/Renderer/Framebuffer.h"
#include "Loom/Renderer/VertexArray.h"
#include "Loom/Renderer/Shader.h"
#include "Loom/Renderer/Renderer.h"

// Scene
#include "Loom/Scene/Scene.h"
#include "Loom/Scene/Entity.h"
#include "Loom/Scene/Component.h"

// Entry Point
#ifdef LOOM_INCLUDE_ENTRYPOINT
#   include "Loom/Core/EntryPoint.h"
#endif
