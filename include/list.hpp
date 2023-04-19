#include <iostream>

template <class T>
class List {
private:
    struct node {
        node(T data) : data(data){};
        T data;
        node *next;
    };

    node *begin_p = nullptr;
    node *end_p = nullptr;
    int length = 0;

public:
    class Iter {
    private:
        node *p;

    public:
        Iter(node *n) : p(n) {}
        Iter &operator++(int i) {
            p = p->next;
            return *this;
        }
        T &operator*() const { return p->data; }
        bool operator==(const Iter &other) const { return p == other.p; }
        bool operator!=(const Iter &other) const { return p != other.p; }
    };

    int len() { return length; };

    void append(T data) {
        using namespace std;
        auto n_node = new node(data);
        if (length == 0) {
            end_p = begin_p = n_node;
        } else {
            end_p->next = n_node;
            end_p = n_node;
        }
        length += 1;
    }

    Iter begin() { return Iter(begin_p); }
    Iter end() { return Iter(nullptr); }
};
