#include <GLFW/glfw3.h>
#include <stdio.h>

void myKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwTerminate();
	else if (key == GLFW_KEY_E && action == GLFW_PRESS)
		printf("You pressed the e button\n");
}

int main()
{
	if (!glfwInit())
	{
		printf("Failed to initialize GLFW. ");
		return -1;
	}
	 
	// Ensure you choose 4.6 for your glad generator as well
	// Or another version of OpenGL that you would like
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	// Core profile means we will not use deprecated fucntion
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Window
	const int windowWidth = 1280;
	const int windowHeight = 720;
	const char* windowTittle = "My Application";

	GLFWwindow* window = glfwCreateWindow(
		windowWidth,
		windowHeight,
		windowTittle,
		nullptr, // Minitor, use glfwPrimaryMonitor() for full-screen
		nullptr // Share, use this for resource sharing (typically not needed)
	);

	if (window == nullptr)
	{
		printf("Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, myKeyCallback);

	glViewport(0, 0, windowWidth, windowHeight);
	while (!glfwWindowShouldClose(window))
	{
		// Clear the screen
		glClearColor(250.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}