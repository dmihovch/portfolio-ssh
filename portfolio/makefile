all:
	gcc -o bin/portfolio main.c src/animations.c src/utils.c src/page.c -lpanel -lncurses 

run: bin/portfolio
	./bin/portfolio

clean:
	rm bin/portfolio
