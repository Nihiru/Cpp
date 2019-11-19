#include <iostream>
#include "IntCell.h"

IntCell:: IntCell(int initialValue = 0) : storedValue(initialValue){

}

int IntCell :: read() const {
     return storedValue;
}

void IntCell :: write(int x){
    storedValue = x;
}
