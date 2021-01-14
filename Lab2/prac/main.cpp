#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* link;

};

struct Node* head;

void Insert(int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = value;
    temp -> link = NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        struct Node* t;
        t = head;
        while(t->link != NULL){
            t = t -> link;
        }
        t -> link = temp;
    }

}

void print(){
    struct Node* temp;
    temp = head;
    while(head != NULL){
        cout<< temp -> data << " ";
        temp = temp -> link;
    }

}

int main()
{
    head = NULL;

    /*
    head =(struct Node*)malloc(sizeof(struct Node));
    head -> data = 2;
    head -> link = (struct Node*)malloc(sizeof(struct Node));
    head -> link -> data = 5;
    head -> link -> link = NULL;
    */

    Insert(1);
    Insert(2);
    Insert(3);

    print();


    return 0;
}
