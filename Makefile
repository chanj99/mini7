//Makefile

CC = gcc
makep: main.c product.o manager.o
	$(CC) -o $@ $^
product.o : product.c product.o
	$(CC) -c product.c -o menu.o
manager.o: manager.c manager.h
	$(CC) -c manager.c
clean:
	rm *.o shop

