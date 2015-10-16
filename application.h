#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

class Screen;

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