/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:05:43 by akotzky           #+#    #+#             */
/*   Updated: 2021/06/10 20:56:47 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_conv {
	char	*conv;
	int		count;
	int		i;
	int		j;
}				t_conv;

typedef struct s_c_data {
	char		ch;
	char		hx[17];
	char		*s;
	void		*p;
	long int	nb;
	int			width;
	long int	preci;
	long int	intlen;
}				t_c_data;

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *str, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_calloc(size_t nitems, size_t size);
void			ft_strrev(char *str);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);

int				ft_printf(const char *format, ...);
int				ft_int_len(long int n);
int				ft_handle_conv(t_conv *c, va_list *alist);
int				ft_c(t_conv *c, va_list *alist);
int				ft_s(t_conv *c, va_list *alist);
int				ft_p(t_conv *c, va_list *alist);
int				ft_i(t_conv *c, va_list *alist);
int				ft_u(t_conv *c, va_list *alist);
int				ft_x(t_conv *c, va_list *alist);
int				ft_ux(t_conv *c, va_list *alist);
void			ft_replace_asterisk(char **conv, va_list *alist);
int				ft_pad_zero(int len, t_conv *cv);
int				ft_pad_space(int len, t_conv *cv);
void			ft_putstr_len(const char *s, size_t len, t_conv *cv);
void			ft_putnbr_pf(long int n, int fd, t_conv *cv);
void			ft_putchar_pf(char c, int fd, t_conv *cv);
int				ft_check(const char c);
int				ft_is_spec(const char c);
int				ft_parse_conv(const char *fmt, t_conv *c);
int				ft_check(const char c);
int				ft_is_spec(const char c);
int				ft_isdigit(int c);
int				ft_has_width(const char *conv);
int				ft_has_asterisk(const char *s);
int				ft_has_flag(const char *conv);
int				ft_has_precision(const char *conv);
int				ft_has_dot(const char *s);
int				ft_parse_conv(const char *fmt, t_conv *c);
int				ft_get_conv_type(const char *conv);

#endif
