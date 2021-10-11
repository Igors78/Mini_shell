/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:53:13 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/10 20:54:09 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/*
** MANDATORY PART
*/

int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t length);
int		ft_isalnum(int ch);
int		ft_isalpha(int ch);
int		ft_isascii(int ch);
int		ft_isdigit(int ch);
int		ft_isprint(int ch);
void	*ft_memccpy(void *dest, const void *src, int ch, size_t length);
void	*ft_memchr(const void *str, int ch, size_t count);
int		ft_memcmp(const void *str1, const void *str2, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t length);
void	*ft_memmove(void *str1, const void *str2, size_t count);
void	*ft_memset(void *str, int ch, size_t length);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *str, int ch);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
int		ft_split_free(char **split);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_wordcount(char const *s, char c);
void	ft_terror(char *str);
char	*ft_straddchar(char *str, char c);
int		ft_atoi_base(char *str, char *base);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strarrlen(char **src);
char	**ft_strarrdup(char **src);
char	**ft_addstrstrarr(char **arr, char *str);
int		get_next_line(int fd, char **line);

/*
** BONUS PART
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif