/**
 *  @file
 *  @brief  Library main file
 *
 *  This file includes all auxiliary files and defines user-space macro
 *  names. This names, though starts with `hleb_` prefix, can be defined
 *  without prefix. Define `HLEB_SUPRESS_LIB_NAME` before inclusion to do so.
 */

#ifndef HLEB_HLEB_H
#define HLEB_HLEB_H

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

/** @cond */
#include "utils.h"
#include "variadic_utils.h"
#include "escseq.h"
#include "attribute.h"
#include "log.h"
#include "ct_assert.h"
/** @endcond */

//------------------------------------------------------------------------------
//  utils.h
#ifdef HLEB_SUPPRESS_LIB_NAME
    #define stringize(e)                HLEB_STRINGIZE(e)
#else
/**
 *  @brief              Stringize argument
 *  @param[in] e        Value to stringize
 *  @return             Stringized param
 */
    #define hleb_stringize(e)           HLEB_STRINGIZE(e)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define stringize_v(e)              HLEB_STRINGIZE_V(e)
#else
/**
 *  @brief              Stringize value of an argument
 *  @param[in] e        Value to stringize
 *  @return             Stringized param value
 */
    #define hleb_stringize_v(e)         HLEB_STRINGIZE_V(e)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define same_type(a, b)             HLEB_SAME_TYPE(a, b)
#else
/**
 *  @brief              Check if two arguments is representatives of same type
 *  @param[in] a,b      Expressions to type comparison
 *  @return             `1` in case params are representatives of same type, `0`
 *                      otherwise
 */
    #define hleb_same_type(a, b)        HLEB_SAME_TYPE(a, b)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define typecheck(type, e)          HLEB_TYPECHECK(type, e)
#else
/**
 *  @brief              Compiletime type-checking assertion
 *  @param[in] type     Type to check
 *  @param[in] e        Expression to check
 */
    #define hleb_typecheck(type, e)     HLEB_TYPECHECK(type, e)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define must_be_array(a)            HLEB_MUST_BE_ARRAY(a)
#else
/**
 *  @brief              Compiletime assertion that `a` is array
 *  @param[in] a        Expression to check
 */
    #define hleb_must_be_array(a)       HLEB_MUST_BE_ARRAY(a)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define array_size(a)               HLEB_ARRAY_SIZE(a)
#else
/**
 *  @brief              Get array capacity in compiletime
 *  @param[in] a        Array to count elements within
 *  @return             Amount of elements in array
 *  @note               Will break compilation if `a` is not an array
 */
    #define hleb_array_size(a)          HLEB_ARRAY_SIZE(a)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define field_sizeof(s, f)          HLEB_FIELD_SIZEOF(s, f)
#else
/**
 *  @brief              Get sizeof of structs field without struct object
 *  @param[in] s        struct name
 *  @param[in] f        field name
 *  @return             sizeof of structs field
 */
    #define hleb_field_sizeof(s, f)     HLEB_FIELD_SIZEOF(s, f)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define with_warn_ignored(warn, what...)                                \
        HLEB_WITH_WARN_IGNORED(warn, what)
#else
/**
 *  @brief              Compile code ignoring specified warning
 *  @param[in] warn     Warning to ignore(example `"-Wadress"`)
 *  @param[in] what     Code to compile
 *  @note               While this macro can be useful in some circumstances,
 *                      be careful. Ignoring warning is bad practice.
 */
    #define hleb_with_warn_ignored(warn, what...)                           \
        HLEB_WITH_WARN_IGNORED(warn, what)
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// variadic_utils.h
#ifdef HLEB_SUPPRESS_LIB_NAME
    #define count_args(...)             HLEB_COUNT_ARGS(__VA_ARGS__)
#else
/**
 *  @brief              Get amount of variadic macro params
 *  @param[in] ...      Param list
 *  @return             Amount of comma-separated params
 *  @bug                This macro can count only up to 10. If param list is
 *                      longer thar 10 elements behavior is undefined
 */
    #define hleb_count_args(...)        HLEB_COUNT_ARGS(__VA_ARGS__)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define do_selected(pref, ...)      HLEB_DO_SELECTED(pref, __VA_ARGS__)
