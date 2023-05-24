// str.h

#ifndef STR_H
    #define STR_H

    #include <string.h>
    
    #include "format.h"



    typedef char* string;

    #define to_string(value)                        ({ \
        _Generic((value), \
            string: (value), \
            default: ({ \
                char buffer[64]; \
                sprintf(buffer, format_of(value), value); \
                strdup(buffer); \
            }) \
        ); \
    })

    #define to_integer(value)                       atoi(to_string(value))

    #define to_float(value)                         atof(to_string(value))

    #define to_nearest_integer(value)               ({ \
        long double float_result = to_float(value); \
        ((float_result - (long long) float_result) >= 0.5)? ((long long) float_result) + 1: (long long) float_result; \
    })
    
    #define join(a,b)                               ({ \
        char buffer[strlen(to_string(a)) + strlen(to_string(b)) + 1]; \
        strcpy(buffer, to_string(a)); \
        strcat(buffer, to_string(b)); \
        strdup(buffer); \
    })

    #define copy(str)                               strdup(str)

#endif