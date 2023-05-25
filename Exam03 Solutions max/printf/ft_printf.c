#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return(write(1, &c ,1));
}

int	ft_putstr(char *str)
{
	int i = 0;
	if (!str)
		return(write(1, "(null)", 6));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return(i);
}

int	ft_putnbr (int nbr)
{
	int i = 0;

	if (nbr == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		i += ft_putnbr(nbr / 10);
	i += ft_putchar((nbr % 10) + 48);
	return (i);
}

int	ft_puthexnbr(unsigned int nbr, char *hex)
{
	int i = 0;
	if (nbr >= 16)
		i += ft_puthexnbr((nbr / 16), hex);
	i += ft_putchar(hex[(nbr % 16)]);
	return (i);
}

int	ft_assign(const char *str, int i, va_list args)
{
	int len = 0;
	if (str[i] == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (str[i] == 'd')
		len = ft_putnbr(va_arg(args, int));
	else if (str[i] == 'x')
		len = ft_puthexnbr(va_arg(args, unsigned int), "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int len = 0;
	int i = 0;
	va_list args;

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

int main(void)
{
	int	r;

	r = 0;
	ft_printf("\n--Mixed ft_printf ---\n");
	ft_printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	ft_printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	ft_printf("\n");
	ft_printf("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	ft_printf("written: %d\n", r);
	printf("\n--Mixed printf ---\n");
	printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("\n");
	printf("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("written: %d\n", r);
}