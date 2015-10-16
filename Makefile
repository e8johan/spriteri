all: spriteri

spriteri: main.cpp application.cpp screen.cpp surface.cpp
	g++ $^ -lSDL -lSDL_image -o $@
