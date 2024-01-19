#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
  Node* newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to display the elements of the linked list
void displayList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
  Node* current = head;
  Node* next;
  while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
  }
}

int main() {
  Node* head = NULL;

  // Test insertAtBeginning function
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 1);

  // Test displayList function
  printf("Linked List: ");
  displayList(head);

  // Test freeList function
  freeList(head);

  return 0;
}
