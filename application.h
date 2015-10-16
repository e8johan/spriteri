#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

class Screen;

/*
 * The application represents the singletons in the system, e.g. event loop and
 * main screen.
 */
class Application
{
public:
    Application(int w, int h, std::string title);
    ~Application();
    
    Screen *screen() const;
    
    int run();

private:
    bool poll();
    
    Screen *m_screen;
};

#endif // APPLICATION_H