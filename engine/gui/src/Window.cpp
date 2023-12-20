#include <engine/gui/Window.hpp>
#include <engine/gui/Text.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui/imconfig.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

#include <algorithm>
#include <iostream>

namespace gam703::engine::gui
{
	namespace
	{
		void initializeGLFW()
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		}

		void initialzeGlad()
		{
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
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

	Window::Window(const std::string& title, int width, int height) :m_window(nullptr), m_title(title), m_width(width), m_height(height)
	{
		initializeGLFW();
		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

		if (!m_window)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_window);
		initialzeGlad();
		initializeIMGUI(m_window);

		glEnable(GL_DEPTH_TEST);
	}

	Window::~Window()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		glfwSetWindowShouldClose(m_window, true);
	}

	std::pair<double, double> Window::getMousePosition() const
	{
		double x = 0, y = 0;
		glfwGetCursorPos(m_window, &x, &y);
		return { x, y };
	}

	bool Window::isKeyPressed(int key) const
	{
		return glfwGetKey(m_window, key) == GLFW_PRESS;
	}

	void Window::resizeWindow(int width, int height)
	{
		m_width = width;
		m_height = height;
		glViewport(0, 0, width, height);
	}

	void Window::setUserData(void* userData)
	{
		glfwSetWindowUserPointer(m_window, userData);
	}

	void Window::setResizeCallback(GLFWframebuffersizefun callback)
	{
		glfwSetFramebufferSizeCallback(m_window, callback);
	}

	void Window::setCursorMovementCallback(GLFWcursorposfun callback)
	{
		glfwSetCursorPosCallback(m_window, callback);
	}

	void Window::setScrollCallback(GLFWscrollfun callback)
	{
		glfwSetScrollCallback(m_window, callback);
	}

	void Window::setCursorMode(int mode)
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, mode);
	}

	void Window::addText(const std::string& text)
	{
		m_elements.push_back(std::make_unique<Text>(text));
	}

	void Window::render() const
	{
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			std::for_each(begin(m_elements), end(m_elements), [](const std::unique_ptr<IGUIElement>& element) { element->renderElement(); });

			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGuiIO& io = ImGui::GetIO();
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
			ImGui::End();
		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

} //gam703::engine::gui
