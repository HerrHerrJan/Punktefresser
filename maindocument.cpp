#include <iostream>
#include <stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include <stdio.h>
#include<string>
#include<cmath>
#include <time.h>
#include <vector>
#include <array>
using namespace std;



SDL_Window* win;
SDL_Surface* surface_window;
TTF_Font *font;

SDL_Surface *background = IMG_Load("bilder/background.png");
SDL_Surface *blocksfresser = IMG_Load("bilder/tiles.png");


class Build {
private:

public:
void tile(int, int);

}

void Build::tile(int x, int y){
SDL_Rect *ziel;
ziel = {x:x,y:y;w:32,h:32};
SDL_BlitSurface{blocksfresser,NULL,surf,&ziel};
}
SDL_Color black = {0, 0, 0};
SDL_Color red = {255, 0, 0};
SDL_Color blue = {0, 0, 255};
SDL_Color white = {255,255,255};

void render_text(int x, int y, string text, SDL_Color farbe=black) {

    SDL_Surface* tsurf = TTF_RenderText_Solid(font, text.c_str(), farbe);

    int breite = tsurf->w;
    int hoehe = tsurf->h;

    SDL_Rect pos = {x, y, breite, hoehe};
    SDL_BlitSurface(tsurf, NULL, surface_window, &pos);
    SDL_FreeSurface(tsurf);
}

int main(int a,char **b){


SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
font = TTF_OpenFont("LucidaSansDemiBold.ttf", 36);


win = SDL_CreateWindow("Punktefresser", 200, 0, 960, 640, SDL_WINDOW_SHOWN);

surface_window = SDL_GetWindowSurface(win);


//SDL_UpdateWindowSurface(win);

SDL_Delay(3000);
return 0;
}
