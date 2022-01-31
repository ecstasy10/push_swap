//
// Created by dev on 30/1/22.
//

#include "../include/push_swap.h"

void	    set_middle(t_frame *frame, t_stack *stack)
{
    long	*array;
    int		i;
    int		quarter_len;

    i = 0;
    frame->stack_len = get_stack_length(stack);
    quarter_len = frame->stack_len / 4;
    if (!(array = (long*)malloc(sizeof(long) * (frame->stack_len + 1))))
        error(frame);
    while (i < frame->stack_len)
    {
        array[i] = stack->num;
        stack = stack->next;
        i++;
    }
    sort_array(array, frame->stack_len);
    frame->quarter = array[quarter_len];
    frame->median = array[quarter_len * 2];
    frame->three_quarters = array[quarter_len * 3];
    free(array);
}

void	set_smallest_number(t_frame *frame, t_stack *stack)
{
    t_stack		*tmp;
    t_stack		*end;

    tmp = stack;
    end = stack->prev;
    frame->smallest = frame->biggest;
    while (1)
    {
        if (tmp->num <= frame->smallest)
            frame->smallest = tmp->num;
        if (tmp == end)
            break ;
        tmp = tmp->next;
    }
}

void	set_biggest_number(t_frame *frame, t_stack *stack)
{
    t_stack		*tmp;
    t_stack		*end;

    tmp = stack;
    frame->biggest = tmp->num;
    end = stack->prev;
    while (1)
    {
        if (tmp->num > frame->biggest)
            frame->biggest = tmp->num;
        if (tmp == end)
            break ;
        tmp = tmp->next;
    }
}

void	set_biggest_smallest(t_frame *frame, t_stack *stack)
{
    set_biggest_number(frame, stack);
    set_smallest_number(frame, stack);
}

