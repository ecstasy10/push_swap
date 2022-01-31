//
// Created by dev on 30/1/22.
//

#include "../include/push_swap.h"

static void		sort_2(t_frame *frame)
{
    if (frame->a->num > frame->a->next->num)
        do_sa(frame);
}

static void		sort_3(t_frame *frame)
{
    t_stack	*stack_a;
    t_stack	*tmp;

    set_biggest_number(frame, frame->a);
    moves_to_end(frame, frame->a, 2);
    if (frame->big_rev_rotate >= 1)
        while (frame->big_rev_rotate-- > 1)
            do_rra(frame);
    stack_a = frame->a;
    tmp = frame->a->next;
    if (stack_a->num > tmp->num)
        do_sa(frame);
}

static void		sort_4(t_frame *frame)
{
    t_stack *stack_a;

    stack_a = frame->a;
    set_biggest_smallest(frame, frame->a);
    while (stack_a->num != frame->smallest)
    {
        do_ra(frame);
        stack_a = stack_a->next;
    }
    do_pb(frame);
    sort_3(frame);
    do_pa(frame);
}

static void		sort_5(t_frame *frame)
{
    t_stack *stack_a_end;
    t_stack	*tmp;
    int		flag;

    flag = 0;
    stack_a_end = frame->a->prev;
    set_middle(frame, frame->a);
    while (flag != 1)
    {
        frame->a == stack_a_end ? flag = 1 : 0;
        if (frame->a->num < frame->median)
            do_pb(frame);
        else
            do_ra(frame);
    }
    sort_3(frame);
    tmp = frame->b->next;
    frame->b->num < tmp->num ? do_sb(frame) : 0;
    do_pa(frame);
    do_pa(frame);
}

void			small_sort(t_frame *frame, int length)
{
    if (length == 2)
        sort_2(frame);
    else if (length == 3)
        sort_3(frame);
    else if (length == 4)
        sort_4(frame);
    else if (length <= 5)
        sort_5(frame);
    return ;
}

