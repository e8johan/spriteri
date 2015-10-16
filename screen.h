#ifndef SCREEN_H
#define SCREEN_H

#include <string>

#include "surface.h"

struct SDL_Surface;

class Screen : public Surface
{
public:
    Screen(int width, int height, std::string title);
    
    void flip();
private:
    SDL_Surface *m_screen;
    std::string m_title;
};

#endif // SCREEN_H