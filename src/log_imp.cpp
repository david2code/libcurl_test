
#include <memory>
#include "log_imp.h"

bool g_is_console = false;

//控制台输出
std::shared_ptr<spdlog::logger> g_console_log = nullptr;

//日志输出
std::shared_ptr<spdlog::logger> g_sys_log = nullptr;
