/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:36:40 by salman            #+#    #+#             */
/*   Updated: 2026/07/16 20:11:25 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ4_H
#define BSQ4_H

#define SUCCESS 0
#define ERROR 1

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned int ui;
typedef unsigned short us;

typedef struct s_bsq {
  char **map;
  us **map_short;

  ui big_size;
  ui height;
  ui width;
  ui save_i;
  ui save_j;

  char empty;
  char fill;
  char obstacle;
} t_bsq;


us solve(FILE *file);
us parsing_legend(FILE *file, t_bsq *data);
us build_map(FILE *file, t_bsq *data);

us map_to_short_arr(t_bsq *data);

void reverse_miner(t_bsq *data);
void find_min(us **tab, int i, int j);

void apply_big(t_bsq *data);


us have_only_charset(const t_bsq *data);
us is_charset(const char c, t_bsq *data);
us have_duplicate_legend(const t_bsq *data);


// utils
void *ft_memset(void *ptr, int val, size_t size);
size_t ft_strlen(const char *src);
char *ft_strdup(const char *src);
ssize_t strip_newline(char *line, ssize_t len);
void free_arr(void **arr, size_t size);
void print_map(const t_bsq *data);
us err(void);





#endif

