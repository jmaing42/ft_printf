#include <stdio.h>
#include "../../src/format.h"


int main() {
	t_printf_format *format = printf_format_parse("Hello %s!");
	printf("%p\n", format);
	printf_format_free(format);
	return 0;
}
