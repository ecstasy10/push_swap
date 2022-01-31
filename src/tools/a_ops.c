//
// Created by dev on 30/1/22.
//

#include "../../include/push_swap.h"

void	do_rra(t_frame *frame)
{
    if (frame->a)
        frame->a = frame->a->prev;
    if (frame->do_write)
        write(1, "rra\n", 4);
}

void	do_ra(t_frame *frame)
{
    if (frame->a)
        frame->a = frame->a->next;
    if (frame->do_write)
        write(1, "ra\n", 3);
}

void	do_pa(t_frame *frame)
{
    long int	number;

    if (frame->b)
    {
        number = frame->b->num;
        shift_stack(&frame->b);
        unshift_stack(frame, &frame->a, number);
    }
    if (frame->do_write)
        write(1, "pa\n", 3);
}

void	do_sa(t_frame *frame)
{
    long int	number;

    if (frame->a && frame->a->next != frame->a)
    {
        number = frame->a->num;
        frame->a->num = frame->a->next->num;
        frame->a->next->num = number;
    }
    if (frame->do_write)
        write(1, "sa\n", 3);
}
