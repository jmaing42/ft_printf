Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

# This variable will be used only if source files are not hardcoded
SRCS ?= $(shell find . -name "*.c" | xargs)

NAME := libftprintf.a
OTHER_USEFUL_FILES := .editorconfig .gitignore

CC := clang
AR := ar
CFLAGS := -Wall -Wextra -Werror -g3
TMPS := $(OTHER_USEFUL_FILES)

TMP_DIR := tmp

all: $(NAME) $(OTHER_USEFUL_FILES)
bonus: all
clean:
	$Qrm -rf $(OTHER_USEFUL_FILES) tmp
fclean: clean
	$Qrm -f $(NAME)
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
.PHONY: all bonus clean fclean re

.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\ntmp\n" > .gitignore

PROFILE ?= release
ifeq ($(PROFILE),release)
CFLAGS += -O3 -DNDEBUG
else ifeq ($(PROFILE),debug)
CFLAGS += -g3 -DDEBUG
else
$(error Bad profile)
endif

TARGET ?= production
ifeq ($(TARGET),production)
CFLAGS += -DNDEVELOPMENT
else ifeq ($(TARGET),development)
CFLAGS += -DDEVELOPMENT
else
$(error Bad target)
endif

POSTFIX := .$(TARGET).$(PROFILE)$(if $(SANITIZER),.$(SANITIZER))

$(TMP_DIR)/%.a:
	$Qmkdir -p $(@D)
	$Q$(AR) rcs $@ $^
$(TMP_DIR)/%$(POSTFIX).o: %.c
	$Qmkdir -p $(@D)
	$Q$(CC) $(CFLAGS) -c $< -o $@ -MMD $(if $(SANITIZER),-fsanitize=$(SANITIZER),)

$(TMP_DIR)/ft_printf$(POSTFIX).a: $(patsubst ./%.c,$(TMP_DIR)/%$(POSTFIX).o,$(SRCS))
.PHONY: $(NAME)
$(NAME): $(TMP_DIR)/ft_printf$(POSTFIX).a
	$Qcp $< $@

-include $(TMP_DIR)/$(SRCS:.c=$(POSTFIX).d)
