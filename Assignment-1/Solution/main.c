#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scanTime(){
    int hours;
    scanf("%d", &hours);
    scanf(":");
    int minutes;
    scanf("%d", &minutes);
    printf("%d %d\n", hours, minutes);
    int time = hours * 60 + minutes;
    return time;
}

struct Node {
    int startTime;
    int endTime;
    float priority;
    struct Node* next;
    struct Node* prev;

};

void addNode (struct Node** head, struct Node** tail, int companyId, int startTime, int endTime, float priority) {
    if (head[companyId] == NULL) {
        head = newNode(startTime, endTime, priority);
        tail = head;

    } else if (head == tail) {
        tail -> next = newNode(startTime, endTime, priority);
        head -> next = tail -> next;
        struct Node* temp = tail;
        tail = tail -> next;
        tail -> prev = temp;
    } else {
        tail -> next = newNode(startTime, endTime, priority);
        struct Node* temp = tail;
        tail = tail -> next;
        tail -> prev = temp;
    }
}

int main(){

    struct Node* head[100000];
    struct Node* tail[100000];
    

    // int A[100];
    for (int i = 0; i < 100000; ++i) {
        head[i] = NULL;
        tail[i] = NULL;
    }
    int companyId;
    while (scanf("%d", &companyId) != EOF) {

        int startTime = scanTime();
        scanf("-");
        int endTime = scanTime();
        float priority;
        scanf("%f", &priority);
        // printf("%d", endTime);
        addNode(head, tail, companyId, startTime, endTime, priority);


    }
}