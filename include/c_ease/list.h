// list.h

#ifndef LIST_H
    #define LIST_H
    
    #include <stdlib.h>
    #include <string.h>

    #include "variable.h"
    #include "in_out.h"
    #include "loop.h"

    
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
        size_t buffer_size = 2;
        char* buffer = malloc(buffer_size * sizeof(char));
        if(buffer == NULL) exit(1);     // TBU

        strcpy(buffer, "[");

        for_range(index, 0, this.size) {
            if(this.value[index].selected_type == STRING) {
                buffer_size += strlen(this.value[index].type_pool.string);
                buffer = realloc(buffer, buffer_size * sizeof(char));
                strcat(buffer, this.value[index].type_pool.string);
            } else {
                buffer_size += 64;      // TBU
                buffer = realloc(buffer, buffer_size * sizeof(char));
                if(buffer == NULL) exit(1);     // TBU
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
                        break;
                    case POINTER:
                        strcat(buffer, to_string(this.value[index].type_pool.pointer));
                        break;
                    default:
                        strcat(buffer, "???");
                }
            }
            buffer_size += 3;
            buffer = realloc(buffer, buffer_size * sizeof(char));
            if(buffer == NULL) exit(1);     // TBU
            strcat(buffer, ", ");
        }
        buffer[strlen(buffer) - 2] = '\0';
        strcat(buffer, "]");

        char result[strlen(buffer) + 1];
        strcpy(result, buffer);
        free(buffer);
        return strdup(result);
    }

    List List_cleanup(List this) {
        for_range(index, 0, this.size) {
            switch(this.value[index].selected_type) {
                case STRING:
                    if(this.value[index].type_pool.string != NULL) free(this.value[index].type_pool.string);
                    break;
                case POINTER:
                    if(this.value[index].type_pool.pointer != NULL) free(this.value[index].type_pool.pointer);
                    break;
            }
        }
        if(this.value != NULL) free(this.value);
        this.size = 0;
    }

#endif