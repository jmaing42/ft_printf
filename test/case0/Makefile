SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

SANITIZER ?= address

all: test.exe
clean:
	rm -rf test.exe*
	rm -rf *.o
re:
	$(MAKE) fclean
	$(MAKE) all
	$(MAKE) -C ../../src re
test: out_expected.txt
	./test.exe > out_result.txt
	diff out_expected.txt out_result.txt -U 3
%.o: %.c
	clang -g3 -c $< -o $@
test.exe: $(OBJS) ../../src/libftprintf.a
	clang -g3 $^ -o $@ -fsanitize=$(SANITIZER)
out_expected.txt: test.exe
	./test.exe printf > out_expected.txt
../../src/libftprintf.a:
	$(MAKE) -C ../../src PROFILE=debug SANITIZER=$(SANITIZER)
.PHONY: all clean fclean re test ../../src/libftprintf.a
