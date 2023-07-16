#include "ft_printf.h"

int	ft_int(int i)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		leng++;
		i *= -1;
	}
	if (i >= 10)
	{
		tmp = ft_int(i / 10);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (ft_putchar("0123456789"[i % 10]) == -1)
		return (-1);
	return (leng + 1);
}

int	ft_unsigned(unsigned int i)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i >= 10)
	{
		tmp = ft_unsigned(i / 10);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (ft_putchar("0123456789"[i % 10]) == -1)
		return (-1);
	return (leng + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[++i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
	}
	return (i);
}

int	ft_hex(unsigned int d, char c)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (d >= 16)
	{
		tmp = ft_hex(d / 16, c);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (c == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[d % 16]) == -1)
			return (-1);
	}
	if (c == 'x')
	{
		if (ft_putchar("0123456789abcdef"[d % 16]) == -1)
			return (-1);
	}
	return (leng + 1);
}

int	ft_point(unsigned long l, int i)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		leng += 2;
	}
	if (l >= 16)
	{
		tmp = ft_point(l / 16, i);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (ft_putchar("0123456789abcdef"[l % 16]) == -1)
		return (-1);
	return (leng + 1);
}
