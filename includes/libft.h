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

#endif
