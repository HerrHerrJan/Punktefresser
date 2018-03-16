#ifndef PROJEKTIL_H
#define PROJEKTIL_H
const int leer = 10;
const int leer_ohne_punkt =11;
const int block_blau = 20;
const int block_grau = 21;
const int block_gelb = 22;
const int look_r=0;
const int look_l=1;
const int look_d=2;
const int look_u=3;
const int player1=130;
const int player2=131;

SDL_Window* win;
SDL_Surface* surface_window;
SDL_Surface *blocksfresser = IMG_Load("bilder/tilesneu.png");
SDL_Surface *bullets = IMG_Load("bilder/Bullet.png");
int level [20][30]{};
void copy_level(int level[20][30],int level_copy[20][30]){
for (int i = 0; i<20;i++){
for(int j =0;j<30;j++){
level_copy [i][j]= level [i][j];

}}
}

class Projektil
{
    private:
        int px;
        int py;
        int vx;
        int vy;
        //int range=7;
        bool active=false;
        SDL_Rect position = {x:px,y:py,w:32,h:32};
        SDL_Rect hor={x:40,y:241,w:18,h:8};
        SDL_Rect ver={x:65,y:301,w:8,h:18};
    public:
        //Projektil();
        Projektil(){};
        void init(int,int,int,int);
        void bewegen();
        void zeichnen();

};

void Projektil::init(int nx,int ny, int nvx, int nvy){
    px=nx;
    py=ny;
    vx=nvx;
    vy=nvy;
    active=true;
    position={x:px,y:py,w:32,h:32};

}

void Projektil::bewegen(){
    //if (px%32==0 && py%32==0){
        int x_pix = (px)/32;
        int y_pix = (py)/32;
        if(vx>0&&level[y_pix][x_pix+1]==20){
        active=false;
        }
        if(vx<0&&level[y_pix][x_pix]==20){
        active=false;
        }
        if(vy>0&&level[y_pix+1][x_pix]==20){
        active=false;
        }
        if(vy<0&&level[y_pix][x_pix]==20){
        active=false;
        }
    //}
    if (active==true){
        px+=vx;
        py+=vy;
    }
    position={x:px,y:py,w:32,h:32};

}

void Projektil::zeichnen(){
    if(active==true){
        if(vx==0){SDL_BlitSurface(bullets,&ver,surface_window,&position);}
        if(vy==0){SDL_BlitSurface(bullets,&hor,surface_window,&position);}
    }
}


#endif // PROJEKTIL_H
