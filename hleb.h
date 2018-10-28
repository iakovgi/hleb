#ifndef HLEB_HLEB_H
#define HLEB_HLEB_H

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

#include "utils.h"
#include "variadic_utils.h"
#include "escseq.h"
#include "attribute.h"
#include "log.h"
#include "ct_assert.h"

//------------------------------------------------------------------------------
//  utils.h
#ifdef HLEB_SUPPRESS_LIB_NAME
    #define stringize(e)                HLEB_STRINGIZE(e)
#else
    #define hleb_stringize(e)           HLEB_STRINGIZE(e)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define stringize_v(e)              HLEB_STRINGIZE_V(e)
#else
    #define hleb_stringize_v(e)         HLEB_STRINGIZE_V(e)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define same_type(a, b)             HLEB_SAME_TYPE(a, b)
#else
    #define hleb_same_type(a, b)        HLEB_SAME_TYPE(a, b)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define typecheck(type, e)          HLEB_TYPECHECK(type, e)
#else
    #define hleb_typecheck(type, e)     HLEB_TYPECHECK(type, e)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define must_be_array(a)            HLEB_MUST_BE_ARRAY(a)
#else
    #define hleb_must_be_array(a)       HLEB_MUST_BE_ARRAY(a)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define array_size(a)               HLEB_ARRAY_SIZE(a)
#else
    #define hleb_array_size(a)          HLEB_ARRAY_SIZE(a)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define field_sizeof(s, f)          HLEB_FIELD_SIZEOF(s, f)
#else
    #define hleb_field_sizeof(s, f)     HLEB_FIELD_SIZEOF(s, f)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define with_warn_ignored(warn, what...)                                \
        HLEB_WITH_WARN_IGNORED(warn, what)
#else
    #define hleb_with_warn_ignored(warn, what...)                           \
        HLEB_WITH_WARN_IGNORED(warn, what)
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// variadic_utils.h
#ifdef HLEB_SUPPRESS_LIB_NAME
    #define count_args(...)             HLEB_COUNT_ARGS(__VA_ARGS__)
#else
    #define hleb_count_args(...)        HLEB_COUNT_ARGS(__VA_ARGS__)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define do_selected(pref, ...)      HLEB_DO_SELECTED(pref, __VA_ARGS__)
#else
    #define gleb_do_selected(pref, ...) HLEB_DO_SELECTED(pref, __VA_ARGS__)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define first_arg(f, o...)          HLEB_FIRST_ARG(f, o)
#else
    #define hleb_first_arg(f, o...)     HLEB_FIRST_ARG(f, o)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define cut_first(f, o...)          HLEB_CUT_FIRST(f, o)
#else
    #define hleb_cut_first(f, o...)     HLEB_CUT_FIRST(f, o)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define foreach(what, args...)      HLEB_FOREACH(what, args)
#else
    #define hleb_foreach(what, args...) HLEB_FOREACH(what, args)
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ct_assert.h
#ifdef HLEB_SUPPRESS_LIB_NAME
    #define ct_assert_msg(cond, msg)    HLEB_COMPILETIME_ASSERT(cond, msg)
#else
    #define hleb_ct_assert_msg(cond, msg)                                   \
                                        HLEB_COMPILETIME_ASSERT(cond, msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define ct_assert(cond)             $ct_assert(cond)
#else
    #define hleb_ct_assert(cond)        $ct_assert(cond)
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// log.h
#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log_on(cond, msg)           HLEB_LOG_ON(cond, msg)
#else
    #define hleb_log_on(cond, msg)      HLEB_LOG_ON(cond, msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define warn_on(cond, msg)          HLEB_WARN_ON(cond, msg)
#else
    #define hleb_warn_on(cond, msg)     HLEB_WARN_ON(cond, msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define err_on(cond, msg)           HLEB_ERR_ON(cond, msg)
#else
    #define hleb_err_on(cond, msg)      HLEB_ERR_ON(cond, msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log_func                    HLEB_LOG_FUNC
#else
    #define hleb_log_func               HLEB_LOG_FUNC
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log(msg)                    HLEB_LOG(msg)
#else
    #define hleb_log(msg)               HLEB_LOG(msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log_var(var, func...)       HLEB_LOG_VAR(var, func)
#else
    #define hleb_log_var(var, func...)  HLEB_LOG_VAR(var, func)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log_mvar(vars...)           HLEB_LOG_VAR_M(vars)
#else
    #define hleb_log_mvar(vars...)      HLEB_LOG_VAR_M(vars)
#endif
//------------------------------------------------------------------------------

#endif // HLEB_HLEB_H

