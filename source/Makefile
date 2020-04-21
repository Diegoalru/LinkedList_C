CC      = gcc
CFLAGS  = -std=c11 -Wall -fmax-errors=10 -Wextra
OBJFLS	= struct.o main.o
EXE		= LinkedList

main: $(OBJFLS)
	$(CC) $(CFLAGS) $(OBJFLS) -o $(EXE);

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@;

permises:
	chmod +x program;

launch: permises
	./$(EXE)

clean:
	rm ./$(EXE) *.o;
