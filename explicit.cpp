#include <iostream>
//https://www.geeksforgeeks.org/g-fact-93/
//https://en.cppreference.com/w/cpp/language/explicit

class  explicitConstructor{
    int storedValue; 
    public:
        // Initializer list
        /* 1) Initializer lists are used instead of assignment statement in the body. When data members are class types 
              initialization is costly
           2) If a data member is const i.e, it cannot be changed after the object has been constructed, then the data
              member's value can be initialized only in the initializer list.
        */

       // Explicit
       /* 1) avoid behind the scenes type conversion
        * 2) A temporary object is created when a non-class member is assigned (=) to an object of a classtype
        *    i) One parameter constructore defines an implicit type conversion
        *   ii) Type-mismatch is avoided by using explicit. 
        */
        explicit explicitConstructor(int tempValue): storedValue(tempValue){};
        // Declaring a const after function declaration means it is read-only or called as accessor
        void display() const{
            std::cout << this->storedValue << std::endl;
        }
        bool operator == (duplicateExplicit &tempExp){
            (storedValue == tempExp.read())? true: false;
        }
        bool operator = (duplicateExplicit &tempExp){
            (storedValue = tempExp.read())
        }
        // Manually performing = operation  
        // void check(explicitConstructor tempExp){
        // if(this == tempExp)
        //     std::cout << "same objects" << std::endl;
        // else
        //     std::cout << "Not same " << std::endl;
        // }
        
        // Default destructor for pointers does nothing, operator "delete" is used to free these memories
        explicitConstructor(){
            // 
        } 
};
// trying to compare two different objects which internally has 
class duplicateExplicit{

      int storedValue; 
    public:
        explicit duplicateExplicit(int tempValue): storedValue(tempValue){};
        // Declaring a const after function declaration means it is read-only or called as accessor
        void display() const{
            std::cout << this->storedValue << std::endl;
        }
        int read() const{
            return storedValue;
        }  
};
int main(){
    explicitConstructor exp(37);
    duplicateExplicit exp1(20);
    
    // Checking values of objects of different classes
    if(exp == exp1)
        std::cout << "same objects" << std::endl;
    else
        std::cout << "Not same " << std::endl;
   
    exp.display();
     exp = exp1;
    // exp.check(exp1);
    if(exp == exp1)
        std::cout << "same objects" << std::endl;
    else
        std::cout << "Not same " << std::endl;
    exp.display();

    return 0;
}