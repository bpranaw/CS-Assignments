CC=g++ -std=c++11
exe_file=task1

$(exe_file): task1_main.cpp solution1.o memory.o
	$(CC) task1_main.cpp solution1.o memory.o -o $(exe_file) 

solution1.o: solution1.cpp
	$(CC) -c solution1.cpp 

memory.o: memory.cpp
	$(CC) -c memory.cpp 

clean: 
	rm -f *.o $(exe_file)


.PHONY: clean