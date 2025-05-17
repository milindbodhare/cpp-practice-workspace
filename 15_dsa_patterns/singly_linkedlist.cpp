#include <iostream>

class Node {
    public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
    // Destructor to free memory
    ~Node() {
        std::cout << "Node with value " << data << " deleted." << std::endl;
    }
    
};

class SinglyLinkedList {
    private:
    Node *head;

    public:
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (head  == nullptr) {
            head = newNode; // Insert at the head, if list is empty
        } else {
            Node* current;
           for(current = head; current->next != nullptr; current = current->next) {
                // Do nothing, just traverse
            }
            current->next = newNode; // Insert at the end
        }
        // Do not delete newNode here, as it is now part of the list
    }

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        newNode->next = head; // Point new node to the current head
        head = newNode; // Update head to the new node
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        if (head->next == nullptr) {
            delete head; // Only one node
            head = nullptr;
            return;
        }
        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next; // Traverse to the second last node
        }
        delete current->next; // Delete the last node
        current->next = nullptr; // Set the next of second last node to null
    }
    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node *temp = head; // Store the current head
        head = head->next; // Move head to the next node
        delete temp; // Delete the old head
    }

    void reverseList() {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr) {
            next = current->next; // Store next node
            current->next = prev; // Reverse the link
            prev = current; // Move prev to current
            current = next; // Move to next node
        }
        head = prev; // Update head to the new first node
    }

    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
        }
        else {
            for(auto current = head; current != nullptr; current = current->next) {
                std::cout << current->data << " -> ";
            }
        }
        std::cout << "nullptr" << std::endl;
    }

    void insertAtPosition(int val, int pos) {
        Node *newNode = new Node(val);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *current = head;
        for (int i = 0; i < pos - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Position out of bounds." << std::endl;
            delete newNode; // Free memory
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void detectLoopInList() {
        Node *slow = head;
        Node *fast = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // Move slow pointer by 1
            fast = fast->next->next; // Move fast pointer by 2

            if (slow == fast) { // Loop detected
                std::cout << "Loop detected in the list." << std::endl;
                return;
            }
        }
        std::cout << "No loop detected in the list." << std::endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtBeginning(4);
    list.display(); // Output: 4 -> 1 -> 2 -> 3 -> nullptr
    list.reverseList();
    list.display(); // Output: 3 -> 2 -> 1 -> 4 -> nullptr
    list.deleteFromEnd();
    list.display(); // Output: 3 -> 2 -> 1 -> nullptr
    list.deleteFromBeginning();
    list.display(); // Output: 2 -> 1 -> nullptr
    list.insertAtPosition(5, 1);
    list.display(); // Output: 2 -> 5 -> 1 -> nullptr
    list.detectLoopInList(); // Output: No loop detected in the list.
    return 0;
}