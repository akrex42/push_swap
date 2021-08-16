/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:12:49 by akrex             #+#    #+#             */
/*   Updated: 2020/11/21 22:43:25 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int 			order;
	int             flag;
	void 			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)
						(int));
void				ft_lstclear(t_list **lst, void (*del)(int));
void				ft_lstiter(t_list *lst, void (*f)(int));
void				ft_lstdelone(t_list *lst, void (*del)(int));
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstadd_back(t_list **head, t_list **tail);
t_list				*ft_lstadd_front(t_list **head, t_list **tail);
t_list				*ft_lstnew(t_list **head, t_list **tail);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *destination, const void *source, int c,
						size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *destination, const void *source,
						size_t n);
void				*ft_memset(void *destination, int c, size_t n);
char				*ft_strchr(const char *str, int ch);
size_t				ft_strlcat(char *destination, const char *source, size_t n);
size_t				ft_strlcpy(char *destination, const char *source, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strrchr(const char *str, int ch);
int					ft_isalpha(int character);
int					ft_isdigit(int digit);
int					ft_isalnum(int ab);
int					ft_isascii(int as);
int					ft_isprint(int pr);
int					ft_toupper(int up);
int					ft_tolower(int low);
void				*ft_calloc(size_t num, size_t size);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
char				*ft_strdup(const char *str);
char				*ft_strnstr (const char *big, const char *little,
						size_t len);
char				*ft_substr (char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);

#endif
