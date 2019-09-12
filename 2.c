#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* pid_t fork(void) is declared in unistd.h */
/* pid_t is a special type for process ids.  it's equivalent to int. */

void main()
{
        pid_t childPID;
	if((childPID=fork())==0)
	{
		printf("I am Child \n");
		int lp;
		for(lp=0;lp<5;lp++)
		{
			printf("*");
			sleep(1);
		}
		printf("\n");
	}
     else {
		 printf("\nI am Father\n");
}
}