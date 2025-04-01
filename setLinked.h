#ifndef SETLINKED_H
#define SETLINKED_H


class setLinked {
private:
    struct Node {
        int value;
        Node *next;
        Node(int val, Node *next = nullptr) : value(val), next(next) {}
    };

    Node *head;

public:
    setLinked() {
        head = nullptr;
    }

    void insert(int x) {
        if (head == nullptr) {
            head = new Node(x, nullptr);
            return;
        }

        if (x < head->value) {
            head = new Node(x, head);
            return;
        }

        if (x == head->value) return;

        Node *current = head;
        while (current -> next != nullptr && current->next->value < x) {
            current = current->next;
        }

        if ( current->next == nullptr || current->next->value != x ) {
            current->next = new Node(x, current->next);
        }
    }

    bool zawieranie(int x) {
        if (head == nullptr || head->value > x) return false;

        if (head -> value == x) return true;

        Node *current = head;
        while (current -> next != nullptr && current->next->value < x) {
            current = current->next;
        }

        if (current->next == nullptr || current->next->value != x) {
            return false;
        }
        return true;
    }

    void usuwanie(int x) {
        if (head == nullptr || head -> value > x ) return;
        if (head -> value == x) {
            Node *temp = head;
            head = head -> next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current -> next != nullptr && current->next->value < x) {
            current = current -> next;
        }
        if (current -> next != nullptr && current->next->value == x) {
            Node *temp = current -> next;
            current -> next = temp ->next;
            delete temp;
            return;
        }
    }

    setLinked operator+(const setLinked& other) {
        setLinked result;
        Node* ptr1 = head;
        Node* ptr2 = other.head;

        while (ptr1 || ptr2) {
            if (ptr1 && (!ptr2 || ptr1 -> value < ptr2 -> value)) {
                result.insert(ptr1 -> value);
                ptr1 = ptr1 -> next;
            }else if (ptr2 && (!ptr1 || ptr2 -> value < ptr1 -> value)) {
                result.insert(ptr2 -> value);
                ptr2 = ptr2 -> next;
            }else {
                result.insert(ptr1 -> value);
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
        }
        return result;
    }

    setLinked operator-(const setLinked& other) {
        setLinked result;
        Node* ptr1 = head;
        Node* ptr2 = other.head;

        while (ptr1) {
            if (!ptr2 || (ptr1 -> value < ptr2 -> value)) {
                result.insert(ptr1 -> value);
                ptr1 = ptr1 -> next;
            }else if (ptr2 && (ptr2 -> value < ptr1 -> value)) {
                ptr2 = ptr2 -> next;
            }else {
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
        }
        return result;
    }

    setLinked operator&(const setLinked& other) {
        setLinked result;
        Node* ptr1 = head;
        Node* ptr2 = other.head;

        while (ptr1 && ptr2) {
            if (ptr1 -> value < ptr2 -> value) {
                ptr1 = ptr1 -> next;
            }else if (ptr2 -> value < ptr1 -> value) {
                ptr2 = ptr2 -> next;
            }else {
                result.insert(ptr1 -> value);
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
        }
        return result;
    }
};


#endif