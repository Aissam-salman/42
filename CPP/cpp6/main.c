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
	// conversion identitaire ?? valeur de base garde les memes 
	// bits dans le meme ordre
	// reinterpretation 
	float a = 420.042f; // ref value
	
	void *b = &a; // Implicit reinterpretation cast
	void *c = (void *)&a; // Explicit reinterpretation cast
	
	void *d = &a; // Implicit promotion > Ok
	int *e = d; // Implicit demotion > Hazardeux
	int *f = (int *)d; // Explicit demotion > ok, you are the boss
	
	printf("%p, %f\n", &a, a);

	printf("%p\n", b);
	printf("%p\n", c);
	
	printf("%p\n", d);
	printf("%p, %d\n", e, *e);
	printf("%p, %d\n", f, *f);
	return 0;
}
