/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:50:12 by rchaves-          #+#    #+#             */
/*   Updated: 2023/05/23 11:35:13 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef unsigned int	t_size;

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);

int		ft_isalpha(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

t_size	ft_strlen(const char *s);

void	*ft_memset(void *b, int c, int len);

void	ft_bzero(void *s, int n);

void	*ft_memcpy(void *dst, const void *src, int n);

void	*ft_memmove(void *dst, const void *src, int n);

t_size	ft_strlcpy(char *dst, const char *src, t_size dstsize);

t_size	ft_strlcat(char *dst, const char *src, t_size dstsize);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, t_size n);

void	*ft_memchr(const void *s, int c, t_size n);

int		ft_memcmp(const char *s1, const char *s2, t_size n);

char	*ft_strnstr(const char *haystack, const char *needle, t_size len);

long	ft_atoi(const char *str);

void	*ft_calloc(t_size count, t_size size);

char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, t_size len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef unsigned long	t_ulong;

typedef unsigned int	t_uint;

void	ft_putchr(char c, int *cnt);

void	ft_putstr(char *str, int *cnt);

void	ft_recursion(long nbr, int base_n, char *base, int *cnt);

void	ft_putnbr(t_ulong nbr, int mode, int *cnt);

int		ft_printf(char const *s, ...);

#endif