#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <vector>
#include "Process.h"

struct CompareProcess {
    bool operator()(const std::shared_ptr<Process> a,const std::shared_ptr<Process> b) const {
        return a->get_arrival_time() > b->get_arrival_time();
    }
};

struct CompareProcessSRTF {
    bool operator()(const std::shared_ptr<Process>& a, const std::shared_ptr<Process>& b) {
        return a->get_remaining_time() > b->get_remaining_time();
    }
};

class Scheduler {
public:
    void add_processes(std::shared_ptr<Process> pr);
    
    Scheduler();
    int get_size();

    void check_for_new_arrivals(int current_time);

    void add_to_ready_queue(std::shared_ptr<Process> p);
    
    std::shared_ptr<Process> get_shortest_ready_process();

    void pop_shortest_ready_process();

    bool has_ready_processes();
    
    bool has_future_processes();

    void remove_processes();
    void print_all_processes();
    std::shared_ptr<Process> first_come_first_served();
    std::shared_ptr<Process> shortests_job_next();


private:
    std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcess> pq;
    
    std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcessSRTF> ready_queue;
};

#endif //SCHEDULER_H