//#include <iostream>
#include <stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
//#include<SDL2/SDL_ttf.h>
#include "include/Spieler.h"
//#include "include/Projektil.h"
#include <stdio.h>
#include<string>
#include<functional>
#include<cmath>
#include <time.h>
#include <vector>
#include <array>
using namespace std;

SDL_Surface *background = IMG_Load("bilder/background.png");
SDL_Surface *blocks = IMG_Load("bilder/base_out_atlas.png");




int level_1 [20][30]{
{block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau},
{block_blau,leer,block_blau,block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,leer,block_blau},
{block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau,block_blau}
};
int level_2 [20][30]{
{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
{20,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20},
{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20}

};
int level_3 [20][30]{
{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
{20,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,10,10,10,20},
{20,10,20,20,20,20,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20,20,20},
{20,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,10,20,20},
{20,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20},
{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20}

};



class Build {
private:
SDL_Rect ausschnitt_block_blau = {x:1,y:546,w:32,h:32};
SDL_Rect ausschnitt_block_gelb = {x:32,y:32,w:32,h:32};
SDL_Rect ausschnitt_block_grau = {x:32,y:0,w:32,h:32};
SDL_Rect ausschnitt_block_leer = {x:114,y:440,w:32,h:32};
SDL_Rect ausschnitt_punkt = {x:0,y:64,w:32,h:32};

protected:
void zeichnen(int, int, SDL_Rect);
public:
int punkte_anzahl=0;
int punkte_anzahl_ausgabe(){
return punkte_anzahl;
};
Build(int);
void build_all(int [20][30]);

};
void Build::build_all(int lev[20][30]){
punkte_anzahl=0;
for (int i=0; i< 30;i++){
for (int j=0; j< 20;j++){
switch (lev[j][i]) {
case block_blau : zeichnen(32*i,32*j,ausschnitt_block_blau); break;
case block_gelb : zeichnen(32*i,32*j,ausschnitt_block_gelb); break;
case block_grau : zeichnen(32*i,32*j,ausschnitt_block_grau); break;
case leer       : zeichnen(32*i,32*j,ausschnitt_block_leer);
//zeichnen(32*i,32*j,ausschnitt_punkt);
punkte_anzahl++; break;
case leer_ohne_punkt : zeichnen(32*i,32*j,ausschnitt_block_leer); break;
default : ; break;
}
}
}
}
void Build::zeichnen(int x, int y, SDL_Rect ausschnitt){
SDL_Rect ziel;
ziel = {x:x,y:y,w:32,h:32};

SDL_BlitSurface(blocks,&ausschnitt,surface_window,&ziel);
};

Build::Build(int a){

}


Build hintergrund(1);
class Objects {
private:

public:
Objects(int);

void draw_points();
};


SDL_Color black = {0, 0, 0};
SDL_Color red = {255, 0, 0};
SDL_Color blue = {0, 0, 255};
SDL_Color white = {255,255,255};

SDL_Event e;
int taste;


bool menu=true;
Spieler punktefresser(32,32,player1);
Spieler ninja(512,512,player2);
Projektil P1[10];
Projektil P2[10];
int level_nr=2;
int timer;
bool ende=false;


int main(int a,char **b){



SDL_Init(SDL_INIT_VIDEO);
//TTF_Init();
//font = TTF_OpenFont("LucidaSansDemiBold.ttf", 36);

win = SDL_CreateWindow("Punktefresser", 200, 50, 960, 640, SDL_WINDOW_SHOWN);
surface_window = SDL_GetWindowSurface(win);
while (menu==true){
ende=false;
switch (level_nr) {
case 1 : copy_level(level_1,level);break;
case 2 : copy_level(level_2,level);break;
case 3 : copy_level(level_3,level);break;
default : copy_level(level_1,level);break;
}

while (ende==false){

while (SDL_PollEvent(&e)!=0){

    //while (SDL_PollEvent(&e)!=0){
    taste = e.key.keysym.sym;

    if (e.type == SDL_KEYDOWN){
    switch (taste){
    case SDLK_0 : ende=true;
    menu=false; break;
    case SDLK_RIGHT : punktefresser.vx=8; break;
    case SDLK_LEFT : punktefresser.vx=-8; break;
    case SDLK_UP : punktefresser.vy=-8; break;
    case SDLK_DOWN : punktefresser.vy=8; break;
    case SDLK_d : ninja.vx=8; break;
    case SDLK_a : ninja.vx=-8; break;
    case SDLK_w : ninja.vy=-8; break;
    case SDLK_s : ninja.vy=8; break;
    case SDLK_LSHIFT : ninja.shoot(&P1[ninja.getbulletcounter()]); break;
    case SDLK_RCTRL : punktefresser.shoot(&P2[punktefresser.getbulletcounter()]); break;
    }
    }
    if (e.type == SDL_KEYUP){
    switch (taste){
    case SDLK_RIGHT : punktefresser.vx=0; break;
    case SDLK_LEFT : punktefresser.vx=0; break;
    case SDLK_UP : punktefresser.vy=0; break;
    case SDLK_DOWN : punktefresser.vy=0; break;
    case SDLK_d : ninja.vx=0; break;
    case SDLK_a : ninja.vx=0; break;
    case SDLK_w : ninja.vy=0; break;
    case SDLK_s : ninja.vy=0; break;

        }

}
}

hintergrund.build_all(level);
punktefresser.bewegen(punktefresser.vx,punktefresser.vy);
punktefresser.zeichnen();
ninja.bewegen(ninja.vx,ninja.vy);
ninja.zeichnen();
//int bc=ninja.getbulletcounter();
//ninja.shoot(&P1[ninja.getbulletcounter()]);
//P1[1].init(90,90,0,0);
for(int i=0;i<10;i++){
    P1[i].bewegen();
    P1[i].zeichnen();
    P2[i].bewegen();
    P2[i].zeichnen();

}
string level = "level";
//render_text(0,0,level,red);

if (hintergrund.punkte_anzahl_ausgabe()==0){
level_nr++;
ende=true;
}

SDL_UpdateWindowSurface(win);

SDL_Delay(5);

}
}
return 0;
}

