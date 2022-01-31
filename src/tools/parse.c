//
// Created by dev on 29/1/22.
//

#include "../../include/push_swap.h"

long		parse_number(t_frame *frame, char *str)
{
    long	num;
    int		i;
    int		len;
    int		sign;

    num = 0;
    i = 0;
    len = 0;
    sign = 1;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
           || str[i] == '\f')
        i++;
    str[i] == '-' ? (sign = -1) : 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] == '0')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
        len++;
    }
    len > 10 ? error(frame) : 0;
    return (num * sign);
}
