#include "types.h"
#include "user.h"

int main()
{
    printf(1, "Lab 2-1 with priority 30\n");
    setpriority(30);
    int i;
    int j;
    for(i = 0; i < 43000; i++){
        asm("nop");
        for(j = 0; j < 43000; j++){
            asm("nop");
        }
    }
    printf(1, "Lab2-1 has finished\n");
    exit(0);
}
