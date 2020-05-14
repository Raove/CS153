#include "types.h"
#include "user.h"

int waitPidTest(void);

int main(int argc, char *argv[])
{
    printf(1, "\n Testing lab1\n");
    waitPidTest();
    exit(0);
}

int waitPidTest(void){
    int ret_pid, exit_status;
    int i;
    int options = 0;
    int pid_a[5]={0, 0, 0, 0, 0};
    printf(1, "\n  C: testing waitpid(int pid, int* status, int options):\n");
    for (i = 0; i <5; i++) {
        pid_a[i] = fork();
        if (pid_a[i] == 0) {
            printf(1, "\nChild with PID# %d and will exit with %d on status\n", getpid(), 0);
            exit(0);
        }
    }
    sleep(5);
    printf(1, "\n Parent: Waiting for child with PID# %d\n",pid_a[3]);
    ret_pid = waitpid(pid_a[3], &exit_status, options);
    printf(1, "\n Parent: Child# %d has exited with %d on status\n",ret_pid, exit_status);
    sleep(5);
    printf(1, "\n Parent: Waiting for child with PID# %d\n",pid_a[1]);
    ret_pid = waitpid(pid_a[1], &exit_status, options);
    printf(1, "\n Parent: Child# %d has exited with %d on status\n",ret_pid, exit_status);
    sleep(5);
    printf(1, "\n Parent: Waiting for child with PID# %d\n",pid_a[2]);
    ret_pid = waitpid(pid_a[2], &exit_status, options);
    printf(1, "\n Parent: Child# %d has exited with %d on status\n",ret_pid, exit_status);
    sleep(5);
    printf(1, "\n Parent: Waiting for child with PID# %d\n",pid_a[0]);
    ret_pid = waitpid(pid_a[0], &exit_status, options);
    printf(1, "\n Parent: Child# %d has exited with %d on status\n",ret_pid, exit_status);
    sleep(5);
    printf(1, "\n Parent: Waiting for child with PID# %d\n",pid_a[4]);
    ret_pid = waitpid(pid_a[4], &exit_status, options);
    printf(1, "\n Parent: Child# %d has exited with %d on status\n",ret_pid, exit_status);
    return 0;
}
