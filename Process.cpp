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

void *Process::getProgramCount() const
{
    return program_counter;
}

void Process::setProgramCount(void* pointer_to_function)
{
    program_counter = pointer_to_function;
}

void Process::setPriority(int priority)
{
    Priority = priority;
}

Process::Process(int pid,int priority,void* pointer_to_function)
{
    PID = pid;
    Priority = priority;
    state = ProcessState::NEW;
    program_counter = pointer_to_function;
}


std::ostream& operator<<(std::ostream& os,const Process& process)  {
    std::cout << "Process ID" <<  " " << process.getPID() << std::endl;
    std::cout << "Process State" << " " << process.getState() << std::endl;
    std::cout << "Process priority" << " " << process.getPriority() << std::endl;
    std::cout << "Process function" << " " << process.getProgramCount() << std::endl;
    return os;
}

