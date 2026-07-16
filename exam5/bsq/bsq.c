#include "bsq.h"

us err(void){
	fprintf(stderr, "map error\n");
	return ERROR;
}

void *ft_memset(void *ptr, int val, size_t size) {
	unsigned char *dst = ptr;
	while (size-- > 0)
		*dst++ = (unsigned char)val;
	return ptr;
}

void free_array(void **arr, size_t size) {
	for (size_t i = 0; i < size; i++) { 
		if (arr[i])
			free(arr[i]);
	}
	free(arr);
}

us have_duplicate(const t_bsq *data) {
	if (data->fill == data->empty)
		return ERROR;
	if (data->fill == data->obstacle)
		return ERROR;
	if (data->obstacle == data->empty)
		return ERROR;
	return SUCCESS;
}

us have_only_charset(const t_bsq data) {
	for (size_t i = 0; data.map[i] && i < data.height; i++) {
		for (size_t j = 0; data.map[i][j]; j++){
			if (is_charset(data.map[i][j], data))
					return ERROR;
		}
	} 
	return SUCCESS;
}

us is_charset(const char c, const t_bsq data) {
	if (c == data.fill || c == data.obstacle || c == data.empty)
		return SUCCESS;
	return ERROR;
}
size_t ft_strlen(const char *s) {
	size_t len = 0;
	while (s[len])
		len++;
	return len;
}

char *ft_strndup(const char *src, size_t n) {

	if (!src || n <= 0)
		return NULL;

	char *dst = malloc(n + 1);
	if (!dst)
		return NULL;
	size_t i = 0;

	while (src[i] && i < n) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}

void print_map(const t_bsq data) {
	for (size_t i = 0; data.map[i] && i < data.height; i++) {
			fprintf(stdout, "%s\n", data.map[i]);
	} 
}

us map_to_short_array(t_bsq *data) {
	data->map_short= malloc(sizeof(unsigned short *) * data->height);
	if (!data->map_short)
		return ERROR;
	ft_memset(data->map_short, 0, sizeof(unsigned short *) * data->height);

	for (size_t i = 0; data->map[i]; i++) {
		data->map_short[i] = malloc(sizeof(unsigned short) * (data->width + 1));
		if (!data->map_short[i]) {
			free_array((void **)data->map_short, data->height);
			return ERROR;
		}
		for (size_t j = 0; data->map[i] && data->map[i][j]; j++) {
			data->map_short[i][j] = (data->map[i][j] == data->empty) ? 1 : 0;
		}
	}
	return SUCCESS;
}

void find_min(unsigned short **tab, int i, int j) {
	if (tab[i][j] == 0)
		return ;
	int sav = tab[i][j - 1];

	if (tab[i - 1][j] < sav)
		sav = tab[i-1][j];
	if (tab[i - 1][j - 1] < sav)
		sav = tab[i - 1][j - 1];

	tab[i][j] = sav + 1;
}

void reverse_mine(t_bsq *data) {
	data->big_square_size = 0;
	data->save_i = 0;
	data->save_j = 0;

	for (size_t i = 0; i < data->height; i++) {
		for (size_t j = 0; j < data->width; j++) {

			if (i > 0 && j > 0)
				find_min(data->map_short, i, j);

			if (data->map_short[i][j] > data->big_square_size) {
				data->big_square_size = data->map_short[i][j];
				data->save_i = i;
				data->save_j = j;
			}
		}
	}
}


void change_map_with_big_square(t_bsq *data) {
	size_t si = data->save_i - data->big_square_size + 1;
	size_t sj = data->save_j - data->big_square_size + 1;

	for (size_t i = si; i <= data->save_i; i++) {
		for (size_t j = sj; j <= data->save_j; j++) {
			data->map[i][j] = data->fill;
		} 
	} 

}

us parsing_legend(FILE *file, t_bsq *data) {
	if (fscanf(file, "%u %c %c %c%*c", &data->height, &data->empty, &data->obstacle, &data->fill) != 4) 
		return ERROR;
	if (data->height == 0 || data->height > INT_MAX)
		return ERROR;
	if (have_duplicate(data))
		return ERROR;
	return SUCCESS;
}

us build_map(FILE *file, t_bsq *data) {
	size_t count = 0;
	char *line = NULL;
	size_t cap = 0;
	data->map = malloc(sizeof(char *) * ((size_t)data->height + 1));
	if (!data->map)
		return ERROR;

	ssize_t ref_len = getline(&line, &cap, file);
	data->width = ref_len - 1;
	ssize_t len = ref_len;
	while (len != -1) {
		if (len != ref_len) {
			free(line);
			free_array((void **)data->map, count);
			return ERROR;
		}
		else if (count >= data->height) {
			free(line);
			free_array((void **)data->map, count);
			return ERROR;
		}
		data->map[count] = ft_strndup(line, data->width);
		if (!data->map[count]) {
			free(line);
			free_array((void **)data->map, count);
			return ERROR;
		}
		count++;
		len = getline(&line, &cap, file);
	}
	data->map[count] = NULL;
	free(line);
	if (count != data->height) {
		free_array((void **)data->map, count);
		return ERROR;
	}
	if (have_only_charset(*data)){
		free_array((void **)data->map, data->height);
		return ERROR;
	}
	return SUCCESS;
}

us solve(FILE *file) {
	t_bsq data;
	ft_memset(&data, 0, sizeof(t_bsq));
	if (parsing_legend(file, &data) || build_map(file, &data))
		return err();
	if (map_to_short_array(&data)){
		free_array((void **)data.map, data.height);
		return err();
	}
	reverse_mine(&data);
	if (data.big_square_size > 0)
		change_map_with_big_square(&data);
	print_map(data);

	free_array((void **)data.map, data.height);
	free_array((void **)data.map_short, data.height);
	return SUCCESS;
}

int main(int ac, char **av) {
    // read from stdin
    if (ac == 1) {
        return solve(stdin);
    }

    // read multi files
    for (int i = 1; i < ac; i++) {
        FILE *file = fopen(av[i], "r");
        if (!file){
            err();
            continue;
        }
        solve(file);
        fclose(file);
        if (i + 1 < ac) {
            fprintf(stdout, "\n");
        }
    }
    return SUCCESS;
}
