#include <iostream>
#include <unistd.h>
#include <chrome_tracing.hpp>

int main(int argc, char* argv[])
{
    ChromeTracing tracing("main", "file.yaml");

    for (int i = 0; i < 10; i++) {
        tracing.start();
        
        usleep(10000); // 10000 [us] = 10 [ms]
        
        double time = tracing.end();
        std::cout << i << ": " << time << " [ms]" << std::endl;
    }

    std::cout << "Average: " << tracing.getAverage() << " [ms]" << std::endl;
    
    return 0;
}
