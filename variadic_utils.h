#ifndef HLEB_VARIADIC_UTILS_H
#define HLEB_VARIADIC_UTILS_H

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

#define $HLEB_COUNT_ARGS(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,       \
        _n, ...) _n
#define HLEB_COUNT_ARGS(...)                                                \
    $HLEB_COUNT_ARGS(, ##__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define $HLEB_DO_SELECTED(count, pref, args...)                             \
    $$HLEB_DO_SELECTED(count, pref, args)
#define $$HLEB_DO_SELECTED(count, pref, args...) pref##_##count(args)

#define HLEB_DO_SELECTED(pref, args...)                                     \
    $HLEB_DO_SELECTED(HLEB_COUNT_ARGS(args), pref, args)

#define HLEB_FIRST_ARG(f, o...)     f
#define HLEB_CUT_FIRST(f, o...)     o

#define $HLEB_FOREACH_1(macro, arg) macro(arg)
#define $HLEB_FOREACH_2(macro, args...)                                     \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_1(macro, HLEB_CUT_FIRST(args))
#define $HLEB_FOREACH_3(macro, args...)                                     \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_2(macro, HLEB_CUT_FIRST(args))
#define $HLEB_FOREACH_4(macro, args...)                                     \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_3(macro, HLEB_CUT_FIRST(args))
#define $HLEB_FOREACH_5(macro, args...)                                     \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_4(macro, HLEB_CUT_FIRST(args))
#define $HLEB_FOREACH_6(macro, args...)                                     \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_5(macro, HLEB_CUT_FIRST(args))
#define $HLEB_FOREACH_7(macro, args...)                                     \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_6(macro, HLEB_CUT_FIRST(args))
#define $HLEB_FOREACH_8(macro, args...)                                     \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_7(macro, HLEB_CUT_FIRST(args))
#define $HLEB_FOREACH_9(macro, args...)                                     \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_8(macro, HLEB_CUT_FIRST(args))
#define $HLEB_FOREACH_10(macro, args...)                                    \
    macro(HLEB_FIRST_ARG(args)); $HLEB_FOREACH_9(macro, HLEB_CUT_FIRST(args))

#define $HLEB_FOREACH(macro, args...)                                       \
    $HLEB_DO_SELECTED(HLEB_COUNT_ARGS(args), $HLEB_FOREACH, macro, args)
#define HLEB_FOREACH(macro, args...)                                        \
    do {                                                                    \
        $HLEB_FOREACH(macro, args);                                         \
    } while(0)

#endif // HLEB_VARIADIC_UTILS_H

