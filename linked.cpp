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

class   my_list  {
    node   *head, *tail;
public : 
    my_list();
    void add_to_head(node   t);
    void add_to_tail(node   t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    void invert();
    friend bool list_equal(my_list a, my_list b);
};

my_list::my_list() 
{
    head = NULL;
    tail = NULL;
}

void my_list:: add_to_head(node  t)
{
    node  *p;
    p =  new  node;
    (*p) = t;
    p-> link = head;
    head = p;
    if (tail == NULL)    // 이전 상태가empty였다면, Tail도첫node로
        tail = p;
}

void my_list:: add_to_tail(node  t)
{
    node  *p;
    p = new node;
    (*p) = t;
    p-> link = NULL;
    if (tail != NULL) // 이전상태가empty가아니라면
        tail->link = p;
    else               // 이전상태가empty였다면head도변경
        head = p;
    tail = p;
}

node my_list:: delete_from_head()
{
    node   temp;
    node   *t;
    t = head;
    temp = *head;
    head = head->link;
    delete   t;
    if (head == NULL)  // 삭제 후 empty가 되면, tail값도 조정
        tail = NULL;
    return   temp;
}
int  my_list:: num_nodes( )
{
    node   *t;
    int count = 0;
    for (t = head; t != NULL; t = t->link)
        count++;
    return   count;
}

bool  my_list:: list_empty( )
{
    if (head == NULL)
        return true;
    else
        return false;
}

bool  equal_data(node t1, node t2)
{
    if (t1.name != t2.name)
        return false;
    if (t1.score != t2.score)
        return false;
    return true;
}

void my_list::invert()
{
    if(head == NULL || head == tail)
        return;
    node *pre, *cur, *next;
    pre = NULL;
    cur = head;
    next = NULL;

    tail = head;
    while(cur != NULL) {
        next = cur->link; // Save the next node
        cur->link = pre; // Reverse the link

        pre = cur; // Move pointers one position ahead
        cur = next;
    }

    head = pre;
    
}

bool is_equal(node *p1, node *p2)
{
    if ( (p1 == NULL) &&  (p2 == NULL) )
        return true;
    if ( (p1 == NULL) ||  (p2 == NULL) )  // AND 조건은 처리 되었으므로, OR 조건 가능
        return false;
    if ( equal_data(*p1, *p2) )
        return(is_equal(p1->link, p2->link));
    else
        return false;
}

bool list_equal(my_list a, my_list b)
{
    return is_equal(a.head, b.head);
}

int main( )
{

    my_list   a,b;
    node   tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    b.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    b.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    b.add_to_head(tmp);
    tmp.set_data("Kim", 83.5);
    b.add_to_head(tmp);  

    b.invert();
    if(list_equal(a, b))
        cout << "Yes, the two lists are identical. \n";
    else
        cout << "No, They are not identical.\n";

    tmp = b.delete_from_head();
    cout << tmp.name << " : " << tmp.score << "\n";

    return 0;
  }