#include "user.h"

// #include <sys/wait.h>
// #include <time.h>

int main() {
    int child_pid, end_id, status;

    if ((child_pid = fork()) == -1) {
        printf(1, "fork error\n");
    } else if (child_pid == 0) {
        printf(1, "This is child process with ID: %d\n", getpid());
        sleep(200);
        exit(0);
    } else {
        printf(1, "Parent %d is waiting for child %d to end\n", getpid(), child_pid);
        end_id = waitpid(child_pid, &status, 1);
        if (end_id == -1) {
            printf(1, "waitpid error\n");
            sleep(1);
            exit(1);
        }else if (end_id == child_pid) {
            printf(1, "child %d status: %d\n", child_pid, status);
        }
    }
    exit(0);
}