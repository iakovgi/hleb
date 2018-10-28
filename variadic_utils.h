#ifndef HLEB_VARIADIC_UTILS_H
#define HLEB_VARIADIC_UTILS_H

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

#define $HLEB_COUNT_ARGS(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,       \
        _n, ...) _n
#define HLEB_COUNT_ARGS(...)                                                \
    $HLEB_COUNT_ARGS(, ##__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#endif // HLEB_VARIADIC_UTILS_H

