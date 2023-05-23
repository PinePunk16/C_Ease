// class.h

#ifndef CLASS_H
    #define CLASS_H

    // constructor must be declaired before other functions.
    // parameter must be between class begin and constructor.

    #define class                           typedef struct {

    #define child_class(parent)             typedef struct { \
                                                parent super;
                                            
    #define constructor(name,...)           } name; \
                                            name name##_new(__VA_ARGS__)

    #define start(...)                      int main(__VA_ARGS__)
#endif
