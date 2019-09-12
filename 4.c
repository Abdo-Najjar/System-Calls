#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//code after fork executed by paren and child but accordind to pids different things can be executed by parent and child

int globalVariable = 2;
main(){
char sIdentifier;
int iStackVariable = 20;
pid_t pID = fork();
   
if (pID == 0)  //child
   {
	// Code only executed by child process  
	sIdentifier = 'C';
	globalVariable++;
	iStackVariable++;
}

else if (pID < 0)  //failed to fork
    {        
	printf("Failed to fork\n");;   
	exit(1);
	// Throw exception    
}

else  // parent
    { // Code only executed by parent process    
	sIdentifier= 'P';
    }
    
// Code executed by both parent and child.  
printf("\n%c\n",sIdentifier);
printf(" Global variable: %d \n", globalVariable);
printf(" Stack variable: %d \n", iStackVariable);
}

//Parent Process: Global variable: 2 Stack variable: 20
//Child Process:  Global variable: 3 Stack variable: 21
