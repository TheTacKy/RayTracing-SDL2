all:
	gcc -o myprogram myprogram.c `sdl2-config --cflags --libs` -lm