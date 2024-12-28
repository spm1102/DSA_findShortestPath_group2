clean:
	-del "build"

build:
	-mkdir "build"
	gcc src/*.c src/BFS/*.c src/A_star/*.c src/Dijkstra/*.c  -Iinc -o build/main -g -O0  -lraylib -lgdi32 -lwinmm -Lraylib/lib -Iraylib/include

run:
	./build/main
