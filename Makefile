TARGET = cmdcalc
.PHONY: all clean run
all: $(TARGET)
clean:
	rm $(TARGET) *.o
run: $(TARGET)
	./$(TARGET)
main.o: main.c
	gcc -c main.c -Wall -Wextra
lab1.o: lab1.c
	gcc -c lab1.c -Wall -Wextra
$(TARGET): main.o lab1.o
	gcc main.o lab1.o -o $(TARGET) -Wall -Wextra
