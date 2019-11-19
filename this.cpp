#include <iostream>

class Foo
{
    public:
        Foo()
        {
            this->value = 0;
        }
        // returns a clone of the object
        Foo get_copy()
        {
            return *this;
        }

        Foo get_cpy()
        {
            return this;
        }

        // using reference as return-type
        Foo& get_copy_as_reference()
        {
            return *this;
        }

        Foo& get_cpy_as_reference()
        {
            return this;
        }

        // using pointers as return-type
        Foo* get_pointer()
        {
            return this;
        }

        void increment()
        {
            this->value++;
        }

        void print_value()
        {
            std::cout << this->value << std::endl;
        }

    private:
        int value;
};

int main()
{
    Foo foo;
    foo.increment();
    foo.print_value();

    // Creates an anonymous object
    foo.get_copy().increment();
    foo.print_value();
    
    //
    foo.get_copy_as_reference().increment();
    foo.print_value();

    // Object call and returning a pointer to the current object 
    foo.get_pointer()->increment();
    foo.print_value();

    return 0;
}