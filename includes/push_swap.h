#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"

void 	push_b(t_list **head_a, t_list **head_b, t_list **tail_a, t_list **tail_b);
void 	push_a(t_list **head_a, t_list **head_b, t_list **tail_a, t_list **tail_b);
void 	swap_a(t_list **tail_a);
void 	swap_b(t_list **tail_b);
void	swap_ab(t_list **tail_b, t_list **tail_a);
void	rotate_b(t_list **head_b, t_list **tail_b);

#endif