#else
/**
 *  @brief              Apply selected macro(or function) on args
 *  @param[in] pref     Prefix of macro name
 *  @param[in] ...      Argument list to be passed through
 *  @note               This macro selects which macro to apply based on amount
 *                      of arg list. Applied macro should have name `pref_N`,
 *                      where N is param count.
 */
    #define hleb_do_selected(pref, ...) HLEB_DO_SELECTED(pref, __VA_ARGS__)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define first_arg(f, o...)          HLEB_FIRST_ARG(f, o)
#else
/**
 *  @brief              Select first elem in comma-separated list
 *  @param[in] ...      Comma-separated list
 *  @return             First list entry
 */
    #define hleb_first_arg(f, o...)     HLEB_FIRST_ARG(f, o)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define cut_first(f, o...)          HLEB_CUT_FIRST(f, o)
#else
/**
 *  @brief              Cut first elem from comma-separated list
 *  @param[in]          Comma-separated list
 *  @return             List with first elem thrown away
 */
    #define hleb_cut_first(f, o...)     HLEB_CUT_FIRST(f, o)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define foreach(what, args...)      HLEB_FOREACH(what, args)
#else
/**
 *  @brief              Apply single-argument macro(or function) to each arg in
 *                      list
 *  @param[in] what     Single argument macro to apply
 *  @param[in] args     Comma-separated argument list
 *  @note               This macro can be compiled if used with 10 or less args
 */
    #define hleb_foreach(what, args...) HLEB_FOREACH(what, args)
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ct_assert.h
#ifdef HLEB_SUPPRESS_LIB_NAME
    #define ct_assert_msg(cond, msg)    HLEB_COMPILETIME_ASSERT(cond, msg)
#else
/**
 *  @brief              Compiletime assert with msg
 *  @param[in] cond     Assert condition
 *  @param[in] msg      Message to be shown is `cond` is false
 *  @note               `cond` should be compiletime evaluated
 */
    #define hleb_ct_assert_msg(cond, msg)                                   \
                                        HLEB_COMPILETIME_ASSERT(cond, msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define ct_assert(cond)             $ct_assert(cond)
#else
/**
 *  @brief              Compiletime assert
 *  @param[in] cond     Assert condition
 *  @note               `cond` should be compiletime evaluated
 */
    #define hleb_ct_assert(cond)        $ct_assert(cond)
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// log.h
#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log_on(cond, msg)           HLEB_LOG_ON(cond, msg)
#else
/**
 *  @brief              Print message to logfile if cond is false
 *  @param[in] cond     Log contition
 *  @param[in] msg      Message to print
 */
    #define hleb_log_on(cond, msg)      HLEB_LOG_ON(cond, msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define warn_on(cond, msg)          HLEB_WARN_ON(cond, msg)
#else
/**
 *  @brief              Similar to `hleb_log_on` except `msg` is yellow
 */
    #define hleb_warn_on(cond, msg)     HLEB_WARN_ON(cond, msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define err_on(cond, msg)           HLEB_ERR_ON(cond, msg)
#else
/**
 *  @brief              Similar to `hleb_log_on` except `msg` is red
 */
    #define hleb_err_on(cond, msg)      HLEB_ERR_ON(cond, msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log_func                    HLEB_FUNC_LOG
#else
/**
 *  @brief              Initiate function to be logged on start and end
 */
    #define hleb_log_func               HLEB_FUNC_LOG
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log(msg)                    HLEB_LOG(msg)
#else
/**
 *  @brief              Unconditionally print message to log
 *  @param[in] msg      Message to print
 */
    #define hleb_log(msg)               HLEB_LOG(msg)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log_var(var, func...)       HLEB_LOG_VAR(var, func)
#else
/**
 *  @brief              Dump var to log with its name and value
 *  @param[in] var      Var to be dumped
 *  @param[in] func     Optional function to form dump of user-defined type
 *  @note               `func` should get pointer to data and return `char[]`
 *                      containing complete dump.
 *  @bug                If `func` returns poiter to allocated memory, that
 *                      memory will leak
 */
    #define hleb_log_var(var, func...)  HLEB_LOG_VAR(var, func)
#endif

#ifdef HLEB_SUPPRESS_LIB_NAME
    #define log_mvar(vars...)           HLEB_LOG_VAR_M(vars)
#else
/**
 *  @brief              Dump multiple vars with one macro invocation
 *  @param[in] vars     Comma-separated list of variables
 *  @note               This macro can't use optional `func`.
 */
    #define hleb_log_mvar(vars...)      HLEB_LOG_VAR_M(vars)
#endif
//------------------------------------------------------------------------------

#endif // HLEB_HLEB_H

