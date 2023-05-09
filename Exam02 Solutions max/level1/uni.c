#include <unistd.h>

int check(int c, char *s, int index)
{
	int i = 0;
	while(i < index)
	{
		if (s[i] == c)
			return 0;
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int k = 0;

	char *s1;
	char *s2;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];

		while (s1[i] != '\0')
			i++;
		while (s2[j] != '\0')
		{
			s1[i] = s2[j]; // append s2 on s1
			i++;
			j++;
		}
		i--; // 0 byte
		while (k <= i)
		{
			if(check(s1[k], s1, k) == 1) // checks for doubles, skips them
				write(1, &s1[k], 1);
			k++;
		}
	}
	write(1, "\n", 1);
}