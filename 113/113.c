#include <stdio.h>
#include <math.h>

int main()
{
	long int n, p;
    while (scanf("%ld", &n) != EOF)
    {
               
        scanf("%ld", &p);
    
        double k = pow(p, 1.0/n);
        printf("%d\n", (int)k);
    }
    return 0;
}
