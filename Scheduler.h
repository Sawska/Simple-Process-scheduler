#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <vector>
#include "Process.h"

struct CompareProcess {
    bool operator()(const std::shared_ptr<Process> a,const std::shared_ptr<Process> b) const {
        return a->getPriority() > b->getPriority();
    }
};

class Scheduler {
public:
    void add_processes(std::shared_ptr<Process> pr);
    void remove_processes();
    void print_all_processes();
    Scheduler();
    std::shared_ptr<Process> first_come_first_served();
    std::shared_ptr<Process> shortests_job_next();
    Process* shortests_remaiming_time_first();
    Process* round_robin();
    bool is_there_processes();

private:
    std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcess> pq;
};

#endif //SCHEDULER_H