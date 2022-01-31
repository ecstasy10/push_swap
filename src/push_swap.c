//
// Created by dev on 24/1/22.
//

#include "../include/push_swap.h"

static void	push_swap(t_frame *frame)
{
    int     stack_length;

    fill_stack_a(frame);
    frame->do_write = 1;
    if (!is_sorted(frame->a))
    {
        stack_length = get_stack_length(frame->a);
        if (stack_length <= 5)
            small_sort(frame, stack_length);
        else if (stack_length <= 100)
            medium_sort(frame);
        else
            large_sort(frame);
        return ;
    }
}

int main(int argc, char **argv)
{
    t_frame     *frame;

    frame = NULL;
    if (argc < 2)
        return (1);
    frame = initialize_frame(frame, argv);
    push_swap(frame);
    free_frame(frame);
//    system("leaks push_swap");
    return (EXIT_SUCCESS);
}
