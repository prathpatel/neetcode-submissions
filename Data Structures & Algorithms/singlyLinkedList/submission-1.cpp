class Node {
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
        head = new Node(-1);   // sentinel: holds no real data
        tail = head;
    }

    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    int get(int index) {
        Node* curr = head->next;
        int i = 0;
        while (curr != nullptr) {
            if (i == index) {
                return curr->val;
            }
            curr = curr->next;
            i = i + 1;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        head->next = node;
        if (tail == head) {      // list was empty
            tail = node;
        }
    }

    void insertTail(int val) {
        Node* node = new Node(val);
        tail->next = node;
        tail = node;
    }

    bool remove(int index) {
        Node* prev = head;
        int i = 0;
        while (i < index) {
            if (prev->next == nullptr) {
                return false;    // index past the end
            }
            prev = prev->next;
            i = i + 1;
        }

        Node* victim = prev->next;
        if (victim == nullptr) {
            return false;        // nothing at this index
        }

        if (victim == tail) {
            tail = prev;
        }
        prev->next = victim->next;
        delete victim;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head->next;
        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};