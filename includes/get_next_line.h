#ifndef	GET_NEXT_LINE_H
#define	GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>

int	get_next_line(int fd, char **line);
int     ft_analyse(char *buffer);
char    *ft_realloc_content(char *line, char *buffer);
char    *ft_cut_line(char *buffer, char **line);
void	ft_free_memory(char **p);

#endif
