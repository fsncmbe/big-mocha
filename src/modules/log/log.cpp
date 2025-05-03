#include "log.hpp"

Log *Log::instance()
{
    static Log* instance = new Log();
    return instance;
}

void Log::init()
{

}

void Log::log(std::string message)
{
    std::cout << message << "\n"; 
}

void Log::onNotify(Event* e)
{
    switch (e->getType())
    {
        case Event::Type::LOGERROR:
            log("\033[1;31mERROR:\033[0m" + e->getMessage());
            break;
        case Event::Type::LOGSUCCESS:
            log("\033[1;31mSUCCESS:\033[0m" + e->getMessage());
            break;
        default:
            log("\033[1;31m" + eventTypeToString(e) + ":\033[0m" + e->getMessage());
            break;
    };
}

std::string Log::eventTypeToString(Event* e)
{
    switch(e->getType())
    {
        case Event::Type::KEY_DOWN:
            return "KEY_DOWN";
        case Event::Type::KEY_UP:
            return "KEY_UP";
    }
    return "";
}
