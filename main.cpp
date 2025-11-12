#include <iostream>
#include "Process.h"
#include "Scheduler.h"

void shortest_remaining_time_first(Scheduler& sched) {
    
    int current_time = 0;
    std::shared_ptr<Process> running_process = nullptr;
    
    std::cout << "--- SRTF Simulation Starting ---" << std::endl;

    while (sched.has_future_processes() || sched.has_ready_processes() || running_process != nullptr) 
    {
        sched.check_for_new_arrivals(current_time);

        std::shared_ptr<Process> shortest_ready_process = sched.get_shortest_ready_process();

        
        if (running_process == nullptr) {
            if (shortest_ready_process != nullptr) {

                running_process = shortest_ready_process;
                sched.pop_shortest_ready_process(); // Remove it from ready queue
                running_process->setState(ProcessState::RUNNING);
            }
        } else {
            if (shortest_ready_process != nullptr && 
                shortest_ready_process->get_remaining_time() < running_process->get_remaining_time()) {
                
                std::cout << "--- (Time: " << current_time << ") PREEMPTION: Stopping PID " << running_process->getPID() 
                          << " (Rem: " << running_process->get_remaining_time() << ")" << std::endl;
                
                sched.add_to_ready_queue(running_process); 
                
                running_process = shortest_ready_process;
                sched.pop_shortest_ready_process();
                running_process->setState(ProcessState::RUNNING);
            }
        }

        if (running_process != nullptr) {
            
            std::cout << "Time: " << current_time 
                      << ", Running PID: " << running_process->getPID() 
                      << " (Rem: " << running_process->get_remaining_time() << ")" << std::endl;
                      
            running_process->wait_for_complitation(); 

            if (running_process->is_finished()) {
                std::cout << "--- (Time: " << current_time + 1 << ") PID " << running_process->getPID() << " finished! ---" << std::endl;
                running_process = nullptr; 
            }
        } else {
            std::cout << "Time: " << current_time << ", CPU Idle" << std::endl;
        }

        current_time++;
        
        if (current_time > 1000) {
            std::cout << "Error: Simulation exceeded 1000 time units. Aborting." << std::endl;
            break;
        }
    }
    
    std::cout << "--- Simulation Complete at Time " << current_time << " ---" << std::endl;
}


int main() {
    Scheduler sched = Scheduler();

    sched.add_processes(std::make_shared<Process>(Process(1, 0, 8))); 
    
    sched.add_processes(std::make_shared<Process>(Process(2, 1, 4)));
    
    sched.add_processes(std::make_shared<Process>(Process(3, 2, 9)));
    
    sched.add_processes(std::make_shared<Process>(Process(4, 3, 5)));

    shortest_remaining_time_first(sched);
 
}