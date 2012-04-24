
EXE=cine
SRC_DIR=src
CC=g++
FLAGS=
D_FLAGS= $(FLAGS) -g
SRC_FILES=$(SRC_DIR)/time.cpp $(SRC_DIR)/film.cpp $(SRC_DIR)/programmation.cpp \
	$(SRC_DIR)/planning.cpp $(SRC_DIR)/salle.cpp $(SRC_DIR)/cinematheque.cpp \
	$(SRC_DIR)/cinema.cpp $(SRC_DIR)/main.cpp


all: $(SRC_FILES)
	$(CC) -o $(EXE).exe $^ $(FLAGS)

debug: $(SRC_FILES)
	$(CC) -o $(EXE).dbg.exe $^ $(D_FLAGS)

clean:
	rm *.exe
