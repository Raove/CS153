#include "types.h"
#include "user.h"

int main()
{
    printf(1, "Lab 2-2 with priority 5\n");
    setpriority(5);
    int i;
    int j;
    for(i = 0; i < 43000; i++){
        asm("nop");
        for(j = 0; j < 43000; j++){
            asm("nop");
        }
    }
    printf(1, "Lab2-2 has finished\n");
    exit(0);
}