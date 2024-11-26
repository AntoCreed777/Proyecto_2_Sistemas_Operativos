#include <iostream>

#include "../../../include/lru_time.h"

int main(){
    LRU_TIME lru_time(3);

    lru_time.push(1);
    lru_time.push(1);
    lru_time.push(1);
    lru_time.push(1);
    lru_time.push(1);
    lru_time.push(1);
    lru_time.push(1);

    std::cout << "Hits: " << lru_time.getHits() << std::endl;
    std::cout << "Misses: " << lru_time.getMisses() << std::endl;

    /*
    Hits: 6
    Misses: 1
    */

    return 0;
}