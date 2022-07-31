Q := $(if $(filter 1 2 3,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory) $(if $(filter 1,$(NO_ADDITIONAL_J)),,-j $(shell sh src/build/script/nproc.sh) NO_ADDITIONAL_J=1)

export V

all: test
clean:
	$Q$(MAKE) -C src fclean
	$Qfind src \( -type f \( -name compile_commands.json -o -name "*.part.json" -o -name "*.exe" \) -o -type d -name .cache \) -delete
	$Qfind src -type d -empty -delete
	$Qfind src -type d -name test | xargs -L1 -I {} make -C {} clean
	@printf "\033[0m"
fclean:
	$Qrm -rf tmp compile_commands.json .vscode/launch.json .vscode/tasks.json
	$Q$(MAKE) -C src fclean
	$Qfind src \( -type f \( -name compile_commands.json -o -name "*.part.json" -o -name "*.exe" \) -o -type d -name .cache \) -delete
	$Qfind src -type d -empty -delete
	$Qfind src -type d -name test | xargs -L1 -I {} make -C {} fclean
	@printf "\033[0m"
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
test:
	$Qfind src -type d -name test | sort | xargs -L1 $(MAKE) -C
	@echo "Some test might need manual review"
publish_without_test:
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qsh src/build/script/copy_src_to_tmp_flatten.sh
	$Qcd tmp && sh ../template/template.sh > Makefile
	$Q(cd tmp && git init && git add . && git commit -m "Initial commit" && git push "$(GIT_REMOTE_URL)" HEAD:master) || (echo "Failed to publish" && false)
	$Qrm -rf tmp
	$Qgit push "$(GIT_REMOTE_URL)" HEAD:source || echo "Failed to push HEAD to source"
publish:
	$Q$(MAKE) test
	$Q$(MAKE) publish_without_test
.PHONY: all clean fclean re init deinit reinit refresh test publish publish_without_test

.PHONY: pre_dev
pre_dev:
	$Qfind src -type d -name test | xargs -L1 -I {} make -C {} dev
.PHONY: compile_commands.json
compile_commands.json: pre_dev
	$Q$(MAKE) -C src -k PROFILE=debug TARGET=development all ; (printf "[" && find src/.cache -name "*.development.debug.o.compile_commands.part.json" | xargs cat && printf "]") > $@
.PHONY: .vscode/launch.json
.vscode/launch.json: pre_dev
	$Q(cat template/launch.json.before.txt && find src -name launch.part.json | xargs cat && cat template/launch.json.after.txt) > $@
.PHONY: .vscode/tasks.json
.vscode/tasks.json: pre_dev
	$Q(cat template/tasks.json.before.txt && find src -name tasks.part.json | xargs cat && cat template/tasks.json.after.txt) > $@
.PHONY: dev
dev: compile_commands.json .vscode/launch.json .vscode/tasks.json
