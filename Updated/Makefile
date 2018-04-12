CC=gcc
CFLAGS = o
OPTION = -std=c99 -Wall -Werror
FILES = Tuple.c Database_new.c
OUTPUT = out

make : $(FILES)
	$(CC) -$(CFLAGS) $(OUTPUT) $(OPTION) $(FILES)

run :
	./$(OUTPUT)

clean :
	rm $(OUTPUT)

run-clean : $(FILES)
	$(CC) -$(CFLAGS) $(OUTPUT) $(OPTION) $(FILES)
	./$(OUTPUT)
	rm $(OUTPUT)
