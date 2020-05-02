/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** get_next_line.c
*/

#include <get_next_line.h>

static char *my_realloc(const char *str, int i)
{
    int a = 0;
    char *tmp = malloc(sizeof(char) * (i + 3));

    for (int j = i + 1; j > 0; j--) {
        tmp[a] = str[a];
        a++;
    }
    tmp[a] = 0;
    return (tmp);
}

char get_one_char(int fd)
{
    static char buff[READ_SIZE];
    static int j = 0;
    static int i = 0;

    if (i == 0) {
        i = read(fd, buff, READ_SIZE);
        j = 0;
    }
    if (i <= 0)
        return (0);
    i--;
    return (buff[j++]);
}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * (READ_SIZE + 1));
    char tmp = get_one_char(fd);
    int count = 0;
    int mult = 1;
    int i = 0;

    if (!tmp)
        return (NULL);
    for (; tmp != 0 && tmp != '\n'; i++) {
        str[i] = tmp;
        count++;
        if (count >= READ_SIZE) {
            mult++;
            str = my_realloc(str, (mult * READ_SIZE));
            count = 0;
        }
        if ((tmp = get_one_char(fd)) == 0)
            return (NULL);
    }
    str[i] = 0;
    return (str);
}
