#ifndef LIBFT_H
# define LIBFT_H

/* Headers */
# include "cub3d.h"

// Libft/libft.c
bool	ft_isspace(int c);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *ptr, size_t n);

#endif
