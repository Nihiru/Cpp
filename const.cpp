#include <iostream>
// const function parameters and return type
// const int func(){
//     return 10;
// }
// int main(){
//     int q = 10;
//     int s = 20;
//     // Read only property set due to the const variable present at the beginning of the variable declaration
//     // const int *p = &q;
//     // *p+=10;
//     // std::cout << "value of q " << q << std::endl;

//     //  Read only property set due to the const declared after the int* 
//     //  1) Address of the pointer cannot be changed
//     //  2) Tracing:
//     //     1) A value will be assigned to a const variable.
//     //     2) Data cannot be changed. Since its a pointer the value is itself an address.

//     int * const t = &s;
//     *t += 20;
//     t = &q;
//     std::cout << "value at t  " << *t << std::endl;
//     // int a  = func();
//     // std::cout << a << std::endl;
//     return 0;
// }
// For built-in types, it doesn’t matter whether you return by value as a const, 
// so you should avoid confusing the client programmer and leave off the const when 
// returning a built-in type by value.


/**
 * Const:
 * 1) const can be specified to class objects
 * 2) const class objects can only explicitly call const member functions
 * 3) Any const member function that attempts to change a member variable or call a non-const member function 
 *    will cause a compiler error
 * 4) Constructors cannot be marked as const. This is because constructors need to be able to initalize their 
 *    member variables, and a const constructor would not be able to do so.
 * 5) Overloading const and non-const member funtions
 */
class constClass{
    private:
        int i_value;
        std::string s_value;
    public:
        // 4
        constClass() const:i_value(10){}
        void setValue(int);
        // 2 
        int  getValue() const;
        // 5
        const std::string& getString() const{
            return s_value;
        }
        std::string& getString{
            return s_value;
        }

};
// 3
void constClass :: setValue(int passedValue){
    i_value = passedValue;
}
int constClass :: getValue() const{
    return i_value;
}
int main(){
    // 1
    const constClass cc;
    // 2
    std::cout << cc.getValue();
    // 3
    // cc.setValue(20);
    std::cout << std::endl;
    return 0;
}