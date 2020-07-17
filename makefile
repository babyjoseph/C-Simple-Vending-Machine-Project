OBJ = adding.o buying.o main.o display.o savingFile.o readingFile.o product_data.o
CPP = g++
all : main
.PHONY : all
	$(OBJ) : %.o : %.cpp
	$(CPP) -c -I. $< -o $@
main : $(OBJ)
	$(CPP) $(OBJ) -o $@
.PHONY : clean
clean :
	rm $(OBJ) main
