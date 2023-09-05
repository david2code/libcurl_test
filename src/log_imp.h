#pragma once

#include "spdlog/common.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/syslog_sink.h"

namespace debug_log {
inline extern std::string GET_BASE_FILENAME(const std::string& file) {
    return file.substr(file.rfind("/") + 1);
}
}
extern std::shared_ptr<spdlog::logger> g_console_log;
extern std::shared_ptr<spdlog::logger> g_sys_log;
extern bool g_is_console;
#ifndef SPDLOG_STR_H
#define SPDLOG_STR_H(x) #x
#endif

#ifndef SPDLOG_STR_HELPER
#define SPDLOG_STR_HELPER(x) SPDLOG_STR_H(x)
#endif

#define LOG_INIT(name)                                            \
    {                                                             \
        g_sys_log = spdlog::syslog_logger_mt("S", name, LOG_PID); \
        g_console_log = spdlog::stdout_color_mt("C");             \
    }

#define LOG_SET_LEVEL_AND_OUTPUT(log_level, is_print) \
    {                                                 \
        spdlog::set_level(log_level);                 \
        spdlog::flush_on(log_level);                  \
        g_is_console = is_print;                      \
    }

#ifdef LOG_DEBUG
#undef LOG_DEBUG
#endif // LOG_DEBUG
#define LOG_DEBUG(...)                                                                                    \
    {                                                                                                     \
        if (g_is_console && g_console_log)                                                                \
            g_console_log->debug(debug_log::GET_BASE_FILENAME(__FILE__) + ":" SPDLOG_STR_HELPER(__LINE__) " :: " __VA_ARGS__); \
        if (g_sys_log)                                                                                    \
            g_sys_log->debug(debug_log::GET_BASE_FILENAME(__FILE__) + ":" SPDLOG_STR_HELPER(__LINE__) " :: " __VA_ARGS__);     \
    }


#ifdef LOG_INFO
#undef LOG_INFO
#endif // LOG_INFO
#define LOG_INFO(...)                                                                                    \
    {                                                                                                    \
        if (g_is_console && g_console_log)                                                               \
            g_console_log->info(debug_log::GET_BASE_FILENAME(__FILE__) + ":" SPDLOG_STR_HELPER(__LINE__) " :: " __VA_ARGS__); \
        if (g_sys_log)                                                                                   \
            g_sys_log->info(debug_log::GET_BASE_FILENAME(__FILE__) + ":" SPDLOG_STR_HELPER(__LINE__) " :: " __VA_ARGS__);     \
    }


#define LOG_WARN(...)                                                                                    \
    {                                                                                                    \
        if (g_is_console && g_console_log)                                                               \
            g_console_log->warn(debug_log::GET_BASE_FILENAME(__FILE__) + ":" SPDLOG_STR_HELPER(__LINE__) " :: " __VA_ARGS__); \
        if (g_sys_log)                                                                                   \
            g_sys_log->warn(debug_log::GET_BASE_FILENAME(__FILE__) + ":" SPDLOG_STR_HELPER(__LINE__) " :: " __VA_ARGS__);     \
    }

#define LOG_ERROR(...)                                                                                    \
    {                                                                                                     \
        if (g_is_console && g_console_log)                                                                \
            g_console_log->error(debug_log::GET_BASE_FILENAME(__FILE__) + ":" SPDLOG_STR_HELPER(__LINE__) " :: " __VA_ARGS__); \
        if (g_sys_log)                                                                                    \
            g_sys_log->error(debug_log::GET_BASE_FILENAME(__FILE__) + ":" SPDLOG_STR_HELPER(__LINE__) " :: " __VA_ARGS__);     \
    }

