#include <stdio.h>

typedef struct {
	int id;
	int grant;
} Student;

int all_granted(Student students[], int length) {
	int i;
	for(i = 0; i < length; i++) {
		if(students[i].grant < 40)
			return 0;
	}
	return 1;
}

int main() {
	int N, k;
	int i;

	while(scanf("%d %d", &N, &k) != EOF)
	{
		if (N == 0 && k == 0)
			break;

		Student students[N];

		/* Initialize students list */
		for(i = 0; i < N; i++) {
			students[i].id = i + 1;
			students[i].grant = 0;
		}

		int k_counter = 1;
		int output_store = 0;

		while(all_granted(students, N) == 0)
		{
			for(i = 0; i < N; i++) {
				if(students[i].grant < 40)
				{
					if (output_store == 0)
					{
						output_store = k_counter;

						if (k_counter < k) {
							k_counter++;
						} else {
							k_counter = 1;
						}
					}

					int needed = 40 - students[i].grant;

					if (output_store >= needed)
					{
						students[i].grant = 40;
						output_store -= needed;

						printf("%3d", students[i].id);
					} else {
						students[i].grant += output_store;
						output_store = 0;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
