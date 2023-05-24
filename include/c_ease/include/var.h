// var.h

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
            string string;
            void* pointer;
        } type_pool;
        type selected_type;
    } var;

    // string and default to be updated
    #define auto(value)     _Generic((value), \
        char: ({ \
            var result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        signed char: ({ \
            var result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned char: ({ \
            var result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        short: ({ \
            var result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned short: ({ \
            var result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        int: ({ \
            var result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned int: ({ \
            var result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        long: ({ \
            var result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned long: ({ \
            var result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        long long: ({ \
            var result; \
            result.selected_type = INTEGER; \
            result.type_pool.integer = (long long) value; \
            result; \
        }), \
        unsigned long long: ({ \
            var result; \
            result.selected_type = UNSIGNED_INTEGER; \
            result.type_pool.unsigned_integer = (unsigned long long) value; \
            result; \
        }), \
        \
        float: ({ \
            var result; \
            result.selected_type = FLOAT_POINT; \
            result.type_pool.float_point = (long double) value; \
            result; \
        }), \
        double: ({ \
            var result; \
            result.selected_type = FLOAT_POINT; \
            result.type_pool.float_point = (long double) value; \
            result; \
        }), \
        long double: ({ \
            var result; \
            result.selected_type = FLOAT_POINT; \
            result.type_pool.float_point = (long double) value; \
            result; \
        }), \
        \
        string: ({ \
            var result; \
            result.selected_type = STRING; \
            result; \
        }), \
        default: ({ \
            var result; \
            result.selected_type = POINTER; \
            result; \
        }) \
    )

#endif