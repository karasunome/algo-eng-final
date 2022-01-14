#include <iostream>
#include <bits/stdc++.h>
#include "skiplist.h"

using namespace std;

bool randomize()
{
    srand((unsigned)time(0));
    if (0 == rand()%2)
        return true;
    return false; 
}

node *skiplist::skip_search(int key)
{
    int index = 0;
    node *pos = start_pos;

    while (pos->below != NULL)
    {
        pos = pos->below;
        while (key >= pos->after->value)
            pos = pos->after;
    }

    return pos;
}

node *skiplist::skip_insert(int key, int value)
{
    int i = -1;
    node *pos = skip_search(key);

    while (true == randomize())
    {
        i++;
        if (this->height <= i)
        {
            this->height++;

        }
    }
}

int skiplist::search(int value)
{
    int index = 0;
    node *next;

    next = this->head->after;
    while(next->value != value && next != this->tail)
    {
        index++;
        next = next->after;
    }

    return (index == this->total_items ? -1 : index);
}

int skiplist::remove(int index)
{
    node *next;
    node *temp_before;
    node *temp_after;

    if (this->total_items <= index)
        return -1;

    next = this->head->after;
    while(index--)
        next = next->after;

#if DEBUG
    cout << index << endl;
    cout << next->value << endl;
#endif

    temp_after = next->after;
    temp_before = next->before;
    delete next;
    temp_after->before = temp_before;
    temp_before->after = temp_after;

    this->total_items--;

    return 0;
}

int skiplist::insert(int value)
{
    node *new_node = new node;
    node *next;

    new_node->value = value;

    next = this->head;
    while (next->value < value)
        next = next->after;
    next = next->before;

    new_node->after = next->after;
    next->after->before = new_node;
    next->after = new_node;
    new_node->before = next;

    this->total_items++;

    return 0;
}

void skiplist::print(void)
{
    node *next = this->head;
    while (next != this->tail)
    {
        cout << "[" << next->value << "] ";
        next = next->after;
    }
    cout << "[" <<  this->tail->value << "] " << endl;
}

skiplist::skiplist()
{
    this->total_items = 0;
    this->head = new node;
    this->tail = new node;

    this->head->value = -INT_MAX;
    this->tail->value = INT_MAX;
    this->head->after = this->tail;
    this->tail->before = this->head;
    start_pos = head;
}

skiplist::~skiplist()
{
}
