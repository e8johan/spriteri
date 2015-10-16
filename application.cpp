#include "application.h"
#include "screen.h"

#include "SDL/SDL.h"

Application::Application(int w, int h, std::string title)
{
    SDL_Init( SDL_INIT_EVERYTHING ); 
    
    m_screen = new Screen(w, h, title);
}

Application::~Application()
{
    SDL_Quit(); 
}

Screen *Application::screen() const
{
    return m_screen;
}

int Application::run()
{
    int m_running = true;
    
    while (m_running)
        m_running = poll();
    
    return 0;
}

bool Application::poll()
{
    SDL_Event event;

    while( SDL_PollEvent( &event )) 
    {
        if ( event.type == SDL_QUIT )
            return false;
    }
    
    return true;
}
