CXX      = g++
CXXFLAGS = -Wall -g

SRC_DIR  = src
OBJ_DIR  = build
BIN_DIR  = bin

SRC      = $(wildcard $(SRC_DIR)/*.cpp)
OBJ      = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

TARGET   = $(BIN_DIR)/main

all: $(TARGET)

# Link les objets pour produire le binaire final
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile chaque .cpp en .o dans build/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
