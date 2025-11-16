/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:28:14 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/16 19:29:17 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

// handle cspdiuxX%
// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.
/*
function allowed
malloc, free, write,
va_start, va_arg, va_copy, va_end

Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)
Each conversion specification is introduced
       by the character %, and ends with a conversion specifier.  In
       between there may be (in this order) zero or more flags, an
       optional minimum field width, an optional precision and an
       optional length modifier.

       The overall syntax of a conversion specification is:

           %[argument$][flags][width][.precision][length modifier]conversion
*/

int ft_printf(const char *format, ...)
{
    int i;
    int total;
    va_list args;

    va_start(args, format);
    
    va_arg(args, char *);

    va_end(args);
    return  (1);
}
