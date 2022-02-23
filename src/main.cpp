#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Callback function for when a window is resized:
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main() {
    // Some setup
    glfwInit(); // Initialize GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // Version Numbers
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Enable Core
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a Window Object
    // creates a window and context, options specified through glfwWindowHint above
    // glfwCreateWindow(width, height, title, monitor, share)
    // monitor: monitor to be used in full screen mode, NULL in windowed mode
    // share: window to share contexts with, NULL if DNE
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD, which gives us the function pointers for OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set up OpenGL's Viewport
    // glViewport(left, bottom, right, top) coordinates
    // Informs OpenGL on how to map normalized device coordinates to window coordinates
    // (see RealTimeRendering notes)
    glViewport(0, 0, 800, 600);

    // Set up resizing callback -> tell OpenGL the callback function to use
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // THE RENDER LOOP IS HERE:
    while(!glfwWindowShouldClose(window)) // Check if we should close
    {
        // Swap colour buffer and show it as output to the screen
        glfwSwapBuffers(window);
        // Are there events that happened? if so, update window state and call appropriate callback methods
        glfwPollEvents();
    }

    glfwTerminate(); // Properly clean up resources
    return 0;
}
