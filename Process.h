#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

enum ProcessState {
    NEW,
    READY,
    RUNNING,
    WAIT,
    COMPLETE
};

class Process {
public:
    int getPID() const;
    int getState() const;
    int getPriority() const;
    void* getProgramCount() const;
    void setProgramCount(void* pointer_to_function);
    void setPriority(int priority);
    Process(int pid,int priority,void* pointer_to_function);
    private:
    int PID;
    ProcessState state;
    void* program_counter;
    int Priority;
     friend std::ostream& operator<<(std::ostream& os, const Process& process);
    

};

#endif //PROCESS_H