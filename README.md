# Scheduling-Algorithms
# CPU Scheduling Algorithms in C++

This C++ code implements four different CPU scheduling algorithms:

1. **First-Come, First-Served (FCFS)**
2. **Shortest Job First (SJF)**
3. **Round Robin (RR)**
4. **Priority Scheduling**

The program calculates and displays the following for each process:
- **PID**: Process ID
- **BT**: Burst Time
- **WT**: Waiting Time
- **TAT**: Turnaround Time
![image](https://github.com/user-attachments/assets/a8290a05-a009-426c-8499-903eba9a4468)
### FCFS (First-Come, First-Served)

- **Non-Preemptive Nature**: FCFS is a non-preemptive scheduling algorithm, meaning once a process starts execution, it runs to completion.
- **Convoy Effect**: FCFS can lead to the "convoy effect," where shorter processes get stuck waiting behind a longer process, leading to higher average waiting time.
- **Fairness**: It treats all processes equally, as they are scheduled in the order of arrival, but does not optimize for any particular performance metric.
### SJF (Shortest Job First)

- **Optimality**: SJF is optimal in terms of minimizing average waiting time when all jobs are available at the same time.
- **Starvation**: Shortest Job First can cause starvation for longer processes if there is a steady stream of shorter processes.
- **Non-Preemptive Variant**: The current implementation of SJF is non-preemptive. A preemptive version, known as Shortest Remaining Time First (SRTF), can also be implemented for more optimized scheduling.

### RR (Round Robin)

- **Preemptive Nature**: Round Robin is a preemptive scheduling algorithm that uses a fixed time quantum to cycle through processes.
- **Quantum Selection**: The choice of quantum is crucial; a small quantum increases context switching overhead, while a large quantum can degrade to FCFS.
- **Fairness**: RR provides a fair allocation of CPU time, ensuring no process waits too long, making it suitable for time-sharing systems.

### Priority Scheduling

- **Priority Inversion**: Higher priority processes are scheduled before lower priority ones, but this can lead to priority inversion where low-priority processes block higher-priority ones.
- **Starvation**: Processes with lower priority may suffer from starvation if higher-priority processes keep arriving. Implementing aging (gradually increasing the priority of waiting processes) can help mitigate this.
- **Assumption in Code**: The current implementation assumes burst time as priority, which needs to be adjusted if actual priority values are to be used.

