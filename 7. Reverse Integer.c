#define _MAX_INT	(2147483646 + 1)
#define _MIN_INT	(-2147483647 - 1)

int reverse(int x) 
{
	double res=0;

	while (x)
	{
		res = res*10 + x%10;
		x /= 10;
	}
	
	if (res > _MAX_INT || res < _MIN_INT)
		return 0;
    else
		return (int)res;
}