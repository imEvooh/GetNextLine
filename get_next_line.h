/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** get_next_line.h
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#ifndef READ_SIZE
#define READ_SIZE 10
#endif /* !READ_SIZE */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */
