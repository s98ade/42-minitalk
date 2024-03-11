/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:13:54 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 13:40:05 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// libc functions
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *str);
void *ft_memset(void *str, int c, size_t len);
void ft_bzero(void *str, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t len);
void *ft_memmove(void *dst, const void *src, size_t len);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t size);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strchr(const char *str, int c);
char *ft_strrchr(const char *str, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
long int ft_atoi(const char *str);
void *ft_calloc(size_t count, size_t size);
char *ft_strdup(const char *s1);
// additional functions
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char *));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

//ft_printf
int	ft_printf(const char *format, ...);
int	check_format(va_list args, const char format);
int	ft_print_chr(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long ptr);
int	ft_print_digit(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex_upper(unsigned int n);
int	ft_print_hex_lower(unsigned long n);
int	ft_print_percent(void);

//get_next_line
char	*get_next_line(int fd);
char    *gnl_strjoin(char *b_s, char const *a_s);
char	*ft_read_upd8(char *result, char *buffer, int fd);
char	*ft_combine_line(char *result, char *buffer, int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strdup(const char *s1);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strchr(const char *str, int c);

#endif
