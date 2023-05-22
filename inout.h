// inout.h

#ifndef INOUT_H
    #define INOUT_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_INPUT_LINE_SIZE         126



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
        float:                  "%g", \
        double:                 "%g", \
        long double:            "%g", \
        \
        default:                "%p" \
    )

    #define print(value)                            printf(format_of(value), value)

    #define line(value)                             print(value); \
                                                    puts("")

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
    #define to_float(value)                         atof(to_string(value))

    #define integer_input(value)                    to_integer(input())
    #define float_input(value)                      to_float(input())

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