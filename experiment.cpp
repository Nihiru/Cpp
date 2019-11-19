#include <iostream>

// class A{
//     public:
//     A(){
//         std::cout << " Constructor A called " << std::endl;
//     }
// };

// class B{
//         public:
//         B(const B&){
//             std::cout  << " Constructor B with B const called " << std::endl;
//         }
    
//         B(){
//             std::cout << " Constructor Called " << std::endl;
//         }
//         B(const A&){
//             std::cout << " Constructor B  with A const called " << std::endl;
//         }

// };

// int main(){
//     A a;
//     B b1(a);
//     B b2 = a;
//     return 0;
// }
void foo(int, int);
void foo(int o =100);
void foo(int , int k =010);
//void foo(int l =100);
int funct(){
    std::cout << "Inside Function " << std::endl;
}

int main(){
    //std::cout << "Hello world" << std::endl;
    //int x = 10;
    //int *p  = &(x+2);
    //const int & refValue = 10;

    //const int pValue ;
    //std::cout << "Value at p" << *p << std::endl;
    // int valueChange = 20;
    // refValue = valueChange;
    // std::cout << "Value at p" << refValue << std::endl;
    

    //    funct();
}