//
// Created by dev on 31/1/22.
//

#include "../include/push_swap.h"

void		large_sort(t_frame *frame)
{
    int	split;

    split = 1;
    median(frame, 'a');
    while (frame->a)
    {
        push_quarters(frame, frame->a, split);
        while (frame->b)
        {
            find_biggest_smallest(frame, 'b');
            find_moves(frame, 'b');
            if (frame->b && (SMALL_ROTATE >= 0 || SMALL_RROTATE >= 0
                             || BIG_ROTATE >= 0 || BIG_RROTATE >= 0))
                push_big_small(frame, frame->b, frame->b->prev);
        }
        while (--frame->after_rotate)
            do_ra(frame);
        split++;
        if (split == 5)
            break ;
    }
}
