#include "setupDearIMGui.h"
#include "Domain/GUIAdmin.h"

int main(int, char**)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;
    setUpGLSLVersion();
    if (!wasWindowCreated())
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    checkImGuiVersionAndCreateContext();
    setUpDearImGui();

    setUpPlatformRenderer();
    loadFonts();

    // Our state
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    GUIAdmin& theAdmin = GUIAdmin::Get();
    theAdmin.initApp();

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        startDearImGuiFrame();
        showDockingSpace();
        theAdmin.showAccountsListWindow();
        theAdmin.showOpenAccountsWindows();
        if(theAdmin.mustShowCreateAccountWindow())
            theAdmin.showCreateAccountWindow();

        
        render();
        renderAdditionalPlatformWindows();
        glfwSwapBuffers(window);
    }

    cleanUp();

    return 0;
}
