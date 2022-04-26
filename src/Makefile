Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

# This variable will be used only if source files are not hardcoded
SRCS ?= $(shell find . -name "*.c" | cut -c 3- | xargs)

NAME := libftprintf.a
OTHER_USEFUL_FILES := .editorconfig .gitignore

CC := clang
AR := ar
CFLAGS := -Wall -Wextra -Werror -g3
TMPS := $(OTHER_USEFUL_FILES)

all: $(NAME) $(OTHER_USEFUL_FILES)
bonus: all
clean:
	$Qrm -rf $(OTHER_USEFUL_FILES)
	$Qfind . -name "*.tmp.*" -delete
fclean: clean
	$Qrm -f $(NAME)
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
.PHONY: all bonus clean fclean re

.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\n*.tmp.*\n" > .gitignore

PROFILE ?= release
ifeq ($(PROFILE),release)
CFLAGS := -O3 -DNDEBUG
else ifeq ($(PROFILE),debug)
CFLAGS += -g3 -DDEBUG
else
$(error Bad profile)
endif

TARGET ?= production
ifeq ($(TARGET),production)
CFLAGS := -DNDEVELOPMENT
else ifeq ($(TARGET),development)
CFLAGS += -DDEVELOPMENT
else
$(error Bad target)
endif

POSTFIX := .$(TARGET).$(PROFILE)$(if $(SANITIZER),.$(SANITIZER))

%.tmp.a:
	$Q$(AR) rcs $@ $^
%$(POSTFIX).tmp.o: %.c
	$Q$(CC) $(CFLAGS) -c $< -o $@ -MMD $(if $(SANITIZER),-fsanitize=$(SANITIZER),)

ft_printf$(POSTFIX).tmp.a: $(SRCS:.c=$(POSTFIX).tmp.o)
$(NAME): ft_printf$(POSTFIX).tmp.a
	$Qcp $< $@
all_variants:
	$(MAKE) PROFILE=release TARGET=production || true
	$(MAKE) PROFILE=release TARGET=production SANITIZER=address || true
	$(MAKE) PROFILE=release TARGET=production SANITIZER=memory || true
	$(MAKE) PROFILE=release TARGET=production SANITIZER=undefined || true
	$(MAKE) PROFILE=release TARGET=development || true
	$(MAKE) PROFILE=release TARGET=development SANITIZER=address || true
	$(MAKE) PROFILE=release TARGET=development SANITIZER=memory || true
	$(MAKE) PROFILE=release TARGET=development SANITIZER=undefined || true
	$(MAKE) PROFILE=debug TARGET=production || true
	$(MAKE) PROFILE=debug TARGET=production SANITIZER=address || true
	$(MAKE) PROFILE=debug TARGET=production SANITIZER=memory || true
	$(MAKE) PROFILE=debug TARGET=production SANITIZER=undefined || true
	$(MAKE) PROFILE=debug TARGET=development || true
	$(MAKE) PROFILE=debug TARGET=development SANITIZER=address || true
	$(MAKE) PROFILE=debug TARGET=development SANITIZER=memory || true
	$(MAKE) PROFILE=debug TARGET=development SANITIZER=undefined || true
.PHONY: $(NAME) all_variants

-include $(SRCS:.c=$(POSTFIX).tmp.d)
