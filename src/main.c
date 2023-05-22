// main.c

#ifndef MAIN_C
    #define MAIN_C

    #include "c_ease/variable.h"
    #include "c_ease/in_out.h"
    #include "c_ease/list.h"
    #include "c_ease/loop.h"

    int main() {
        List list = List_new();

        for_range(index, 0, 3) {
            print("Insert a number: ");
            List_append(list, to_float(input()));
        }   
        line("Your list is: ", List_to_string(list));

        List_cleanup(list);
        return 0;
    }

#endif