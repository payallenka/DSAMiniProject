#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 5

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertPage(struct Node** pageTable, int pageNumber, int elem) {
    struct Node* newNode = createNode(elem);
    if (pageTable[pageNumber] == NULL) {
        pageTable[pageNumber] = newNode;
    } else {
        struct Node* temp = pageTable[pageNumber];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPageTable(struct Node** pageTable) {
    for (int i = 0; i < MAX_PAGES; i++) {
        struct Node* temp = pageTable[i];
        printf("Page %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* pageTable[MAX_PAGES] = {NULL};
    int n, elem, pageNumber;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        pageNumber = elem % MAX_PAGES;
        insertPage(pageTable, pageNumber, elem);
    }

    printf("\nPage Table:\n");
    displayPageTable(pageTable);

    return 0;
}
