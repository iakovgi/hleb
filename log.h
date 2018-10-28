#ifndef HLEB_LOG_H
#define HLEB_LOG_H

#include "utils.h"
#include "escseq.h"
#include "attribute.h"

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define HLEB_LOG_FILENAME_LEN       1024
#define HLEB_LOG_BUF_LEN            1024

FILE*       hleb_log_file   = NULL;

__constructor(101)
void hleb_init_log_file()
{
    char    filename[HLEB_LOG_FILENAME_LEN] = {};

    time_t  raw     = time(NULL);
    struct  tm  *t  = localtime(&raw);

    snprintf(filename, HLEB_LOG_FILENAME_LEN,
            "hleb_log_%02d.%02d.%04d[%02d:%02d:%02d]",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec);

    hleb_log_file = fopen(filename, "w");
    if(hleb_log_file == NULL) {
        perror("Can't creat log file");
        abort();
    }
}

__destructor(101)
void hleb_close_log_file()
{
    fflush(hleb_log_file);
    fclose(hleb_log_file);
    hleb_log_file = NULL;
}

char        hleb_log_buf[HLEB_LOG_BUF_LEN] = {};

#define     $bprintf(...)                                                   \
    snprintf(hleb_log_buf, HLEB_LOG_BUF_LEN, __VA_ARGS__)

#define     $fprintf(...)                                                   \
    do {                                                                    \
        fprintf(hleb_log_file, __VA_ARGS__);                                \
        fflush(hleb_log_file);                                              \
    } while(0)

#define $HLEB_LOG_WHENCE                                                    \
    $$HLEB_LOG_WHENCE(__FILE__, __LINE__, __func__)

#define $$HLEB_LOG_WHENCE(file, line, func)                                 \
    ({                                                                      \
        $bprintf(SETCOLOR(BGREEN) "[%s:%d:%s]" RESET,                       \
                file, line, func);                                          \
        hleb_log_buf;                                                       \
    })

#define HLEB_LOG_ON(cond, msg)                                              \
    do {                                                                    \
        if(!(cond))                                                         \
            $fprintf("%s: %s\n",                                            \
                    $HLEB_LOG_WHENCE, msg);                                 \
    } while(0)

#define HLEB_WARN_ON(cond, msg)                                             \
    do {                                                                    \
        if(!(cond))                                                         \
            $fprintf("%s: "SETCOLOR(BYELLOW)"("#cond") failed: %s\n" RESET, \
                    $HLEB_LOG_WHENCE, msg);                                 \
    } while(0)

#define HLEB_ERR_ON(cond, msg)                                              \
    do {                                                                    \
        if(!(cond))                                                         \
            $fprintf("%s: "SETCOLOR(BRED)"("#cond") failed: %s\n" RESET,    \
                    $HLEB_LOG_WHENCE, msg);                                 \
    } while(0)

#define $$HLEB_FUNC_LOG(line)                                               \
    char ___ld##line[HLEB_LOG_BUF_LEN] = {};                                \
    snprintf(___ld##line, HLEB_LOG_BUF_LEN,                                 \
            SETCOLOR(BGREEN)"[%s:%s]"RESET, __FILE__, __func__);            \
                                                                            \
    $fprintf("%s: start\n", ___ld##line);                                   \
                                                                            \
    void _log_helper_##line(void* _)                                        \
    {                                                                       \
        $fprintf("%s: finish\n", ___ld##line);                              \
    };                                                                      \
                                                                            \
    int _log_helper_var##line __cleanup(_log_helper_##line) = 0;            \
    do {} while(0)

#define HLEB_FUNC_LOG                                                       \
    $HLEB_FUNC_LOG(__LINE__)

#define $HLEB_FUNC_LOG(line)                                                \
    $$HLEB_FUNC_LOG(line)

#define HLEB_LOG(msg)                                                       \
    do {                                                                    \
        $fprintf("%s: %s\n", $HLEB_LOG_WHENCE, msg);                        \
    } while(0)

#define HLEB_LOG_VAR(var, func...) $HLEB_LOG_VAR(var, func)

#define $HLEB_LOG_VAR(var, func...)                                          \
    do {                                                                    \
        char ___ld##line[HLEB_LOG_BUF_LEN] = {};                            \
        int  ___nargs = HLEB_COUNT_ARGS(func);                              \
        char* ___fstr = SETCOLOR(BRED)"Undefined type"RESET;                \
        $fprintf("%s: var log: (" #var ") = ", $HLEB_LOG_WHENCE);           \
        if(___nargs == 0) {                                                 \
            if     (HLEB_SAME_TYPE((var), int))            ___fstr = "%d";  \
            else if(HLEB_SAME_TYPE((var), unsigned))       ___fstr = "%u";  \
            else if(HLEB_SAME_TYPE((var), char))           ___fstr = "%c";  \
            else if(HLEB_SAME_TYPE((var), char*))          ___fstr = "%s";  \
            else if(HLEB_SAME_TYPE((var), float))          ___fstr = "%f";  \
            else if(HLEB_SAME_TYPE((var), double))         ___fstr = "%lf"; \
            else if(HLEB_SAME_TYPE((var), void*))          ___fstr = "%p";  \
            else if(HLEB_SAME_TYPE((var), long))           ___fstr = "%ld"; \
            else if(HLEB_SAME_TYPE((var), unsigned long))  ___fstr = "%lu"; \
            else if(HLEB_SAME_TYPE((var), short))          ___fstr = "%hd"; \
            else if(HLEB_SAME_TYPE((var), unsigned short)) ___fstr = "%hu"; \
            else if(HLEB_SAME_TYPE((var), long long))      ___fstr = "%lld";\
            else if(HLEB_SAME_TYPE((var),                                   \
                                     unsigned long long))  ___fstr = "%llu";\
        } else {                                                            \
            HLEB_WITH_WARN_IGNORED( "-Wint-conversion",                     \
                ___fstr = func((var));                                      \
            )                                                               \
        }                                                                   \
        $fprintf(___fstr, (var));                                           \
        $fprintf("\n");                                                     \
    } while(0)

#define HLEB_LOG_VAR_M(vars...) HLEB_FOREACH(HLEB_LOG_VAR, vars)

#endif // HLEB_LOG_H

