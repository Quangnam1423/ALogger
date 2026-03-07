#include <ALogger.h>

namespace ALogger
{
    Logger::Logger()
    {
        // Constructor implementation
    }

    Logger::~Logger()
    {
        // Destructor implementation
    }

    void Logger::Log(const char* message)
    {
        // Log the message (for demonstration, we'll just print it)
        printf("Log: %s\n", message);
    }
}