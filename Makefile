CC=cc

game: $(wildcard *.c)
	$(CC) $^ -o $@ $(shell pkg-config --cflags --libs gl glu glfw3)
