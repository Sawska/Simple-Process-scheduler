#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>

enum ProcessState {
    NEW,
    READY,
    RUNNING,
    WAIT,
    COMPLETE
};

class Process {
public:
    int getPID() const;
    int getState() const;
    int getPriority() const;
    void setPriority(int priority);
    void setState(ProcessState st);
    int getTimeToComplete() const;
    bool is_finished();
    Process(int pid,int priority,int work_time);
    void wait_for_complitation();
    private:
    int PID;
    ProcessState state;
    int Priority;
    int time_to_complete;
    int time_execued_so_far = 0;
    friend std::ostream& operator<<(std::ostream& os, const Process& process);
};

#endif //PROCESS_H