/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:33:27 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/22 13:35:56 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void dump_32bits_integer(int const n);
void dump_64bits_double(double const z);

#include <stdio.h>

void dump_32bits_integer(int n)
{
    unsigned int bits = *(unsigned int *)&n;
    printf("int    [%d]:\t", n);
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (bits >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}

void dump_64bits_double(double n)
{
    unsigned long long bits = *(unsigned long long *)&n;
    printf("double [%g]:\t", n);
    for (int i = 63; i >= 0; i--)
    {
        printf("%llu", (bits >> i) & 1);
        if (i == 63 || i == 52) printf(" ");
    }
    printf("\n");
}

int main()
{
	int a = 42;

	double b = a; // Implicit conversion cast
	double c = (double)a;// Explicit conversion cast

	double d = a; // Implicit promotion > ok
	int e = d; // Implicit demotion > Hazardeux !!
	int f = (int)d; //  Explicit demotion > Ok you are in charge

	dump_32bits_integer(a);

	dump_64bits_double(b);
	dump_64bits_double(c);

	dump_64bits_double(d);
	dump_32bits_integer(e);
	dump_32bits_integer(f);

	return 0;
}
