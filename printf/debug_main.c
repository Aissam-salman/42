#include <stdio.h>

int ft_printf(const char *format, ...);

int main(void)
{
	int len;
	len = ft_printf("Hello %s, your score is %d out of %u. Pointer: %p, Hex: %x, Char: %c\n", "Alice", -42, 100u, (void*)0x1234abcd, 255u, 'A');
	printf("ft_printf returned length: %d\n", len);
	len = printf("Hello %s, your score is %d out of %u. Pointer: %p, Hex: %x, Char: %c\n", "Alice", -42, 100u, (void*)0x1234abcd, 255u, 'A');
	printf("printf returned length: %d\n", len);
	return 0;
}
