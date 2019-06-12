/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 08:35:54 by fhong             #+#    #+#             */
/*   Updated: 2019/05/28 23:15:31 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** is
*/

int					ft_isspace(char c);
int					ft_isalpha(int c);
int					ft_isoperator(char c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isprime(unsigned long int n);

/*
** mem
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_swap(int *a, int *b);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *restrict dest, const void *restrict src,
					size_t n);
void				*ft_memccpy(void *restrict dest, const void *restrict src,
					int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);
void				*ft_memalloc(size_t size);

/*
** nbr
*/

int					ft_atoi(const char *str);
intmax_t			ft_atoi_intmax(const char *str);
size_t				ft_intlen_base(intmax_t value, int base);
size_t				ft_uintlen_base(uintmax_t value, int base);
char				*ft_itoa(int n);
char				*ft_itoa_base(intmax_t value, char *base);
char				*ft_itoa_base_uint(uintmax_t nb, char *base);
int					*ft_intnew(size_t size);
size_t				*ft_size_t_new(size_t size);

/*
** str
*/

size_t				ft_strlen(const char *str);
size_t				ft_strnlen(const char *str, size_t size);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_strrev(char *str);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strdup(char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
					size_t dstsize);

/*
** put
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *str, size_t size);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbr_base(intmax_t value, char *base);
void				ft_put_base_unsigned(uintmax_t n, int base);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_put_char_times(char c, int times);
void				ft_putlst(t_list *lst);

/*
** lst
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_last(t_list *alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst,
					void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst,
					void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content,
					size_t content_size);
t_list				*ft_lstmap(t_list *lst,
					t_list *(*f)(t_list *elem));

/*
** wchar
*/

size_t				ft_wstrlen(wchar_t *wstr);

/*
** intmax_t uintmax_t
*/

void				ft_putnbr_uintmax_t(uintmax_t nb);
void				ft_putnbr_uintmax_t_base(uintmax_t value, char *base);

/*
** other
*/

void				ft_exit(char *str);
void				ft_tablefree(char **table);

#endif
