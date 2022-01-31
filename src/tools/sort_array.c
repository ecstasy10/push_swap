//
// Created by dev on 30/1/22.
//

#include "../../include/push_swap.h"

void	sort_array(long *array, int len)
{
    long	tmp;
    int		i;

    tmp = 0;
    i = 0;
    while (i < len - 1)
    {
        if (array[i] <= array[i + 1])
            i++;
        else
        {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            i = 0;
        }
    }
}