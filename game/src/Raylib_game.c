#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "Engine/EngineTypes.h"
#include "GameLogic/Player.h"
#include "GameLogic/GameLogic.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void InGameUpdate();
void InGameRender();
void ResetGame();

struct Game game;
float deltaTime;

void Init()
{
    deltaTime = 0.0f;
   
    game.state = inGame;
}


int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
		
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Renderer");
    
    Init();
       
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //set delta time
        deltaTime = GetFrameTime();

        switch (game.state)
        {
            case mainMenu:
                
                break;
            case inGame:
                //----------------------------------------------------------------------------------
                // LOGIC
                //----------------------------------------------------------------------------------
                InGameUpdate();
                //----------------------------------------------------------------------------------               
                // Draw
                //----------------------------------------------------------------------------------
                InGameRender();
                break;
            case reset:
                ResetGame();
                break;
        }              
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



void InGameUpdate()
{
   
}

void InGameRender()
{
    BeginDrawing();
        ClearBackground(BLACK);
       

        DrawFPS(10, 10);
        DrawText(TextFormat("dt: %f", deltaTime), 10, 30, 20, RED);
    EndDrawing();
    
}

void ResetGame()
{
    
}


