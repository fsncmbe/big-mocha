#ifndef LOG_HPP
#define LOG_HPP

#include "../module.hpp"
#include "../event/observer.hpp"
#include "../event/event.hpp"

// Singleton Module log
class Log : public Module, public Observer<std::string>
{
public:
    static Log* instance();
    
    void init();
    void log(const char* message);

    // Observer
    void onNotify(Event<std::string>* e);
private:
    Log() {};
};

#endif