#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
typedef struct ll ll;

struct ll
{
    int key;
    string name;
    ll*next = NULL;
};

ll* createMap()
{
    ll* map = new ll;
    map -> key = -1;
    map -> name = "Abc";
    return map;
}

int size(ll*head)
{
    int size;
    while(head != NULL)
    {
        head = head -> next;
        size += 1;
    }
    return size;
}

string find(ll*head, int key)
{
    while(head != NULL)
    {
        if(head -> key == key)
        {
            return head -> name;
        }
        head = head -> next;
    }
    return "Not found\n";
}

ll* insert(ll*head, int key, string name)
{
    if(head -> key == -1)
    {
        head -> key = key;
        head -> name = name;
        return head;
    }
    ll* copy = head;
    while(head != NULL)
    {
        if(head -> key == key)
        {
            head -> name = name;
            return copy;
        }
        head = head -> next;
    }

    ll* New_Node = new ll;
    New_Node -> key = key;
    New_Node -> name = name;
    New_Node -> next = copy;
    return New_Node;
}

ll* erase(ll*head, int key)
{
    if(head -> key == key)
    {
        return head -> next;
    }
    ll* current = head;
    ll* prev = head;
    while(head != NULL)
    {
        if(head -> key == key)
        {
            prev -> next = head -> next;
            return current;
        }
        prev = head;
        head = head -> next;
    }
    return current;
    cout << "\nElement not found";
}

ll*begin(ll*head)
{
    return head;
}

int main()
{
    ll*map = createMap();
    cout << map -> key;
    cout << "\nEnter number of elements to be inserted in the map: ";
    int number;
    cin >> number;

    for(int i = 0; i < number; i++)
    {
        cout << "Enter ID: ";
        int val;
        cin >> val;

        string name;
        cout << "Enter name: ";
        cin >> name;

        map = insert(map,val,name);
    }

    cout << "\nMENU\n";
    cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";

    while(true)
    {
        cout << "\nEnter choice: ";
        int choice;
        cin >> choice;
        string name;
        int val;
        ll* copy;
        switch(choice)
        {
            case 1:
                cout << "\nEnter ID: ";
                cin >> val;
                cout << "Enter name: ";
                cin >> name;
                map = insert(map,val,name);
                break;

            case 2:
                cout << "Enter ID to be searched for: ";
                cin >> val;
                name = find(map,val);
                cout << name;
                break;

            case 3:
                if(map == NULL)
                {
                    cout << "The map is empty!!\n";
                    break;
                }
                cout << "Enter ID to be deleted: ";
                cin >> val;
                map = erase(map,val);
                break;

            case 4:
                copy = map;
                while(copy != NULL)
                {
                    cout << "\nName: " << copy -> name << " ID: " << copy -> key;
                    copy = copy -> next;
                }
                cout << "\n";
                break;

            case 5:
                _Exit(0);

            default:
                cout << "\nEnter valid choice\n";
        }
    }
}
