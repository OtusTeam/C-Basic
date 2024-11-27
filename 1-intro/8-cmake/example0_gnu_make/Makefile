TARGET = gnu_make_example

CC = g++
CFLAGS = -g -Wall -Wfatal-errors -std=c++17
OBJ = main.o answer.o

.DEFAULT_GOAL := $(TARGET)
.PHONY: $(TARGET) clean

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ifeq ($(OS),Windows_NT)
    RM = cmd /C del /Q /F /S
else
    RM = rm -f
endif

clean:
	$(RM) *.o
	$(RM) $(TARGET)*
