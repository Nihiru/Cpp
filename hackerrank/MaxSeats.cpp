#include <iostream>

int main(){
    std::string  s,d ;
    char c;
    int no_of_rows, max =1, count =1, cp=0, j=0;
    std::cin >> no_of_rows;
    for(int i=0 ; i< no_of_rows;i++){
        std::getline(std::cin,d);
        s+=d;
    }
    std::cout << "Original String : " << s<<std::endl;
    for(int i=0;i<s.length();i++){
        count =0;
        // retrieve length of consecutive characters
        if(s[i] == s[i+1]){
            count++;continue;
        }
        // Condition only for checking the consecutive characters based on the read consecutive characters
        if(s[i] != s[i+1]){ 
            cp = i+1;
            j =cp;
            if(s[cp] != s[cp + count]){
                while(j< cp+count){
                    if(s[j] == s[j+ 1])
                        j++;
                }

            }
            // since the consecutive readings are same 
            max = count + count;
        }
    }
    std::cout << max << std::endl;
    return 0;
}