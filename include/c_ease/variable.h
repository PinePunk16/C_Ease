// variable.h

#ifndef GENERIC_H
    #define GENERIC_H

    #include <stdbool.h>
    #include <string.h>



    typedef enum {
        INTEGER,
        UNSIGNED_INTEGER,
        FLOAT_POINT,
        STRING,
        POINTER
    } type;
    

    typedef struct {
        union {
            long long integer;
            unsigned long long unsigned_integer;
            long double float_point;
            char* string;
            void* pointer;
        } type_pool;
        type selected_type;
    } variable;

    // string and default to be updated
    #define auto(value)     _Generic((value), \
        char: ({ \
            variable result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        signed char: ({ \
            variable result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned char: ({ \
            variable result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        short: ({ \
            variable result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned short: ({ \
            variable result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        int: ({ \
            variable result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned int: ({ \
            variable result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        long: ({ \
            variable result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned long: ({ \
            variable result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        long long: ({ \
            variable result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned long long: ({ \
            variable result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        \
        float: ({ \
            variable result; \
            result.selected_type = FLOAT_POINT; \
            result.type_pool.float_point = (long double) value; \
            result; \
        }), \
        double: ({ \
            variable result; \
            result.selected_type = FLOAT_POINT; \
            result.type_pool.float_point = (long double) value; \
            result; \
        }), \
        long double: ({ \
            variable result; \
            result.selected_type = FLOAT_POINT; \
            result.type_pool.float_point = (long double) value; \
            result; \
        }), \
        \
        char*: ({ \
            variable result; \
            result; \
        }), \
        \
        default: ({ \
            variable result; \
            result; \
        }) \
    )

#endif