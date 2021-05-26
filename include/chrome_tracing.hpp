#include <chrono>

class ChromeTracing
{
 public:
    ChromeTracing();
    ~ChromeTracing();

    void   start();
    double end();
    double getAverageTime();

private:
};
