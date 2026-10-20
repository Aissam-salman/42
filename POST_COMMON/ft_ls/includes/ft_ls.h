/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:23:06 by salman            #+#    #+#             */
/*   Updated: 2026/10/12 19:09:12 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#define SUCCESS 0
#define ERROR 1

#define EXIT_CODE_SUCCESS 0
#define EXIT_CODE_MINOR 1
#define EXIT_CODE_MAJOR 2



#endif
/*
* Which files are listed::
* -a , -d, -R
* What information is listed::
* -g, -l
* Sorting the output::
* -r, -f, -t, -u, 
* General output formatting::
* --color=
* Formatting file timestamps::
* Formatting the file names::
*/

// ## mandatory 
// -l  use a long listing format
// -R  list subdirectories recursively
// -a  do not ignore entries starting with .
// -r  reverse order while sorting
// -t  sort by time, newest first
//
// ## bonus
// Manage ACL and extended attributes
// management of the columns without the option -l (man 4 tty)
// -u  with -lt: sort by, and show, access time; 
//	   with -l: show access time and sort by name; 
//	   otherwise: sort by access time, newest first
// -f same as -a -U  : do not ignore entries starting with . (-U) do not sort directory entries
// -g  like -l, but do not list owner
// -d list directories themselves, not their contents
// Management of view in colors ( ls --color=always | cat -v) 
// optimization of your code ? ex. ls -lR

// ls - list directory content   
// ls [OPTION]... [FILE]...   
// sort entries alphabetically   by default if none   -cftuvSUX nor --sort is specified
//
// RETURN 
//  Exit status:
     // 0 success
     // 1 minor problems  (e.g., failure to access a file or directory not
     //   specified as a command line argument.  This happens when listing a
     //   directory in which entries are actively being removed or renamed.)
     // 2 serious trouble (e.g., memory exhausted, invalid option, failure
     //   to access a file or directory specified as a command line argument
     //   or a directory loop)

// STEPS ? 
// with no args 
//		print current in current directory filename and dirname, like ls .
// with args   ./ft_ls [OPTION]... [FILE]...
// parsing
//		i accept   -lllllR    like the bash 
//		i accept   -lR
//		i accept   -lRartufgd
//		i accept   -tr or -rt  the same
//		i accept   ls src -l or ls -l src  same 
//		i accept   ls -a -l , ls -la  same 
//		if don't accept ls -  
//					ls: cannot access '-': No such file or directory
//		i don't accept  ls -- 
//      if not existing file or flags exit 2 
//				flags  ls: invalid option -- 'z'
//					   Try 'ls --help' for more information.
//				file   ls: cannot access 'fos': No such file or directory
// check validity if is file or dir 
//		if file in args
//			print with option if i have
//		else if dir 
//			enter to dir, and print list with option if i have
//
//	one option == one function, same order to prompt 
//
//	PRINT 
//	CLEAR 
//	EXIT 0
//			
//			ordre ls  :  Error , file, dir
//			 man 3 opendir, man 3 readdir, man 3 closedir.
//			 man 2 stat
//NOTE: 
//total: X is the space total of all file or dir curr in disk
