#ifndef HLEB_UTILS_H
#define HLEB_UTILS_H

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

#define str(s) #s
#define xstr(s) str(s)

#define __QLINE__ xstr(__LINE__)

#define BUILD_BUG_ON(cond)      ((void)sizeof(char[1 - 2*!!(cond)]))
#define BUILD_BUG_ON_ZERO(e)    (sizeof(struct{int:-!!(e)}))

#define __same_type(a, b) __builtin_types_compatible_p(typeof(a), typeof(b))

#define __STATIC_ASSERT_HELPER(cond, msg, pref, suf)            \
    do {                                                        \
        void __attribute__((error(msg))) pref ## suf() {};      \
        if(!(cond))                                             \
            pref ## suf();                                      \
    } while(0)

#define _STATIC_ASSERT_HELPER(cond, msg, pref, suf)             \
    __STATIC_ASSERT_HELPER(cond, msg, pref, suf)

#define STATIC_ASSERT(cond, msg)                                \
       _STATIC_ASSERT_HELPER(cond, msg, _assert_, __LINE__);

#define TYPECHECK(type, e) STATIC_ASSERT(                       \
        __same_type(typeof(e), type),          \
        "TYPECHECK failed on " #type " with " #e)

// &a[0] degrades to pointer in case `a` is array
#define __must_be_array(a) BUILD_BUG_ON_ZERO(__same_type((a), &(a)[0]))
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]) + __must_be_array(a))


#endif // HLEB_UTILS_H

