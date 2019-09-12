#include <unistd.h>
#include <stdio.h>

void main()
{
printf(" first \n");
fork();
printf(" second\n");
printf(" third\n");
}
