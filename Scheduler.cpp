#include "Scheduler.h"

Scheduler::Scheduler()
{
    pq = std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcess> {};    
    ready_queue = std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcessSRTF> {};
}

void Scheduler::add_processes(std::shared_ptr<Process> pr)
{
    pr->setState(ProcessState::NEW);
    pq.push(pr);
}

void Scheduler::check_for_new_arrivals(int current_time)
{
    while(!pq.empty() && pq.top()->get_arrival_time() <= current_time)
    {
        std::shared_ptr<Process> arriving_process = pq.top();
        pq.pop();
        
        arriving_process->setState(ProcessState::READY);
        ready_queue.push(arriving_process);
        
        std::cout << "--- (Time: " << current_time << ") Process " << arriving_process->getPID() << " arrived and moved to ready queue. ---" << std::endl;
    }
}

void Scheduler::add_to_ready_queue(std::shared_ptr<Process> p)
{
    p->setState(ProcessState::READY);
    ready_queue.push(p);
}

std::shared_ptr<Process> Scheduler::get_shortest_ready_process()
{
    if (ready_queue.empty()) {
        return nullptr;
    }
    return ready_queue.top();
}

void Scheduler::pop_shortest_ready_process()
{
    if (!ready_queue.empty()) {
        ready_queue.pop();
    }
}

bool Scheduler::has_ready_processes()
{
    return !ready_queue.empty();
}

bool Scheduler::has_future_processes()
{
    return !pq.empty();
}

int Scheduler::get_size()
{
    return pq.size() + ready_queue.size();
}

void Scheduler::remove_processes() {

}

void Scheduler::print_all_processes()
{
    std::priority_queue<std::shared_ptr<Process>,std::vector<std::shared_ptr<Process>>,CompareProcess> temp_pq = pq;
    while(!temp_pq.empty()) {
        std::shared_ptr<Process> pr = temp_pq.top();
        temp_pq.pop();
        std::cout << pr << std::endl;
    }
}

std::shared_ptr<Process> Scheduler::first_come_first_served()
{

    return nullptr;
}

std::shared_ptr<Process> Scheduler::shortests_job_next()
{
    return nullptr;
}