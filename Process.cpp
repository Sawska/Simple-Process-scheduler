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

int Process::get_arrival_time() const {
    return arrival_time;
}

int Process::get_remaining_time() const {

    return time_to_complete - time_execued_so_far;
}

Process::Process(int pid, int arrival_time_in, int work_time, int priority_in)
{
    PID = pid;
    arrival_time = arrival_time_in;
    time_to_complete = work_time;
    Priority = priority_in;
    state = ProcessState::NEW;
}

void Process::wait_for_complitation()
{
    time_execued_so_far++;
}

int Process::getTimeToComplete() const {
    return time_to_complete;
}

bool Process::is_finished()
{

    if(time_execued_so_far >= time_to_complete) {
        state = ProcessState::COMPLETE;
        return true; 
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os,const Process& process)  {
    std::cout << "Process ID" <<  " " << process.getPID() << std::endl;
    std::cout << "Process State" << " " << process.getState() << std::endl;
    std::cout << "Process priority" << " " << process.getPriority() << std::endl;
    std::cout << "Process work time" << " " << process.getTimeToComplete() << std::endl;

    return os;
}