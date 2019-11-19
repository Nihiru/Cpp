#include <iostream>
#include <stdexcept>
int difference(int *array, int n, int m){
    //std::cout << "Function call: success" << std::endl;
    int i,j;
    int temp;
    int diff =0,max =0, min =0;
    for(i=0;i<n-1;i++)
    {
        //std::cout << "inside first loop";
        for(j=0;j<n-i-1;j++){
            //std::cout <<" Inside second loop : success" << std::endl;
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    int sub_value;
    //std::cout <<"Swapping operation: Success" << std::endl;
    std::cout << "N: " << n << "\t"<< "M :"<< m << std::endl;
    if(n > m)
        sub_value = n -m;
    else 
        throw std::out_of_range("Invlaid operation");
    for(i=0;i<sub_value;i++){
        min += array[i];

    }
    for(i=1;i<=sub_value;i++){
        max += array[i];
    }
    std::cout << "max: " << max << "\t"<< "min :"<<min << std::endl;
    return max - min;
}
int main(){
    int *p;
    int test_case, N,M;
    int ret_Value;
    std::cin >> test_case;
    std::cin >> N >> M;
    p = new int[N];
    for(int i=0 ;i<N ;i++){
        std::cin >>p[i];
    }
    //std::cout << "Reading Value: Success" << std::endl;
    try
    {
         ret_Value = difference(p,N,M);
    }
    catch(const std::out_of_range& oor)
    {
        std::cerr << "Out of range error: " <<oor.what()  << '\n';
    }
    
   
    //std::cout << "After perfoming operation: Success"<< std::endl;
    for(int i=0;i<N;i++){
        std::cout << p[i] << "\t";
    }
    std::cout << "Difference between Max sum of an array and minimum sum of an array:" << ret_Value << std::endl;
    delete [] p;
    return 0;
}