class Node  {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    ~LinkedList() {
        Node curr = head;
        while(curr != nullptr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    int get(int index) {
        Node* curr = head->next;
        int i = 0;
        while(curr != nullptr) {
            if(i == index) {
                return curr->val;
            }
            curr = curr->next;
            i = i + 1;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        if(tail == head) {
            tail = newNode;
        }
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }

    bool remove(int index) {
        Node* curr = head;
        int i = 0;
        while(i < index) {
            if(curr == nullptr) {
                return false;
            }
            curr = curr->next;
            i = i + 1;
        }

        Node* theonewhogotKilled = curr->next;
        if(theonewhogotKilled == nullptr) {
            return false;
        }

        if(tail == theonewhogotKilled) {
            tail = curr;
        }
        curr->next = theonewhogotKilled->next;
        delete theonewhogotKilled;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head->next;
        while(curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};
