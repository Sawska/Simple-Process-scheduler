#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <vector>
#include "Process.h"

struct CompareProcess {
    bool operator()(const Process& a,const Process& b) const {
        return a.getPriority() > b.getPriority();
    }
};

class Scheduler {
public:
    void add_processes(Process pr);
    void remove_processes();
    void print_all_processes();
    Scheduler();
    ~Scheduler();
private:
    std::priority_queue<Process,std::vector<Process>,CompareProcess> pq;
};

#endif //SCHEDULER_H