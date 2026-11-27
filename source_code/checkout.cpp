#include <iostream>
#include <string>
using namespace std;

struct CHECKOUTTIME
{
    string name;
    string checkoutTime;
};

#define MAX_SIZE  100

class Checkout {
private:
    CHECKOUTTIME checkout[MAX_SIZE];
    int top = -1;

public:
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(string name, string checkoutTime) {
        if (isFull()) {
            return;
        }
        else {
            top++;
            checkout[top].name = name;
            checkout[top].checkoutTime = checkoutTime;
        }
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        else {
            top--;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack Is Empty";
            return;
        }

        cout << "Name: " + checkout[top].name <<
            "\nCheckoutTime : " << checkout[top].checkoutTime;
    }
    int size() {
        return top + 1;
    }
    void disPlay() {
        if (isEmpty()) {
            cout << "  Stack Is Empty " << endl;
            return;

        }

        for (int i = top; i >= 0; i--) {
            cout << "Name : " << checkout[i].name << endl << "CheckoutTime : " << checkout[i].checkoutTime << endl;
        }

    }
};


int main() {
    Checkout c;

    string name, checkouttime;
    int choice;
    do {
        cout << "\n--- Stack Menu--\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. peek\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Size of the stack\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter name and checkout time: ";
            cin >> name >> checkouttime;
            c.push(name, checkouttime);
            break;
        case 2:
            c.pop();
            break;

        case 3:
            c.peek();
            break;
        case 4:
            if (c.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;
        case 5:
            if (c.isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not ful1.\n";
            break;
        case 6:
            cout << "Current size of stack:" << c.size();
            break;
        case 7:
            c.disPlay();
            break;
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid Choice! Please try again.\n";
        }
        } while (choice  != 8);

    
    return 0;
}