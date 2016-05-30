#include <iostream>

using std::cout;
using std::endl;

class Node{
    friend class SortedLinkedList;
public:
    Node(const int &_val) : val{_val} {}
    ~Node() { delete next; }
private:
    int val;
    Node *next{nullptr};
};

class SortedLinkedList{
public:
    void insertSorted(const int &_val){
        if (first == nullptr){
            first = new Node{_val};
        }
        else{
            Node *aux = first;
            if (_val <= aux->val){
                first = new Node{_val};
                first -> next = aux;
                return;
            }
            Node *tmp = aux;
            while(aux != nullptr && _val > (aux -> val)){
                tmp = aux;
                aux = aux -> next;
            }
            tmp -> next = new Node{_val};
            if (aux != nullptr){
                tmp = tmp -> next;
                tmp -> next = aux;
            }
        }
    }
    void imprimir(){
        Node *aux = first;
        if (aux != nullptr){
            cout << aux -> val;
            aux = aux -> next;
        }
        while(aux != nullptr){
            cout << "->" << aux -> val;
            aux = aux -> next;
        }
        cout << endl;
    }
private:
    Node *first{nullptr};
};

int main(){

    SortedLinkedList a;

    a.insertSorted(9);
    a.insertSorted(6);
    a.insertSorted(15);
    a.insertSorted(2);
    a.insertSorted(6);
    a.insertSorted(3);

    a.imprimir();

    return 0;
}
