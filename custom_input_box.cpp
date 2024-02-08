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


static void DrawStyleEditControls(void);  // Draw and process scroll bar style edition controls

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
     const int screenWidth = 1024;
     const int screenHeight = 768;

    //InitWindow(screenWidth, screenHeight, "raygui - GuiScrollPanel()");

    InitWindow(screenWidth, screenHeight, "MATRIX OPERATIONS");

    Rectangle panelRec = { 20, 40, 200, 150 };
    Rectangle panelContentRec = { 0, 0, 340, 340 };
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

        GuiScrollPanel(panelRec, NULL, panelContentRec, &panelScroll, &panelView);

        BeginScissorMode(panelView.x, panelView.y, panelView.width, panelView.height);
        GuiGrid(  { panelRec.x + panelScroll.x, panelRec.y + panelScroll.y, panelContentRec.width, panelContentRec.height }, NULL, 16, 3, NULL);
        EndScissorMode();

       // if (showContentArea) DrawRectangle(panelRec.x + panelScroll.x, panelRec.y + panelScroll.y, panelContentRec.width, panelContentRec.height, Fade(RED, 0.1));

        DrawStyleEditControls();

        //GuiCheckBox(  { 565, 80, 20, 20 }, "SHOW CONTENT AREA", & showContentArea);

        GuiSliderBar(  { 590, 385, 145, 15 }, "WIDTH", TextFormat("%i", (int)panelContentRec.width), & panelContentRec.width, 1, 600);
        GuiSliderBar(  { 590, 410, 145, 15 }, "HEIGHT", TextFormat("%i", (int)panelContentRec.height), & panelContentRec.height, 1, 400);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Draw and process scroll bar style edition controls
static void DrawStyleEditControls(void)
{
    // ScrollPanel style controls
    //----------------------------------------------------------
    GuiGroupBox(  { 550, 170, 220, 205 }, "SCROLLBAR STYLE");

    int style = GuiGetStyle(SCROLLBAR, BORDER_WIDTH);
    GuiLabel(  { 555, 195, 110, 10 }, "BORDER_WIDTH");
    GuiSpinner(  { 670, 190, 90, 20 }, NULL, & style, 0, 6, false);
    GuiSetStyle(SCROLLBAR, BORDER_WIDTH, style);

    style = GuiGetStyle(SCROLLBAR, ARROWS_SIZE);
    GuiLabel(  { 555, 220, 110, 10 }, "ARROWS_SIZE");
    GuiSpinner(  { 670, 215, 90, 20 }, NULL, & style, 4, 14, false);
    GuiSetStyle(SCROLLBAR, ARROWS_SIZE, style);

    style = GuiGetStyle(SCROLLBAR, SLIDER_PADDING);
    GuiLabel(  { 555, 245, 110, 10 }, "SLIDER_PADDING");
    GuiSpinner(  { 670, 240, 90, 20 }, NULL, & style, 0, 14, false);
    GuiSetStyle(SCROLLBAR, SLIDER_PADDING, style);

    bool scrollBarArrows = GuiGetStyle(SCROLLBAR, ARROWS_VISIBLE);
    GuiCheckBox(  { 565, 280, 20, 20 }, "ARROWS_VISIBLE", & scrollBarArrows);
    GuiSetStyle(SCROLLBAR, ARROWS_VISIBLE, scrollBarArrows);

    style = GuiGetStyle(SCROLLBAR, SLIDER_PADDING);
    GuiLabel(  { 555, 325, 110, 10 }, "SLIDER_PADDING");
    GuiSpinner(  { 670, 320, 90, 20 }, NULL, & style, 0, 14, false);
    GuiSetStyle(SCROLLBAR, SLIDER_PADDING, style);

    style = GuiGetStyle(SCROLLBAR, SLIDER_WIDTH);
    GuiLabel(  { 555, 350, 110, 10 }, "SLIDER_WIDTH");
    GuiSpinner(  { 670, 345, 90, 20 }, NULL, & style, 2, 100, false);
    GuiSetStyle(SCROLLBAR, SLIDER_WIDTH, style);

    const char* text = GuiGetStyle(LISTVIEW, SCROLLBAR_SIDE) == SCROLLBAR_LEFT_SIDE ? "SCROLLBAR: LEFT" : "SCROLLBAR: RIGHT";
    bool toggleScrollBarSide = GuiGetStyle(LISTVIEW, SCROLLBAR_SIDE);
    GuiToggle(  { 560, 110, 200, 35 }, text, & toggleScrollBarSide);
    GuiSetStyle(LISTVIEW, SCROLLBAR_SIDE, toggleScrollBarSide);
    //----------------------------------------------------------

    // ScrollBar style controls
    //----------------------------------------------------------
    GuiGroupBox(  { 550, 20, 220, 135 }, "SCROLLPANEL STYLE");

    style = GuiGetStyle(LISTVIEW, SCROLLBAR_WIDTH);
    GuiLabel(  { 555, 35, 110, 10 }, "SCROLLBAR_WIDTH");
    GuiSpinner(  { 670, 30, 90, 20 }, NULL, & style, 6, 30, false);
    GuiSetStyle(LISTVIEW, SCROLLBAR_WIDTH, style);

    style = GuiGetStyle(DEFAULT, BORDER_WIDTH);
    GuiLabel(  { 555, 60, 110, 10 }, "BORDER_WIDTH");
    GuiSpinner(  { 670, 55, 90, 20 }, NULL, & style, 0, 20, false);
    GuiSetStyle(DEFAULT, BORDER_WIDTH, style);
    //----------------------------------------------------------
}