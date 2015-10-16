#include "surface.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

Surface::Surface(int width, int height)
{
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    m_surface = SDL_CreateRGBSurface( 0, width, height, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff );
#else
    m_surface = SDL_CreateRGBSurface( 0, width, height, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000 );
#endif
}

Surface::Surface( SDL_Surface *surface )
    : m_surface(surface)
{
}

Surface::~Surface()
{
    SDL_FreeSurface(m_surface);
}

Surface *Surface::fromFile( const std::string &filename )
{
    return new Surface(IMG_Load(filename.c_str()));
}

void Surface::optimizeToScreen()
{
    SDL_Surface *optimized = SDL_DisplayFormat( m_surface );
    SDL_FreeSurface( m_surface );
    m_surface = optimized;
}

void Surface::blit(int x, int y, const Surface *source)
{
    SDL_Rect offset;
    
    offset.x = x;
    offset.y = y;
    
    SDL_BlitSurface( source->m_surface, NULL, m_surface, &offset );
}

void Surface::setSurface(SDL_Surface *s)
{
    m_surface = s;
}

SDL_Surface *Surface::surface() const
{
    return m_surface;
}
