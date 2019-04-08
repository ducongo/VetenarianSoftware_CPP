#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

template <class T>
class List
{
    class Node {

        friend class List;

        private:
            T data;
            Node* next;
    };

    public:
        List();
        ~List();
        void print();
        void add(T);

    private:
        Node* head;
};



/*template <typename T>
List<T>::List(){

    head = NULL;
}

template <typename T>
List<T>::~List(){

    Node *currNode, *nextNode;

    currNode = head;

    while (currNode != NULL){
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}


template <typename T>
void List<T>::add(T e){

    Node* currnode = head;
    Node* tempnode = new Node;
    Node* prevnode;

    tempnode->data = e;
    tempnode->next = NULL;

    if (head == NULL){

        head = tempnode;

    }else if (*(tempnode->data) < currnode->data){

        tempnode->next = currnode;

        head = tempnode;

    }else{

        while (currnode->next != NULL){

            prevnode = currnode;
            currnode = currnode->next;

            if (*(tempnode->data) < currnode->data){

                prevnode->next = tempnode;
                tempnode->next = currnode;
                return;
            }
        }

        currnode->next = tempnode;
    }
    return;
}

*/

#endif
