#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main( int argc, char *argv[], char *env[] )
{
   pid_t my_pid, parent_pid, child_pid;
   int status;

/* print error message if fork() fails */
   if((child_pid = fork()) < 0 )
   {
      perror("fork failure");
      exit(1);
   }

/* fork() == 0 for child process */

   if(child_pid == 0)
   {
      printf("Child: I will sleep 3 seconds and then execute - date - command \n");
      sleep(3); 
      printf("Child: Now, I woke up and am executing date command \n");
      execl("/bin/date", "date", NULL);
      _exit(1);
   }
/*
 * parent process
 */
   else
   {
      wait(&status); /* can use wait(NULL) since exit status from child is not used. */
      printf("Parent: my child is dead. I am going to leave.\n");
   }

   return 0;
}
