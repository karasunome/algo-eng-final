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

node *insert(node *pos, node *q, int key, int value)
{
    node *new_node = new node;
    node *next;

    new_node->value = value;

    new_node->after = pos->after;
    new_node->before = pos;
    pos->after->before = new_node;
    pos->after = new_node;

    new_node->above = q->above;
    new_node->below = q;
    q->above->below = new_node;
    q->above = new_node;

    return new_node;
}

node *skiplist::skip_insert(int key, int value)
{
    int i = -1;
    node *pos = this->skip_search(key);
    node *q;

    do
    {
        i++;
        if (this->height <= i)
        {
            this->height++;
            start_pos = insert(NULL, start_pos, -INT_MAX, -INT_MAX);
            tail = 
           
        }
    } while (true == this->randomize());

    return NULL;
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
