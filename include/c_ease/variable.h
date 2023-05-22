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
        long long integer;
        unsigned long long unsigned_integer;
        long double float_point;
        char* string;
        void* pointer;

        type selected_type;
    } variable;

    #define IS_FLOAT(value)                 _Generic((value), float: true,          default: false)
    #define IS_DOUBLE(value)                _Generic((value), double: true,         default: false)
    #define IS_LONG_DOUBLE(value)           _Generic((value), long double: true,    default: false)

    #define IS_FLOAT_POINT(value)           (IS_FLOAT(value) || IS_DOUBLE(value) || IS_LONG_DOUBLE(value))

    #define IS_CHAR(value)                  _Generic((value), char: true,           default: false)
    #define IS_SIGNED_CHAR(value)           _Generic((value), signed char: true,    default: false)
    #define IS_SHORT(value)                 _Generic((value), short: true,          default: false)
    #define IS_INT(value)                   _Generic((value), int: true,            default: false)
    #define IS_LONG(value)                  _Generic((value), long: true,           default: false)
    #define IS_LONG_LONG(value)             _Generic((value), long long: true,      default: false)

    #define IS_SIGNED_INTEGER(value)        (IS_CHAR(value) || IS_SIGNED_CHAR(value) || IS_SHORT(value) || IS_INT(value) || IS_LONG(value) || IS_LONG_LONG(value))

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

    #define auto_DEBUG(value)       ( \
        (IS_FLOAT_POINT(value))? ({ \
            variable result; \
            result.selected_type = FLOAT_POINT; \
            result.float_point = (long double) value; \
            result; \
        }): \
        ({ \
            variable result; \
            result.selected_type = POINTER; \
            result.pointer = (void*) value; \
            result; \
        }) \
    )

#endif