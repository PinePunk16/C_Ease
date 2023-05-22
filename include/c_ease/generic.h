// generic.h

#ifndef GENERIC_H
    #define GENERIC_H

    typedef enum {
        INTEGER,
        UNSIGNED_INTEGER,
        FLOAT_POINT,
        STRING,
        POINTER
    } type;

    typedef struct {
        long long integer;
        unsigned long long unsigned_integer;
        long double float_point;
        char* string;
        void* pointer;

        type selected_type;
    } generic;

     // Add other types...
    #define auto(value)     _Generic((value), \
        int: ({ \
            generic result; \
            result.selected_type = INTEGER; \
            result.intger = (long long) value; \
            result; \
        }), \
        float: ({ \
            generic result; \
            result.selected_type = FLOAT_POINT; \
            result.intger = (long double) value; \
            result; \
        }), \
        char*: ({ \
            generic result; \
            result.selected_type = STRING; \
            strcpy(result.string, (char*) value); \
            result; \
        }), \
    )

#endif