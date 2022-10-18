CC=cc

game: $(wildcard *.c)
	$(CC) $^ -o $@ $(shell pkg-config --cflags --libs glfw3)