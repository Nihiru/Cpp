#include <iostream>
#include <cstring>
#define MAX 10

/**
 * Implementing a stack 
 * 1) Overloading [] operator for boundary checking
 * 
 */
// class STACK{
//     private:
//         int stackArray[MAX];
//         int top,last;
//     public:
//         STACK();
//         void push(int ele);
//         void pop();
//         void display();
//        // STACK operator[](int ele);
// };
// STACK :: STACK(){
//     memset(stackArray,0,MAX* sizeof(int));
//     top = -1;
//     last = -1;
// }
// void STACK :: push(int element){
//     if(this->stackArray == NULL){
//         std::cout << "Accessing reference object caused error: " << std::endl;
//         return ;
//     }
//     else{
//         top++;
//         if((this->top) * sizeof(int) == MAX* sizeof(int)){
//             std::cout << "Stack overflow occurred " << std::endl;
//             return ;
//         }
//         else{
//         this->stackArray[top] = element;
//         }
//     }
// }

// void STACK :: pop(){
    
//     int removedItem = 0 ;
//     if(this->stackArray == NULL){
//         std::cout << "Accessing reference object caused error: " << std::endl;
//         return ;
//     }

//     if(top == -1){
//         std::cout << "Stack underflow occurred " << std::endl;
//         return ;
//     }
//     else{
//        removedItem =  this->stackArray[top--];
//     }
//     std::cout << "Deleted Item :" << removedItem << std::endl;
// }

// void STACK :: display(){
//     if(this->stackArray == NULL){
//         std::cout << "Error while accessing referenced object " << std::endl;
//         return;
//     }

//     if(top == -1){
//         std::cout << "Nothing to display :" << std::endl;
//         return;
//     }
//     else{
//         for(int i=top ;i>=0 ; i--)
//             std::cout << this->stackArray[i] << "\t" ;
//     }
//     std::cout << std::endl;
// }
// // STACK STACK::operator[](int i){
// //     if(i > MAX)
// //         std::cout << " Array has reached maximum limit :" << std::endl;
// //     else
// //         return this->stackArray[i];  
// // }
// int main(){
//     STACK s;
//     int val;
//     s.display();
//     for(int i = 0 ;i< 10; i++){
//         std::cin >> val;
//         s.push(val);
//     }
//     s.display();
//     s.push(20);
//     s.pop();
//     s.display();
//     s.pop();
//     return 0;
// }
/**
 * Foo& operator [] (int i) 
{
    if (i < 0 || i > MAX_SIZE)
        cout << "Array out of bounds!\n";
    else 
        return Foo[i]; 
}

Foo operator [] (int i) const
{
    if (i < 0 || i > MAX_SIZE)
        cout << "Array out of bounds!\n";
    else 
        return Foo[i]; 
}
 */
/**
 * Implementing stack through linked list
 */
class STACK{
    public:
        int data;
        STACK *next;
        int top;
        STACK();
        STACK * newNode(int);
        void push(int element);
        int pop();
        void display();
};
STACK :: STACK(){
    this->data =  0;
    this->next = NULL;
    this->top = -1;
}
STACK* STACK :: newNode(int element){
    STACK *tempNode;
    tempNode->data = element;
    tempNode->next = NULL;
    return tempNode;
}
void STACK :: push(int element){
    STACK *newNode = newNode(element);
    if(this->top == -1)
        top++;
    else{ 
        this->next = newNode;
        this = newNode;
    }
    
}

int STACK :: pop(){
    if(this->top == -1)
        std::cout << "Stack Underflow " << std::endl;
    else
    {
        /* code */
    }
    
    return 0;
}

int main(){
    STACK s;

    return 0;
}