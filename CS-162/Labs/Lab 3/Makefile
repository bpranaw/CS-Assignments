CC = g++

EXE_FILE = pizzapizza

all: $(EXE_FILE)

$(EXE_FILE): pizza.h pizza.cpp prog.cpp
	$(CC) pizza.h pizza.cpp prog.cpp -o $(EXE_FILE)


clean:
	rm -f *.o $(EXE_FILE)
