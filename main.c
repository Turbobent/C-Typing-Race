#include <stdio.h>
#include <time.h>
#include <string.h>

//this is a type racer 
void main(){
 char typethis[] = "hej med jer\n";
 char usersInput[100];

 printf("%s", typethis);
 scanf("%s", usersInput); 
 if(strcmp(typethis,usersInput) == 0){
    printf("win");
 }else{
  printf("try again");
 }
}