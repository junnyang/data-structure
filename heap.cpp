#include <iostream>
#include <string>
using namespace std;

#define HSIZE 100

class element {
public : 
    string name;
    double score;
    void set_data(string n, double s);
};

void element::set_data(string n, double s)
{
    name = n;
    score = s;
}

class my_heap {
    element h[HSIZE];
    int csize;
public :
    my_heap();
    my_heap(element a[], int n);
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    void adjust(int t_root);
    bool heap_full();
    bool heap_empty();
};

my_heap::my_heap()
{
    csize = 0;
}

my_heap::my_heap(element a[], int n)
{
    int k;

    for(k = 1 ; k <= n ; k++)
        h[k] = a[k-1];
    csize = n;

    for(k = n/2 ; k >= 1 ; k--)
        adjust(k);
}

int my_heap::h_size()
{
    return csize;
}

void my_heap::insert_heap(element t)
{
    int k;
    csize++;
    k = csize;
    while((k != 1) && (t.score > h[k/2].score))
    {
        h[k] = h[k/2];
        k /= 2;
    }
    h[k] = t;
}

element my_heap::delete_heap()
{
    element t;
    element tmp;
    int parent, child;

    t = h[1];
    tmp = h[csize];
    csize--;
    parent = 1;
    child = 2;

    while (child <= csize)
    {
        if((child < csize) && (h[child].score < h[child + 1].score))
            child++;
        if(tmp.score >= h[child].score)
            break;
        h[parent] = h[child];
        parent = child;
        child *= 2;
    }

    h[parent] = tmp;
    return t;
    
}

void my_heap::adjust(int t_root)
{
    double tmpkey;
    int child;
    element tmp;

    tmp = h[t_root];
    tmpkey = h[t_root].score;
    child = 2 * t_root;

    while (child <= csize)
    {
        if((child < csize) && (h[child].score < h[child +1].score))
            child++;
        if(tmpkey > h[child].score)
            break;
        else
        {
            h[child / 2] = h[child];
            child *= 2;
        }
    }

    h[child / 2] = tmp;
}

bool my_heap::heap_empty()
{
    if(csize == 0)
        return true;
    else
        return false;
}

bool my_heap::heap_full()
{
    if(csize >= HSIZE - 1)
        return true;
    else
        return false;
}

int main()
{
    element temp;
    element a[10] = {{"Kim",88} , {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu", 94}, {"Cho", 85}};
    my_heap h1(a,6);
    
    while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }
    
    return 0;
}