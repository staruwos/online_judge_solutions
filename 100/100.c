#include <stdio.h>
#include <stdlib.h>

int algo(int i, int steps)
{
	if (i == 1)
		return steps;
	else
	{
		if (i%2 != 0)
		{
			i = (3*i) + 1;
		}
		else
			i = i/2;
		
	}
	steps++;
	return algo(i, steps);
	
}


int main (int argc, char** argv)
{
	int i, j;

	while(scanf("%d %d", &i, &j) != EOF)
        {
            printf("%d %d ", i, j);
            
            int start = i;
            int end = j;
            
            if (i > j) {
                start = j;
                end = i;
            }

            int maxSteps = 0;
            int k; 
            
            for (k = start; k <= end; k++)
            {
                int steps = algo(k, 1);
                if (steps > maxSteps)
                    maxSteps = steps;
            }
            printf("%d\n", maxSteps);
        }

	return 0;
}
