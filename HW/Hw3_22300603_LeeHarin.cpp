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
        return ')';
    if(ch == '{')
        return '}';
    if(ch == '[')
        return ']';
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
                stack1.push(input[i]);
            else
            {
                if(stack1.top_element())
                {
                    top = stack1.pop();
                    if(is_match(input[i], top)) //type이 맞지 않으면 수행
                    { 
                        cout << stack1.top_element() << endl;
                        cout << input[i] << endl;
                        cout << "Error: mis-matched parenthesis, '" << matching(top) << "'is expected.";
                        error = 1;
                        break;
                    } 
                }   
                else
                {
                    cout << "Error: An extra parenthesis '" << input[i] << "'is found."; 
                    error = 2;
                    break;
                }
            }
        }    
    }

    if(error == 0)
       cout << "It’s a normal expression";

    return 0;
}