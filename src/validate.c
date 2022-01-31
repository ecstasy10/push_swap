//
// Created by dev on 30/1/22.
//

#include "../include/push_swap.h"

void    check_duplicates(t_frame *frame)
{
    t_stack		*slow;
    t_stack		*fast;

    slow = frame->a;
    while (slow != frame->a->prev)
    {
        fast = slow->next;
        while (fast != frame->a)
        {
            if (slow->num == fast->num)
                error(frame);
            fast = fast->next;
        }
        slow = slow->next;
    }
}

int     is_sorted(t_stack *stack)
{
    t_stack		*aux;

    if (!stack)
        return (0);
    aux = stack;
    while (aux->next != stack)
    {
        if (aux->num > aux->next->num)
            return (0);
        aux = aux->next;
    }
    return (1);
}
