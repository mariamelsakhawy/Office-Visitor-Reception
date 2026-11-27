#include<iostream>
#include<string>
using namespace std;

class room
{
public:
    int id;
    string name;
    int capacity;
    bool isbooked;
};

class node
{
public:
    room data;
    node* next;
};

class linkedlist
{
private:
    node* head;
    int size;

public:
    linkedlist()
    {
        head = NULL;
        size = 0;
    }

    ~linkedlist()
    {
        clear();
    }

    bool isempty()
    {
        return (head == NULL);
    }

    int count()
    {
        return size;
    }

    node* search(int item)
    {
        node* temp = head;
        while (temp != NULL)
        {
            if (temp->data.id == item)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    bool isfound(int item)
    {
        return (search(item) != NULL);
    }

    void append(room r)
    {
        if (isfound(r.id))
        {
            cout << "room id already exists\n";
            return;
        }
        node* newnode = new node;
        newnode->data = r;
        newnode->next = NULL;
        if (isempty())
        {
            head = newnode;
        }
        else
        {
            node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        size++;
    }

    void Delete(int item)
    {
        if (isempty())
        {
            cout << "the list is empty\n";
            return;
        }
        node* delptr = head;
        node* prev = NULL;
        while (delptr != NULL && delptr->data.id != item)
        {
            prev = delptr;
            delptr = delptr->next;
        }
        if (delptr == NULL)
        {
            cout << "item not found\n";
            return;
        }
        if (prev == NULL)
        {
            head = delptr->next;
        }
        else
        {
            prev->next = delptr->next;
        }
        delete delptr;
        size--;
    }

    void update(int item, string newname, int newcapacity)
    {
        node* temp = search(item);
        if (temp == NULL)
        {
            cout << "item not found\n";
            return;
        }
        temp->data.name = newname;
        temp->data.capacity = newcapacity;
    }

    bool bookRoom(int item)
    {
        node* temp = search(item);
        if (temp == NULL)
        {
            cout << "room not found\n";
            return false;
        }
        if (temp->data.isbooked)
        {
            cout << "room is already booked\n";
            return false;
        }
        temp->data.isbooked = true;
        cout << "room " << temp->data.name << " booked successfully\n";
        return true;
    }

    bool releaseRoom(int item)
    {
        node* temp = search(item);
        if (temp == NULL)
        {
            cout << "room not found\n";
            return false;
        }
        if (!temp->data.isbooked)
        {
            cout << "room is already available\n";
            return false;
        }
        temp->data.isbooked = false;
        cout << "room " << temp->data.name << " is now available\n";
        return true;
    }

    node* findAvailableRoom()
    {
        node* temp = head;
        while (temp != NULL)
        {
            if (!temp->data.isbooked)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void display()
    {
        if (isempty())
        {
            cout << "the list is empty\n";
            return;
        }
        node* temp = head;
        cout << "id\tname\t\tcapacity\tstatus\n";
        while (temp != NULL)
        {
            cout << temp->data.id << "\t" << temp->data.name << "\t\t" << temp->data.capacity << "\t\t";
            if (temp->data.isbooked)
            {
                cout << "booked\n";
            }
            else
            {
                cout << "available\n";
            }
            temp = temp->next;
        }
    }

    void clear()
    {
        while (head != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};

bool bad()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "invalid input, please enter a number\n";
        return true;
    }
    return false;
}

bool readroom(room& r)
{
    cout << "enter room id: ";
    cin >> r.id;
    if (bad())
    {
        return false;
    }
    if(r.id<0){
        cout<<"room id must be psitive\n";
        return false;
    }
    cin.ignore();
    cout << "enter room name: ";
    getline(cin, r.name);
    cout << "enter room capacity: ";
    cin >> r.capacity;
    if (bad())
    {
        return false;
    }
    if (r.capacity <= 0)
    {
        cout << "capacity must be greater than 0\n";
        return false;
    }
    r.isbooked = false;
    return true;
}

int main()
{
    linkedlist l1;
    int choice;
    int item;
    int newcapacity;
    string newname;
    room r;

    do
    {
        cout << "\n1) add room   2) delete\n";
        cout << "3) search         4) update        5) display        6) count\n";
        cout << "7) book room     8) release room 9) find available 0) exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        if (bad())
        {
            choice = -1;
            continue;
        }

        switch (choice)
        {
            case 1:
                if (readroom(r))
                {
                    l1.append(r);
                }
                break;

           

            case 2:
                cout << "enter room id to delete: ";
                cin >> item;
                if (bad())
                {
                    break;
                }
                l1.Delete(item);
                break;

            case 3:
            {
                cout << "enter room id to search: ";
                cin >> item;
                if (bad())
                {
                    break;
                }
                node* found = l1.search(item);
                if (found != NULL)
                {
                    cout << "item is found: " << found->data.name
                         << " (capacity " << found->data.capacity << ", ";
                    if (found->data.isbooked)
                    {
                        cout << "booked)\n";
                    }
                    else
                    {
                        cout << "available)\n";
                    }
                }
                else
                {
                    cout << "item not found\n";
                }
                break;
            }

            case 4:
                cout << "enter room id to update: ";
                cin >> item;
                if (bad())
                {
                    break;
                }
                cin.ignore();
                cout << "enter the new name: ";
                getline(cin, newname);
                cout << "enter the new capacity: ";
                cin >> newcapacity;
                if (bad())
                {
                    break;
                }
                if (newcapacity <= 0)
                {
                    cout << "capacity must be greater than 0\n";
                    break;
                }
                l1.update(item, newname, newcapacity);
                break;

            case 5:
                l1.display();
                break;

            case 6:
                cout << "the list contains: " << l1.count() << endl;
                break;

            case 7:
                cout << "enter room id to book: ";
                cin >> item;
                if (bad())
                {
                    break;
                }
                l1.bookRoom(item);
                break;

            case 8:
                cout << "enter room id to release: ";
                cin >> item;
                if (bad())
                {
                    break;
                }
                l1.releaseRoom(item);
                break;

            case 9:
            {
                node* avail = l1.findAvailableRoom();
                if (avail != NULL)
                {
                    cout << "first available room: ID " << avail->data.id
                         << " - " << avail->data.name
                         << " (capacity " << avail->data.capacity << ")\n";
                }
                else
                {
                    cout << "no available rooms right now\n";
                }
                break;
            }

            case 0:
                cout << "goodbye\n";
                break;

            default:
                cout << "invalid choice\n";
        }
    }
    while (choice != 0);

    return 0;
}