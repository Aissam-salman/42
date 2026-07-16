#ifndef BSQ_H
# define BSQ_H

#define SUCCESS 0
#define ERROR 1

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_bsq {
    char **map;
    unsigned short **map_short;
    unsigned int width;
    unsigned int height;
    unsigned int save_i;
    unsigned int save_j;
    unsigned int big_square_size;
    char empty;
    char obstacle;
    char fill;
} t_bsq;

typedef unsigned short us;

// core
us solve(FILE *file);
us parsing_legend(FILE *file, t_bsq *data);
us build_map(FILE *file, t_bsq *data);
us map_to_short_array(t_bsq *data);
void reverse_mine(t_bsq *data);
void change_map_with_big_square(t_bsq *data);
void find_min(unsigned short **tab, int i, int j);



// utils
void *ft_memset(void *ptr, int value, size_t size);
us err(void);
us is_charset(const char c, const t_bsq data);
us have_only_charset(const t_bsq data);
size_t ft_strlen(const char *s);
char *ft_strndup(const char *src, size_t n);
void free_array(void **arr, size_t size);
void print_map(const t_bsq data);
us have_duplicate(const t_bsq *data);


#endif
