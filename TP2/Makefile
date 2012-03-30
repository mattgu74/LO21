
EXE=bnp
SRC_DIR=src
CC=g++
FLAGS=
D_FLAGS= $(FLAGS) -g
SRC_FILES= $(SRC_DIR)/date.cpp $(SRC_DIR)/banque.cpp $(SRC_DIR)/typecompte.cpp $(SRC_DIR)/compte.cpp $(SRC_DIR)/client.cpp $(SRC_DIR)/main.cpp

all: $(SRC_FILES)
	$(CC) -o $(EXE).exe $^ $(FLAGS)

debug: $(SRC_FILES)
	$(CC) -o $(EXE).dbg.exe $^ $(D_FLAGS)

clean:
	rm *.exe
