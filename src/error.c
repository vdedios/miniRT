#include "miniRT.h"

/*
** If any error is encountered the function will exit with EXIT_FAILURE macro.
*/

void	        ft_error_handler(int error_id)
{
	errno = error_id;
	if (error_id == 1)
		perror("<<ERROR>> add the correct number of args");
	else if (error_id == 2)
		perror("<<ERROR>> write a valid arg");
	else if (error_id == 4)
		perror("<<ERROR>> wrong scene, please check format or path");
	exit(EXIT_FAILURE);
}
