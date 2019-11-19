#include <iostream>
// The BigThree is mainly implemented for memory leaks, RAII , performance, better understanding of the work
// Defaults do not work 
class IntCell{
    public:
        // an object invokes this function
        explicit IntCell(int initialValue = 10 ){
            // Dynamic allocation of member variable
            storedValue = new int(initialValue);
        }

        // read only value
        int read() const{
            return *storedValue;
        }


        void write(int x){
            *storedValue = x;
        }
        IntCell (const IntCell & rhs){
            storedValue = new int(*rhs.storedValue);
        }
        ~IntCell(){
            delete storedValue;
        }
        // returns address of the cloned object 
        const IntCell& operator =  (const IntCell & rhs){
            if(this != &rhs)
                *storedValue = *rhs.storedValue;
            // A separate block of memory will be allocated
            // Is Memory reclaimed for the cloned object ????
            return *this;
        }
    private:
        int *storedValue;


};

int main(){
    IntCell a;
    std::cout <<  "\t" << &a << std::endl; 
    IntCell b = a;
    IntCell c;
    c = b;
    std::cout << &b << "\t" << &c << std::endl;
    std::cout << a.read() << "\t" << b.read() << "\t" << c.read() << std::endl;
    return 0;
}