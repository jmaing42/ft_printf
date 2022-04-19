all: test.exe
clean:
	rm -rf test.exe*
re:
	$(MAKE) clean
	$(MAKE) all
test.exe:
	clang -g3 main.c ../../src/libftprintf.a -o $@
