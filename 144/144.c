#include <stdio.h>

typedef struct {
    int id;
    int grant;
}Student;

int all_granted(Student students[], int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		if(students[i].grant < 40)
			return 0;
	}	
	return 1;
}

int main()
{
    int N, k;
    int i;

    while(scanf("%d %d", &N, &k) != EOF)
    {
        Student students[N];

	/* Initialize students list */
	for(i = 0; i < N; i++)
	{
		students[i].id = i+1;
		students[i].grant = 0;
	}
	int current_coin = 1;
	int students_left = N;

	while(all_granted(students, N) == 0)
	{
		for(i = 0; i < N; i++)
		{
			if(students[i].grant < 40)
			{
				if(students[i].grant + current_coin > 40)
				{
					current_coin = (students[i].grant + current_coin) - 40;
					students[i].grant = 40;
					printf("%d ", students[i].id);
				}
				else
				{
					students[i].grant += current_coin;
					if(current_coin + 1 > k)
						current_coin = 1;
					else
						current_coin++;

					if (students[i].grant == 40)
						printf("%d ", students[i].id);
				}

			}

		}
	
	}
	
		
    }
    return 0;
}
