#ifndef SCREEN_H
#define SCREEN_H

#include <string>

#include "surface.h"

struct SDL_Surface;
class Application;

/*
 * A screen is a specialization of a surface. This surface represents the 
 * double buffered window surface shown to the users.
 * 
 * Screens are intended to be created through an Application object.
 */
class Screen : public Surface
{
public:
    void flip();
    
private:
    Screen(int width, int height, std::string title);
    
    friend class Application;
    
    SDL_Surface *m_screen;
    std::string m_title;
};

#endif // SCREEN_H