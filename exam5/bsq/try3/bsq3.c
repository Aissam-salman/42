/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:50:13 by salman            #+#    #+#             */
/*   Updated: 2026/07/16 13:33:24 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq3.h"

us err(void) {
    fprintf(stderr, "map error\n");
    return ERROR;
}

us parsing_legend(FILE *file, t_bsq *data) {
    if (fscanf(file, "%u %c %c %c%*c", &data->height, &data->empty, &data->obs,
               &data->fill) != 4) {
        return ERROR;
    }
    if (data->height == 0 || data->height > INT_MAX) {
        return ERROR;
    }
    if (have_duplicate_legend(data)) {
        return ERROR;
    }
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
    if (!data->map_short)
        return ERROR;
    ft_memset(data->map_short, 0, sizeof(us *) * data->height);

    for (size_t i = 0; i < data->height; i++) {
        data->map_short[i] = malloc(sizeof(us) * data->width);
        if (!data->map_short[i]) {
            free_arr((void **)data->map_short, data->height);
            return ERROR;
        }
        for (size_t j = 0; j < data->width; j++) {
            data->map_short[i][j] = (data->map[i][j] == data->empty ? 1 : 0);
        }
    }

    return SUCCESS;
}

void reverse_miner(t_bsq *data) {
    data->big_size = 0;
    data->save_i = 0;
    data->save_j = 0;

    for (size_t i = 0; i < data->height; i++) {
        for (size_t j = 0; j < data->width; j++) {
            if (i > 0 && j > 0)
                find_min(data->map_short, i, j);

            if (data->map_short[i][j] > data->big_size) {
                data->big_size = data->map_short[i][j];
                data->save_i = i;
                data->save_j = j;
            }
        }
    }
}
void apply_bigs(t_bsq *data) {
  size_t si = data->save_i - data->big_size + 1;
  size_t sj = data->save_j - data->big_size + 1;

  for (size_t i = si; i <= data->save_i; i++) {
    for (size_t j = sj; j <= data->save_j; j++)
      data->map[i][j] = data->fill;
  }
}

void find_min(us **tab, int i, int j) {
  if (tab[i][j] == 0) return;

  int sav = tab[i][j - 1];

  if (tab[i - 1][j] < sav) {
    sav = tab[i - 1][j];
  }
  if (tab[i - 1][j - 1] < sav)
    sav = tab[i - 1][j - 1];

  tab[i][j] = sav + 1;
}

void print_map(t_bsq *data) {
    for (size_t i = 0; i < data->height; i++) {
        fprintf(stdout, "%s\n", data->map[i]);
    }
}

void *ft_memset(void *ptr, int val, size_t size) {
    unsigned char *tmp = ptr;
    while (size-- > 0)
        *tmp++ = val;
    return ptr;
}

size_t ft_strlen(const char *s) {
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

char *ft_strdup(const char *src) {
    if (!src)
        return NULL;
    char *dst = malloc(ft_strlen(src) + 1);
    if (!dst)
        return NULL;
    size_t i = 0;
    while (src[i]) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

ssize_t strip_newline(char *line, ssize_t len) {
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
        len--;
    }
    return len;
}

us is_charset(const char c, const t_bsq *data) {
    if (c == data->fill || c == data->empty || c == data->obs) {
        return SUCCESS;
    }
    return ERROR;
}

us have_only_charset(const t_bsq *data) {
    for (size_t i = 0; i < data->height; i++) {
        for (size_t j = 0; j < data->width; j++) {
            if (is_charset(data->map[i][j], data)) {
                return ERROR;
            }
        }
    }
    return SUCCESS;
}

us have_duplicate_legend(const t_bsq *data) {
    if (data->fill == data->empty || data->fill == data->obs ||
        data->empty == data->obs) {
        return ERROR;
    }
    return SUCCESS;
}

void free_arr(void **arr, size_t size) {
    while (size-- > 0)
            free(arr[size]);
    free(arr);
}

us solve(FILE *file) {
    t_bsq data;
    ft_memset(&data, 0, sizeof(t_bsq));

    if (parsing_legend(file, &data) || build_map(file, &data))
        return err();

    if (map_to_short_arr(&data)) {
        free_arr((void **)data.map, data.height);
        return err();
    }

    reverse_miner(&data);
    if (data.big_size > 0)
        apply_bigs(&data);

    print_map(&data);

    free_arr((void **)data.map, data.height);
    free_arr((void **)data.map_short, data.height);
    return SUCCESS;
}

int main(int ac, char **av) {
    if (ac == 1) {
        return solve(stdin);
    }

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
