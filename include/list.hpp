#include <iostream>

template <class T>
class List {
private:
    struct node {
        node(T data) : data(data){};
        node(T data, node *next) : data(data), next(next){};
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

    Iter begin() { return Iter(begin_p); }
    Iter end() { return Iter(nullptr); }
    int len() { return length; };

    void append(T data) {
        using namespace std;
        auto n_node = new node(data, nullptr);
        if (length == 0) {
            end_p = begin_p = n_node;
        } else {
            end_p->next = n_node;
            end_p = n_node;
        }
        length += 1;
    }

    T pop(int index) {
        node *p = begin_p;
        T re;
        if (index) {
            node *q;
            while (index--) {
                q = p;
                p = p->next;
            }
            re = p->data;
            q->next = p->next;
            delete p;
        } else {
            node *temp = begin_p;
            re = begin_p->data;
            delete begin_p;
            begin_p = temp->next;
        }
        return re;
    }
    std::ostream &operator<<(std::ostream &os);
};

template <class T>
std::ostream &List<T>::operator<<(std::ostream &os) {
    std::cout << "hi";
    return os;
}
