#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		ft_putchar(*str);
		++size;
		++str;
	}
	return (size);
}

int	ft_putnbr(int value)
{
	int	size;

	size = 0;
	if (value == -2147483648)
	{
		size += ft_putstr("-2");
		size += ft_putnbr(147483648);
	}
	else
	{
		if (value < 0)
		{
			size += ft_putchar('-');
			value = -value;
		}
		if (value >= 10)
			size += ft_putnbr(value / 10);
		size += ft_putchar(value % 10 + 48);
	}
	return (size);
}

int	ft_putnbr_unsigned(unsigned int nbr, unsigned int base, int uppercase)
{
	int	i;

	i = 0;
	if (nbr >= base)
		i += ft_putnbr_unsigned(nbr / base, base, uppercase);
	if (uppercase)
		i += ft_putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[nbr % base]);
	else
		i += ft_putchar("0123456789abcdefghijklmnopqrstuvwxyz"[nbr % base]);
	return (i);
}

int	ft_putnbr_pointer(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return(ft_putstr("(nil)"));
	if (nbr >= 16)
		i += ft_putnbr_pointer(nbr / 16);
	else
		i += ft_putstr("0x");
	i += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (i);
}
