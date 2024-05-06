#include <iostream>
#include <string>
using namespace std;


class node {
public:
        string   name;
        double      score;
        node *link;
        void   set_data(string   s, double n);
};

void   node::set_data(string s, double n) {
           name = s;
           score = n;
}

class my_list {
     node   *head;
public:
        my_list() {
                head = NULL;
        }
        void add_to_head(node   t);
        void add_to_tail(node   t);
        void delete_from_head();
        void remove_a_node(string s);
        double score_sum();
        double get_score();
        int  num_nodes();
        void show_all_data();
};



int main()
{

    my_list a;

    node   tmp;

    tmp.set_data("Kim", 83.5);

    a.add_to_head(tmp);

    tmp.set_data("Lee", 78.2);

    a.add_to_head(tmp);           // head 위치로 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검

    tmp.set_data("Park", 91.3);  

    a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가
    
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2단계 점검

    tmp = a.delete_from_head();

    cout  << tmp.name << " is deleted.\n";   // 3단계 점검

    tmp.set_data("Choi", 85.1);  

    a.add_to_tail(tmp);             

    tmp.set_data("Ryu", 94.3);  

    a.add_to_head(tmp);             // 2개의 원소 추가

    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";

    cout << "Park’s score : " << a.get_score("Park")<< "\n";  // 4단계 점검

    if (a.remove_a_node("Kim") == 1)

    cout <<  "Kim is deleted from the list. \n";     // 5단계 점검

    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";  // 최종 점검       

    return 0;

  }