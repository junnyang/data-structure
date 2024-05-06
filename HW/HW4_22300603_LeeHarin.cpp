#include <iostream>
#include <string>
using namespace std;


#define YES true
#define NO false


bool check(string pl, int fro , int rear)
{
    if(fro >= rear)
        return true;
    if(pl[fro] != pl[rear])
        return false;

    return(check(pl, fro+1, rear-1));
}
int main()

{

        string  input;

        int len; 

        cout << "Input a string : ";

        cin >> input; 

        len = input.size(); 

        if ( check(input, 0, len-1) == YES)

                cout << " Yes, it is a palindrome. \n";

        else

                cout << " No, it is not a palindrome. \n";

         return 0;

}