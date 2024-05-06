#include <cstring>
#include <iostream>
#include <string>
using namespace std;


#define SIZE 100
#define EOS "$"

class op_stack {
    char s[SIZE];
    int top;
public :
    op_stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
    };
    
op_stack::op_stack() {
    top = 0;
}

void op_stack::push(char x){
    if(top == SIZE )
    {
        cout << "Error: Stack is full." << endl;
        return;
    }
    s[top] = x;
    top++;
}

char op_stack::pop(){
    if (empty()) {
        cout << "Error: Stack is empty." << endl;
        return '\0';
    }
    top--;
    return(s[top]);
}

bool op_stack::empty(){
    return(top == 0);
}

char op_stack::top_element(){
    if (empty())
        return '\0';
    return(s[top - 1]);
}

bool is_operand(char ch){
    if((ch == '(') || (ch == '{') || (ch == '[') || (ch == ')') || (ch == '}') || (ch == ']'))
        return 1;
}

bool is_open(char ch){
    if((ch == '(') || (ch == '{') || (ch == '['))
        return 1;
}

bool is_match(char ch, char top){
    if((ch == ')' && top == '(') || (ch == '}' && top == '{')|| (ch == ']' && top == '['))
        return 1;
    return 0;
}

bool matching(char ch){
    if(ch == '(')
        return 1;
    if(ch == '{')
        return 2;
    if(ch == '[')
        return 3;
    return '\0';
}

int main()
{
    string input, output; 
    op_stack stack1;
    cout << "Input an expression of a formula : ";
    cin >> input;
    input += EOS;
    const char *c = input.c_str(); 
    char top;
    int error = 0;
    
    for(int i = 0 ; i < input.size() ; i++)
    {
        if(is_operand(input[i]))
        {
            if(is_open(input[i]))
            {
                stack1.push(input[i]);
                continue;
            }
            else
            {
                char top;
                top = stack1.pop();
                if(top == '\0')
                {
                    cout << "Error: An extra parenthesis '" << input[i] << "'is found." << endl;
                    error = 1;
                    break;
                }
                    
                else if(is_match(input[i], top))
                    continue;
                else 
                {
                    int x;
                    char k;
                    x = matching(input[i]);
                    switch (x)
                    {
                    case 1:
                        k = ')';
                        break;
                    case 2:
                        k = '}';
                        break;
                    case 3:
                        k = ']';
                        break;
                    
                    default:
                        break;
                    }
                    cout << k << endl;
                    cout << "Error: mis-matched parenthesis, '" << k << "' is expected." << endl;
                    error = 1;
                    break;
                }
            }
        }  
    }

    if(error == 0)
       cout << "It’s a normal expression";

    return 0;
}