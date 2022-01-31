//
// Created by dev on 26/1/22.
//

#include "../include/push_swap.h"

static void		fill_stack(t_frame *frame, char *number_list, int i, int j)
{
    long int    number;

    while (number_list)
    {
        while (*number_list)
        {
            while (!(j = 0) && *number_list && *number_list == ' ')
                number_list++;
            while (*(number_list + j)
                && (*(number_list + j) == '-' || *(number_list + j) == '+' ||
                    ft_isdigit(*(number_list + j))))
                j++;
            if (!*number_list)
                break ;
            number = parse_number(frame, number_list);
            if (number > INT_MAX || number < INT_MIN)
                error(frame);
            push_to_stack(frame, &frame->a, number);
            number_list += j;
        }
        number_list = frame->argv[++i];
    }
    if (!frame->a)
        error(frame);
}

void        fill_stack_a(t_frame *frame)
{
    char	*number_list;
    int     i;
    int     j;

    i = 1;
    j = 0;
    if (ft_strcmp(frame->argv[i], "-v") == 0)
    {
        frame->argv++;
        frame->print_stacks = 1;
    }
    number_list = frame->argv[i];
    error_check(frame);
    fill_stack(frame, number_list, i, j);
    check_duplicates(frame);
}

void	initialize_moves(t_frame *frame)
{
    frame->biggest = 0;
    frame->big_rotate = 0;
    frame->big_rev_rotate = 0;
    frame->big_flag = 0;
    frame->smallest = 0;
    frame->small_rotate = 0;
    frame->small_rev_rotate = 0;
    frame->small_flag = 0;
}


t_frame		*initialize_frame(t_frame *frame, char **argv)
{
    if (!(frame = (t_frame *)malloc(sizeof(t_frame))))
        exit(1);
    frame->a = NULL;
    frame->b = NULL;
    frame->argv = argv;
    frame->line = NULL;
    frame->str = NULL;
    frame->print_stacks = 0;
    frame->do_write = 0;
    frame->stack_len = 0;
    frame->after_rotate = 0;
    frame->quarter = 0;
    frame->median = 0;
    frame->three_quarters = 0;
    frame->biggest = 0;
    frame->big_rotate = 0;
    frame->big_rev_rotate = 0;
    frame->big_flag = 0;
    frame->smallest = 0;
    frame->small_rotate = 0;
    frame->small_rev_rotate = 0;
    frame->small_flag = 0;
    frame->after_rotate = 0;
    return (frame);
}

