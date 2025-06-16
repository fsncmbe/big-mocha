#include <mocha/helper/log.hpp>

namespace {
std::string levelToString(mocha::LogLevel level)
{
  switch (level) {
    case mocha::LogLevel::DEBUG:
        return "DEBUG";
    case mocha::LogLevel::INFO:
        return "INFO";
    case mocha::LogLevel::WARNING:
        return "WARNING";
    case mocha::LogLevel::ERROR:
        return "ERROR";
    case mocha::LogLevel::CRITICAL:
        return "CRITICAL";
    default:
        return "UNKNOWN";
    }
}

struct {
  std::string active_levels = "ERRORINFO";
} inst;
}

namespace mocha {

void addLogLevel(LogLevel level)
{
  inst.active_levels.append(levelToString(level));
}

void log(LogLevel level, const std::string& message)
{
  std::string str_level = levelToString(level);
  if (inst.active_levels.find(str_level) == std::string::npos) {return;}
  time_t now = time(0);
  tm* timeinfo = localtime(&now);
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp),
            "%H:%M:%S", timeinfo);

  std::ostringstream logEntry;
  logEntry << "[" << timestamp << "] "
          << str_level << ": " << message << "\n";

  std::cout << logEntry.str();
}
} 