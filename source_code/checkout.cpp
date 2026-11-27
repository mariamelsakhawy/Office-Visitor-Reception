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

    string peek()
    {
        if (isEmpty())
        {
            return "Stack Is Empty";
        }

        return "Name: " + checkout[top].name +
            "\nCheckoutTime : " + checkout[top].checkoutTime;
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
    
    return 0;
}