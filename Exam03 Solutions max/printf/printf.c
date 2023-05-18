#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int num)
{
	int i;

	i = 0;
	if (num == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		num = 147483648;
	}
	if (num < 0)
	{
		i += ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		i += ft_putnbr(num / 10);
	i += ft_putchar((num % 10) + 48);
	return (i);
}

int	ft_hex_putnbr(unsigned int num, char *hex)
{
	int i;

	i = 0;
	if (num >= 16)
		i += ft_hex_putnbr((num / 16), hex);
	i += ft_putchar(hex[(num % 16)]);
	return (i);
}

int	ft_assign(const char *str, int i, va_list args)
{
	int	len;

	len = 0;
	if (str[i] == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (str[i] == 'd')
		len = ft_putnbr(va_arg(args, int));
	else if (str[i] == 'x')
		len = ft_hex_putnbr(va_arg(args, unsigned int), "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	len;
	int	i;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_assign(str, i + 1, args);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}


int main (void)
{
	int nbr = INT_MAX;
	int nbr1 = INT_MIN;
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("%d is %x\n", nbr, nbr);
	ft_printf("%d is %x\n", nbr1, nbr1);
}