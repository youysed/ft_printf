#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h> 

int	ft_putstr(const char *str);
int	ft_putnbr(int value);
int	ft_putnbr_pointer(unsigned long nbr);
int	ft_putnbr_unsigned(unsigned int nbr, unsigned int base, int uppercase);
int	ft_putchar(char c);
int	ft_flags(va_list args, char flag);
int	ft_printf(const char *format, ...);

#endif
