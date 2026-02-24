# Pfade und Dateien
SRC = src/main.cpp src/Board.cpp src/Pawn.cpp src/Render.cpp
OBJ = $(SRC:.cpp=.o)
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)
TARGET = chess

# Standardziel
all: $(TARGET)

# Linken
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# Kompilieren von .cpp zu .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean – löscht alle Objekt- und Ziel-Dateien
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild (clean + all)
re: clean all

.PHONY: all clean re