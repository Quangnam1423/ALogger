#ifndef ALOGGER_H
#define ALOGGER_H

#include <config.h>
#include <stdio.h>

namespace ALogger
{
    class ALOGGER_EXPORT Logger
    {
    public:
        Logger();
        ~Logger();

        void Log(const char* message);
    };
}

#endif // ALOGGER_H