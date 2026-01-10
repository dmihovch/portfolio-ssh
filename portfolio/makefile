all:
	gcc -o bin/portfolio main.c src/animations.c src/utils.c src/home.c src/resume.c logs/logs.c -lpanel -lncurses


nodebug:
	gcc -o bin/portfolio main.c src/animations.c src/utils.c src/resume.c -lpanel -lncurses 

run: bin/portfolio
	./bin/portfolio

clean:
	rm bin/portfolio
