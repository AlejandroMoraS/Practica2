.PHONY: all initx gettyx shx clean
all: initx gettyx shx

initx: init.c
	gcc -o init init.c

gettyx: getty.c
	gcc -o getty getty.c

shx: sh.c
	gcc -o sh sh.c

clean:
	rm init getty sh
