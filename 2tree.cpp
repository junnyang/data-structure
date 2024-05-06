#include <iostream>
#include <string>
using namespace std;

class node {
public :
    string name;
    double score;
    node *left, *right;
    void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class my_queue {
private :
    struct queueNode {
        node *data;
        queueNode *next;
    };
    queueNode *front;
    queueNode *rear;

public : 
    my_queue();
    ~my_queue();
    void insert_q(node *t);
    node *delete_q();
    bool q_empty();

};

my_queue::my_queue()
{
    front = NULL;
    rear = NULL;
}

my_queue::~my_queue()
{
    while (!q_empty())
    {
        delete_q();
    }
}

void my_queue::insert_q(node *n)
{
    queueNode *temp = new queueNode;
    temp->data = n;
    temp->next = nullptr;
    if (front == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

node *my_queue::delete_q()
{
    if (front == nullptr)
    {
        return nullptr;
    }
    queueNode *temp = front;
    node *data = front->data;
    front = front->next;
    delete temp;
    return data;
}

bool my_queue::q_empty()
{
    return (front == nullptr);
}

class nstack {
private:
    struct stackNode {
        node *data;
        stackNode *next;
    };
    stackNode *top;

public:
    nstack();
    ~nstack();
    void push(node *n);
    node *pop();
    bool stack_empty();
};

nstack::nstack()
{
    top = nullptr;
}

nstack::~nstack()
{
    while (!stack_empty())
    {
        pop();
    }
}

void nstack::push(node *n)
{
    stackNode *temp = new stackNode;
    temp->data = n;
    temp->next = top;
    top = temp;
}

node *nstack::pop()
{
    if (top == nullptr)
    {
        return nullptr;
    }
    stackNode *temp = top;
    node *data = top->data;
    top = top->next;
    delete temp;
    return data;
}

bool nstack::stack_empty()
{
    return (top == nullptr);
}

class my_tree {
    public :
        int node_count;
        node *root;
        my_tree();
        int insert_root(node t);
        int insert_left(string tname, node t);
        int insert_right(string tname, node t);

        double score_sum();
        double score_average();
        void print_data_inorder();
        void print_data_preorder();
        void print_data_postorder();

        void nonrecursive_inorder();
        void print_data_levelorder();
};

my_tree::my_tree()
{
    node_count = 0;
    root = NULL;
}

int my_tree::insert_root(node t)
{
    if(root != NULL)
        return 0;
    node *p;
    p = new node;
    (*p) = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count++;
    return 1;
}

int node_insert_left(node *p, string tname, node tnode)
{
    int result;
    if(p == NULL) 
        return 0;
    if(p->name == tname)
    {
        if(p->left != NULL)
            return -1;
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }
    else
    {
        result = node_insert_left(p->left, tname, tnode);
        if(result != 0)
            return result;
        return node_insert_left(p->right, tname, tnode);
    }
}

int my_tree::insert_left(string tname, node tnode)
{
    int result;

    result = node_insert_left(root, tname, tnode);
    if(result == 1)
        node_count++;
    return result;
}

int node_insert_right(node *p, string tname, node tnode)
{
    int result;

    if(p == NULL) 
        return 0;
    if(p->name == tname)
    {
        if(p->right != NULL)
            return -1;
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->right = t;
        return 1;
    }
    else
    {
        result = node_insert_right(p->left, tname, tnode);
        if(result != 0)
            return result;
        return node_insert_right(p->right, tname, tnode);
    }
}

int my_tree::insert_right(string tname, node tnode)
{
    int result;

    result = node_insert_right(root, tname, tnode);
    if(result == 1)
        node_count++;
    return result;
}

double sum_allnodes(node *p)
{
    if(p == NULL)
        return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

double my_tree::score_sum()
{
    return sum_allnodes(root);
}

int count_allnodes(node *p)
{
    if(p == NULL)
        return 0;
    return count_allnodes(p->left) + count_allnodes(p->right) + 1;
}

double average_allnodes(node *p)
{
    if(p == NULL)
        return 0;
    int count;
    count = count_allnodes(p);

    return sum_allnodes(p) / count;
}

double my_tree::score_average()
{
    return average_allnodes(root);
}

void inorder_print(node *p)
{
    if(p == NULL)
        return;
    
    inorder_print(p->left);
    cout << p->name << " : " << p->score << "\n";
    inorder_print(p->right);
}

void my_tree::print_data_inorder()
{
    inorder_print(root);
}

void preorder_print(node *p)
{
    if(p == NULL)
        return;
       
    cout << p->name << " : " << p->score << "\n";
    preorder_print(p->left);
    preorder_print(p->right);
}

void my_tree::print_data_preorder()
{
    preorder_print(root);
}

void postorder_print(node *p)
{
    if(p == NULL)
        return;
       
    postorder_print(p->left);
    postorder_print(p->right);
    cout << p->name << " : " << p->score << "\n";
}

void my_tree::print_data_postorder()
{
    postorder_print(root);
}

void my_tree::nonrecursive_inorder()
{
    nstack s1;
    node *t;

    t = root;
    while(1)
    {
        while (t != NULL)
        {
            s1.push(t);
            t = t->left;
        }
        while (t == NULL)
        {
            if(s1.stack_empty())
                return;
            t = s1.pop();
        }
        cout << t->name << " : " << t->score << endl;
        t = t->right;
    }
}

void my_tree::print_data_levelorder()
{
    my_queue a1;
    node *t;

    if(root == NULL)
        return;
    a1.insert_q(root);
    while (1)
    {
        if(a1.q_empty())
            return;
        t = a1.delete_q();
        cout << t->name << " : " << t->score << "\n";
        if(t->left != NULL)
            a1.insert_q(t->left);
        if(t->right != NULL)
            a1.insert_q(t->right);
    }
}

node *make_copy(node *p)
{
    node *t;

    if(p == NULL)
        return NULL;
    t = new node;

    *t = *p;
    t->left = make_copy(p->left);
    t->right = make_copy(p->right);
    return t;
}

void copy_tree(my_tree &t1, my_tree t2)
{
    t1.node_count = t2.node_count;
    t1.root = make_copy(t2.root);
}

bool equal_test(node *p1, node *p2)
{
    if((p1 == NULL) && (p2 == NULL))
        return true;
    if(p1 == NULL)
        return false;
    if(p2 == NULL)
        return false;
    if(p1->name != p2->name)
        return false;
    if(p1->score != p2->score)
        return false;

    if(equal_test(p1->left, p2->left) && equal_test(p1->right, p2->right))
        return true;
    else
        return false;
}

bool equal_tree(my_tree t1, my_tree t2)
{
    if(t1.node_count != t2.node_count)
        return false;
    return equal_test(t1.root, t2.root);
}

int main ()
{
    my_tree thetree;
    node tmp;

    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);

    cout << "Score Sum : " << thetree.score_sum() << "\n";
    cout<< "Score Average : " << thetree.score_average() << "\n";
    cout <<"\n Inorder Traversal Result \n";
    thetree.print_data_inorder();
    cout << "\n Preorder Traversal Result \n";
    thetree.print_data_preorder();
    cout << "\n Postorder Traversal Result \n";
    thetree.print_data_postorder();
    

    cout << "\nNon-recursive Inorder Result \n";
    thetree.nonrecursive_inorder();
    cout << "\nLevel-Order traversal Result \n";
    thetree.print_data_levelorder();
    my_tree tree2;
    copy_tree(tree2, thetree);
    cout << "\nThe inorder traversal Result of the new tree \n";
    tree2.print_data_inorder();
    if (equal_tree(tree2, thetree) )
        cout << "Yes\n";
    else
        cout << "No\n";
    tmp.set_data("Youn", 7.7);
    thetree.insert_right("Cho", tmp);
    if (equal_tree(tree2, thetree) )
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}