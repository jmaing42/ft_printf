Q := $(if $(filter 1 2 3,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory) $(if $(filter 1,$(NO_ADDITIONAL_J)),,-j $(shell sh build/script/nproc.sh) NO_ADDITIONAL_J=1)

CC := clang
AR := ar
ARFLAGS := cr$(if $(filter 1,$(V) $(VERBOSE)),v,)
CPPFLAGS := $(shell find . -type d -mindepth 1 | grep -v /test/ | sed "s/^/-I /" | xargs)
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS)

SRC_DIR := .
CACHE_DIR := .cache

SRCS := $(shell find . -name "*.c" | grep -v /test/ | xargs)

NAME := libftprintf.a

all: $(NAME)
bonus: all
clean:
	$Qrm -rf $(CACHE_DIR)
fclean:
	$Q$(MAKE) clean
	$Qrm -f $(EXECUTABLE_TARGETS:=.exe)
re:
	$Q$(MAKE) NO_ADDITIONAL_J=1 fclean
	$Q$(MAKE) NO_ADDITIONAL_J=1 all
test:
	$Qfind . -type d -mindepth 1 -name "test" | xargs -L1 -I {} make -C {} test
.PHONY: all bonus clean fclean re test

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

SUFFIX := .$(TARGET).$(PROFILE)$(if $(SANITIZER),.$(SANITIZER))
CFLAGS += $(if $(SANITIZER),-fsanitize=$(SANITIZER),)
LDFLAGS += $(if $(SANITIZER),-fsanitize=$(SANITIZER),)

$(CACHE_DIR)/%.a:
	$Qmkdir -p $(@D)
	$Q$(AR) $(ARFLAGS) $@ $^
$(CACHE_DIR)/%$(SUFFIX).o: %.c
	$Qmkdir -p $(@D)
	$Q$(CC) $(CFLAGS) -MJ $@.compile_commands.part.json -MMD -o $@ -c $<

$(CACHE_DIR)/libftprintf$(SUFFIX).a: $(patsubst ./%.c,$(CACHE_DIR)/%$(SUFFIX).o,$(SRCS))
.PHONY: $(NAME)
$(NAME): $(CACHE_DIR)/libftprintf$(SUFFIX).a
	$Qcp $< $@

# dependencies
-include $(patsubst ./%.c,$(CACHE_DIR)/%$(SUFFIX).d,$(SRCS))
