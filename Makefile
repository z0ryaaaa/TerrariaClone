CC = gcc
CFLAGS = -Wall -std=c17
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

SRC = main.cpp
OUT = game

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)

