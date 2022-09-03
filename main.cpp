#include <iostream>

#include <GLFW/glfw3.h>
#include <HighlighterConfig.h>

#ifdef USE_ADDER
    #include "Adder/add.h"
#endif

using namespace std;

int main(int argc, char argv[])
{
    cout << "Hello World!" << endl;

    #ifdef USE_ADDER
        cout << add(12.0f, 2.33f) << endl;
    #else
        cout << "Adder not used" << endl;
    #endif
    
    cout << argv[0] << "VERSION "<< Highlighter_VERSION_MAJOR << "." << Highlighter_VERSION_MINOR << endl;

    GLFWwindow* window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        //draw();

        // Update animation
        //animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}