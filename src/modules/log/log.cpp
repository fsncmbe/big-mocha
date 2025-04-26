#include "log.hpp"

Log *Log::instance()
{
    static Log* instance = new Log();
    return instance;
}
