#include <chrono>
#include <fstream>

class ChromeTracing
{
 public:
    ChromeTracing(std::string name, std::string filePath)
        : m_count(0)
        , m_sum(0.0)
        , m_name(name)
    {
        if (!filePath.empty()) {
            m_file.open(filePath);
        }
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
        double timeUs = std::chrono::duration_cast<std::chrono::microseconds>(end - m_start).count();
        double timeMs = timeUs / 1000.0;

        if (m_file.is_open()) {
            double startTimePoint = std::chrono::duration_cast<std::chrono::microseconds>(m_start.time_since_epoch()).count();
            
            m_file << "{\"name\":\""            << m_name
                   << "\",\"ph\":\"X\",\"ts\":" << std::to_string(startTimePoint)
                   << ",\"dur\":"               << std::to_string(timeUs)
                   << ",\"tid\":\""             << m_name
                   << "\",\"pid\":\"func\",\"args\":{}},";
        }

        m_count++;
        m_sum += timeMs;

        return timeMs;
    }
    
    double getAverage()
    {
        return m_sum / (double)m_count;
    }

    void resetAverage()
    {
        m_count = 0;
        m_sum   = 0.0;
    }

private:
    std::chrono::system_clock::time_point m_start;
    
    int    m_count;
    double m_sum;

    std::string   m_name;
    std::ofstream m_file;
};
