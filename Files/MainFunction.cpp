#include <iostream>
#include "IntCell.h"

int main(){
    IntCell in (345);
    std::cout << in.read() << std::endl;
    in.write(20);
    std::cout << in.read() << std::endl;
    return 0;
}