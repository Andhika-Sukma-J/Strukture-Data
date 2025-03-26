#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void reverse(Node **head)
{
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void printList(Node *head)
{
    Node *node = head;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;

    Node *second = new Node();
    second->data = 2;
    second->next = NULL;

    head->next = second;

    Node *third = new Node();
    third->data = 3;
    third->next = NULL;

    second->next = third;

    Node *fourth = new Node();
    fourth->data = 4;
    fourth->next = NULL;

    third->next = fourth;

    Node *fifth = new Node();
    fifth->data = 5;
    fifth->next = NULL;

    fourth->next = fifth;

    cout << "Original Linked List :" << endl;
    printList(head);

    reverse(&head);

    cout << "Reversed Linked List :" << endl;
    printList(head);
    cout << endl;

    return 0;
}

 Original Linked List:
 1 2 3 4 5
 Original Linked List:
 5 4 3 2 1

