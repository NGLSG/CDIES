#include <iostream>
#include<SDL2/SDL.h>
using namespace std;
int main() {
  //sdl使用需要初始化SDL_Init
    if(SDL_Init(SDL_INIT_VIDEO)){
      SDL_Log("SDL2初始化失败,%s",SDL_GetError());//屏幕输出
      return 1;
    }
    SDL_Window *window=SDL_CreateWindow("My first SDL2 project",//创建window,使用要释放
        SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,400,300,//SDL_WINDOWPOS_CENTERED:居中
        SDL_WINDOW_SHOWN);
    if(window==nullptr){
    SDL_Log("桌面初始化失败,%s",SDL_GetError());
    return 2;
    }
    SDL_Delay(3000);//SDL_Delay等待
    SDL_DestroyWindow(window);//释放SDL_Window *

    return 0;
}
