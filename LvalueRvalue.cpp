/*
 * Meaning:
 *      C: 
 *         An lvalue is an expression e that may appear on the left or on the right hand side of an assignment
 *         An rvalue is an expression that can only appear on the right hand side of an assignment
 *  
 *      C++:
 *          An lvalue is an expression that refers to a memory location and allows us to take the address of 
 *          that memory location via the & operator.
 *          An rvalue is an expression that is not an lvalue. 
 *          Ex:
 *             int i = 43;
 *             int *p = &i; // here i is an lvalue
 * 
*/
#include <iostream>

std::string global = "World";

/**
 * When T is an object type and you evaluate a function that has return type T, 
 * you get a value of type T which is an rvalue. On the other hand, 
 * if the function has return type T &, you get a value of type T 
 * which is an lvalue (and the value is the thing bound to the reference in the return statement).
 * */

int & setValue(){
    
    static int x = 10; // x value is changed via the reference returned by the function
    return x;
}
int RtoLConversion(){
    int y ;
    // & should point to an existing object
    static int &yref = y; // will work !!!

    //int *pref = &y = 340; // will not work !!!
    /* It does not have specific memory address. A forbidden conversion from rvalue to lvalue
    A volatile numeric constant (rvalue) should become an lvalue in order to be referenced to.
    what would the reference point to once the numeric value is gone?
    */
    //int &xref = 10; will not work !!!.
    
    // Workaround
    /**
     * Bind a const lvalue to rvalue 
     * Under the hood the compiler creates an hidden variable for you (i.e. an lvalue) where to store the original literal constant, and then bounds that hidden variable to your reference.    
    */
   const int &xref = 10; // will work
    yref++;
    
    return yref;
}
void valueReference(){
    /** rvalue reference is created using a double ampersand whereas lvalue reference is created using single ampersand
     * 
     *  |---------------------------------------------------------------------- |
     *  |L-value reference	 |   Can be initialized with	  |     Can modify  |
     *  |---------------------------------------------------------------------- |
        |Modifiable l-values |    Yes                         |      Yes        |
        |Non-modifiable      |    No	                      |      No         |
        |R-values	         |    No	                      |      No         |
     *  -------------------------------------------------------------------------
     * 
     * L-value references to cosnt objects can be initialized with l-values and r-values alike. 
     * However, those vlaues can't be modified
     *  
     *  |------------------------------------------------------------------------------ |
     *  |L-value reference to const	 |   Can be initialized with	  |     Can modify  |
     *  |------------------------------------------------------------------------------ |
        |Modifiable l-values         |    Yes                         |      Yes        |
        |Non-modifiable              |    No	                      |      No         |
        |R-values	                 |    No	                      |      No         |
     * ----------------------------------------------------------------------------------
     * 
     * 
     * 
     * 
     * 
        */
       int x =5;
       int &lref =x; // l-value refernce initialized with l-value x
       int &&rref =5 // r-value refernce initialized with r-value 5
    /**
     *  |---------------------------------------------------------------------- |
     *  |R-value reference	 |   Can be initialized with	  |     Can modify  |
     *  |---------------------------------------------------------------------- |
        |Modifiable l-values |    No                          |      No         |
        |Non-modifiable      |    No	                      |      No         |
        |R-values	         |    Yes	                      |      Yes        |
     *  -------------------------------------------------------------------------
     * 
     * L-value references to cosnt objects can be initialized with l-values and r-values alike. 
     * However, those vlaues can't be modified
     *  
     *  |------------------------------------------------------------------------------ |
     *  |L-value reference to const	 |   Can be initialized with	  |     Can modify  |
     *  |------------------------------------------------------------------------------ |
        |Modifiable l-values         |    No                          |      No         |
        |Non-modifiable              |    No	                      |      No         |
        |R-values	                 |    Yes                        |      No         |
     * ----------------------------------------------------------------------------------
     * 
     * R-values references cannot be initialized with l-values.
     * 
     * 
     */
}
int main(){

    /**
     * Function gets called
     * Assignment operation takes place
     * 
    */
    setValue() = 40;
    std::cout << setValue() << std::endl; //<< std::endl << RtoLConversion << std::endl; 
    return 0;
}