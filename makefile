Objects = wait.o
DEPS = stdafx.h
CC=gcc
wait : $(Objects)
	$(CC) -o wait $(Objects)
wait.o : wait.cpp $(DEPS)
	$(CC) -c wait.cpp
clean :
	rm wait.o
