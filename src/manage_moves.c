//
// Created by dev on 30/1/22.
//

#include "../include/push_swap.h"

void		moves_to_start(t_frame *frame, t_stack	*stack, int flag)
{
    t_stack	*tmp;
    int		element;

    if (stack)
    {
        tmp = stack;
        element = (flag == 1) ? frame->smallest : frame->biggest;
        while (tmp->num != element)
        {
            flag == 1 ? frame->small_rotate++ : frame->big_rotate++;
            tmp = tmp->next;
        }
    }
}

void		moves_to_end(t_frame *frame, t_stack *stack, int flag)
{
    t_stack	*tmp;
    int		element;

    if (stack)
    {
        tmp = stack->prev;
        element = (flag == 1) ? frame->smallest : frame->biggest;
        while (tmp->num != element)
        {
            flag == 1 ? frame->small_rev_rotate++ : frame->big_rev_rotate++;
            tmp = tmp->prev;
        }
        flag == 1 ? frame->small_rev_rotate++ : frame->big_rev_rotate++;
    }
}

static void	calc_moves_smallest(t_frame *frame, t_stack	*stack)
{
    int		flag;

    flag = 1;
    if (stack)
    {
        moves_to_start(frame, stack, flag);
        moves_to_end(frame, stack, flag);
        if (frame->small_rotate <= frame->small_rev_rotate)
            frame->small_rev_rotate = -1;
        else
            frame->small_rotate = -1;
    }
}

static void	calc_moves_biggest(t_frame *frame, t_stack	*stack)
{
    int		flag;

    flag = 2;
    if (stack)
    {
        moves_to_start(frame, stack, flag);
        moves_to_end(frame, stack, flag);
        if (frame->big_rotate <= frame->big_rev_rotate)
            frame->big_rev_rotate = -1;
        else
            frame->big_rotate = -1;
    }
}


void		calculate_moves(t_frame *frame, t_stack	*stack)
{
    calc_moves_smallest(frame, frame->b);
    calc_moves_biggest(frame, frame->b);
    if (frame->big_rotate != -1 && (frame->big_rotate >= frame->small_rotate &&
            frame->big_rotate >= frame->small_rev_rotate))
        frame->big_rotate = -1;
    else if (frame->big_rev_rotate != -1
        && (frame->big_rev_rotate >= frame->small_rotate &&
            frame->big_rev_rotate >= frame->small_rev_rotate))
        frame->big_rev_rotate = -1;
    else if (frame->small_rotate != -1
        && (frame->big_rotate >= frame->small_rotate &&
                frame->big_rev_rotate >= frame->small_rev_rotate))
        frame->big_rotate = -1;
    else if (frame->small_rev_rotate != -1
        && (frame->small_rev_rotate >= frame->big_rotate &&
            frame->small_rev_rotate >= frame->big_rev_rotate))
        frame->small_rev_rotate = -1;
    if (frame->small_rotate != -1 || frame->small_rev_rotate != -1)
        frame->small_flag = 1;
    else if (frame->big_rotate != -1 || frame->big_rev_rotate != -1)
        frame->big_flag = 1;
}

