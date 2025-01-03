all:
	gcc -o raytracing raytracing.c `sdl2-config --cflags --libs` -lm