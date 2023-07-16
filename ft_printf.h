#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_format(va_list *args, char c);
int	ft_int(int i);
int	ft_unsigned(unsigned int i);
int	ft_string(char *str);
int	ft_hex(unsigned int d, char c);
int	ft_point(unsigned long l, int i);
int	ft_check(char c);
#endif
