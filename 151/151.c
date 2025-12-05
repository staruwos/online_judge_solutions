#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        int m = 1;
        int target = 13; 

        while (1) {
            int regions[100] = {0}; 
            int count_off = 0;
            int current = 1; 
            
            regions[1] = 1; 
            count_off++;
            int last_region = 1;
           

            while (count_off < N) 
            {
                int step = 0;
                
                while (step < m) 
                {
                    current++;
                    if (current > N) current = 1; 
                    
                    
                    if (regions[current] == 0) 
                    {
                        step++;
                    }
                }
                
                regions[current] = 1;
                last_region = current;
                count_off++;
            }

            if (last_region == target) {
                printf("%d\n", m);
                break;
            }
            
            m++;
            
        }
    }
    return 0;
}
