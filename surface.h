#ifndef SURFACE_H
#define SURFACE_H

#include <string>

struct SDL_Surface;
class Surface;

/*
 * A surface represents a graphical surface with graphical operations.
 */
class Surface
{
public:
    Surface( int width, int height );
    ~Surface();
    
    static Surface *fromFile( const std::string &filename );
    
    void optimizeToScreen();
    
    void blit( int x, int y, const Surface *source );
    
protected:
    Surface(SDL_Surface *surface);
    void setSurface(SDL_Surface *surface);
    SDL_Surface *surface() const;
    
private:
    SDL_Surface *m_surface;
};

#endif // SURFACE_H