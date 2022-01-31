//
// Created by dev on 29/1/22.
//

#include "../include/push_swap.h"

void		unshift_stack(t_frame *frame, t_stack **stack, int num)
{
    t_stack		**top;
    t_stack		*tmp;

    top = stack;
    if (*top)
    {
        if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
            error(frame);
        tmp->next = *top;
        tmp->prev = (*top)->prev;
        (*top)->prev = tmp;
        tmp->prev->next = tmp;
        tmp->num = num;
        *top = (*top)->prev;
    }
    else
    {
        if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
            error(frame);
        (*top)->next = *top;
        (*top)->prev = *top;
        (*top)->num = num;
    }
}

void		shift_stack(t_stack **stack)
{
    t_stack		**top;
    t_stack		*tmp;

    top = stack;
    if (*top)
    {
        if ((*top)->next == *top)
        {
            free(*top);
            *top = NULL;
        }
        else
        {
            tmp = *top;
            *top = (*top)->next;
            tmp->prev->next = *top;
            (*top)->prev = tmp->prev;
            free(tmp);
        }
    }
}

void		push_to_stack(t_frame *frame, t_stack **stack, int num)
{
    t_stack		**top;
    t_stack		*tmp;

    top = stack;
    if (*top)
    {
        if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
            error(frame);
        tmp->next = *top;
        tmp->prev = (*top)->prev;
        (*top)->prev = tmp;
        tmp->prev->next = tmp;
        tmp->num = num;
    }
    else
    {
        if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
            error(frame);
        (*top)->next = *top;
        (*top)->prev = *top;
        (*top)->num = num;
    }
}

int		    get_stack_length(t_stack *stack)
{
    t_stack	*tmp;
    t_stack	*end;
    int		len;

    len = 0;
    tmp = stack;
    if (stack)
        end = stack->prev;
    while (tmp)
    {
        len++;
        if (tmp == end)
            break ;
        tmp = tmp->next;
    }
    return (len);
}