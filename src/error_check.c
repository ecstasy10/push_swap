//
// Created by dev on 29/1/22.
//

#include "../include/push_swap.h"

void			error(t_frame *frame)
{
    write(2, "Error\n", 6);
    free_frame(frame);
    exit(-1);
}

void		error_check(t_frame *frame)
{
    char	*str;
    int		i;

    i = 1;
    str = frame->argv[i];
    while (str)
    {
        while (*str)
        {
            if (*str == ' ' || ft_isdigit(*str))
                str++;
            else if (*str == '-' && ft_isdigit(*(str + 1)) &&
                     (str == frame->argv[i] || *(str - 1) == ' '))
                str++;
            else if (*str == '+' && ft_isdigit(*(str + 1)) &&
                     (str == frame->argv[i] || *(str - 1) == ' '))
                str++;
            else
                error(frame);
        }
        str = frame->argv[++i];
    }
}

