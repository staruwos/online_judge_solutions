#include <stdio.h>
#include <stdlib.h>

int algo(int n, int steps)
{
	printf("%d\n", n);
	if (n == 1)
		return steps;
	else
	{
		if (n%2 != 0)
		{
			n = (3*n) + 1;
		}
		else
			n = n/2;
		
	}
	steps++;
	algo(n, steps);
	
}


int main (int argc, char** argv)
{
	int n = 22;
	int steps = algo(n, 1);
	printf("Steps = %d\n", steps);

	return 0;
}
