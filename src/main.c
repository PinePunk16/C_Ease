// main.c

#ifndef MAIN_C
    #define MAIN_C

    #include "c_ease/variable.h"
    #include "c_ease/in_out.h"
    #include "c_ease/list.h"

    int main() {
        List list = List_new();

        for(size_t index = 0; index < 3; index++) {
            print("Insert a number: ");
            List_append(list, float_input());
        }   
        line(join("Your list is: ", List_to_string(list)));

        List_cleanup(list);
        return 0;
    }

#endif