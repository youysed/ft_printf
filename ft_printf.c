#include "ft_printf.h"

int	ft_flags(va_list args, char flag)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (flag == 'p')
		return (ft_putnbr_pointer(va_arg(args, unsigned long)));
	else if (flag == 'd' || flag == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (flag == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), 10, 0));
	else if (flag == 'x')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), 16, 0));
	else if (flag == 'X')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), 16, 1));
	else if (flag == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	va_start(args, format);
	size = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			size += ft_flags(args, *format);
		}
		else
		{
			ft_putchar(*format);
			++size;
		}
		++format;
	}
	va_end(args);
	return (size);
}
