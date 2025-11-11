#include <iostream>
#include "Process.h"
#include "Scheduler.h"

const int quantum = 0;

void round_robin(Scheduler& sched) {
    std::shared_ptr<Process> work_process = sched.first_come_first_served();
}


int main() {
    Scheduler sched = Scheduler();
    std::shared_ptr<Process> shr_pt1 =  std::make_shared<Process>(Process(1,1,2));
    std::shared_ptr<Process> shr_pt2 =  std::make_shared<Process>(Process(2,2,3));
    std::shared_ptr<Process> shr_pt3 =  std::make_shared<Process>(Process(3,2,1));
    sched.add_processes(shr_pt1);
    sched.add_processes(shr_pt2);
    sched.add_processes(shr_pt3);

    std::shared_ptr<Process> work_process;
    // while((work_process = sched.first_come_first_served()) != nullptr)
    while((work_process = sched.shortests_job_next()) != nullptr)
    {
        work_process->setState(ProcessState::RUNNING);
        while(work_process->is_finished())
        {
            work_process->wait_for_complitation();
        }

    }
 
}
