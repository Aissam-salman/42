/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:46:09 by salman            #+#    #+#             */
/*   Updated: 2026/07/16 20:11:24 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq4.h"

us solve(FILE *file) {
    t_bsq data;
    ft_memset(&data, 0, sizeof(t_bsq));

    if (parsing_legend(file, &data) || build_map(file, &data)) {
        return err();
    }

    if (map_to_short_arr(&data)) {
        free_arr((void **)data.map, data.height);
        return err();
    }

    reverse_miner(&data);

    if (data.big_size > 0)
        apply_big(&data);
    print_map(&data);

    free_arr((void **)data.map, data.height);
    free_arr((void **)data.map_short, data.height);
    return SUCCESS;
}

us parsing_legend(FILE *file, t_bsq *data) {
    if (fscanf(file, "%u %c %c %c%*c", &data->height, &data->empty,
               &data->obstacle, &data->fill) != 4)
        return ERROR;
    if (data->height == 0 || data->height > INT_MAX)
        return ERROR;
    if (have_duplicate_legend(data))
        return ERROR;
    return SUCCESS;
}

us build_map(FILE *file, t_bsq *data) {
    size_t count = 0;
    char *line = NULL;
    size_t capacity = 0;

    data->map = malloc(sizeof(char *) * ((size_t)data->height + 1));
    if (!data->map)
        return ERROR;
    ft_memset(data->map, 0, sizeof(char *) * ((size_t)data->height + 1));

    ssize_t len = getline(&line, &capacity, file);

    if (len != -1)
        len = strip_newline(line, len);

    ssize_t ref_len = len;
    if (ref_len <= 0) {
        free(line);
        free_arr((void **)data->map, 0);
        return ERROR;
    }
    data->width = ref_len;
    while (len != -1) {
        if (len != ref_len || count >= data->height) {
            free(line);
            free_arr((void **)data->map, count);
            return ERROR;
        }
        data->map[count] = ft_strdup(line);
        if (!data->map[count]) {
            free(line);
            free_arr((void **)data->map, count);
            return ERROR;
        }
        count++;
        len = getline(&line, &capacity, file);

        if (len != -1)
            len = strip_newline(line, len);
    }
    data->map[count] = NULL;
    free(line);

    if (count != data->height) {
        free_arr((void **)data->map, count);
        return ERROR;
    }

    if (have_only_charset(data)) {
        free_arr((void **)data->map, data->height);
        return ERROR;
    }

    return SUCCESS;
}

us map_to_short_arr(t_bsq *data) {
  data->map_short = malloc(sizeof(us *) * data->height);
  if (data->map_short)
    return ERROR;
  ft_memset(data->map_short, 0, sizeof(us *) * data->height);
  
  for (size_t i = 0;)
}

void reverse_miner(t_bsq *data);

void find_min(us **tab, int i, int j);

void apply_big(t_bsq *data);

us have_only_charset(const t_bsq *data);

us is_charset(const char c, t_bsq *data);

us have_duplicate_legend(const t_bsq *data) {
    if (data->fill == data->empty || data->fill == data->obstacle ||
        data->empty == data->obstacle) {
        return ERROR;
    }
    return SUCCESS;
}

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
