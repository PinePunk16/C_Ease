// main.c

#ifndef MAIN_C
    #define MAIN_C

    #include "c_ease.h"



    start() {
        List list = List_new();

        string a;
        a = "John";
        string b = a;
        line(b, a);

        a = "Hi";
        line(b, a);

        for_range(index, 0, 10) List_append(list, index);

        line("Your list is: ", List_to_string(list), "!!");

        List_cleanup(list);
        return 0;
    }

#endif