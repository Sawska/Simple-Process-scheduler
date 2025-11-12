# Simple Process Scheduler

This is a **C++ project** that simulates various CPU scheduling algorithms.  
It provides a basic framework for understanding how different schedulers manage processes with varying burst times, priorities, and arrival times.

---

## Features

This project demonstrates the implementation of the following scheduling algorithms:

- **Round Robin (RR)** – A preemptive, time-sharing algorithm where each process gets a small unit of CPU time (time quantum).
- **Shortest Remaining Time First (SRTF)** – A preemptive scheduling algorithm that selects the process with the smallest remaining execution time to run next.
- **First-Come, First-Served (FCFS)** – A non-preemptive algorithm where processes are handled in the order they arrive.
- **Shortest Job Next (SJN)** – A non-preemptive algorithm that selects the process with the smallest total burst time.

---

## Code Structure

The project is built around two primary classes:

### `Process`
Represents a single process with properties such as:
- Process ID (PID)
- Burst time
- Arrival time
- Remaining time

### `Scheduler`
Manages queues of processes (e.g., ready queue, future queue) and contains the logic for implementing different scheduling algorithms.

---

## How to Build and Run

Compile the source files using a C++ compiler such as **g++**:

```bash
g++ main.cpp Scheduler.cpp Process.cpp -o scheduler_sim -std=c++17
