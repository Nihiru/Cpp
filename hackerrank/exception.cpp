#include <iostream>
#include <stdexcept>

class Server{
    private:
            static int load;
    public:
            static int getLoad(){
                return load;
            }
            static void StaticMemberFunc(){
                load += 1;
            }
            void  NonStaticMemberFunc(){
                StaticMemberFunc();
            }
};
// Static variables needs to be defined outside the class. Else, it would cause undefined reference

int Server::load = 0;

int main(){
    Server s;
    std::cout << s.getLoad() << std::endl;
    s.StaticMemberFunc();
    s.NonStaticMemberFunc();
    std::cout << s.getLoad() << std::endl;
    return 0;
}