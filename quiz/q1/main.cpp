// { Driver Code Starts
/* Program to split a circular linked list into two halves */

#include <stdio.h>
#include <stdlib.h>

/* structure for a Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);

    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

/* Driver program to test above functions */
int main()
{

    return 0;
}
// } Driver Code Ends

/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *temp = head;
    Node *slow = head, *fast = head;
    while (fast->next != head || fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head)
        fast = fast->next;

    printf("%d %d \n", fast->data, slow->data);
}