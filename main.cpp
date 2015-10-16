#include "surface.h"
#include "screen.h"
#include "application.h"

int main( int argc, char* args[] ) 
{
    // Create an application with a main screen
    Application app( 640, 480, "Spritify" );
    
    // Create a surface from a file
    Surface *hello = Surface::fromFile( "ship.png" );
    // Optimize the surface to the screen
    hello->optimizeToScreen();
    
    // Blit the hello surface onto the screen
    app.screen()->blit(100, 100, hello);
    // Flip the screen, i.e. make the changes visible
    app.screen()->flip();
    
    // Execute the mainloop and exit when done
    return app.run();
}
