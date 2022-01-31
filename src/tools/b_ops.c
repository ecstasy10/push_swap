//
// Created by dev on 30/1/22.
//

#include "../../include/push_swap.h"

void	do_rrb(t_frame *frame)
{
    if (frame->b)
        frame->b = frame->b->prev;
    if (frame->do_write)
        write(1, "rrb\n", 4);
}

void	do_rb(t_frame *frame)
{
    if (frame->b)
        frame->b = frame->b->next;
    if (frame->do_write)
        write(1, "rb\n", 3);
}

void	do_pb(t_frame *frame)
{
    long int	number;

    if (frame->a)
    {
        number = frame->a->num;
        shift_stack(&frame->a);
        unshift_stack(frame, &frame->b, number);
    }
    if (frame->do_write)
        write(1, "pb\n", 3);
}


void	do_sb(t_frame *frame)
{
    long int	number;

    if (frame->b && frame->b->next != frame->b)
    {
        number = frame->b->num;
        frame->b->num = frame->b->next->num;
        frame->b->next->num = number;
    }
    if (frame->do_write)
        write(1, "sb\n", 3);
}
