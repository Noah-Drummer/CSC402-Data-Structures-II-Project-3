all: p3_402

p3_402: p3_402.o Song.o
	g++ p3_402.o Song.o -o p3_402
	
p3_402.o: p3_402.cpp
	g++ -c p3_402.cpp
	
Song.o: Song.cpp
	g++ -c Song.cpp
	
clean:
	rm *.o p3_402