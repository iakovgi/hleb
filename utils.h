#ifndef HLEB_UTILS_H
#define HLEB_UTILS_H

#include "ct_assert.h"

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

#define HLEB_STRINGIZE(e)       #e
#define HLEB_STRINGIZE_V(e)     HLEB_STRINGIZE(e)

#define __QLINE__               HLEB_STRINGIZE_V(__LINE__)

#define HLEB_SAME_TYPE(a, b)                                                \
    __builtin_types_compatible_p(typeof(a), typeof(b))

#define HLEB_TYPECHECK(type, e)                                             \
    do {                                                                    \
        HLEB_COMPILETIME_ASSERT(                                            \
            HLEB_SAME_TYPE(typeof(e), type),                                \
            "TYPECHECK failed on " #type " with " #e);                      \
    } while(0)


#define HLEB_MUST_BE_ARRAY(a)                                               \
    HLEB_BUILD_BUG_ON_ZERO(HLEB_SAME_TYPE((a), &(a)[0]))

#define HLEB_ARRAY_SIZE(a)                                                  \
    (sizeof(a)/sizeof(a[0]) + HLEB_MUST_BE_ARRAY(a))

#define HLEB_FIELD_SIZEOF(s, f)     (sizeof(((s*)0)->f))

#define $HLEB_COUNT_ARGS(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,       \
        _n, ...) _n
#define HLEB_COUNT_ARGS(...)                                                \
    $HLEB_COUNT_ARGS(, ##__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define $$HLEB_WITH_WARN_IGNORED(warn) GCC diagnostic ignored warn

#define $HLEB_WITH_WARN_IGNORED(warn)                                       \
    HLEB_STRINGIZE_V($$HLEB_WITH_WARN_IGNORED(warn))

#define HLEB_WITH_WARN_IGNORED(warn, what...)                               \
    _Pragma("GCC diagnostic push")                                          \
    _Pragma($HLEB_WITH_WARN_IGNORED(warn))                                  \
    what                                                                    \
    _Pragma("GCC diagnostic pop")

#endif // HLEB_UTILS_H

