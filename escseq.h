#ifndef HLEB_ESCSEQ_H
#define HLEB_ESCSEQ_H

#include "utils.h"

#ifndef __GNUC__
    #error "hleb lib relies on GNU C extensions. Use gcc compiler"
#endif

#define CSI         "\e["

#define RESET       CSI "0m"

#define BOLD        CSI "1m"
#define ITALIC      CSI "3m"
#define UNDERLINED  CSI "4m"
#define BLINK       CSI "5m"

#define CURUP(n)    CSI HLEB_STRINGIZE_V(n) "A"
#define CURDOWN(n)  CSI HLEB_STRINGIZE_V(n) "B"
#define CURFWD(n)   CSI HLEB_STRINGIZE_V(n) "C"
#define CURBWD(n)   CSI HLEB_STRINGIZE_V(n) "D"
#define CURNXTL(n)  CSI HLEB_STRINGIZE_V(n) "E"
#define CURPRVL(n)  CSI HLEB_STRINGIZE_V(n) "F"
#define CURPOS(r,c) CSI HLEB_STRINGIZE_V(r) ";" HLEB_STRINGIZE_V(c) "H"

#define CLRDISP(p)  CSI HLEB_STRINGIZE_V(p) "J"
#define CLRLINE(p)  CSI HLEB_STRINGIZE_V(p) "K"

#define SCRLUP(n)   CSI HLEB_STRINGIZE_V(n) "S"
#define SCRLDWN(n)  CSI HLEB_STRINGIZE_V(n) "T"

#define REPORT      CSI "6n"

#define SAVEPOS     "\e7"
#define RESTPOS     "\e8"

#define SETCOLOR(c) CSI HLEB_STRINGIZE_V(c) "m"

#define RBLACK      30
#define RRED        31
#define RGREEN      32
#define RYELLOW     33
#define RBLUE       34
#define RMAGNETA    35
#define RCYAN       36
#define RWHITE      37
#define BBLACK      90
#define BRED        91
#define BGREEN      92
#define BYELLOW     93
#define BBLUE       94
#define BMAGNETA    95
#define BCYAN       96
#define BWHITE      97

#endif // HLEB_ESCSEQ_H

