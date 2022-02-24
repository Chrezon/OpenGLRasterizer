#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Callback function for when a window is resized:
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Function to process and organize all the inputs from our window
void processInput(GLFWwindow *window)
{
    // The if statements returns whether or not any key is being currently pressed
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // GLFW_RELEASE otherwise
        glfwSetWindowShouldClose(window, true);     // window should close set to true,
                                                          // render loop check fails and window closes
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
        // Process our input
        processInput(window);
        // Do some stuff here -> actual rendering commands
        // Set the colour to clear the buffer to -> state-setting function
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // Clear the colour buffer to the clear colour so we don't see the stuff from last frame -> state-using function
        // we can also clear the depth buffer: GL_DEPTH_BUFFER_BIT and stencil buffer: GL_STENCIL_BUFFER_BIT
        glClear(GL_COLOR_BUFFER_BIT);
        // Swap colour buffer and show it as output to the screen
        glfwSwapBuffers(window);
        // Are there events that happened? if so, update window state and call appropriate callback methods
        glfwPollEvents();
    }

    glfwTerminate(); // Properly clean up resources
    return 0;
}

// TODO: Move all of this somewhere else

// Hello Triangle:
// Transforming 3D coordinates to 2D pixels is managed by the graphics pipeline (see reading notes)
//      1. Transform 3D coordinates to 2D coordinates
//      2. Transform 2D coordinates to pixels
// Some of the shaders in graphics pipeline is customizable -> control over GPU, save CPU cycles
//      Shaders are written in GLSL (OpenGL Shading Language)
// VERTEX SHADER -> Shape Assembly -> GEOMETRY SHADER -> Rasterization -> FRAGMENT SHADER -> Tests and Blending
// All caps = modifiable sections (again, see reading notes for what each stage does)
// (also tessellation and transform feedback loop exists)
//
// OpenGL processes normalized device coordinates [-1.0, 1.0]
// We use 0.0f on the z-axis since we want 2D shapes for now
// transformed to screenspace coords via viewport transform -> specify data via glViewport
float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
};

// After defining vertex data, we send it to vertex shader
//      - Create memory on GPU to store the data
//      - Configure how OpenGL should interpret the memory
//      - Specify how to send data to graphics card
// Then vertex shader can process this data from its memory
// Memory managed via VBO (Vertex Buffer Objects)
unsigned int VBO;
glGenBuffers(1, &VBO); // glGenBuffers(int howMany, &unsigned int IDReferenceReturn)

// Vertex buffers are type GL_ARRAY_BUFFER, we need to bind the generated buffer to this target
glBindBuffer(GL_ARRAY_BUFFER, VBO);

// Now, if we call on GL_ARRAY_BUFFER, we'll be configuring the bound buffer VBO
// glBufferData is used to copy user-defined data into the bound buffer
// glBufferData(type of buffer, size of data (bytes), data we want to send, how graphics card should manage the data)
// GL_STREAM_DRAW: data is sent once and used as a stream (stream)
// GL_STATIC_DRAW: data is sent once and used a lot (static)
// GL_DYNAMIC_DRAW: data changed frequently and used a lot (dynamic)
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW)
