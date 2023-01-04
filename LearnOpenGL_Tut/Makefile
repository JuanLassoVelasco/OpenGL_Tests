PROG_NAME := testProg

INCLUDE_DIR := include
SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj

EXE := $(BIN_DIR)/$(PROG_NAME)
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

OPNGL_FLAGS := $(pkg-config --cflags glfw3) -lGL -lgflw3 -lXinerama -lXcursor -lX11 -lpthread -lXrandr -lXi -ldl -lm -lXxf86vm -lGLU $(pkg-config --static --libs glfw3) 
CXX_FLAGS := -I $(INCLUDE_DIR)

$(EXE): $(OBJ) | $(BIN_DIR)
	g++ $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	env PKG_CONFIG_PATH=/usr/local/lib/pkgconfig/glfw3.pc g++ $(OPNGL_FLAGS) $(CXX_FLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)

# env PKG_CONFIG_PATH=/usr/local/lib/pkgconfig/glfw3.pc g++ -L/lib/x86_64-linux-gnu/libglfw.so $(CXX_FLAGS)
