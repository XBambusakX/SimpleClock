all:
	g++ -o "SimpleClock :3" ./src/* `pkg-config --cflags --libs sdl3` `pkg-config --cflags --libs sdl3-ttf`
