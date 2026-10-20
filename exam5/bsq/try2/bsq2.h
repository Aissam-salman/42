#ifndef BSQ2_H
# define BSQ2_H

# define SUCCESS 0
# define ERROR 1

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned int ui;
typedef unsigned short us;

typedef struct s_bsq {
  char **map;
  us **map_short;

  ui width;
  ui height;
  ui big_size;
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
void apply_big_square(t_bsq *data);
void find_min(us **tab, int i, int j);

void *ft_memset(void *ptr, int val, size_t size);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *src);
ssize_t strip_newline(char *line, ssize_t len);
void free_arr(void **arr, size_t size);

us is_charset(const char c, const t_bsq *data);
us have_only_charset(const t_bsq *data);
us have_duplicate(const t_bsq *data);

void print_map(const t_bsq *data);
us err(void);







#endif 
