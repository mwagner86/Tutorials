#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int arg1;
	int arg3;
	int res;

	arg1 = 0;
	arg3 = 0;
	res = 0;

	if(argc == 4)
	{
		arg1 = atoi(argv[1]);
		arg3 = atoi(argv[3]);
		if(argv[2][0] == '+')
			res = arg1 + arg3;
		else if(argv[2][0] == '-')
			res = arg1 - arg3;
		else if(argv[2][0] == '*')
			res = arg1 * arg3;
		else if(argv[2][0] == '/')
			res = arg1 / arg3;
		else if(argv[2][0] == '%')
			res = arg1 % arg3;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
}
