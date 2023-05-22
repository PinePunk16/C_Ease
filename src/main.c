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
            float current = float_input();
            List_append_float_point(&list, current);
            if(IS_LONG_DOUBLE(current)) line(current);
        }
        line(List_to_string(list));

        List_cleanup(list);
        return 0;
    }

#endif