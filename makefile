#MakeFile by Ryan Kuhl
#YOLO
#BrObama
CC = g++
CFLAGS = -c -g
LFLAGS = -g -o proj2.x

main: test_vector.o
	$(CC) $(LFLAGS) test_vector.o
	rm -f *.h.gch
	rm -f *.o
test_vector.o: Vector.hpp Vector.h test_vector.cpp
	$(CC) $(CFLAGS) Vector.h
	$(CC) $(CFLAGS) test_vector.cpp

