#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Blocks{
	int id;
	struct Blocks* next;
};

int length = 0;


int n_root(int n, int p)
{
	
}

int find_block_index(struct Blocks blocks[], int block)
{
	int i, j;
	for(i = 0; i < length; i++)
	{
		struct Blocks *current = &blocks[i];
		while (current != NULL)
		{
			if(current->id == block)
			{
				return i;
			}
			current = current->next;
		}
	}


}

void print_blocks(struct Blocks blocks[])
{
	int i, j;
	for(i = 0; i < length; i++)
	{
		printf("%d: ", i);

		struct Blocks *current = &blocks[i];
		while (current != NULL)
		{
			printf("%d ", current->id);
			current = current->next;
		}
		printf("\n");
	}

}

int move_over(struct Blocks blocks[], int a, int b)
{
	
}

int pile_over(struct Blocks blocks[], int a, int b)
{
	int i, j;
	int a_index = find_block_index(blocks, a);
	int b_index = find_block_index(blocks, b);	

	struct Blocks *current = &blocks[b_index];
	while (current != NULL)
	{
		if(current->id == b)
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			struct Blocks *ablock = &blocks[a_index];
			while(ablock != NULL)
			{
				if(ablock->id == a && ablock->next == NULL)
				{
					current->next = ablock;
					break;
				}
				else
					ablock = ablock->next;
			}
			break;

		}
		current = current->next;
	}

	blocks[1].
}

int move_onto(struct Blocks blocks[], int a, int b)
{
	int i, j;
	int a_index = find_block_index(blocks, a);
	int b_index = find_block_index(blocks, b);	
	
	struct Blocks *current = &blocks[a_index];
	while (current != NULL)
	{
		if(current->id == a)
		{
			current = current->next;
			while (current != NULL)
			{
				/* move move move */
			}

		}
	}
	


}

int pile_onto(struct Blocks blocks[], int a, int b)
{

}

int main()
{
	int n_blocks, block_a, block_b;
	char input_string[20]; 
	char command_a[10], command_b[10];
	int i;	
	

	fgets(input_string, 10, stdin);
	n_blocks = atoi(input_string);
	struct Blocks blocks[n_blocks];
	length = n_blocks;

	for(i = 0; i < n_blocks; i++)
	{
		blocks[i].id = i;
		blocks[i].next = NULL;
	}
	print_blocks(blocks);
	if(fgets(input_string, 20, stdin))
	{
		/*if (strcmp(input_string, "quit") == 0)
			break;*/
		if(strcmp(input_string, "quit") != 0)
		{
			sscanf(input_string, "%s %d %s %d", command_a, &block_a, command_b, &block_b);
			/*if(strcmp(command_a, "move") == 0)
			{
				break;
			}*/
			if(strcmp(command_a, "pile") == 0)
			{
				pile_over(blocks, block_a, block_b);
				print_blocks(blocks);
			}	
		}
	}
	return 0;
}
