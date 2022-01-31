//
// Created by dev on 29/1/22.
//

#include "../../include/push_swap.h"

static void		free_stack(t_stack *stack)
{
    t_stack		*track_next;
    t_stack		*delete;

    if (stack)
    {
        track_next = stack->next;
        while (track_next != stack)
        {
            delete = track_next;
            track_next = track_next->next;
            free(delete);
        }
        free(track_next);
    }
}

void		free_frame(t_frame *frame)
{
    if (frame)
    {
        if (frame->a)
            free_stack(frame->a);
        if (frame->b)
            free_stack(frame->b);
        if (frame->line)
            free(frame->line);
        if (frame->str)
            free(frame->str);
        free(frame);
    }
}