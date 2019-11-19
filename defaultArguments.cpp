//https://en.cppreference.com/w/cpp/language/default_arguments
class C{
    int a;
    static int b;
    int mem(int g = a); // error : Invalid use of non-static member
    int static_mem(int h = b); // OK : Use of static member
    void f(int i = 10);
    void g(int i, int j = 99);
    void h(int i = 10, int j);
    C(int arg);
};
void C::f(int i = 3){} // error due to redeclaring default parameter
void C::g(int i =  10, int j){} // OK 
void C::h(int u, int h =20){} // error : all parameters that follow default arguments should
                              // have a default argument supplied in this or a previous declaration from the same scope
void C::C(int arg = 20){} // error : turns this into default constructor
//int C::mem(int a){};

int f(int = 0);
void h() {
  int j = f(1);
  int k = f();  // calls f(0);
}
int (*p1)(int) = &f;
int (*p2)()    = &f; // error : the type of f in int(int)   