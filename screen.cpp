#include "screen.h"

#include "SDL/SDL.h"

Screen::Screen(int width, int height, std::string title)
    : Surface(0), m_title(title)
{
    setSurface(SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE));
    SDL_WM_SetCaption(title.c_str(), NULL);
}

void Screen::flip()
{
    SDL_Flip( surface() );
}
