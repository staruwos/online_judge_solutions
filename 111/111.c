#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, aux, num, ret;
	char line[30];
	char *token;
	int tok;
	fgets(line, 30, stdin);
	sscanf(line, "%d", &n);
	while(2 <= n && n <= 20)
	{
	    /*int ret = sscanf(line, "%d %d", &n, &aux);*/
	    /*if(ret != 1)*/
	    /*{*/
	        /* read first corrected order */
	        int corrected[n];
	        fgets(line, 30, stdin);
	        
	        /* get first token */
	        printf("%s", line);
	        
			token = strtok(line, " ");
	        printf("tok = %s\n", token);	        
	        
	        /* read students */
	        while(fgets(line, 30, stdin) != NULL)
	        {
	            ret = sscanf(line, "%d %d", &n, &aux);
	            /* get students */
	            if(ret != 1)
	            {
	                n = -1;
	                printf("%s", line);
	            }
	            else
	            {
	                /* new events */
	                break;
	            }
	        }
	        
	    /*}*/
	    
	}
	return 0;

}
