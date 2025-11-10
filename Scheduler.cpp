#include "Scheduler.h"

void Scheduler::add_processes(Process pr)
{
    pq.push(pr);
}

void Scheduler::remove_processes() {
    std::priority_queue<Process,std::vector<Process>,CompareProcess> temp_pq;

    while(!pq.empty()) {
        Process pr = pq.top();
        pq.pop();
        if(pr.getState() == ProcessState::COMPLETE) {
            continue;
        }
        temp_pq.push(pr);
    }
    pq = temp_pq;
}

void Scheduler::print_all_processes()
{
    std::priority_queue<Process,std::vector<Process>,CompareProcess> temp_pq;

    while(!pq.empty()) {
        Process pr = pq.top();
        pq.pop();
        std::cout << pr << std::endl;
        temp_pq.push(pr);
    }
    pq = temp_pq;
}

Scheduler::Scheduler()
{
    
}

Scheduler::~Scheduler()
{

}
