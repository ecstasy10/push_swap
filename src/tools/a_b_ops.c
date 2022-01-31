//
// Created by dev on 30/1/22.
//

#include "../../include/push_swap.h"

void	do_rr(t_frame *frame)
{
    do_ra(frame);
    do_rb(frame);
    if (frame->do_write)
        write(1, "rr\n", 3);
}

void	do_rrr(t_frame *frame)
{
    do_rra(frame);
    do_rrb(frame);
    if (frame->do_write)
        write(1, "rrr\n", 4);
}

void	do_ss(t_frame *frame)
{
    do_sa(frame);
    do_sb(frame);
    if (frame->do_write)
        write(1, "ss\n", 3);
}
