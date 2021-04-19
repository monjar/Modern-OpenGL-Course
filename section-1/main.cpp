#include <stdio.h>
#include <iostream>
// Importing GLFW and GLEW libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Window Dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    //INIT GLFW and print if error
    if (!glfwInit())
    {
        std::cout << "GLFW init failed";
        glfwTerminate();
        return -1;
    }

    //Setup GLFW window
    //Setting version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //Disabling backward compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Enable forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //Create the window
    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Section 1 Window", NULL, NULL);
    if (!mainWindow)
    {
        std::cout << "GLFW window failed to create.";
        glfwTerminate();
        return -2;
    }

    //Get buffer size info
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    //Set window context
    glfwMakeContextCurrent(mainWindow);

    //Enable expreimental for glew
    glewExperimental = GL_TRUE;

    //Init GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cout << "GLEW Init failed.";
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return -2;
    }

    //Setup viewport
    glViewport(0, 0, bufferWidth, bufferHeight);

    //Main window loop
    while (!glfwWindowShouldClose(mainWindow))
    {
        //Poll for user input
        glfwPollEvents();

        //Clear window
        glClearColor(1, 1, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        //Swap the buffer we drew in with the one we want to see
        glfwSwapBuffers(mainWindow);
    }

    return 0;
}