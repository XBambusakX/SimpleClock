#ifndef RENDER_HPP
#define RENDER_HPP

#include <iostream>
#include <string>
#include <cmath>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

namespace RENDER {
  void renderBackground(SDL_Renderer* renderer, SDL_Color color);
  void drawText(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y, SDL_Color color);
  void drawRectangle(SDL_Renderer* renderer, float x, float y, float w, float h, SDL_Color color, bool filled);
  void drawCircle(SDL_Renderer* renderer, float x, float y, float r, SDL_Color color, bool filled);
  void drawImage(SDL_Renderer* renderer, SDL_Texture* texture, float x, float y, float w, float h);
}
#endif 
