.PHONY: all clean

SOURCES_DIR = sources

all: main.o bitfuncs.o strfuncs.o
	gcc -o formater main.o bitfuncs.o strfuncs.o -lm

clean:
	rm -rf formater *.o

main.o: $(SOURCES_DIR)/main.c
	gcc -c -o main.o $(SOURCES_DIR)/main.c

bitfuncs.o: $(SOURCES_DIR)/bitfuncs.c
	gcc -c -o bitfuncs.o $(SOURCES_DIR)/bitfuncs.c

strfuncs.o: $(SOURCES_DIR)/strfuncs.c
	gcc -c -o strfuncs.o $(SOURCES_DIR)/strfuncs.c
