/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
   	//empty List
    if(head == NULL)
        return NULL;
    
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {
        
        if( (curr -> next != NULL) && curr -> data == curr -> next -> data) {
            Node* next_next = curr ->next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
    
    return head; 
}

//Remove duplicates from unsorted LL
Node* removeDuplicates(Node* head) {
    if (head == NULL)
         return NULL;

    unordered_set<int> visited;
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        if (visited.find(curr->data) != visited.end()) {
            Node* next_node = curr->next;
            delete curr;
            prev->next = next_node;
            curr = next_node;
        } 
        else {
            visited.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
