#include<stdio.h>
#include<stdlib.h>
void main(){
printf("The Files in Directory are:\n");
execl("/bin/ls","ls",NULL);
printf("\n\n\n\n New Line\n");
}

