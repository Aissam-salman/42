/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:56:44 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 17:24:07 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isalpha(int c);

/**
 * @brief Checks for a digit (0 through 9).
 * @param c The character to check.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character.
 * @param c The character to check.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks whether a character is a 7-bit unsigned char value that fits into the ASCII character set.
 * @param c The character to check.
 * @return 1 if the character is an ASCII character, 0 otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Checks for any printable character including space.
 * @param c The character to check.
 * @return 1 if the character is printable, 0 otherwise.
 */
int		ft_isprint(int c);

/**
 * @brief Calculates the length of a string.
 * @param s The string to measure.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the constant byte c.
 * @param s A pointer to the memory area to be filled.
 * @param c The character to fill the memory area with.
 * @param n The number of bytes to be filled.
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.
 * @param s A pointer to the memory area to be zeroed.
 * @param n The number of bytes to be zeroed.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to be copied.
 * @return A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory areas may overlap.
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to be copied.
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string they tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string they tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Converts a lowercase letter to the corresponding uppercase letter.
 * @param c The character to convert.
 * @return The converted letter, or c if the conversion was not possible.
 */
int		ft_toupper(int c);

/**
 * @brief Converts an uppercase letter to the corresponding lowercase letter.
 * @param c The character to convert.
 * @return The converted letter, or c if the conversion was not possible.
 */
int		ft_tolower(int c);

/**
 * @brief Locates the first occurrence of c (converted to a char) in the string pointed to by s.
 * @param s The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the located character, or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of c (converted to a char) in the string pointed to by s.
 * @param s The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the located character, or NULL if the character does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the first n bytes of s1 and s2.
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @param n The maximum number of characters to be compared.
 * @return An integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the first instance of c.
 * @param s The memory area to be scanned.
 * @param c The character to be located.
 * @param n The number of bytes to be scanned.
 * @return A pointer to the matching byte or NULL if the character does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 * @param s1 The first memory area.
 * @param s2 The second memory area.
 * @param n The number of bytes to be compared.
 * @return An integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string s2 in the string s1, where not more than n characters are searched.
 * @param s1 The string to be searched.
 * @param s2 The string to be located.
 * @param n The maximum number of characters to be searched.
 * @return If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1, NULL is returned; otherwise a pointer to the first character of the first occurrence of s2 is returned.
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

/**
 * @brief Converts the initial portion of the string pointed to by nptr to int.
 * @param nptr The string to be converted.
 * @return The converted value.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero.
 * @param nmemb The number of elements to be allocated.
 * @param size The size of each element.
 * @return A pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Returns a pointer to a new string which is a duplicate of the string s.
 * @param s The string to be duplicated.
 * @return A pointer to the duplicated string, or NULL if insufficient memory was available.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Allocates and returns a substring from the string 's'. The substring begins at index 'start' and is of maximum size 'len'.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates and returns a new string, which is the result of the concatenation of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. The array must be ended by a NULL pointer.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Allocates and returns a string representing the integer received as an argument.
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/**
 * @brief convert string nbr from base to other base
 * @param nbr The string to be convert
 * @param base_from	The base origin of nbr writed with
 * @param base_to The target base
 * @return The string representing the nbr with base_to. NULL if error.
 */ 
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

/**
 * @brief Applies the function 'f' to each character of the string 's' to create a new string resulting from successive applications of 'f'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of 'f'. NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function 'f' to each character of the string 's'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor, followed by a newline.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief A structure to represent a node in a linked list.
 * @param content The data contained in the node.
 * @param next A pointer to the next node in the list.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Allocates and returns a new node.
 * @param content The content to create the new node with.
 * @return The new node.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the node 'new_node' at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new_node The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new_node);

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node 'new_node' at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new_node The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new_node);

/**
 * @brief Takes as a parameter a node and frees the memory of the node’s content using the function 'del' given as a parameter and free the node.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every successor of that node, using the function 'del' and free.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content of each node.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function to apply.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content of each node. Creates a new list resulting of the successive applications of the function 'f'. The 'del' function is used to delete the content of a node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function to apply.
 * @param del The address of the function used to delete the content of the node.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
