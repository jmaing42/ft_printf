# Assuming modifying the libft's source files only.
# If tester's source files were modified, run make in appropriate directory

Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

# This variable will be used only if source files are not hardcoded
SRCS ?= $(wildcard *.c)

NAME := libftprintf.a
OTHER_USEFUL_FILES := .editorconfig .gitignore

CC := gcc
AR := ar
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic -g3
TMPS := *.o *.d $(OTHER_USEFUL_FILES)

all: $(NAME) $(OTHER_USEFUL_FILES)
bonus: all
clean:
	$Qrm -rf $(TMPS) $(OTHER_USEFUL_FILES)
fclean: clean
	$Qrm -f $(NAME)
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
.PHONY: all bonus clean fclean re

.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\n*.o\n*.d\n*.a\n*.exe\n\nlibftprintf.a\n" > .gitignore

%.a:
	$Q$(AR) rcs $@ $^
%.o: %.c
	$Q$(CC) $(CFLAGS) -c $< -o $@ -MMD
%.exe:
	$Q$(CC) $(LDFLAGS) -o $@ $^

$(NAME): $(SRCS:.c=.o)

-include $(SRCS:.c=.d)
