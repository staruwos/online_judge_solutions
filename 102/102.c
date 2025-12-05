#include <stdio.h>
#include <string.h>
#include <limits.h>
/*
 b *[x][0] = B
 b[x][1] = G
 b[x][2] = C
 */
long long b[3][3];


long long final_maxMoves = INT_MAX;
char final_order[3] = "";


void test_order(char order[3])
{
	long long i ;
	long long total_moves = 0;
	for(i = 0; i < 3; i++)
	{

		if(order[i] == 'B')
		{
			long long total = b[0][0] + b[1][0] + b[2][0];
			total_moves += total - b[i][0];
		}
		else if(order[i] == 'G')
		{
			long long total = b[0][1] + b[1][1] + b[2][1];
			total_moves += total - b[i][1];
		}
		else if(order[i] == 'C')
		{
			long long total = b[0][2] + b[1][2] + b[2][2];
			total_moves += total - b[i][2];
		}
	}
<<<<<<< HEAD
=======
	
>>>>>>> 902411b (102)
	if (total_moves < final_maxMoves)
	{
		final_maxMoves = total_moves;
		strcpy(final_order, order);
	}
<<<<<<< HEAD
	else if (total_moves == final_maxMoves)
	{
		if (strcmp(final_order, order) > 0)
			strcpy(final_order, order);
	}
=======
	if (total_moves == final_maxMoves)
	{
		if(strcmp(final_order, order) == 1)
			strcpy(final_order, order);
	}	
	/*printf("%s %d\n", order, total_moves);*/
>>>>>>> 902411b (102)
}

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *a, long long left, long long right)
{
	long long i;
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
		&b[0][0], &b[0][1], &b[0][2],
		&b[1][0], &b[1][1], &b[1][2],
		&b[2][0], &b[2][1], &b[2][2]) != EOF)
	{
		char s[10];
		strcpy(s, "GBC");
		permute(s, 0, 2);

		printf("%s %d\n", final_order, final_maxMoves);

		strcpy(final_order, "");
		final_maxMoves = INT_MAX;
	}

	return 0;
}
