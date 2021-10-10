final: main.o inputFunc.o charFunc.o mathFunc.o txtrFunc.o
	gcc -std=c99 -Wall -Wextra -Wconversion -Wpedantic main.o inputFunc.o charFunc.o mathFunc.o txtrFunc.o -o program `sdl2-config --cflags --libs` -lSDL2_image -lm

main.o: main.c main.h common.h
	gcc -std=c99 -Wall -Wextra -Wconversion -Wpedantic main.c `sdl2-config --cflags --libs` -lSDL2_image -lm -o main.o -c

inputFunc.o: inputFunc.c inputFunc.h common.h
	gcc -std=c99 -Wall -Wextra -Wconversion -Wpedantic inputFunc.c `sdl2-config --cflags --libs` -lSDL2_image -lm -o inputFunc.o -c

charFunc.o: charFunc.c charFunc.h common.h
	gcc -std=c99 -Wall -Wextra -Wconversion -Wpedantic charFunc.c `sdl2-config --cflags --libs` -lSDL2_image -lm -o charFunc.o -c

mathFunc.o: mathFunc.c mathFunc.h common.h
	gcc -std=c99 -Wall -Wextra -Wconversion -Wpedantic mathFunc.c `sdl2-config --cflags --libs` -lSDL2_image -lm -o mathFunc.o -c

txtrFunc.o: txtrFunc.c txtrFunc.h common.h
	gcc -std=c99 -Wall -Wextra -Wconversion -Wpedantic txtrFunc.c `sdl2-config --cflags --libs` -lSDL2_image -lm -o txtrFunc.o -c

clearProgram:
	rm -rf program

clearFiles:
	rm -rf *.o
