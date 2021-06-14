/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:37:37 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/14 17:34:43 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# define X7 0x40
# define X8 0x80
# define FC1 0x80
# define FC2 0x800
# define FC3 0x10000
# define FC4 0x200000
# define FC5 0x4000000

typedef struct s_format_arg
{
	char	flag;
	long	width;
	long	precision;
	char	spec_type;
	int		minus;
	long	field;
	long	show;



	
	char	length;
	char	plus;
	char	sharp;
	int		sharp_x;
}				t_format_arg;

typedef struct s_length
{
	signed char		*length_hh;
	short int		*length_h;
	long int		*length_l;
	long long int	*length_ll;
	int				*length;
}				t_length;

int				ft_is_spec_type(char spec_type);
int				ft_isnum(char c);
int				ft_isnump(char c);

char			*ft_sharp(char *save, t_format_arg *format_arg);
char			*ft_addplus_space(char *save, t_format_arg format_arg);

char			*ft_convert_c(va_list *ap, t_format_arg format_arg);
char			*ft_convert_di(va_list *ap, t_format_arg *format_arg);
int				ft_convert_n(va_list *ap, size_t len, t_format_arg format_arg);

char			*ft_itoa_st(size_t num);
char			*ft_convert_p(size_t num, char *set, t_format_arg format_arg);
char			*ft_convert(size_t num, const char *set, int base);
char			*ft_convert_uxp(va_list *ap, t_format_arg format_arg);

int				ft_printf(const char *format, ...);
int				ft_parse(const char **format, va_list *ap, size_t len);
int				ft_save(va_list *ap, t_format_arg format_arg, size_t len);
int				ft_save_putout(t_format_arg f_arg, char *save);

t_format_arg	ft_init_format_arg(char character, long num);
t_format_arg	ft_get_flag(const char **format, t_format_arg format_arg);
t_format_arg	ft_get_field(const char **format, va_list *ap,
					t_format_arg format_arg);
long			ft_get_precision(const char **format, va_list *ap);
char			get_length(const char **format);

char			*ft_chrdup(long n);
int				ft_wbyte(long n);
int				ft_wbyte_topindex(int size, long n);
char			*ft_convert_string(int *string);

void			ft_putright(char *save, t_format_arg format_arg);
char			*ft_putright_num(char *save, t_format_arg *format_arg);
void			ft_putleft(char *save, t_format_arg format_arg);
void			ft_putleft_num(char *save, t_format_arg *format_arg);

void			ft_putout(char *save, t_format_arg format_arg);
void			ft_putzero(char *save, t_format_arg format_arg);
long			ft_max(long a, long b);
long			ft_min(long a, long b);
long			ft_abs(long a);

#endif
