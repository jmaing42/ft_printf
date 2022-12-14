all: test

include $(BASE_PATH)/build/compile_commands.mk

build: .cache/Makefile

.cache/Makefile:
	$(Q3)mkdir -p .cache
	$(Q2)sh $(BASE_PATH)/build/script/test_build.sh $(BASE_PATH) $(SRCS_FILE) $(INCS_FILE)

clean:
	$(Q2)rm -rf .cache

fclean: clean
	$(Q2)rm -f launch.part.json tasks.part.json

test: build

build:
	$(Q2)make COMMON_FLAGS=$(COMMON_FLAGS) -C .cache

launch.part.json:
	$(Q2)printf '    {\n      "type": "lldb",\n      "request": "launch",\n      "name": "Debug unit test %s",\n      "program": "%s/.cache/test.exe",\n      "cwd": "%s",\n      "preLaunchTask": "build unit test %s",\n    },\n' "$$(basename "$$(pwd)")" "$$(pwd)" "$$(pwd)" "$$(basename "$$(pwd)")" > $@

tasks.part.json:
	$(Q2)printf '    {\n      "label": "build unit test %s",\n      "type": "shell",\n      "command": "make build",\n      "options": {\n        "cwd": "%s",\n      },\n      "problemMatcher": ["$$gcc"]\n    },\n' "$$(basename "$$(pwd)")" "$$(pwd)" > $@

dev: launch.part.json tasks.part.json
