#include <stdio.h>
#include <limits.h>

int ft_printf(const char *format, ...);

int main(void)
{
	// int len;
	// len = ft_printf("Hello %s, your score is %d out of %u. Pointer: %p, Hex: %x, Char: %c\n", "Alice", -42, 100u, (void*)0x1234abcd, 255u, 'A');
	// printf("ft_printf returned length: %d\n", len);
	// len = printf("Hello %s, your score is %d out of %u. Pointer: %p, Hex: %x, Char: %c\n", "Alice", -42, 100u, (void*)0x1234abcd, 255u, 'A');
	// printf("printf returned length: %d\n", len);
	
	int len;

	len = printf("r %x \n", LONG_MAX);
	printf("printf return: %d\n", len);
	len = ft_printf("m %x \n", LONG_MAX);
	printf("ft_printf r: %d\n", len);
	return 0;
}
/*
For /home/alamjada/francinette/tests/printf/printfTester/tests/x_test.cpp:
48:     TEST(24, print(" %x ", LONG_MAX));
49:     TEST(25, print(" %x ", LONG_MIN));
51:     TEST(27, print(" %x ", ULONG_MAX));
52:     TEST(28, print(" %x ", 9223372036854775807LL));
53:     TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

For /home/alamjada/francinette/tests/printf/printfTester/tests/upperx_test.cpp:
48:     TEST(24, print(" %X ", LONG_MAX));
49:     TEST(25, print(" %X ", LONG_MIN));
51:     TEST(27, print(" %X ", ULONG_MAX));
52:     TEST(28, print(" %X ", 9223372036854775807LL));
53:     TEST(29, print(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
*/
