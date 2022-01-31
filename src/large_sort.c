//
// Created by dev on 31/1/22.
//

#include "../include/push_swap.h"

void		large_sort(t_frame *frame)
{
    int	split;

    split = 1;
    set_middle(frame, frame->a);
    while (frame->a)
    {
        push_quarters(frame, frame->a, split);
        while (frame->b)
        {
            set_biggest_smallest(frame, frame->b);
            calculate_moves(frame, frame->b);
            if (frame->b && (frame->small_rotate >= 0 || frame->small_rev_rotate >= 0
                             || frame->big_rotate >= 0 || frame->big_rev_rotate >= 0))
                push_big_small(frame, frame->b, frame->b->prev);
        }
        while (--frame->after_rotate)
            do_ra(frame);
        split++;
        if (split == 5)
            break ;
    }
}
