class Node{
    public:

    Node* next;
    Node* back;
    string url;

    Node(string link){
        url = link;
        back = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    Node *curr, *head;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        curr = head;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        curr->next->back = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(steps--) if(curr->back) curr = curr->back;
        return curr->url;
    }
    
    string forward(int steps) {
         while(steps--) if(curr->next) curr = curr->next;
         return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */