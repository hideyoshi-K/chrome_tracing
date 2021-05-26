#include <chrono>

class ChromeTracing
{
 public:
    ChromeTracing()
        : m_count(0)
        , m_sum(0.0)
    {
    }
    
    ~ChromeTracing()
    {
    }

    void start()
    {
        m_start = std::chrono::system_clock::now();
    }
    
    double end()
    {
        auto end = std::chrono::system_clock::now();
        double time = std::chrono::duration_cast<std::chrono::microseconds>(end - m_start).count() / 1000.0;

        m_count++;
        m_sum += time;

        return time;
    }
    
    double getAverage()
    {
        return m_sum / (double)m_count;
    }

private:
    std::chrono::system_clock::time_point m_start;
    
    int    m_count;
    double m_sum;
};
