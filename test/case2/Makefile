Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

all: test
clean:
	$Qrm -rf tmp ft_printf
fclean: clean
re: fclean all
init: | printf_tester
deinit: fclean
	$Qrm -rf tmp
	$Qrm -rf printf_tester
reinit: deinit init
refresh:
	$Qrm -rf ft_printf
	$Qcp -r ../../src ft_printf
test: init clean
	$Q$(MAKE) refresh
	$Qcp -r printf_tester ft_printf
	$Q$(MAKE) -C ft_printf/printf_tester a
.PHONY: all clean fclean re init deinit reinit refresh test

printf_tester:
	$Qrm -rf tmp
	$Qgit clone --depth=1 https://github.com/Tripouille/printfTester.git tmp
	$Qmv tmp printf_tester
