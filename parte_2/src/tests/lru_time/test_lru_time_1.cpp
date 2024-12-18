#include <iostream>

#include "../../../include/lru_time.h"

int main(){
    LRU_TIME lru_time(3);

    lru_time.push(1);
    lru_time.push(2);
    lru_time.push(1);
    lru_time.push(3);
    lru_time.push(4);
    lru_time.push(2);
    lru_time.push(5);

    std::cout << "Hits: " << lru_time.getHits() << std::endl;
    std::cout << "Misses: " << lru_time.getMisses() << std::endl;

    /*
    Hits: 2
    Misses: 5
    */

    return 0;
}