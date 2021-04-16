PROJECT_NAME = Tic_Tac_Toe
BUILD = build

SRC = main.c\
src/printMatrix.c

TEST_SRC = src/printMatrix.c\
src/main.c\
test/test.c\
unity/unity.c\

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

INC	= -Iinc\
-Iunity\

PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

DOCUMENTATION_OUTPUT = documentation/html

$(PROJECT_NAME):all

.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).out

run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out


test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
coverageCheck:$(BUILD)
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

$(BUILD):
	mkdir build
