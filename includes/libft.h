/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:08:11 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/28 20:55:01 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Headers */
# include "cub3d.h"

// Libft/libft.c
bool	ft_isspace(int c);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	**ft_split(char *s, char delim);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);

#endif
