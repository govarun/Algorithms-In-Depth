#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scanTime(){
    int hours;
    scanf("%d", &hours);
    scanf(":");
    int minutes;
    scanf("%d", &minutes);
    int time = hours * 60 + minutes;
    return time;
}

struct Node {
    int startTime;
    int endTime;
    float priority;
    struct Node* next;
    struct Node* prev;

} node;

int main(){
    struct Node* head[100000];
    struct Node* last[100000];
    

    // int A[100];
    for (int i = 0; i < 100000; ++i){
        head[i] = NULL;
        last[i] = NULL;
    }
    int companyId;
    while (scanf("%d", &companyId) != 0 && scanf("%d", &companyId) != EOF) {
        int startTime = scanTime();
        scanf("-");
        int endTime = scanTime();
        float priority;
        scanf("%f", &priority);
        printf("%d", startTime);

    }
}