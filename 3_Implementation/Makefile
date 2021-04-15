#Target : dependency
#<TAB>Command

PROJECT_NAME = main.exe
SRC = main.c printMatrix.c 

INC = inc


$(PROJECT_NAME):$(SRC) 
	gcc -I $(INC) $(SRC) -o main.exe

run: $(PROJECT_NAME)
	$(PROJECT_NAME)
clean:
	del /q *.exe
