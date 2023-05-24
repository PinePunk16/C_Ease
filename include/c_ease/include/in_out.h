// in_out.h

#ifndef IN_OUT_H
    #define IN_OUT_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "loop.h"

    #define MAX_INPUT_LINE_SIZE         256

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

    void clear() {
        #ifdef __WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

#endif