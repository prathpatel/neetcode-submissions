class Node {
public:
    int val;
    Node* next = nullptr;
    Node(int val) : val(val) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = new Node(-1);   // sentinel, holds no real data
        tail = head;
    }

    ~LinkedList() {
        while (head) { Node* nxt = head->next; delete head; head = nxt; }
    }

    int get(int index) {
        Node* curr = head->next;
        for (int i = 0; curr; curr = curr->next, i++)
            if (i == index) return curr->val;
        return -1;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        head->next = node;
        if (tail == head) tail = node;   // list was empty
    }

    void insertTail(int val) {
        tail->next = new Node(val);
        tail = tail->next;
    }

    bool remove(int index) {
        Node* prev = head;
        for (int i = 0; i < index && prev->next; i++) prev = prev->next;
        if (!prev->next) return false;
        Node* victim = prev->next;
        if (victim == tail) tail = prev;
        prev->next = victim->next;
        delete victim;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        for (Node* curr = head->next; curr; curr = curr->next)
            res.push_back(curr->val);
        return res;
    }
};