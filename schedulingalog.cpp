#include <bits/stdc++.h>
using namespace std;

void FCFS(int pid[], int bt[], int n)
{
    int waiting_time[n];
    int turn_around_time[n];
    waiting_time[0] = 0;
    turn_around_time[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = turn_around_time[i - 1];
        turn_around_time[i] = waiting_time[i] + bt[i];
    }
    cout << "PID\tBT\tWT\tTAT\n";
    int total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << pid[i] << "\t" << bt[i] << "\t" << waiting_time[i] << "\t" << turn_around_time[i] << "\n";
        total_wt += waiting_time[i];
    }
    cout << "Average Waiting Time: " << (float)total_wt / n << "\n";
}

void SJF(int pid[], int bt[], int n)
{
    int waiting_time[n];
    int turn_around_time[n];
    int temp_pid[n], temp_bt[n];
    for (int i = 0; i < n; i++)
    {
        temp_pid[i] = pid[i];
        temp_bt[i] = bt[i];
    }
    // Sort by burst time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (temp_bt[i] > temp_bt[j])
            {
                swap(temp_bt[i], temp_bt[j]);
                swap(temp_pid[i], temp_pid[j]);
            }
        }
    }
    waiting_time[0] = 0;
    turn_around_time[0] = temp_bt[0];
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = turn_around_time[i - 1];
        turn_around_time[i] = waiting_time[i] + temp_bt[i];
    }
    cout << "PID\tBT\tWT\tTAT\n";
    int total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << temp_pid[i] << "\t" << temp_bt[i] << "\t" << waiting_time[i] << "\t" << turn_around_time[i] << "\n";
        total_wt += waiting_time[i];
    }
    cout << "Average Waiting Time: " << (float)total_wt / n << "\n";
}

void RR(int pid[], int bt[], int n, int quantum)
{
    int remaining_time[n];
    int waiting_time[n] = {0}, turn_around_time[n] = {0};
    for (int i = 0; i < n; i++)
    {
        remaining_time[i] = bt[i];
    }
    int t = 0;
    while (true)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                done = false;
                if (remaining_time[i] > quantum)
                {
                    t += quantum;
                    remaining_time[i] -= quantum;
                }
                else
                {
                    t += remaining_time[i];
                    waiting_time[i] = t - bt[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        turn_around_time[i] = bt[i] + waiting_time[i];
    }
    cout << "PID\tBT\tWT\tTAT\n";
    int total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << pid[i] << "\t" << bt[i] << "\t" << waiting_time[i] << "\t" << turn_around_time[i] << "\n";
        total_wt += waiting_time[i];
    }
    cout << "Average Waiting Time: " << (float)total_wt / n << "\n";
}

void Priority(int pid[], int bt[], int priority[], int n)
{
    int waiting_time[n];
    int turn_around_time[n];
    int temp_pid[n], temp_bt[n], temp_priority[n];
    for (int i = 0; i < n; i++)
    {
        temp_pid[i] = pid[i];
        temp_bt[i] = bt[i];
        temp_priority[i] = priority[i];
    }
    // Sort by priority
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (temp_priority[i] > temp_priority[j])
            {
                swap(temp_priority[i], temp_priority[j]);
                swap(temp_pid[i], temp_pid[j]);
                swap(temp_bt[i], temp_bt[j]);
            }
        }
    }
    waiting_time[0] = 0;
    turn_around_time[0] = temp_bt[0];
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = turn_around_time[i - 1];
        turn_around_time[i] = waiting_time[i] + temp_bt[i];
    }
    cout << "PID\tBT\tPriority\tWT\tTAT\n";
    int total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << temp_pid[i] << "\t" << temp_bt[i] << "\t" << temp_priority[i] << "\t\t" << waiting_time[i] << "\t" << turn_around_time[i] << "\n";
        total_wt += waiting_time[i];
    }
    cout << "Average Waiting Time: " << (float)total_wt / n << "\n";
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int pid[n], bt[n], priority[n];
    cout << "Enter the process ID and burst time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> pid[i] >> bt[i];
    }
    cout << "Enter the priority for each process:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> priority[i];
    }
    cout << "FCFS:\n\n";
    FCFS(pid, bt, n);
    cout << "---------------------------------\n";
    cout << "SJF:\n\n";
    SJF(pid, bt, n);
    cout << "---------------------------------\n";
    cout << "RR (Quantum = 2):\n\n";
    RR(pid, bt, n, 2);
    cout << "---------------------------------\n";
    cout << "Priority:\n\n";
    Priority(pid, bt, priority, n);
    cout << "---------------------------------\n";
    return 0;
}
