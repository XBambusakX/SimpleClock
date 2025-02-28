#include <iostream>
#include <string>
#include <cmath>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "render.hpp"

void RENDER::renderBackground(SDL_Renderer* renderer, SDL_Color color){
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(renderer);
}

void RENDER::drawText(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y, SDL_Color color){
  SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), 0, color);
  SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_FRect textRect;
  textRect.w = textSurface->w;
  textRect.h = textSurface->h;
  textRect.x = (x - textSurface->w/2.0f);
  textRect.y = (y - textSurface->h/2.0f);
  SDL_RenderTexture(renderer, textTexture, nullptr, &textRect);
  SDL_DestroySurface(textSurface);
  SDL_DestroyTexture(textTexture);
}
void RENDER::drawRectangle(SDL_Renderer* renderer, float x, float y, float w, float h, SDL_Color color, bool filled){
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_FRect rect{x, y, w, h};
  if(filled){
    SDL_RenderFillRect(renderer, &rect);
  } else {
    SDL_RenderRect(renderer, &rect);
  }
}
void RENDER::drawCircle(SDL_Renderer* renderer, float x, float y, float r, SDL_Color color, bool filled){
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  if(filled){
    for (int w = 0; w < r * 2; w++) {
        for (int h = 0; h < r * 2; h++) {
            int dx = r - w; // horizontal offset
            int dy = r - h; // vertical offset
            if ((dx * dx + dy * dy) <= (r * r)) {
                SDL_RenderPoint(renderer, x + dx, y+ dy);
            }
        }
    }
  } else {
    for(float i = 0; i < 360; i+=0.1){
      SDL_RenderPoint(renderer, x + r*cos(i), y + r*sin(i));
    }
  }
}

void RENDER::drawImage(SDL_Renderer* renderer, SDL_Texture* texture, float x, float y, float w, float h){
  SDL_FRect rect{x-w/2, y-h/2, w, h};
  SDL_RenderTexture(renderer, texture, nullptr, &rect);
}
