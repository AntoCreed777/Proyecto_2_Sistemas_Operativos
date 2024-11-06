#include <iostream>
#include "cola.h"

int main() {
    Cola<int> cola({2,3,1,4,1,4});
    cola.push(3);
    cola.pop();

    while (cola.size()){
        std::cout << cola.pop() << std::endl;
        
    }


    return 0;
}
