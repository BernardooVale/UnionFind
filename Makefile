# Nome do executável
TARGET = pa4.out

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -I$(INC_DIR)

# Arquivos fonte e objetos
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Regra padrão
all: $(BIN_DIR)/$(TARGET)

# Regra para construir o executável
$(BIN_DIR)/$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^

# Regra para construir os arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objeto e binários
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET)

# Regra para limpar arquivos temporários
.PHONY: all clean











