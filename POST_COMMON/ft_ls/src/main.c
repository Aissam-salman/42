/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:57:24 by salman            #+#    #+#             */
/*   Updated: 2026/10/12 12:21:29 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"
#include "libft.h"
#include <dirent.h>

int main(int ac, char **av) {
  (void)ac;
  (void)av;
  if (ac == 1) {
    DIR *curr_dir = opendir(".");
    if (!curr_dir) {
      ft_putendl_fd("Error: serious", 2);
      exit(EXIT_CODE_MAJOR);
    }
    struct dirent *dp = NULL;
    while ((dp = readdir(curr_dir)) != NULL) {
			ft_printf("%s\n", dp->d_name);
			//TODO: 
			// liste d_name 
			// append to array 
			// sort by octets, ascii order 
			// print 🖨️
    }
    closedir(curr_dir);
  }
  return SUCCESS;
}
