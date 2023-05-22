// in_out.h

#ifndef IN_OUT_H
    #define IN_OUT_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "loop.h"

    #define MAX_INPUT_LINE_SIZE         256



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

    #define print(...)          ({ \
        char* values[] = {__VA_ARGS__ }; \
        for_range(index, 0, sizeof((char*[]){__VA_ARGS__}) / sizeof(char*)) printf(format_of(values[index]), values[index]); \
        NULL; \
    })

    #define line(...)                             ({ \
        print(__VA_ARGS__); \
        puts(""); \
        NULL; \
    })

    #define input()                                 ({ \
        char buffer[MAX_INPUT_LINE_SIZE + 1]; \
        fgets(buffer, MAX_INPUT_LINE_SIZE + 2, stdin); \
        buffer[strcspn(buffer, "\n")] = '\0'; \
        strdup(buffer); \
    })

    #define to_string(value)                        ({ \
        _Generic((value), \
            char*: (value), \
            default: ({ \
                char buffer[64]; \
                sprintf(buffer, format_of(value), value); \
                strdup(buffer); \
            }) \
        ); \
    })

    #define to_integer(value)                       atoi(to_string(value))
    #define to_nearest_integer(value)               ({ \
        long double float_result = atof(to_string(value)); \
        ((float_result - (long long) float_result) >= 0.5)? ((long long) float_result) + 1: (long long) float_result; \
    })
    #define to_float(value)                         atof(to_string(value))

    #define join(a,b)                               ({ \
        char buffer[strlen(to_string(a)) + strlen(to_string(b)) + 1]; \
        strcpy(buffer, to_string(a)); \
        strcat(buffer, to_string(b)); \
        strdup(buffer); \
    })

    void clear() {
        #ifdef __WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

#endif