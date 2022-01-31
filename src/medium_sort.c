//
// Created by dev on 30/1/22.
//

#include "../include/push_swap.h"

static void	rotate_and_push_to_a(t_frame *frame)
{
    if (frame->small_rotate >= 0)
        while (frame->small_rotate--)
            do_rb(frame);
    else if (frame->small_rev_rotate >= 0)
        while (frame->small_rev_rotate--)
            do_rrb(frame);
    else if (frame->big_rotate >= 0)
        while (frame->big_rotate--)
            do_rb(frame);
    else if (frame->big_rev_rotate >= 0)
        while (frame->big_rev_rotate--)
            do_rrb(frame);
    do_pa(frame);
    frame->small_flag ? do_ra(frame) : 0;
    (frame->big_flag || !frame->b) ? frame->after_rotate++ : 0;
    initialize_moves(frame);
}

void	push_big_small(t_frame *frame, t_stack *stack, t_stack *stack_end)
{
    while (1)
    {
        while (stack->num != frame->smallest && stack->num != frame->biggest)
            stack = stack->next;
        if (stack->num == frame->smallest || stack->num == frame->biggest)
        {
            rotate_and_push_to_a(frame);
            break ;
        }
        else
            stack = stack->next;
        if (stack == stack_end)
            break ;
        stack = frame->b;
    }
}

void	push_half(t_frame *frame, int split)
{
    t_stack	*stack;
    t_stack	*stack_a_end;
    int		flag;

    stack = frame->a;
    stack_a_end = frame->a->prev;
    flag = 0;
    set_smallest_number(frame, frame->a);
    while (1)
    {
        if (stack == stack_a_end)
            flag = 1;
        if (split == 1 && stack->num <= frame->median)
            do_pb(frame);
        else if (split == 2 && stack->num > frame->median)
            do_pb(frame);
        else if (stack->num == frame->smallest)
            break ;
        else
            do_ra(frame);
        if (flag == 1)
            break ;
        stack = frame->a;
    }
    initialize_moves(frame);
}

void		medium_sort(t_frame *frame)
{
    int	split;

    split = 1;
    set_middle(frame, frame->a);
    while (frame->a)
    {
        push_half(frame, split);
        while (frame->b)
        {
            set_biggest_smallest(frame, frame->b);
            calculate_moves(frame, frame->b);
            if (frame->b && (frame->small_rotate >= 0
                || frame->small_rev_rotate >= 0
                || frame->big_rotate >= 0
                || frame->big_rev_rotate >= 0))
                    push_big_small(frame, frame->b, frame->b->prev);
        }
        while (--frame->after_rotate)
            do_ra(frame);
        split++;
        if (split == 3)
            break ;
    }
}
