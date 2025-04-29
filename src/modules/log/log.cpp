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
        case Event::EventType::LOGERROR:
            log("\033[1;31mERROR:\033[0m" + e->getMessage());
            break;
        case Event::EventType::LOGSUCCESS:
            log("\033[1;31mSUCCESS:\033[0m" + e->getMessage());
            break;
    }
}