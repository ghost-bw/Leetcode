

class MinStack {
public:
    class Node {
    public:
        int val;
        int mn;
        Node* next;

        Node(int val, int mn, Node* next) {
            this->val = val;
            this->mn = mn;
            this->next = next;
        }
    };

    Node* head;

    MinStack() {
        head = nullptr;
    }

    void push(int value) {
        if (head == nullptr) {
            head = new Node(value, value, nullptr);
        } else {
            head = new Node(value, min(value, head->mn), head);
        }
    }

    void pop() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        return head->val;
    }

    int getMin() {
        return head->mn;
    }
};