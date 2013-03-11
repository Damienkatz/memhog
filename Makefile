CC = gcc
CFLAGS = -g -O2
OBJECTS = memhog.o

memhog : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o memhog

memhog.o : memhog.c
	$(CC) $(CFLAGS) -c memhog.c