#include "Process.h"

int Process::getPID() const
{
    return PID;
}

int Process::getState() const
{
    return state;
}

int Process::getPriority() const
{
    return Priority;
}


void Process::setPriority(int priority)
{
    Priority = priority;
}

void Process::setState(ProcessState st)
{
    state = st;
}

Process::Process(int pid,int priority,int work_time)
{
    PID = pid;
    Priority = priority;
    state = ProcessState::NEW;
    time_to_complete = work_time;
}

void Process::wait_for_complitation()
{
    std::cout << "Process working  with PID" << " " << this->getPID() << std::endl;
    if(!is_finished()) {
        time_execued_so_far++;
    }
}

int Process::getTimeToComplete() const {
    return time_to_complete;
}

bool Process::is_finished()
{
    if(time_to_complete < time_execued_so_far) {
        return false;
    } else {
        state = ProcessState::COMPLETE;
        return true;
    }
}

std::ostream& operator<<(std::ostream& os,const Process& process)  {
    std::cout << "Process ID" <<  " " << process.getPID() << std::endl;
    std::cout << "Process State" << " " << process.getState() << std::endl;
    std::cout << "Process priority" << " " << process.getPriority() << std::endl;
    std::cout << "Process work time" << " " << process.getTimeToComplete() << std::endl;

    return os;
}

