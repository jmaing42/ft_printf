NAME = libftprintf.a

OBJS = $(OBJS)

OTHER_USEFUL_FILES = .editorconfig .gitignore

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(OTHER_USEFUL_FILES)
bonus: all
clean:
	rm -f $(OBJS) $(NAME) $(OTHER_USEFUL_FILES)
fclean: clean
	rm -f $(EXECUTABLE_TARGETS)
re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: all bonus clean fclean re

.editorconfig:
	printf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	(printf ".*\n*.o\n\n" && echo "$(NAME)" | xargs -n 1 echo) > $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
