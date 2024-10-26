CC=gcc
CFLAGS=-Wall -Wextra -Wno-error

OBJECTS=main.o datastructcher.o StringUtils.o Fileutils.o 
program: $(OBJECTS)
	$(CC) $(CFLAGS) -o program $(OBJECTS)

main.o: source/main.c
	$(CC) $(CFLAGS) -c source/main.c

datastructcher.o: source/datastructcher.c
	$(CC) $(CFLAGS) -c source/datastructcher.c

StringUtils.o: source/StringUtils.c
	$(CC) $(CFLAGS) -c source/StringUtils.c

Fileutils.o: source/FileUtils.c
	$(CC) $(CFLAGS) -c source/FileUtils.c
	


clean:
	del -rf *.o program