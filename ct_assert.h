#ifndef HLEB_CT_ASSERT_H
#define HLEB_CT_ASSERT_H

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

#define HLEB_BUILD_BUG_ON_ZERO(e)   (sizeof(struct{int:-!!(e)}))
#define HLEB_BUILD_BUG_ON(cond)     ((void)sizeof(char[1 - 2*!!(cond)]))

#define HLEB_COMPILETIME_ASSERT(cond, msg)                                  \
    $HLEB_COMPILETIME_ASSERT(cond, msg, __LINE__)

#define $HLEB_COMPILETIME_ASSERT(cond, msg, line)                           \
    $$HLEB_COMPILETIME_ASSERT(cond, msg, line)

#define $$HLEB_COMPILETIME_ASSERT(cond, msg, line)                          \
    do {                                                                    \
        __attribute__((error(msg)))                                         \
            void _hleb_ct_assert_line_##line() {}                           \
        if(!(cond))                                                         \
            _hleb_ct_assert_line_##line();                                  \
    } while(0)

#define $ct_assert(cond)                                                    \
    HLEB_COMPILETIME_ASSERT(cond, "ct_assert failed: " #cond)

#endif // HLEB_CT_ASSERT_H

