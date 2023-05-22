// variable.h

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
    } variable;

    // this has the same issue of List_append()
    #define auto(value)     _Generic((value), \
        int: ({ \
            variable result; \
            result.selected_type = INTEGER; \
            result.integer = (long long) value; \
            result; \
        }), \
        unsigned int: ({ \
            variable result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        float: ({ \
            variable result; \
            result.selected_type = FLOAT_POINT; \
            result.float_point = (long double) value; \
            result; \
        }), \
        char*: ({ \
            variable result; \
            result.selected_type = STRING; \
            strcpy(result.string, (char*) value); \
            result; \
        }), \
        default: ({ \
            variable result; \
            result.selected_type = POINTER; \
            result.pointer = (void*) value; \
            result; \
        }) \
    )

#endif