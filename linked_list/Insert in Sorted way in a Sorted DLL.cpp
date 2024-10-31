/*
Link : https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1
*/
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node *temp = head;
        struct Node* new_node = getNode(x);
        // add at beginning
               if(temp -> data > x){
                new_node -> next = temp;
               temp->prev = new_node;
               return new_node;
    }
    //add in the middle
       while(temp && temp -> next){
           if(temp -> data <= x && x <= temp->next->data){
               new_node -> next = temp -> next;
               temp->next->prev = new_node;
               temp->next = new_node;
               new_node -> prev = temp;
               return head;
           }
           temp = temp->next;
       }
       //add at last of the node
       temp -> next = new_node; 
       new_node->prev = temp;
       return head;
    
    }
};

/*

1: Approach to Sorted Insertion in a Doubly Linked List
The goal of this function, sortedInsert, is to insert a new node with a given value x into a sorted doubly linked list while maintaining the order. The function follows these steps:

* Create a New Node:We start by creating a new node using the getNode(x) function, which initializes the node with the value x.

*Check for Insertion at the Beginning:

     We first check if the list is empty or if the new node should be inserted at the beginning.
If the head exists and the value of the head node is greater than x, we place the new node before the head. We update the pointers accordingly:
Set the new node's next to the current head.
Update the current head's prev to point to the new node.
Return the new node as the new head of the list.
Traverse the List for Insertion in the Middle:

If the new node is not to be inserted at the beginning, we traverse the list to find the correct position for the new node.
We use a while loop to iterate through the list until we find a node such that the new node's value x lies between the current node's value and the next node's value.
When the correct position is found, we adjust the pointers to insert the new node:
Set the new node's next to the current node's next.
Update the prev pointer of the next node (if it exists) to point to the new node.
Link the current node's next to the new node and set the new node's prev to the current node.
Insert at the End:

If we reach the end of the list without finding a suitable position, we insert the new node at the end.
We set the last node's next to the new node and update the new node's prev to point to the last node.
Return the Head:

Finally, we return the head of the list, which remains unchanged unless the new node was inserted at the beginning.
Complexity Analysis
Time Complexity: O(n), where n is the number of nodes in the list. In the worst case, we may need to traverse the entire list to find the correct insertion point.
Space Complexity: O(1), since we are using a constant amount of extra space for the new node.
*/