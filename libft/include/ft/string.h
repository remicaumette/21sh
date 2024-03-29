/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:07:45 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 23:25:35 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <string.h>

void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char **s1, char **s2, int i);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			**ft_strsplit(char const *s, char c);
void			ft_strarr_del(char **arr);
int				ft_strarr_len(char **arr);
char			**ft_strarr_add(char **arr, char *elem);
void			ft_strarr_sort(char **arr, int reverse);
char			**ft_strarr_clone(char **arr);
char			*ft_strarr_join(char **arr, char *with);
char			**ft_strarr_new(size_t size);
void			ft_sub(char ref, char new, char *str);
char			*ft_strpp(char **str);
int				ft_str_isdigit(const char *str);

#endif
