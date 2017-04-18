#include <string.h>

#define _MAX_INT	(2147483646 + 1)
#define _MIN_INT	(-2147483647 - 1)

int myAtoi(char* str) 
{
	int i=0, len, num; 
	double res=0;
	int nSign = 1;

	len = strlen(str);

	while(str[i] == ' ')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		nSign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	for (; i<len; i++)
	{
		num = str[i] - '0';

		if(num > 9 || num < 0)
			break;

		res = res*10 + num;
	}

	res *= nSign;

	if(res > _MAX_INT)
		return _MAX_INT;
	else if (res < _MIN_INT)
		return _MIN_INT;

	return (int)res;
}