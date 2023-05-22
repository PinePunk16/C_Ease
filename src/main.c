// main.c

#ifndef MAIN_C
    #define MAIN_C

    #include "c_ease/inout.h"
    #include "c_ease/list.h"



    int main() {
        List list = List_new();

        for(size_t index = 0; index < 3; index++) {
            print("Insert a number: ");
            long double current = float_input();
            line(current);
            
            List_append(&list, current);
        }
        line(List_to_string(list));

        List_cleanup(list);
        return 0;
    }

#endif