#include <iostream>
class copyConstructor{
    int storedValue;

    public:
        copyConstructor(const copyConstructor & rhs) : storedValue(rhs.storedValue){
            std::cout << " Inside  Constructor " << std::endl;
        }

        ~copyConstructor(){
            std::cout << " Destructor Callled" << std::endl;
        }

        const copyConstructor & copyConstructor:: operator = (const copyConstructor & rhs){
            // This checking is to make sure that current object is not being altered
            /** Real time example : consider a program that copies one file to another. A normal algorithm 
             *                      begins by truncating the target file to zero length. If no check is 
             *                      performed to verify that the source and target file are indeed different,
             *                      then the source file will be truncated 
             * This is knwon as aliasing.
             */                       

            std::cout << " Indside Conversion Constructor " << std::endl;
            if(this != &rhs)
                storedValue = rhs.storedValue;
            // *this is effectively used in chain function calls
            // when function returns a *this it actually clones the current object and returns
            return *this;
        }

};
int main(){

    return 0;
}