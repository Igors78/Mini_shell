/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:53:13 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/27 10:15:23 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

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

/*
** PRINTF
*/

# define HEXLOW "0123456789abcdef"
# define HEXUPP "0123456789ABCDEF"
# define OCT "01234567"
# define DEC "0123456789"
# define BIN "01"
# define FLAGS "0-.*"
# define NUMS "0123456789"

typedef struct s_data
{
	va_list	ap;
	int		dash;
	int		zero;
	int		period;
	int		asterisk;
	int		width;
	int		precision;
	int		i;
	char	c;
	char	cha;
	int		output;
	size_t	count;
}			*t_data;
int		ft_printf(const char *format, ...);
void	dispatch(char *format, t_data table);
void	read_flags(char *format, t_data table);
void	handle_d(t_data table);
void	ft_putnbr_base(long int nbr, char *base, t_data table);
void	handle_c(t_data table);
void	handle_s(t_data table);
void	handle_p(t_data table);
void	handle_u(t_data table);
void	handle_x(t_data table);
void	handle_bigx(t_data table);
void	handle_perc(char *format, t_data table);
void	handle_spec(long num, t_data table);
void	handle_spec_u(unsigned int num, t_data table);
void	handle_spec_x(unsigned int num, t_data table);
void	handle_spec_bigx(unsigned int num, t_data table);
void	handle_spec_p(unsigned long num, t_data table);
void	handle_spec_c(t_data table);
void	handle_precis(long num, t_data table);
void	parse(char *format, t_data table);
t_data	init_table(t_data table);
t_data	reset_table(t_data table);

/*
** GET NEXT LINE
*/

# define BUFFER_SIZE 42

int		get_next_line(int fd, char **line);

#endif