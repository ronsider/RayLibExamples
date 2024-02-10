/*******************************************************************************************
*
*   raygui - Controls test
*
*   TEST CONTROLS:
*       - GuiScrollPanel()
*
*   DEPENDENCIES:
*       raylib 4.0  - Windowing/input management and drawing.
*       raygui 3.0  - Immediate-mode GUI controls.
*
*   COMPILATION (Windows - MinGW):
*       gcc -o $(NAME_PART).exe $(FILE_NAME) -I../../src -lraylib -lopengl32 -lgdi32 -std=c99
*
*   COMPILATION (Linux - gcc):
*       gcc -o $(NAME_PART) $(FILE_NAME) -I../../src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -std=c99
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2019-2024 Vlad Adrian (@Demizdor) and Ramon Santamaria (@raysan5)
*
**********************************************************************************************/


#include <tuple>
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{

    //Rectangle some_rect{ 4000,2000,30,40 };
    
    // Initialization
    //---------------------------------------------------------------------------------------
     const int screenWidth = 1024;
     const int screenHeight = 768;

    //InitWindow(screenWidth, screenHeight, "raygui - GuiScrollPanel()");

    

    InitWindow(screenWidth, screenHeight, "MATRIX OPERATIONS");

    //Rectangle panelRec = { 20, 40, 200, 150 };
    Rectangle panelRec = { 20, 40, 300, 300 };
   // Rectangle panelContentRec = { 0, 0, 340, 340 };
    Rectangle panelContentRec = { 0, 0, 7000, 7000 };// =>the key to make te program work
    Rectangle panelView = { 0 };
    Vector2 panelScroll = { 99, -20 };

    bool showContentArea = true;



    //lambdas:
    auto lambda = [screenWidth, screenHeight ]() ->std::pair<int,int>
        {return { screenWidth / 4, screenHeight / 30  }; };
    //const auto [headerXposition, headerYposition] = std::tie(screenWidth / 2, screenHeight / 30);
   

    /////////
    /////////
    

    // HeaderDimensions
    const auto HeaderDimensions = lambda();// HeaderDimensions.first = width, HeaderDimensions.second = height, 
    
    SetTargetFPS(60);
    //---------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

       // DrawText(TextFormat("[%f, %f]", panelScroll.x, panelScroll.y), 4, 4, 20, RED);
        //const int headerYposition = static_cast<int>(screenHeight / 30);
        

        //DrawText(TextFormat("[%f, %f]", panelScroll.x, panelScroll.y), 4, 20, 20, RED);

        DrawText("Matrix Operations", HeaderDimensions.first, HeaderDimensions.second, 50, RED);

        GuiScrollPanel(panelRec, nullptr, panelContentRec, &panelScroll, &panelView);
        

        /*BeginScissorMode(panelView.x, panelView.y, panelView.width, panelView.height);
        GuiGrid(  { panelRec.x + panelScroll.x, panelRec.y + panelScroll.y, panelContentRec.width, panelContentRec.height }, NULL, 16, 3, NULL);
        EndScissorMode();*/

        if (showContentArea) DrawRectangle(panelRec.x + panelScroll.x, panelRec.y + panelScroll.y, panelContentRec.width, panelContentRec.height, Fade(RED, 0.1));

        //DrawStyleEditControls();

       // GuiCheckBox(  { 565, 80, 20, 20 }, "SHOW CONTENT AREA", & showContentArea);

       /* GuiSliderBar(  { 590, 385, 145, 15 }, "WIDTH", TextFormat("%i", (int)panelContentRec.width), & panelContentRec.width, 1, 600);
        GuiSliderBar(  { 590, 410, 145, 15 }, "HEIGHT", TextFormat("%i", (int)panelContentRec.height), & panelContentRec.height, 1, 400);*/

       // DrawRectangle(100, 100, 300, 300,BLACK);

        Camera2D cam;

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

