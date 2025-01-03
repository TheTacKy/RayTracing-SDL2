#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#define WIDTH 900
#define HEIGHT 600
#define COLOR_WHITE 0xffffffff

struct Circle
{
    double x;
    double y;
    double r; // radius
};

void FillCircle(SDL_Surface* surface, struct Circle circle, Uint32 color)
{
    double radius_squared = pow(circle.r,2);
    for(double x = circle.x - circle.r; x <= circle.x + circle.r; x++) 
    {
        for(double y = circle.y - circle.r; y <= circle.y + circle.r; y++)
        {
            double distance_squared = pow(x - circle.x, 2) + pow(y-circle.y, 2);
            if(distance_squared < radius_squared)
            {
                SDL_Rect pixel = (SDL_Rect){x, y, 1, 1,};
                SDL_FillRect(surface, &pixel, color);
            }
        }
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("RayTracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    struct Circle circle = {200, 200, 80};
    FillCircle(surface, circle, COLOR_WHITE);

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);
}