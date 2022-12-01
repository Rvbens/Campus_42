/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:50:12 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/01 09:42:59 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef unsigned int	t_size;

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

int		ft_atoi(const char *str);

void	*ft_calloc(t_size count, t_size size);

char	*ft_strdup(const char *s1);

#endif