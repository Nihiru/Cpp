#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;
        try{
            
            Server::compute(A,B);
        }
        catch(bad_alloc &ex){
            cout << "Not enough memory"<<std::endl;
        }
        catch(invalid_argument &in){
            cout << "Exception: A is negative"<<std::endl;
        }
        catch(...){
            cout << "Other Exception"<<std::endl;
        }

	}
	cout << Server::getLoad() << endl;
	return 0;
}