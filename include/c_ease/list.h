// list.h

#ifndef LIST_H
    #define LIST_H
    
    #include <stdlib.h>
    #include <string.h>

    #include "variable.h"
    #include "in_out.h"


    
    typedef struct {
        variable* value;
        size_t size;
    } List;

    List List_new() {
        List this;
        this.value = NULL;
        this.size = 0;
        return this;
    }

    void List_append_variable(List* this, const variable value) {
        (this -> size)++;

        if(this -> value == NULL) this -> value = malloc((this -> size) * sizeof(variable));
        else this -> value = realloc(this -> value, (this -> size) * sizeof(variable));

        if(this -> value == NULL) exit(1); //TBU

        (this -> value)[(this -> size) - 1] = value;
    }
    #define List_append(this,value)         List_append_variable(&this, auto(value))

    char* List_to_string(List this) {
        char buffer[64] = "[";  // Size to be made variable
        for(size_t index = 0; index < this.size; index++) {
            switch(this.value[index].selected_type) {
                case INTEGER:
                    strcat(buffer, to_string(this.value[index].type_pool.integer));
                    break;
                case UNSIGNED_INTEGER:
                    strcat(buffer, to_string(this.value[index].type_pool.unsigned_integer));
                    break;
                case FLOAT_POINT:
                    strcat(buffer, to_string(this.value[index].type_pool.float_point));
                    break;
                case STRING:
                    strcat(buffer, to_string(this.value[index].type_pool.string));
                    break;
                case POINTER:
                    strcat(buffer, to_string(this.value[index].type_pool.pointer));
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