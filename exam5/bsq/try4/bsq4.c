/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:46:09 by salman            #+#    #+#             */
/*   Updated: 2026/07/16 13:48:28 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq4.h"

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


int main(int ac, char **av) {
  if (ac == 1)
    return solve(stdin);

  for (int i = 1; i < ac; i++) {
    FILE *file = fopen(av[i], "r");
    if (!file) {
      err();
      continue;
    }
    solve(file);
    fclose(file);
    if (i + 1 < ac)
      fprintf(stdout, "\n");
  }
  return SUCCESS;
}
