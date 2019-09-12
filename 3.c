#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
        pid_t childPID;
	//printf("\n START   ");
	
	
	if((childPID=fork())==0)
	
	{
		printf("\nI am Child \n");
		int lp;
		for(lp=0;lp<5;lp++)
		{

			printf("*");
			sleep(1);
		}
		printf("\n");


	}
     else 
{
		 printf("\nI am Father\n");
                wait();
}



}
