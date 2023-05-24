// main.c

#ifndef MAIN_C
    #define MAIN_C

    #include "c_ease/in_out.h"
    #include "c_ease/list.h"
    #include "c_ease/loop.h"
    #include "c_ease/variable.h"

    start() {
        List list = List_new();

        for_range(index, 0, 10) List_append(list, index);

        line("Your list is: ", List_to_string(list));

        List_cleanup(list);
        return 0;
    }

#endif