// main.c

#ifndef MAIN_C
    #define MAIN_C

    #include "c_ease.h"



    start() {
        List list = List_new();

        string test[3];
        test[0] = "Hello ";
        test[1] = "world ";
        test[2] = "lol.";
        for_range(index, 0, 3) print(test[index]);
        line();
        test[0] = test[1];
        test[1] = "wide ";
        for_range(index, 0, 3) print(test[index]);
        line();
        test[0] = join(test[0], test[1]);
        line(join(test[0], test[2]));

        for_range(index, 0, 10) List_append(list, index);

        line("Your list is: ", List_to_string(list), "!!");

        List_cleanup(list);
        return 0;
    }

#endif