CC = g++
EXEC = Mandelbrot
INCLUDE = -I/opt/homebrew/Cellar/sfml/2.5.1_2/include
FLAGS = -Wall -pedantic -O3 -Os
LIBS = -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
STD = -std=c++17
S = src
O = obj
B = bin

all: $(O) $(B) $(O)/Main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(LIBS)

$(O)/Main.o: $(O)/Engine.o
	$(CC) $(S)/Main.cpp -c -o $(O)/Main.o $(INCLUDE) $(STD) $(FLAGS)

$(O)/Engine.o: $(O)/Mandelbrot.o
	$(CC) $(S)/Engine.cpp -c -o $(O)/Engine.o $(INCLUDE) $(STD) $(FLAGS)

$(O)/Mandelbrot.o: $(O)/Complexe.o
	$(CC) $(S)/Mandelbrot.cpp -c -o $(O)/Mandelbrot.o $(INCLUDE) $(STD) $(FLAGS)

$(O)/Complexe.o:
	$(CC) $(S)/Complexe.cpp -c -o $(O)/Complexe.o $(INCLUDE) $(STD) $(FLAGS)

clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)
