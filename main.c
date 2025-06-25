#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#endif


char *typeFunctions = {""};
char *typeText[] = {
    "The beauty of typing lies not just in the speed with which your fingers move, but in the precision of your thoughts flowing directly into words. Each keystroke is a deliberate act, forming a bridge between your mind and the machine.\n",
    
    "In the early days of computing, punch cards and command lines were the norm. Today, we have intuitive interfaces and lightning-fast processors, but at the heart of it all still lies the humble keyboard—your direct link to digital creation.\n",
    
    "To become truly fast at typing, you must learn to let go of hesitation. Your brain and hands must work in harmony, predicting the next word as you finish the last, always staying one step ahead of the screen.\n",
    
    "Sometimes the hardest part of a task is simply beginning. But once your fingers touch the keys and you type your first word, momentum carries you forward, and suddenly the impossible seems achievable.\n",
    
    "Writing code is like solving a puzzle with logic as your guide. Every function, every loop, every semicolon tells a story of structure and intent. Typing is how we bring those ideas to life.\n",
    
    "Never underestimate the power of a quiet keyboard and a focused mind. In those moments, ideas take shape, problems unravel, and entire worlds are written, one sentence at a time.\n",
    
    "Speed without control is meaningless. It's not enough to type fast—you must also type well. Every typo is a detour, and every correction is a second lost. Master both speed and precision.\n",
    
    "The difference between a good typist and a great one isn't how quickly they move—it's how rarely they stop. Flow, rhythm, and confidence turn typing from a chore into a form of art.\n",
    
    "Imagine being able to type out your thoughts as quickly as you think them. No delay, no interruption—just pure, unfiltered expression pouring out onto the page.\n",
    
    "Some of the most powerful tools ever created were typed into existence. From the first lines of UNIX to the sprawling codebases of modern operating systems, it all began with a keyboard and a clear vision.\n",
    
    "Each new paragraph is a blank canvas. You’re not just racing to type words—you’re composing thoughts, refining language, and building something meaningful in real time.\n",
    
    "Practice does not make perfect. Practice makes progress. Each time you race, you learn a little more, you miss a little less, and you grow a little faster.\n",
    
    "The fingers learn, even when the mind forgets. Over time, muscle memory will guide you through the most difficult phrases, and your hands will type words you no longer have to think about.\n",
    
    "There's something satisfying about the sound of keys clicking in rhythm—like a drummer keeping time for the concert of your thoughts. It means you’re in the zone, typing with intention.\n",
    
    "A true typist knows that mistakes are part of the process. What matters most is how quickly you recover and how focused you remain. Typing is not a sprint; it's a test of consistency.\n",
    
    "When you're typing quickly and fluidly, you're not just racing—you're communicating at the speed of thought. It’s one of the closest things to telepathy that technology allows.\n",
    
    "Great programmers are often great typists—not because they type fast, but because they spend less time fixing what they mistyped. Clarity and precision always beat brute force.\n",
    
    "You can only get faster by pushing your limits. That means racing even when you feel tired, typing through the difficult words, and pushing your comfort zone every single day.\n",
    
    "In a world full of distractions, typing is a form of meditation. It requires presence, focus, and intent. When you're typing, you're truly in the moment.\n",
    
    "The greatest authors in history didn't use fancy tools or fast machines. They used their fingers, their minds, and their discipline. That's all you need to leave a mark on the world, too.\n",
    
    NULL
};

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    srand(time(NULL));
    int count = 0;
    while (typeText[count] != NULL) count++;
    int position = rand() % count;

    printf("Type this within 120 seconds:\n\n%s\n", typeText[position]);
    printf("Start typing below:\n");

    char input[10000] = {0};
    int idx = 0;
    time_t start = time(NULL);

    while (1) {
        // Check if time is up
        if (time(NULL) - start >= 12) {
            printf("\n Time's up!\n");
            break;
        }

     
        #ifdef _WIN32
        if (_kbhit()) {
            char c = _getch();
            if (c == '\r') break; 
            if (c == '\b' && idx > 0) { 
                printf("\b \b");
                idx--;
                input[idx] = '\0';
            } else if (c >= 32 && c < 127 && idx < sizeof(input) - 1) {
                putchar(c);
                input[idx++] = c;
            }
        }
        Sleep(10); 
        #else
        //for linux
        struct timeval tv = {0, 10000};
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(0, &fds);
        if (select(1, &fds, NULL, NULL, &tv)) {
            char c;
            read(0, &c, 1);
            if (c == '\n') break;
            if (c == 127 && idx > 0) { 
                printf("\b \b");
                idx--;
                input[idx] = '\0';
            } else if (idx < sizeof(input) - 1) {
                putchar(c);
                input[idx++] = c;
            }
        }
        #endif
    }

    if (strncmp(input, typeText[position], strlen(typeText[position])) == 0) {
        printf("Correct!\n");
    } else {
        printf("Try again.\n");
    }

    return 0;
}