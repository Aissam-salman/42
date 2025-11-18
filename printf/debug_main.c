#include <stdio.h>

int ft_printf(const char *format, ...);

int main(void)
{
	// int len;
	// len = ft_printf("Hello %s, your score is %d out of %u. Pointer: %p, Hex: %x, Char: %c\n", "Alice", -42, 100u, (void*)0x1234abcd, 255u, 'A');
	// printf("ft_printf returned length: %d\n", len);
	// len = printf("Hello %s, your score is %d out of %u. Pointer: %p, Hex: %x, Char: %c\n", "Alice", -42, 100u, (void*)0x1234abcd, 255u, 'A');
	// printf("printf returned length: %d\n", len);
	
	int len;

	len = printf("r %u \n", -1);
	printf("printf return: %d\n", len);
	len = ft_printf("m %u \n", -1);
	printf("ft_printf r: %d\n", len);
	return 0;
}
/*
26:     TEST(2, print(" %u ", -1));
37:     TEST(13, print(" %u ", -9));
38:     TEST(14, print(" %u ", -10));
39:     TEST(15, print(" %u ", -11));
40:     TEST(16, print(" %u ", -14));
41:     TEST(17, print(" %u ", -15));
42:     TEST(18, print(" %u ", -16));
43:     TEST(19, print(" %u ", -99));
44:     TEST(20, print(" %u ", -100));
45:     TEST(21, print(" %u ", -101));
47:     TEST(23, print(" %u ", INT_MIN));
48:     TEST(24, print(" %u ", LONG_MAX));
50:     TEST(26, print(" %u ", UINT_MAX));
51:     TEST(27, print(" %u ", ULONG_MAX));
52:     TEST(28, print(" %u ", 9223372036854775807LL));
53:     TEST(29, print(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
*/
