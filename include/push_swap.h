//
// Created by dev on 24/1/22.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
// remove
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

# define QUARTER frame->quarter
# define MEDIAN frame->median
# define THREE_Q frame->three_quarters
# define BIGGEST frame->biggest
# define BIG_ROTATE frame->big_rotate
# define BIG_RROTATE frame->big_rrotate
# define BIG_FLAG frame->big_flag
# define SMALLEST frame->smallest
# define SMALL_ROTATE frame->small_rotate
# define SMALL_RROTATE frame->small_rrotate
# define SMALL_FLAG frame->small_flag

typedef struct		s_stack
{
    long int		num;
    struct s_stack	*next;
    struct s_stack	*prev;
}					t_stack;

/*
 * Definition of stacks a & b
 */

typedef struct		s_frame
{
    struct s_stack	*a;
    struct s_stack	*b;

    char			**argv;
    char			*line;
    char			*str;

    int				print_stacks;
    int				do_write;
    int				stack_len;
    long			quarter;
    long			median;
    long			three_quarters;

    long			biggest;
    int				big_rotate;
    int				big_rev_rotate;
    int				big_flag;

    long			smallest;
    int				small_rotate;
    int				small_rev_rotate;
    int				small_flag;

    int				after_rotate;
}					t_frame;

/*
 * Push swap
 */
t_frame		*initialize_frame(t_frame *frame, char **argv);
void        fill_stack_a(t_frame *frame);
void		free_frame(t_frame *frame);
void		push_to_stack(t_frame *frame, t_stack **stack, int num);
int         is_sorted(t_stack *stack);
void		check_duplicates(t_frame *frame);
int		    get_stack_length(t_stack *stack);
void	    set_biggest_number(t_frame *frame, t_stack *stack);
void		shift_stack(t_stack **stack);
void		unshift_stack(t_frame *frame, t_stack **stack, int num);
void		moves_to_end(t_frame *frame, t_stack *stack, int flag);
void	    set_biggest_smallest(t_frame *frame, t_stack *stack);
void	    set_smallest_number(t_frame *frame, t_stack *stack);
void	    set_middle(t_frame *frame, t_stack *stack);
void		medium_sort(t_frame *frame);
void	    initialize_moves(t_frame *frame);
void		calculate_moves(t_frame *frame, t_stack	*stack);

/*
 * Sort
 */
void		small_sort(t_frame *frame, int length);

/*
 * Tools
 */
long		parse_number(t_frame *frame, char *str);
void	    sort_array(long *array, int len);

/*
 * Stack A operations
 */
void	    do_sa(t_frame *frame);
void	    do_pa(t_frame *frame);
void	    do_ra(t_frame *frame);
void	    do_rra(t_frame *frame);

/*
 * Stack B operations
 */
void	    do_sb(t_frame *frame);
void	    do_pb(t_frame *frame);
void	    do_rb(t_frame *frame);
void	    do_rrb(t_frame *frame);

/*
 * Stacks A & B operations
 */
void	    do_ss(t_frame *frame);
void	    do_rr(t_frame *frame);
void	    do_rrr(t_frame *frame);

/*
 * Errors
 */
void		error_check(t_frame *frame);
void		error(t_frame *frame);


#endif
