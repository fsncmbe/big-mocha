#ifndef MOCHALOG_HPP
#define MOCHALOG_HPP

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

namespace mocha {

enum class LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

// Adds to what should be logged for debug purpose, error and info already in
void addLogLevel(LogLevel level);

// Writes message to console, implement to file later on
void log(LogLevel level, const std::string& message);

}


#endif