# Dynamic Code analysis for Priority Scheduling

## Background: Linux Scheduling

This was a Task from TUM I solved in 2025, its goal is to understand how to find bugs using Sanitizers and enhance our C coding capabilities. The task at hand is to enhance the scheduler's ability to allocate computation time to each process.

In Linux, when a process is spawned (the mechanism of which we don't care for this task), it initially enters the state of ready. Subsequently, it waits to receive its allocated time, then transitions to the running state where it performs computations. The process's allocated time can be revoked by the scheduler at any time. Afterward, it may receive time again or be terminated altogether.

We now want to look at a simple priority scheduling algorithm, that is inspired by Linux's scheduling. Our scheduling algorithm works as follows given a list of processes and their (estimated) runtime:
1. Add the processes to a priority queue (which we use a min heap for) and assign priority to tasks with lower runtime
2. As long as there is still processes waiting take the process with the minimum runtime
3. Execute this process and continue at 2. afterwards

## task

Your task now is to find bugs in the following scheduling algorithm using dynamic analysis, similar to how you did this in the homework

You can find example calls below in the run section to test your implementation. 

### Hints

1. Use AddressSanitzers to find an fix the bugs.
2. In total there are 7 bugs that we want you to identify and fix. 
3. Do not add “additional” bugs that can not be found by Asan. This might lead to tests failing.
4. Do not remove or change any print statements.

## Compile

To run AddressSanitizer on your machine use the given Makefile. To use the Makefile, navigate to your assignment folder in your terminal and type the bash command `make` or `make all`. This will compile the program to `scheduler.out` and with AddressSanitizer to `asan.out`.

## Run 

Now you can run an example without AddressSanitizer with `make run` and one example with AddressSanitizer by executing `make runa`. You may want to call asan with different arguments locally. As promised, one such example could look like:
* `./asan.out 1 2 42 3` or `./scheduler.out 1 2 42 3` respectively 

In the above example we run two processes: `process 1` with an estimated execution time of `2 seconds` and `process 42` with an estimated execution time of `3 seconds`. If your program runs correctly it should output something like:
```
./scheduler.out 1 2 42 3
Starting scheduling
Process 1 executed for 2 seconds
Process 42 executed for 3 seconds
Printing summary
Process[1] ran for 2 seconds
Process[42] ran for 3 seconds
```


