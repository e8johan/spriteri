#include "surface.h"
#include "screen.h"
#include "application.h"

int main( int argc, char* args[] ) 
{ 
    Application app( 640, 480, "Spritify" );
    
    Surface *hello = Surface::fromFile( "ship.png" );
    hello->optimizeToScreen();
    
    app.screen()->blit(100, 100, hello);
    app.screen()->flip();
    
    return app.run();
}
