#include <iostream>

template <class T>
class List {
private:
    struct node {
        node(T data) : data(data){};
        T data;
        node *next;
    };
    
    class Iter{
    private:
        node* p;
    public:
        Iter(node* n):p(n){}
        Iter& operator++(){
            p = p->next;
            return *this;
        }
        bool operator==(Iter& other){
            return p == other.p;
        }
        bool operator!=(Iter& other){
            return p != other.p;
        }
    };
    int length = 0;
    node *begin = nullptr;
    node *end = nullptr;

public:
    int len() { return length; };
    void append(T data){
        auto n_node = new node(data);
        if(length == 0){
            end = begin = n_node;
        }else{
            end->next = n_node;
            end = n_node;
        }
    }
};
