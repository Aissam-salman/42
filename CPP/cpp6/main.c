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

#include <stdio.h>

int main()
{
	int a = 42;

	int const *b =&a;  // Implicit type qualifier cast
	int const *c = (int const *)&a; // Explicit type qualifier cast
	
	int const *d = &a; //Implicit promotion > ok
	int *e = d; // Implicit demotion > noooo
	int *f = (int *)d; // Explicit demotion > ok, you're in charge
	return 0;
}
