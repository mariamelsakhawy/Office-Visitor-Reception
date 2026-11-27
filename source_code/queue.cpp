
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    int visitorID;
    Node* next;

    Node(int id) {
        visitorID = id;
        next = NULL;
    }
};

class VisitorQueue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    VisitorQueue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    ~VisitorQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
        count = 0;
    }

    bool contains(int id) const {
        Node* current = front;

        while (current != NULL) {
            if (current->visitorID == id) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    void enqueue(int id) {
        Node* newNode = new Node(id);

        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
        cout << "Visitor added successfully.\n";
    }

    bool dequeue(int& id) {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return false;
        }

        Node* temp = front;
        id = front->visitorID;
        front = front->next;

        delete temp;
        count--;

        if (front == NULL) {
            rear = NULL;
        }

        return true;
    }

    bool peek(int& id) const {
        if (front == NULL) {
            return false;
        }

        id = front->visitorID;
        return true;
    }

    bool isEmpty() const {
        return front == NULL;
    }

    int size() const {
        return count;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* current = front;

        cout << "\nWaiting Visitors:\n";

        while (current != NULL) {
            cout << current->visitorID << endl;
            current = current->next;
        }
    }
};

int readNumber() {
    string input;
    int number;

    while (true) {
        if (!getline(cin, input)) {
            return 0;
        }

        stringstream ss(input);

        if (ss >> number) {
            ss >> ws;

            if (ss.eof()) {
                return number;
            }
        }

        cout << "Please enter a valid number: ";
    }
}

int main() {
    VisitorQueue q;
    int choice, id;

    do {
        cout << "\n--- Office Visitor Reception ---\n";
        cout << "1. Add Visitor\n";
        cout << "2. Check-in Next Visitor\n";
        cout << "3. Show Next Visitor\n";
        cout << "4. Display Waiting Visitors\n";
        cout << "5. Show Number of Visitors\n";
        cout << "6. Check if Queue is Empty\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        choice = readNumber();

        switch (choice) {
        case 1:
            cout << "Enter Visitor ID: ";
            id = readNumber();

            if (id <= 0) {
                cout << "ID must be positive.\n";
            }
            else if (q.contains(id)) {
                cout << "This ID already exists.\n";
            }
            else {
                q.enqueue(id);
            }
            break;

        case 2:
            if (q.dequeue(id)) {
                cout << "Visitor " << id
                     << " is ready for check-in.\n";
            }
            break;

        case 3:
            if (q.peek(id)) {
                cout << "Next Visitor ID: " << id << endl;
            }
            else {
                cout << "Queue is empty.\n";
            }
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Waiting Visitors: " << q.size() << endl;
            break;

        case 6:
            if (q.isEmpty()) {
                cout << "Queue is empty.\n";
            }
            else {
                cout << "Queue is not empty.\n";
            }
            break;

        case 0:
            cout << "Program closed.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}