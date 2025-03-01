#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <iomanip>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "render.hpp"

const int dgWidth{190};
const int dgHeight{32};
const int dgFontSize1{40};
const int dgFontSize2{24};

int gWidth = dgWidth;
int gHeight = dgHeight;
int gFontSize1 = dgFontSize1;
int gFontSize2 = dgFontSize2;

SDL_Window* gWindow{nullptr};
SDL_Renderer* gRenderer{nullptr};
TTF_Font* gFont1{nullptr};
TTF_Font* gFont2{nullptr};

std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_time), "%H:%M:%S");

    return ss.str();
}

bool init(){
  if(!SDL_Init(SDL_INIT_VIDEO)){
    SDL_Log("SDL could not initialize! Error: %s\n", SDL_GetError());
    return false;
  }
  gWindow = SDL_CreateWindow(
      "Clock_app",
      gWidth, gHeight,
      SDL_WINDOW_TRANSPARENT | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_UTILITY | SDL_WINDOW_BORDERLESS);
  if(gWindow == nullptr){
    SDL_Log("Window could not be created! Error: %s\n", SDL_GetError());
    return false;
  }
  gRenderer = SDL_CreateRenderer(gWindow, nullptr);
  if(gRenderer == nullptr){
    SDL_Log("Renderer could not be created! Error: %s\n", SDL_GetError());
    return false;
  }
  if(TTF_Init() == false){
    SDL_Log("TTF could not initialize! Error: %s\n", SDL_GetError());
    return false;
  }
  gFont1 = TTF_OpenFont("/usr/share/fonts/Electroharmonix.otf", gFontSize1);
  if(gFont1 == nullptr){
    SDL_Log("Font could not be created! Error: %s\n", SDL_GetError());
    return false;
  }
  gFont2 = TTF_OpenFont("/usr/share/fonts/Electroharmonix.otf", gFontSize2);
  if(gFont2 == nullptr){
    SDL_Log("Font could not be created! Error: %s\n", SDL_GetError());
    return false;
  }
  return true;
}


void close(){
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  TTF_CloseFont(gFont1);
  TTF_CloseFont(gFont2);
  gRenderer = nullptr;
  gWindow = nullptr;
  gFont1 = nullptr;
  gFont2 = nullptr;
  TTF_Quit();
  SDL_Quit();
}

int main(int argc, char* args[]){
    if(!init()){
      SDL_Log("Failed to initialize!\n");
      return -1;
    }
        bool quit{false};
        SDL_Event e;
        SDL_zero(e);

        while(!quit){
            while(SDL_PollEvent(&e) != 0){
                if(e.type == SDL_EVENT_QUIT){
                    quit = true;
                }




            }
          RENDER::renderBackground(gRenderer, {0x00, 0x00, 0x00, 0x00}); 

          RENDER::drawText(gRenderer, gFont1, getCurrentTime() ,gWidth/2, gHeight/2, {0xFF, 0xFF, 0xFF, 0xFF});
          SDL_RenderPresent(gRenderer);
          SDL_Delay(1000);
        }

    close();
    return 0;
}
