#include "Scheduler.h"

void Scheduler::add_processes(std::shared_ptr<Process> pr)
{
    pq.push(pr);
}

void Scheduler::remove_processes() {
    std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcess> temp_pq;

    while(!pq.empty()) {
        std::shared_ptr<Process> pr = pq.top();
        pq.pop();
        if(pr->getState() == ProcessState::COMPLETE) {
            continue;
        }
        temp_pq.push(pr);
    }
    pq = temp_pq;
}

void Scheduler::print_all_processes()
{
    std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcess> temp_pq;

    while(!pq.empty()) {
        std::shared_ptr<Process> pr = pq.top();
        pq.pop();
        std::cout << pr << std::endl;
        temp_pq.push(pr);
    }
    pq = temp_pq;
}

Scheduler::Scheduler()
{
    pq = std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcess> {};    
}

std::shared_ptr<Process> Scheduler::first_come_first_served()
{
        while(pq.size() > 0)
        {
        std::shared_ptr<Process> pr = pq.top();
        pq.pop();
        return pr;
        }
        return nullptr;
}

std::shared_ptr<Process> Scheduler::shortests_job_next()
{

    if(pq.empty()) {
        return nullptr;
    }

    std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcess> temp_pq;
    
    std::shared_ptr<Process> shortest_job = pq.top();
    pq.pop();

    while(!pq.empty()) {
        std::shared_ptr<Process> current_process = pq.top();
        pq.pop();

        if(current_process->getTimeToComplete() < shortest_job->getTimeToComplete()) {
            temp_pq.push(shortest_job);

            shortest_job = current_process;
        } else {
            temp_pq.push(current_process);
        }
    }
    pq = temp_pq;

    return shortest_job;
}

Process *Scheduler::shortests_remaiming_time_first()
{
    return nullptr;
}

Process *Scheduler::round_robin()
{
    return nullptr;
}

bool Scheduler::is_there_processes()
{
    return pq.size() != 0;
}
