//
// Created by dev on 31/1/22.
//

#include "../include/push_swap.h"

static void	push_first_quarter(t_frame *frame)
{
    if (frame->b && frame->b->num > frame->quarter / 2)
        do_rb(frame);
    do_pb(frame);
}

static void	push_second_quarter(t_frame *frame)
{
    if (frame->b && frame->b->num > (frame->median / 4) * 3)
        do_rb(frame);
    do_pb(frame);
}

static void	push_third_quarter(t_frame *frame)
{
    if (frame->b && frame->b->num > (frame->median / 4) * 5)
        do_rb(frame);
    do_pb(frame);
}

static void	push_fourth_quarter(t_frame *frame)
{
    if (frame->b && frame->b->num > (frame->median / 4) * 7)
        do_rb(frame);
    do_pb(frame);
}

void		push_quarters(t_frame *frame, t_stack *stack_a, int split)
{
    t_stack	*stack_a_end;
    int		flag;

    stack_a_end = frame->a->prev;
    flag = 0;
    set_biggest_smallest(frame, frame->a);
    while (flag != 1)
    {
        stack_a == stack_a_end ? flag = 1 : 0;
        if (split == 1 && stack_a->num <= frame->quarter)
            push_first_quarter(frame);
        else if (split == 2 && stack_a->num > frame->quarter
                && stack_a->num <= frame->median)
            push_second_quarter(frame);
        else if (split == 3 && stack_a->num > frame->median
                && stack_a->num <= frame->three_quarters)
            push_third_quarter(frame);
        else if (split == 4 && stack_a->num > frame->three_quarters)
            push_fourth_quarter(frame);
        else if (split == 4 && stack_a->num == frame->smallest)
            break ;
        else
            do_ra(frame);
        stack_a = frame->a;
    }
    initialize_moves(frame);
}

