#include <iostream>
#include <string>
using namespace std;

string reverse(string re){
    if(re == "")
        return "";
    
    return(reverse(re.substr(1))) + re[0];
}

int main()

{

        string  input, r_input;

        cout << "Input a string : ";

        cin >> input; 

        r_input = reverse(input); 

        cout << r_input << endl;

        return 0; 

}