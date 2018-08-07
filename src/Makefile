CC = gcc

memory_eater: memory_eater.c
	$(CC) -Wall -O2 -o ../bin/memory_eater memory_eater.c

memory_eater: cpu_eater.c
	$(CC) -Wall -O2 -o ../bin/cpu_eater cpu_eater.c

clean:
	rm ../bin/memory_eater ../bin/cpu_eater
