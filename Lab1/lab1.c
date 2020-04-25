#include "types.h"
#include "user.h"

int exitWaitTest(void);
int waitPidTest(void);

int main(int argc, char *argv[])
{
    printf(1, "\n Testing lab1\n");
    if (atoi(argv[1]) == 1)
        exitWaitTest();
    else if (atoi(argv[1]) == 2)
        waitPidTest();
    else
        printf(1, "\ntype \"lab1 1\" to test exit and wait, \"lab1 2\" to test waitpid \n");
    // End of test
    exit(0);
}

int exitWaitTest(void) {
    int pid, ret_pid, exit_status;
    int i;
    // use this part to test exit(int status) and wait(int* status)
    printf(1, "\n  A & B: exit(int status) & wait(int* status):\n");
    for (i = 0; i < 2; i++) {
        pid = fork();
        if (pid == 0) { // only the child executed this code
            if (i == 0)
            {
                printf(1, "\nChild with PID# %d and will exit with %d on status\n", getpid(), 0);
                exit(0);
            }
            else
            {
                printf(1, "\nChild with PID# %d and will exit with %d on status\n" ,getpid(), -1);
                exit(-1);
            }
        } else if (pid > 0) { // only the parent executes this code
            ret_pid = wait(&exit_status);
            printf(1, "\n Parent: child with PID# %d has exited with status %d\n", ret_pid, exit_status);
        } else  // something went wrong with fork system call
        {
            printf(2, "\nError using fork\n");
            exit(-1);
        }
    }
    return 0;
}

int waitPidTest(void){
    int ret_pid, exit_status;
    int i;
    int options = 0;
    int pid_a[5]={0, 0, 0, 0, 0};
    // use this part to test wait(int pid, int* status, int options)
    printf(1, "\n  C: testing waitpid(int pid, int* status, int options):\n");
    for (i = 0; i <5; i++) {
        pid_a[i] = fork();
        if (pid_a[i] == 0) { // only the child executed this code
            printf(1, "\nChild with PID# %d and will exit with %d on status\n", getpid(), 0);
            exit(0);}}
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
