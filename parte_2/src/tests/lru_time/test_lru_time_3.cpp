#include <iostream>

#include "../../../include/lru_time.h"

int main(){
    LRU_TIME lru_time(3);

    lru_time.push(1);
    lru_time.push(2);
    lru_time.push(3);
    lru_time.push(4);
    lru_time.push(5);
    lru_time.push(6);
    lru_time.push(7);
    lru_time.push(8);
    lru_time.push(9);
    lru_time.push(10);

    std::cout << "Hits: " << lru_time.getHits() << std::endl;
    std::cout << "Misses: " << lru_time.getMisses() << std::endl;

    return 0;
}