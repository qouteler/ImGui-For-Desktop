#pragma once
#include "style.hpp"

static bool center = true;
static int y, x;

void imgui(bool* p_open, GLFWwindow* window)
{
    // this hides the title bar, disables dragging and resizing

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove
    | ImGuiWindowFlags_NoTitleBar
    | ImGuiWindowFlags_NoResize
    | ImGuiWindowFlags_NoBringToFrontOnFocus;

    // runs the style function, changes colors, border rounding, etc..
    style();

    {
        // code here

        ImGui::Begin("Desktop Imgui", p_open, window_flags);

        ImGui::Text("Resolution: %x, %d", x, y);

        ImGui::Checkbox("center ui", &center);

        ImGui::Text("hello");  

        // code here
        

        /*Forces the gui to fill the screen, 
        Checking "center ui" will disable this*/
        if (center)
        {    
            glfwGetWindowSize(window, &x, &y);
            ImGui::SetWindowPos(ImVec2(0, 0));
            ImGui::SetWindowSize(ImVec2(x, y));
        }

        ImGui::End();
    }
}

void imgui(bool*, GLFWwindow* window);