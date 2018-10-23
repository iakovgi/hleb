#ifndef HLEB_ATTRIBUTE_H
#define HLEB_ATTRIBUTE_H

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif


#define __error(msg)        __attribute__((error(msg)))
#define __warning(msg)      __attribute__((warning(msg)))
#define __deprecated(msg)   __attribute__((deprecated(msg)))

#define __pure              __attribute__((pure))
#define __const             __attribute__((const))

#define __noreturn          __attribute__((noreturn))

#define __noinline          __attribute__((noinline))
#define __inline            __attribute__((always_inline))

#define __hot               __attribute__((hot))
#define __cold              __attribute__((cold))

#define __w_unused_res      __attribute__((warn_unused_result))

#define __constructor(p)    __attribute__((constructor(p)))
#define __destructor(p)     __attribute__((destructor(p)))

#define __cleanup(f)        __attribute__((cleanup(f)))

#endif // HLEB_ATTRIBUTE_H

