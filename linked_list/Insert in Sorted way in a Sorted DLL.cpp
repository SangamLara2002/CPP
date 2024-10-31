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
To see the approach click on the given link below:
https://discuss.geeksforgeeks.org/comment/c44bf63d-4630-4bb9-bde3-dbe64bc31451/practice
*/