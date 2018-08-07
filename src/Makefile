CC = gcc

all: memory_eater cpu_eater

memory_eater: memory_eater.c
	$(CC) -Wall -O2 -o ../bin/memory_eater memory_eater.c

cpu_eater: cpu_eater.c
	$(CC) -Wall -O2 -o ../bin/cpu_eater cpu_eater.c -lm 

clean:
	rm ../bin/memory_eater ../bin/cpu_eater
