#include <iostream>
#include "skiplist.h"

using namespace std;

int main(int argc, char *argv[])
{
    int cmd;
    int value;
    int exit = 1;
    skiplist *list = new skiplist();

    while (exit)
    {
        cout << "1. insert item" << endl;
        cout << "2. print list" << endl;
        cout << "3. remove item" << endl;
        cout << "4. search item" << endl;
        cout << "9. exit" << endl;
        cin >> cmd;

        switch (cmd)
        {
        case 1:
            cout << "number: ";
            cin >> value;
            list->insert(value);
            cout << endl;
            break;
        
        case 2:
            list->print();
            break;

        case 3:
            cout << "index: ";
            cin >> value;
            list->remove(value);
            cout << endl;
            break;
        
        case 4:
            cout << "value: ";
            cin >> value;
            cout << "index = " << list->search(value) << endl;
            break;

        case 9:
            exit = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}