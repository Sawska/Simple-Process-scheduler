#include <iostream>
#include "Process.h"

int add_two_nums(int a,int b) {
    int c = a +b;
    std::cout << c << std::endl;
    return c;
}

int main() {
    Process process = Process(1,1,(void*)add_two_nums);
    std::cout << "Process ID" <<  " " << process.getPID() << std::endl;
    std::cout << "Process State" << " " << process.getState() << std::endl;
    std::cout << "Process priority" << " " << process.getPriority() << std::endl;
    std::cout << "Process function" << " " << process.getProgramCount() << std::endl;
}