// list.h

#ifndef LIST_H
    #define LIST_H
    
    #include <stdlib.h>
    #include <string.h>

    #include "generic.h"
    #include "inout.h"


    
    typedef struct {
        generic* value;
        size_t size;
    } List;

    List List_new() {
        List this;
        this.value = NULL;
        this.size = 0;
        return this;
    }

    void List_append_integer(List* this, const long long value) {
        (this -> size)++;

        if(this -> value == NULL) this -> value = malloc((this -> size) * sizeof(generic));
        else this -> value = realloc(this -> value, (this -> size) * sizeof(generic));

        if(this -> value == NULL) exit(1); //TBU

        (this -> value)[(this -> size) - 1].selected_type = INTEGER;
        (this -> value)[(this -> size) - 1].integer = value;
    }
    void List_append_unsigned_integer(List* this, const unsigned long long value) {
        (this -> size)++;

        if(this -> value == NULL) this -> value = malloc((this -> size) * sizeof(generic));
        else this -> value = realloc(this -> value, (this -> size) * sizeof(generic));

        if(this -> value == NULL) exit(1); //TBU

        (this -> value)[(this -> size) - 1].selected_type = UNSIGNED_INTEGER;
        (this -> value)[(this -> size) - 1].unsigned_integer = value;
    }
    void List_append_float_point(List* this, const long double value) {
        (this -> size)++;

        if(this -> value == NULL) this -> value = malloc((this -> size) * sizeof(generic));
        else this -> value = realloc(this -> value, (this -> size) * sizeof(generic));

        if(this -> value == NULL) exit(1); //TBU

        (this -> value)[(this -> size) - 1].selected_type = FLOAT_POINT;
        (this -> value)[(this -> size) - 1].float_point = value;
    }
    // To allocate or reallocate memory before copying string
    void List_append_string(List* this, const char* value) {
        (this -> size)++;

        if(this -> value == NULL) this -> value = malloc((this -> size) * sizeof(generic));
        else this -> value = realloc(this -> value, (this -> size) * sizeof(generic));

        if(this -> value == NULL) exit(1); //TBU

        (this -> value)[(this -> size) - 1].selected_type = STRING;
        strcpy((this -> value)[(this -> size) - 1].string, value);
    }
    void List_append_pointer(List* this, void* value) {
        (this -> size)++;

        if(this -> value == NULL) this -> value = malloc((this -> size) * sizeof(generic));
        else this -> value = realloc(this -> value, (this -> size) * sizeof(generic));

        if(this -> value == NULL) exit(1); //TBU

        (this -> value)[(this -> size) - 1].selected_type = POINTER;
        (this -> value)[(this -> size) - 1].pointer = value;
    }

    // This still doesn't work
    #define List_append(this,value)         _Generic((value), \
        char:                                   List_append_integer(this, (long long) value), \
        signed char:                            List_append_integer(this, (long long) value), \
        unsigned char:                          List_append_unsigned_integer(this, (unsigned long long) value), \
        \
        short:                                  List_append_integer(this, (long long) value), \
        unsigned short:                         List_append_unsigned_integer(this, (unsigned long long) value), \
        \
        int:                                    List_append_integer(this, (long long) value), \
        unsigned int:                           List_append_unsigned_integer(this, (unsigned long long) value), \
        \
        long:                                   List_append_integer(this, (long long) value), \
        unsigned long:                          List_append_unsigned_integer(this, (unsigned long long) value), \
        \
        long long:                              List_append_integer(this, (long long) value), \
        unsigned long long:                     List_append_unsigned_integer(this, (unsigned long long) value), \
        \
        float:                                  List_append_float_point(this, (long double) value), \
        double:                                 List_append_float_point(this, (long double) value), \
        long double:                            List_append_float_point(this, (long double) value), \
        \
        char*:                                  List_append_string(this, (char*) value), \
        default:                                List_append_pointer(this, (void*) value) \
    )

    char* List_to_string(List this) {
        char buffer[64] = "[";  // Size to be made variable
        for(size_t index = 0; index < this.size; index++) {
            switch(this.value[index].selected_type) {
                case INTEGER:
                    strcat(buffer, to_string(this.value[index].integer));
                    break;
                case UNSIGNED_INTEGER:
                    strcat(buffer, to_string(this.value[index].unsigned_integer));
                    break;
                case FLOAT_POINT:
                    strcat(buffer, to_string(this.value[index].float_point));
                    break;
                case STRING:
                    strcat(buffer, to_string(this.value[index].string));
                    break;
                case POINTER:
                    strcat(buffer, to_string(this.value[index].pointer));
                    break;
                default:
                    strcat(buffer, "???");
            }
            strcat(buffer, ", ");
        }
        buffer[strlen(buffer) - 2] = '\0';
        strcat(buffer, "]");
        return strdup(buffer);
    }

    List List_cleanup(List this) {
        if(this.value != NULL) free(this.value);
        this.size = 0;
    }

#endif