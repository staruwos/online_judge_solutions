#include <stdio.h>
#include <string.h>

int can_be_sorted(char string[])
{
	int i, j;
	int length = strlen(string);
	for(i = 0; i < length; i++)
	{
		if(string[i] < string[i+1])
		{
			return 1;
		}	
	}
	return -1;
}

int bubblesort(char string[])
{
	int i;
	int length = strlen(string);
	int last = -1;
	for(i = length-2; i >= 0; i--)
	{
		if(string[i] < string[i+1])
		{
			last = i;
			break;
		}
	}
	int j = length - 1;
    while (string[j] <= string[i]) {
        j--;
    }


	char tmp = string[j];
	string[j] = string[i];
	string[i] = tmp;

	int left = i + 1, right = length - 1;
    while (left < right) {
        char t = string[left];
        string[left] = string[right];
        string[right] = t;
        left++;
        right--;
    }

}


int main(int argc, char** argv)
{
	char code[50];
	while(scanf("%s", code) != EOF)
	{
		if(code[0] == '#')
			return 0;
		
		int result = can_be_sorted(code);
		if(result == -1)
		{
			printf("No Successor\n");
		}
		else if(result == 1)
		{
			bubblesort(code);
			printf("%s\n", code);
		}		
	}
	return 0;
}
