#include <engine/core/Engine.hpp>
#include <engine/core/Scene.hpp>

#include <imgui/imconfig.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

namespace gam703::engine::core
{
	namespace
	{
		void resizeWindow(GLFWwindow* glfwWindow, int width, int height)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getWindow().resizeWindow(width, height);
				engine->getScene().getSceneRenderer()->calculateProjectionMatrix(engine->getWindow().getAspectRatio());
			}
		}

		void processInput(Engine& engine)
		{
			if (engine.getInput().isKeyPressed(GLFW_KEY_ESCAPE))
			{
				engine.stop();
			}
		}

		void mouseMovement(GLFWwindow* glfwWindow, double mouseX, double mouseY)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getInput().processMouseMovement(mouseX, mouseY);
			}
		}

		void scrollCallback(GLFWwindow* glfwWindow, double xOffset, double yOffset)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getInput().processMouseScroll(xOffset, yOffset);
			}
		}


		void initializeIMGUI(GLFWwindow* window)
		{
			// Setup Dear ImGui context
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

			// Setup Dear ImGui style
			ImGui::StyleColorsDark();
			//ImGui::StyleColorsLight();

			// Setup Platform/Renderer backends
			ImGui_ImplGlfw_InitForOpenGL(window, true);
			ImGui_ImplOpenGL3_Init("#version 330");
		}
	}

	Engine::Engine(const std::string& title, int width, int height) : m_window(title, width, height), m_inputHandler(&m_window), m_time(glfwGetTime()), m_scene(this)
	{
		m_window.setUserData(this);
		m_window.setResizeCallback(resizeWindow);
		m_window.setCursorMovementCallback(mouseMovement);
		m_window.setScrollCallback(scrollCallback);
		initializeIMGUI(m_window.getGLFWWindow());
	}

	Engine::~Engine()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		glfwTerminate();
	}

	void Engine::start()
	{
		m_isRunning = true;
		run();
	}

	void Engine::renderGUI()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		m_window.render(ImGui::GetCurrentContext());
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void Engine::run()
	{
		while (m_isRunning)
		{
			m_time.processTime(glfwGetTime());
			m_scene.updateScene(m_time.getDeltaTime());
			renderGUI();
			processInput(*this);

			m_inputHandler.resetMouseOffset();
			m_window.swapBuffers();
			glfwPollEvents();
		}
	}

	void Engine::stop()
	{
		m_isRunning = false;
	}

} //gam703::engine::core
