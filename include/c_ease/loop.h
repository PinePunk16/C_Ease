// loop.h

#ifndef LOOP_H
    #define LOOP_H

    // Inverted start and end don't work yet
    #define for_range(index,start,end)      for(long long index = start; ((start < end)? index < end : index > end); index += ((start < end)? 1 : index -1))

#endif