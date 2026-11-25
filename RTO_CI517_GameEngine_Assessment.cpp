// RTO_CI517_GameEngine_Assessment.cpp : Defines the entry point for the application.
//


#include "RTO_CI517_GameEngine_Assessment.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

using namespace std;


// handle startup arguments (if any) 
int main(int argc, char* argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO)) // if true, log success, else log failure and return 1
    {
        SDL_Log("SDL initialisation failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Log("SDL initialised successfully!");

	// creating window and renderer. setting them to null for now
    // so that we can check if they were created successfully later on. 
    SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

    if (!SDL_CreateWindowAndRenderer(
        "RTO Game Engine", // name 
		800,// width
		600, // height
		SDL_WINDOW_RESIZABLE, // SDL window flag fora resizable window
		&window,// memory address of window pointer
		&renderer)) // memory address of renderer pointer

		// if true, log success, else log failure
    {
        SDL_Log("Window creation failed: %s", SDL_GetError()); // if fails, display error message 
        SDL_Quit(); // shut down sdl 
		return 1; // return 1 (noticeable error)
    }

    SDL_Log("Window and renderer created successfully!");

    // ==================================================================================
    // the game loop 
	bool isRunning = true; // set isRunning to true to start the game loop  
	SDL_Event event; // create an SDL_Event object to handle events
            
             // ==============================================================
	               // rendering a rectangle to the screen
	                SDL_FRect rectangle = { 100, 100, 200, 150 }; // create a rectangle with x, y, width and height
               //  ==============================================================

            while (isRunning) // while isRunning is true, keep running the game loop

    {
        while (SDL_PollEvent(&event)) // while there are events to process
		{                                // retrieve the next event from the event queue 
                                            // and store it in the event object
            if (event.type == SDL_EVENT_QUIT) // if the event is a quit event
            {
                isRunning = false; // set isRunning to false to exit the game loop
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // set the background color 

		SDL_RenderClear(renderer); // clear the previous frame with the background color

		SDL_SetRenderDrawColor(renderer, 150, 0, 150, 255); // set the draw color for the rectangle
        // ==============================================================
		SDL_RenderFillRect(renderer, &rectangle); // render the rectangle to the screen
        // ==============================================================
        SDL_RenderPresent(renderer); // present the renderer to the window

	}
	

	SDL_DestroyRenderer(renderer); // destroy renderer
	SDL_DestroyWindow(window); // destroy window


    SDL_Quit();

    return 0;
    // =====================================================================================
}