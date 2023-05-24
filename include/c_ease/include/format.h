// format.h

#ifndef FORMAT_H
    #define FORMAT_H

    #define format_of(value)    _Generic((value), \
        char*:                  "%s", \
        \
        char:                   "%c", \
        signed char:            "%hhd", \
        unsigned char:          "%hhu", \
        \
        short:                  "%hd", \
        unsigned short:         "%hu", \
        \
        int:                    "%d", \
        unsigned int:           "%u", \
        \
        long:                   "%ld", \
        unsigned long:          "%lu", \
        \
        long long:              "%lld", \
        unsigned long long:     "%llu", \
        \
        float:                  "%f", \
        double:                 "%lf", \
        long double:            "%Lf", \
        \
        default:                "%p" \
    )
    
#endif