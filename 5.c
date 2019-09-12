#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>

/* pid_t fork(void) is declared in unistd.h */
/* pid_t is a special type for process ids.  it's equivalent to int. */


int main(void) { 
pid_t child_pid; /* i.e., int  pid; */
int status;
pid_t wait_result;
child_pid = fork();
	
if (child_pid == 0){ 		
/* this code is only executed in the child process */ 		
printf("\n\nI am a child and my pid = %d", getpid());
execl("/bin/ls", "ls", ".",  NULL);

/* if execl succeeds, this code is never used */		
printf( "Could not execl file /bin/ls  \n");
exit(1);  /* this exit stops only the child process */
}

else if (child_pid > 0) {
/* this code is only executed in the parent process */
printf("\n\nI am the parent and my pid = %d", getpid() );
printf( "\n\nMy child has pid = %d",child_pid);
}
	
else {	
printf("The fork system call failed to create a new process");	
exit(1);
}

/* this code is executed by only the parent process because the child either is executing from "/bin/ls" or exited.  */
	
printf("\n\nI am a happy, healthy process and my pid = %d", getpid());
	
if (child_pid == 0) 	{
/* this code will never be executed */
printf("This code will never be executed!\n");
}
else {	
/* this code is only executed by the parent process */	
printf("\n\nI am a parent and I am going to wait for my child");
	do {
/* parent waits for the SIGCHLD signal sent to the parent of a (child) process when the child process terminates */
	wait_result = wait(&status);
	} while (wait_result != child_pid);
printf("\n\nI am a parent and I am quitting.\n\n");
}
return 0;
}
