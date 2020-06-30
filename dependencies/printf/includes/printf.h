/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:15:51 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/30 11:46:20 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define LONG_MASK 0xF000000000000000
# define INF 0x7FF0000000000000
# define NANS 0x7FF8000000000000
# define NEGS 0x8000000000000000
# define MINF 0xFFF0000000000000

/*
** %[flags][width][.precision][lenght]type
*/
typedef struct			s_flags
{
	short				zero;
	short				plus;
	short				minus;
	short				hash;
	short				space;
	char				*apostrophe;
}						t_flags;

typedef struct			s_format
{
	t_flags				*flags;
	int					width;
	int					precision;
	int					float_precision;
	char				length;
	char				type;
	int					*print_l;
	int					last_pos;
}						t_format;

int						ft_printf(const char *s, ...);

/*
** flags.c
*/
char					*ft_plus(char *str, t_format *format);
char					*ft_hash(char *str, t_format *format);
char					*ft_space(char *str, t_format format);
char					*ft_apostrophe(char *str, t_format format);

/*
** printf.c
*/
char					*ft_extract_format(const char *s);
char					*ft_pre_format(va_list args, t_format *format,
							char *printf_buf);
void					ft_formater(const char **s, char **print_buf,
							va_list args, int **c_nulls);
int						ft_printf(const char *s, ...);

/*
** thousands_utils.c
*/
char					*ft_thousands_sep(char *str, t_format format);
void					ft_separate_float(int i, char *integer, char *decimal,
							char *str);

/*
** types_cspdiu.c
*/
char					*ft_c_conv(t_format *format, va_list args, int pos);
char					*ft_s_conv(t_format format, va_list args);
char					*ft_p_conv(t_format format, va_list args);
char					*ft_di_conv(t_format format, va_list args);
char					*ft_u_conv(t_format format, va_list args);

/*
** types_xXfegn.c
*/
char					*ft_hex_conv(t_format *format, va_list args);
char					*ft_floatpoint_conv(t_format format, va_list args);
void					ft_n_conv(t_format format, va_list args,
							char *printf_buf);

/*
** utils_e.c
*/
int						ft_count_figures(long long int num);
unsigned long long		ft_get_integer(double num, char type, int *exp);
char					*ft_get_decimals(unsigned long long f_num, int *exp,
						t_format format);
char					*ft_exp_str(double num, int *exp, t_format format);

/*
** utils_f.c
*/
double					ft_ten_power(int p);
unsigned long long		ft_rounding(unsigned long long *i_num,
							unsigned long long f_num,
							double num, int precision);
char					*ft_add_zeroes(char *f_str, int precision);
char					*ft_float_str(double num, t_format format);

/*
** utils_format.c
*/
short					ft_check_flags(t_format *format, char set);
int						ft_check_number(char *format_info, int *i,
							va_list args, t_format *format);
char					ft_check_length(char *format_info, int *i);
void					ft_classify_format(char *format_info, t_format *format,
							va_list args);

/*
** utils_g.c
*/
char					*ft_trim_f_zeros(char *num);
char					*ft_trim_e_zeros(char *num);
char					*ft_g_conv(double num, int *exp, t_format format);

/*
** utils_printf.c
*/
char					*ft_string_to_char(char *s);
void					ft_initialize_format(t_format *format, int **c_nulls);
char					*ft_post_format(char *format_aux, t_format *format);

/*
** utils_xXp.c
*/
void					ft_print_hex(char *hex, long long int num, char uplow);

/*
** width_precision.c
*/
char					*ft_set_spaces(int num, char symbol);
char					*ft_trim_string(char *str, int pos);
char					*ft_width(t_format *format, char *str);
char					*ft_precision(t_format format, char *str);

#endif
