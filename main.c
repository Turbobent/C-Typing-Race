#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char *typethis[] = {
    "In a world driven by technology and rapid communication, the ability to type quickly and accurately has become more important than ever before. Whether you're coding, writing, or simply chatting, typing is a skill worth mastering.\n",
    
    "The elegance of C programming lies in its simplicity and power. With just a few lines of code, you can create complex systems, manage memory directly, and build software that runs incredibly fast and efficiently.\n",
    
    "Typing isn't just about speed — it's about rhythm, flow, and muscle memory. The more you practice, the more your fingers will dance across the keyboard like a pianist performing a well-rehearsed symphony.\n",
    
    "Every typist knows the frustration of a missed keystroke or an accidental typo, but true mastery comes from learning to correct mistakes on the fly and maintaining composure under pressure.\n",
    
    "As you race through each sentence, remember that each keystroke represents more than just letters on a screen — it's a step toward mastery, precision, and personal growth in a world that rewards speed and skill.\n",
    
    "Imagine you're in a coding competition where every second counts. Your ability to type out accurate logic, debug swiftly, and compile without error could be the difference between winning and losing. This is the power of refined typing skills.\n",
    NULL
};

void main(){
srand(time(NULL));

 int count = 0;
    while (typethis[count] != NULL) count++;
 
 int position = rand()% count;

 char usersInput[10000];

 printf("%s", typethis[position]);
 fgets(usersInput, sizeof(usersInput), stdin);

 if(strcmp(typethis[position],usersInput) == 0){
    printf("win");
 }else{
  printf("try again");
 }
}