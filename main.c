/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <get_next_line.h>

int main(int ac, char **av)
{
    int fd = 0;
    char *s;

    if (ac == 2)
        fd = open(av[1], O_RDONLY);
    else {
        printf("./getnextline [fileToRead]\n");
        return 84;
    }
    s = get_next_line(fd);
    while (s) {
        printf("%s\n", s);
        free(s);
        s = get_next_line(fd);
    }
    free(s);
    close(fd);
    return 0;
}
