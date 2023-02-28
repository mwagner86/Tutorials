#include <unistd.h>

int ft_word_len(char *str)
{
	int i = 0;

	while(str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void ft_expand_str(char *str)
{
	int flag_first_word = 1;
	int word_len;
	
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			++str;
		word_len = ft_word_len(str);
		if (word_len > 0 && flag_first_word == 0)
			write(1, "   ", 3);
		flag_first_word = 0;
		write(1, str, word_len);
		str = str + word_len;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		ft_expand_str(argv[1]);
	write (1, "\n", 1);
	return (0);
}
