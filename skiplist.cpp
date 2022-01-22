#include <iostream>
#include <bits/stdc++.h>
#include "skiplist.h"

using namespace std;

bool skiplist::randomize()
{
    //srand((unsigned)time(NULL));
    if (rand()%2)
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

node *skiplist::insert(node *p, node *q, int key, int value)
{
    node *new_node = new node;
    new_node->value = value;

    if (NULL == p) /* when we add a new level */
    {
        new_node->before = p;
        new_node->after = NULL;
        new_node->above = NULL;
        new_node->below = q;
        q->above = new_node;
    }
    else if (NULL == q)
    {
        new_node->before = p;
        new_node->after = p->after;
        new_node->above = NULL;
        new_node->below = NULL;
        p->after->before = new_node;
        p->after = new_node;
    }
    else
    {
        new_node->before = p;
        new_node->after = p->after;
        new_node->below = q;
        new_node->above = q->above;
        p->after = new_node;
        q->above = new_node;
    }

    return new_node;
}

node *skiplist::skip_insert(int key, int value)
{
    int i = -1;
    node *pos = this->skip_search(key);
    node *q = NULL;
    node *start_pos_after;

    do
    {
        i++;
        if (this->height <= i) /* add new level */
        {
            this->height++;
            start_pos_after = start_pos->after;
            start_pos = this->insert(NULL, start_pos, -INT_MAX, -INT_MAX);
            this->insert(start_pos, start_pos_after, +INT_MAX, +INT_MAX);
        }
        q = this->insert(pos, q, key, value);
        while (NULL == pos->above)
            pos = pos->before;
        pos = pos->above;
    } while (true == this->randomize());

    this->total_items++;

    return q;
}

void skiplist::print(void)
{
    for (node* p = start_pos; NULL != p; p = p->below)
    {
        for (node *q = p; NULL != q; q = q->after)
        {
            printf("[%d] ", q->value);
        }
        printf("\n");
    }
}

skiplist::skiplist()
{
    this->total_items = 0;
    this->height = 0;

    start_pos = new node;
    start_pos->after = new node;

    start_pos->value = -INT_MAX;
    start_pos->after->value = INT_MAX;

    start_pos->above = NULL;
    start_pos->before = NULL;
    start_pos->below = NULL;

    start_pos->after->before = start_pos;
    start_pos->after->above = NULL;
    start_pos->after->after = NULL;
    start_pos->after->below = NULL;
}

skiplist::~skiplist()
{
}
