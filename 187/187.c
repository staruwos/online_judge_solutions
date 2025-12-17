#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int number;
	char name[30];
}Account;

typedef struct {
	int sequence;
	
}Transaction;


int main()
{
	char input[50];
	while(scanf("%s", input) != EOF)
	{
		printf("%d\n", input[0] - '0');
	}
	

	return 0;
}
