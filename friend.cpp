#include <iostream>
// Forward declaration so that compiler knows this while parsing
class Storage;
// Moving this class forward to make a friend of member function of this class
class Display{
    private:
        bool m_displayIntFirst;
    public:
        Display(bool displayIntFirst):m_displayIntFirst(displayIntFirst){}
        void displayItem(const Storage& storage);
};
class Storage{
    private:
        int m_nValue;
        double m_dValue;
    public:
        Storage():m_nValue(0),m_dValue(0.0){
            
        }
        Storage(int nValue, double dValue){
            m_nValue =nValue;
            m_dValue =dValue;
        }
    /**
     * Non-member function call
     */
    friend void rest (Storage &st);

    /**
     * Friend Class:
     * 1) Class Accumulator will be able to access all the private members of Storage class
     * 2) Tranisitve property cannot be applied
     *  */ 
    friend class Accumulator; // without this call to reset will throw an error

    /**
     * Friend member functions
     * 1) Making a single member function to access private member variables of storage class
     * 2) In order to make a member function a friend, the compiler has to have seen the 
     *    definition for the class of the friend member function. Since class Storage hasn’t seen the full 
     *    definition for class Display yet, the compiler will error at the point where we try to make the 
     *    member function a friend.
     */
    friend void Display::displayItem(const Storage &st);
};
// This is needed as the compiler will not recognize Storage
void Display::displayItem(const Storage& storage){
            if(m_displayIntFirst){
                std::cout << storage.m_nValue << "" << storage.m_dValue << "\n";
            }else{
                std::cout << storage.m_dValue << "" << storage.m_nValue << "\n" ;
            }
}
class Accumulator{
    private:
        int m_value;
    public:
        Accumulator(){
            m_value = 0;
        }
        void add(int value){
            m_value += value;
        }
        //Accessing a Private member variable of Storage class
        void reset(Storage &st){
            std::cout << st.m_dValue << std::endl; 
        }
};
// non-member function that access 
void rest(Storage &st){
    std::cout << st.m_dValue << "\t"  << st.m_nValue;
}

int main(){
    Storage st;
    Storage store(20,40.00);
    Accumulator ac;
    Display d(false);
    Display dd(true);

    ac.reset(st);
    rest(st);

    d.displayItem(st);
    dd.displayItem(store);
    
    return 0;
}