#ifndef SPIELER_H
#define SPIELER_H
#include "Projektil.h"


class Spieler
{
    private:
    int xpos;
    int ypos;
    int x_pixel = (xpos)/32;
    int y_pixel = (ypos)/32;
    int turndelay = 0;

    int final_x_step=0;
    int final_y_step=0;
    int step_size=4;
    const int horizontal = 123;
    const int vertikal =124;
    int ausrichtung = horizontal;
    int look_where=0;

    int bulletcounter=0;

    int look_how=player1;
    SDL_Rect position = {x:xpos,y:ypos,w:32,h:32};
    SDL_Rect ausschnitt_r = {x:32,y:96,w:32,h:32};
    SDL_Rect ausschnitt_l = {x:0,y:96,w:32,h:32};
    SDL_Rect ausschnitt_d = {x:64,y:128,w:32,h:32};
    SDL_Rect ausschnitt_u = {x:32,y:128,w:32,h:32};


    SDL_Rect ausschnitt_r_go = {x:64,y:96,w:32,h:32};
    SDL_Rect ausschnitt_l_go = {x:32,y:64,w:32,h:32};
    SDL_Rect ausschnitt_d_go = {x:64,y:64,w:32,h:32};
    SDL_Rect ausschnitt_u_go = {x:64,y:32,w:32,h:32};

    void punkte_fressen();
public:
    int vx;
    int vy;
    Spieler(int, int, int);
    void zeichnen();
    int getbulletcounter();
    void shoot(Projektil*);
    void bewegen_up();
    void bewegen_down();
    void bewegen_left();
    void bewegen_right();
    void bewegen(int,int);
};

int Spieler::getbulletcounter(){bulletcounter++; bulletcounter=bulletcounter%10; return bulletcounter;}

void Spieler::shoot(Projektil *P){
    if(look_where==look_d){P->init(xpos+12,ypos+20,0,8);}
    if(look_where==look_u){P->init(xpos+12,ypos-10,0,-8);}
    if(look_where==look_l){P->init(xpos-10,ypos+15,-8,0);}
    if(look_where==look_r){P->init(xpos+20,ypos+15,8,0);}


}

void Spieler::bewegen(int x, int y){
    if (xpos%32==0 && ypos%32==0){
        punkte_fressen();
        final_x_step=0;
        final_y_step=0;
        int x_pix = (xpos)/32;
        int y_pix = (ypos)/32;
        if (ausrichtung==horizontal && (level[y_pix+1][x_pix]==leer||level[y_pix+1][x_pix]==leer_ohne_punkt) && y>0){//will nach oben hor bewegung
            x=0;
        }
        else if (ausrichtung==horizontal && (level[y_pix-1][x_pix]==leer||level[y_pix-1][x_pix]==leer_ohne_punkt) && y<0){//will nach unten bei hor beweung
            x=0;
        }
        if (ausrichtung==vertikal && (level[y_pix][x_pix+1]==leer || level[y_pix][x_pix+1]==leer_ohne_punkt) && x>0){//will nach rechts ver bewegung
            y=0;
        }
        else if (ausrichtung==horizontal && (level[y_pix][x_pix-1]==leer|| level[y_pix][x_pix-1]==leer_ohne_punkt) && x<0){//will nach links bei ver beweung
            y=0;
        }
        if (((level[y_pix][x_pix-1]!=leer&&level[y_pix][x_pix-1]!=leer_ohne_punkt) && x<0 )){//fährt gegen wand
            x=0;
            look_where=look_l;
           // cout << "fährt gegen wand" << endl;
        }
        if (((level[y_pix][x_pix+1]!=leer&&level[y_pix][x_pix+1]!=leer_ohne_punkt) && x>0 )){//fährt gegen wand
            x=0;
            look_where=look_r;
           // cout << "fährt gegen wand" << endl;
        }
        if (((level[y_pix-1][x_pix]!=leer&&level[y_pix-1][x_pix]!=leer_ohne_punkt) && y<0 )){//fährt gegen wand
            y=0;
            look_where=look_u;
            //cout << "fährt gegen wand" << endl;
        }
        if (((level[y_pix+1][x_pix]!=leer&&level[y_pix+1][x_pix]!=leer_ohne_punkt) && y>0 )){//fährt gegen wand
            y=0;
            look_where=look_d;
            //cout << "fährt gegen wand" << endl;
        }
        if (x>0){
            final_x_step=step_size;
        }
        else if (x<0){
            final_x_step=-step_size;
        }
        if (y>0){
            final_y_step=step_size;
        }
        else if (y<0){
            final_y_step=-step_size;
        }

        //ypos+=final_y_step;
        //xpos+=final_x_step;
        if (x<0){
            if(look_where==look_l&&turndelay==0){xpos+=final_x_step;}
            if(look_where!=look_l){bewegen_left(); turndelay=7;}
            if (turndelay>0){turndelay--;}
        }
        else if ( x>0){
            if(look_where==look_r&&turndelay==0){xpos+=final_x_step;}
            if(look_where!=look_r){bewegen_right(); turndelay=7;}
            if (turndelay>0){turndelay--;}
        }
        if (y<0){
            if(look_where==look_u&&turndelay==0){ypos+=final_y_step;}
            if(look_where!=look_u){bewegen_up(); turndelay=7;}
            if (turndelay>0){turndelay--;}
        }
        else if ( y>0){
            if(look_where==look_d&&turndelay==0){ypos+=final_y_step;}
            if(look_where!=look_d){bewegen_down(); turndelay=7;}
            if (turndelay>0){turndelay--;}
        }
    }
    else {
    xpos +=final_x_step;
    ypos +=final_y_step;

}

position = {x:xpos,y:ypos,w:32,h:32};
}

void Spieler::bewegen_down(){
//ypos+=32;
look_where=look_d;
}
void Spieler::bewegen_up(){
//ypos-=32;
look_where=look_u;
}
void Spieler::bewegen_left(){
//xpos+=32;
look_where=look_l;
}
void Spieler::bewegen_right(){
//ypos-=32;
look_where=look_r;
}
void Spieler::punkte_fressen(){
x_pixel=xpos/32;
y_pixel=ypos/32;
if (level[y_pixel][x_pixel]==leer){
level[y_pixel][x_pixel]=leer_ohne_punkt;
}
}

Spieler::Spieler(int x, int y,int z){
xpos=x;
ypos=y;
look_how=z;
};


void Spieler::zeichnen(){
    if (look_how==player1){
        switch (look_where){
            case look_r : SDL_BlitSurface(blocksfresser,&ausschnitt_r_go,surface_window,&position);break;
            case look_l : SDL_BlitSurface(blocksfresser,&ausschnitt_l_go,surface_window,&position); break;
            case look_u : SDL_BlitSurface(blocksfresser,&ausschnitt_u_go,surface_window,&position); break;
            case look_d : SDL_BlitSurface(blocksfresser,&ausschnitt_d_go,surface_window,&position); break;

            }
        }
    else {
        switch (look_where){
            case look_r : SDL_BlitSurface(blocksfresser,&ausschnitt_r,surface_window,&position);break;
            case look_l : SDL_BlitSurface(blocksfresser,&ausschnitt_l,surface_window,&position); break;
            case look_u : SDL_BlitSurface(blocksfresser,&ausschnitt_u,surface_window,&position); break;
            case look_d : SDL_BlitSurface(blocksfresser,&ausschnitt_d,surface_window,&position); break;

            }
        }
}


#endif // SPIELER_H
