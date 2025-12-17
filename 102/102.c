#include <stdio.h>
#include <string.h>
/*
b[x][0] = B
b[x][1] = G
b[x][2] = C
*/
int b[3][3];


int final_maxMoves = 99999999;
char final_order[3] = "";


void test_order(char order[3])
{
	int i ;
	int total_moves = 0;
	for(i = 0; i < 3; i++)
	{
		
		if(order[i] == 'B')
		{
			int total = b[0][0] + b[1][0] + b[2][0];
			total_moves += total - b[i][0];	
		}
		else if(order[i] == 'G')
		{
			int total = b[0][1] + b[1][1] + b[2][1];
			total_moves += total - b[i][1];	
		}
		else if(order[i] == 'C')
		{
			int total = b[0][2] + b[1][2] + b[2][2];
			total_moves += total - b[i][2];	
		}
	}	
	if (total_moves < final_maxMoves)
	{
		final_maxMoves = total_moves;
		strcpy(final_order, order);
	}
	printf("%s %d\n", order, total_moves);
}

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *a, int left, int right)
{
	int i;
	if (left == right)
		test_order( a);
	else
	{
		for(i = left; i <= right; i++)
		{
			swap((a + left), (a + i));
			permute(a, left + 1, right);

			/* backtrack */
			swap((a + left), (a + i));
		}
	}
	
}


int main()
{

	while(scanf("%u %u %u %u %u %u %u %u %u",
                 &b[0][0], &b[0][1], &b[0][2],  // Bin 1
                 &b[1][0], &b[1][1], &b[1][2],  // Bin 2
                 &b[2][0], &b[2][1], &b[2][2]) != EOF)
	{

		char a[3] = "GBC";
		permute(a, 0, 2);
	}
	printf("%s %d", final_order, final_maxMoves);	
	return 0;
}
