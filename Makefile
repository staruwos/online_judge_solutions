SRC_NAME = $(notdir $(CURDIR))
INPUT_FILE = input
FLAGS = -lm -lcrypt -O2 -pipe -ansi -Wno-unused-result  

all:
	gcc -o $(SRC_NAME) $(SRC_NAME).c $(FLAGS)

run:
	@./$(SRC_NAME) < $(INPUT_FILE)
