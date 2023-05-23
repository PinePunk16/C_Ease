// main.c

#ifndef MAIN_C
    #define MAIN_C

    #include "c_ease/class.h"
    #include "c_ease/in_out.h"
    #include "c_ease/list.h"
    #include "c_ease/loop.h"
    #include "c_ease/variable.h"

    class
        char name[32]
        constructor(Person, char name[]) { 
            Person this;
            strcpy(this.name, name);
            return this;
        }
        void Person_show(Person this) {
            line(this.name);
        }
    
    start() {
        Person person = Person_new("John");
        Person_show(person);

        List list = List_new();         // This is not a class yet, don't get confused.

        for_range(index, 0, 10) List_append(list, index);

        line("Your list is: ", List_to_string(list));

        List_cleanup(list);
        return 0;
    }

#endif