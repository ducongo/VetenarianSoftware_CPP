#include <string>

using namespace std;

#include "list.h"

template <typename T>
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
