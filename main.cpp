/*
 This program is created for testing skiplist data structure class.
 */

#include <iostream>
#include "skiplist.h"

using namespace std;

int main(int argc, char *argv[])
{
    int cmd;
    int value;
    int result;
    int exit = 1;
    skiplist *list = new skiplist();
    node *found;

    /* initialization dummy skiplist */
    list->skip_insert(12, 12);
    list->skip_insert(17, 17);
    list->skip_insert(20, 20);
    list->skip_insert(25, 25);
    list->skip_insert(31, 31);
    list->skip_insert(38, 38);
    list->skip_insert(39, 39);
    list->skip_insert(44, 44);
    list->skip_insert(50, 50);
    list->skip_insert(55, 55);

    while (exit)
    {
        cout << "1. insert item" << endl;
        cout << "2. print list" << endl;
        cout << "3. remove item" << endl;
        cout << "4. search item" << endl;
        cout << "9. exit" << endl;
        cout << "select: ";
        cin >> cmd;

        switch (cmd)
        {
        case 1:
            cout << "number: ";
            cin >> value;
            list->skip_insert(value, value);
            cout << endl;
            break;
        
        case 2:
            list->print();
            break;

        case 3:
            cout << "value: ";
            cin >> value;
            result = list->skip_remove(value);
            cout << value << " value " << ((result == 0) ? "has been deleted." \
                    : "can not be found!") << endl;
            break;
        
        case 4:
            cout << "value: ";
            cin >> value;
            result = list->skip_get_item_index(value);
            if (0 > result)
                cout << value << " can not be found" << endl;
            else
                cout << value << " found in index " << result << endl;
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