#include <stdio.h>
#include <stdlib.h>

struct Node{
    int number;
    struct Node* next;
}*head= NULL, *tail=NULL;

struct Node* createNode(int number){
    struct Node* newNode;
    newNode =(Node*) malloc(sizeof(Node));
    newNode->number = number;
    newNode->next= NULL;

    return newNode;
}

void pushHead(int number){
    struct Node* newNode=createNode(number);
    if(head == NULL){
        head = tail = newNode;
    }else {
        newNode ->next=head;
        head=newNode;
    }
}

void pushTail(int number){
    struct Node* newNode=createNode(number);
    if(head == NULL){
        head = tail = newNode;
    }else {
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(int number){
    struct Node* newNode= createNode(number);
    if(head == NULL){
        head = tail = newNode;
    } else if(head->number > number){
        pushHead(number);
    }else if (tail->number<number){
        pushTail(number);
    }else{
        struct Node* curr = head;
        struct Node* prev = head;
        while (curr){
            if (curr -> number > number){
                prev->next = newNode;
                newNode->next = curr;
                break;
            }
            prev = curr;
            curr=curr->next;
        }
    }
}

void popHead(){
    if(head == NULL){
        return;
    }else if(head == tail){
        struct Node* del = head;
        head = tail = NULL;
        free(del);
    }else{
        struct Node* del = head;
        head = head -> next;
        del -> next = NULL;
        free(del);
    }
}

void popTail(){
    if(head == NULL){
        return;
    }else if(head == tail){
        struct Node* del = head;
        head = tail = NULL;
        free(del);
    }else{
        struct Node* del = tail;
        struct Node* curr = head;
        while (curr){
            if(curr -> next == tail){
                tail = curr;
                curr->next = NULL;
                free(del);
                break;
            }
            curr = curr ->next;
        }
    }
}

void popMid(int number){
    if(head == NULL){
        return;
    } else if(head->number == number){
        popHead();
    } else if(tail->number == number){
        popTail();
    }else{
        struct Node* curr = head;
        struct Node* prev = head;
        while (curr){
            if(curr-> number == number){
                prev->next=curr->next;
                curr-> next=NULL;
                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        
    }
}

void searchNode(int number){
    if(head == NULL){
        return;
    } else if(head->number == number){
        printf("ketemu %i\n", number);
    } else if(tail->number == number){
        printf("ketemu %i\n", number);
    }else{
        struct Node* curr = head;
        struct Node* prev = head;
        while (curr){
            if(curr-> number == number){
                printf("ketemu %i\n", number);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

void printList(){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%i ", temp->number);
        temp= temp->next;
    }
}

int main(){
    pushMid(2);
    pushMid(10);
    pushMid(9);

    // popMid(9);
    searchNode(9);
    printList();

    return 0;
}