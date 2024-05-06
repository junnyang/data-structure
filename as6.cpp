#include <iostream>
#include <string>
using namespace std;

#define SIZE 100
#define EOS '\0'

class node {
public :
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class my_queue {
    node *front, *rear;
public :
    my_queue();
    void insert_queue(node   t);
    node delete_queue();
    bool queue_empty();
};

my_queue::my_queue() 
{
    front = NULL;
    rear = NULL;
}

void my_queue::insert_queue(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(queue_empty())
    {
        front = p;
        rear = p;
    }
    rear->link = p;
    rear = p;
}

node my_queue::delete_queue()
{
    node tmp, *t;
    if(queue_empty())
        return tmp;
    tmp = *front;
    t = front;
    front = front->link;
    delete t;
    if(front == NULL)
        rear = NULL;
    return tmp;
}

bool my_queue::queue_empty()
{
    return (front == NULL); 
}

int main( )
{

    my_queue    a;
    node    tmp;

    tmp.set_data("Kim", 22.2);

    a.insert_queue(tmp);

    tmp.set_data("Lee", 33.3);

    a.insert_queue(tmp);           // head 위치로 2개의 원소 추가

    tmp.set_data("Park", 44.4);  

    a.insert_queue(tmp);             // tail 위치로 1개의 원소 추가

    tmp.set_data("Choi", 55.5);  

    a.insert_queue(tmp);             

    tmp.set_data("Ryu", 94.3);  

    a.insert_queue(tmp);             // 2개의 원소 추가

    tmp = a.delete_queue();
    cout << tmp.name << " : " << tmp.score << "\n";  // 4단계 점검

    tmp = a.delete_queue();
    cout << tmp.name << " : " << tmp.score << "\n";

    return 0;

  }