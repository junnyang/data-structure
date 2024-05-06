#include <iostream>
#include <string>
using namespace std;

class weight {
public :
    int kg;
    int gram;
    weight();
    void set_weight(int n1, int n2);
    int get_weight();
};

weight::weight()
{
    kg = 0;
    gram = 0;
}

void weight::set_weight(int n1, int n2)
{
    kg = n1;
    gram = n2;
}

int weight::get_weight()
{
    return (kg * 1000) + gram ; 

}

weight add_weight(weight n1, weight n2)
{
    weight t;
    t.kg =  n1.kg + n2.kg;
    t.gram = n1.gram + n2.gram;

    return t;
}

int less_than(weight n1, weight n2)
{
    if(n1.kg < n2.kg)
        return 1;
    else if(n1.kg == n2.kg)
    {
        if(n1.gram < n2.gram)
            return 1;
        return 0;
    }
    return 0;
}

int main( )

{

weight  w1, w2, w3 ;  // weight라는 class object 3개 생성

    w1.set_weight(3, 400);  // w1을 3kg 400 g으로

    w2.set_weight(2, 700);  // w2을 2kg 700 g으로

    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 6kg 100g

    cout << w3.get_weight( ) << "grams\n"; // w3의 값 ‘6100 grams’ 출력

    if ( less_than(w1, w2) ) // w1이 w2보다 작은 값인가 판단
        cout << "yes.\n";

    else
        cout << "no. \n";   // 작지 않으므로 ‘no’ 출력
}