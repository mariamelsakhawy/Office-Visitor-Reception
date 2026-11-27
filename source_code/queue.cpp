#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Queue Node
struct QueueNode {
    int visitorID;
    QueueNode* next;

    QueueNode(int id) : visitorID(id), next(NULL) {}
};

class VisitorQueue {
private:
    QueueNode *front, *rear;
    int count;

public:
    VisitorQueue() {
        front = rear = NULL;
        count = 0;
    }

    ~VisitorQueue() {
        while (front != NULL) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        count = 0;
    }

    bool contains(int id) {
        QueueNode* curr = front;
        while (curr != NULL) {
            if (curr->visitorID == id)
                return true;
            curr = curr->next;
        }
        return false;
    }

    void enqueue(int id) {
        QueueNode* n = new QueueNode(id);

        if (rear == NULL) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }

        count++;
        cout << "Visitor added successfully.\n";
    }

    bool dequeue(int& id) {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return false;
        }

        QueueNode* temp = front;
        id = front->visitorID;
        front = front->next;

        delete temp;
        count--;

        if (front == NULL)
            rear = NULL;

        return true;
    }

    bool peek(int& id) {
        if (front == NULL)
            return false;

        id = front->visitorID;
        return true;
    }

    bool isEmpty() {
        return front == NULL;
    }

    int size() {
        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        QueueNode* curr = front;
        cout << "\nWaiting Visitors:\n";
        while (curr != NULL) {
            cout << curr->visitorID << "\n";
            curr = curr->next;
        }
    }
};

// safely read integer input
int readNumber() {
    string line;
    int num;

    while (true) {
        if (!getline(cin, line))
            return 0;

        stringstream ss(line);
        if (ss >> num) {
            ss >> ws;
            if (ss.eof())
                return num;
        }

        cout << "Please enter a valid number: ";
    }
}

int main() {
    VisitorQueue q;
    int choice, id;

    do {
        cout << "\n--- Office Visitor Reception ---\n"
             << "1. Add Visitor\n"
             << "2. Check-in Next Visitor\n"
             << "3. Show Next Visitor\n"
             << "4. Display Waiting Visitors\n"
             << "5. Show Number of Visitors\n"
             << "6. Check if Queue is Empty\n"
             << "0. Exit\n"
             << "Enter choice: ";

        choice = readNumber();

        switch (choice) {
            case 1:
                cout << "Enter Visitor ID: ";
                id = readNumber();

                if (id <= 0) {
                    cout << "ID must be positive.\n";
                } else if (q.contains(id)) {
                    cout << "This ID already exists.\n";
                } else {
                    q.enqueue(id);
                }
                break;

            case 2:
                if (q.dequeue(id)) {
                    cout << "Visitor " << id << " is ready for check-in.\n";
                }
                break;

            case 3:
                if (q.peek(id))
                    cout << "Next Visitor ID: " << id << "\n";
                else
                    cout << "Queue is empty.\n";
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Waiting Visitors: " << q.size() << "\n";
                break;

            case 6:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
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