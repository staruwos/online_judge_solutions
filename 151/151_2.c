#include <stdio.h>
#

/* N = total of regions*/


int main()
{
	int N, m;
	int i, j, counter = 1, last_counter = 0;
	while(scanf("%d", &N) != EOF)
	{
		if (N < 13 || N > 100)
			break;
		
		int list[N+1];
		for (i = 0; i <= N; i++)
			list[i] = 0;

		m = 1;
		
		for(m = 1; m <= N; m++)
		{
			printf("for m = %d\n", m);
			for (i = 0; i <= N; i++)
				list[i] = 0;
			counter = 1;
			last_counter = 1;
			printf("1 ");
			for(i = 0; i < N-1; i++)
			{
				counter = ((counter + m) % N);
				//counter == 0 ? counter=17 : counter;
				if(counter == 0)
				{
					counter = N;
				}
				else if (last_counter+m > N)
					counter += 1;
				
				/*
				while(list[counter] != 0)
				{
					counter++;
				}*/
				for(j = 0; 	
				list[counter] = 1;
				last_counter = counter;
				printf("%d ", counter); 
			}
			printf("\n");
		} 
	}	
	return 0;
}
