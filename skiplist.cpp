#include <iostream>
#include <bits/stdc++.h>
#include "skiplist.h"

using namespace std;

bool skiplist::randomize()
{
    srand((unsigned)time(NULL));
    if (1 == rand()%2)
    {
        printf("even\n");
        return true;
    }
    printf("odd\n");
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

    if ((NULL == p) || (NULL == q)) /* when we add a new level */
    {
        new_node->before = p;
        new_node->after = NULL;
        new_node->above = NULL;
        new_node->below = q;
        q->above = new_node;
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
    node *q;
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
        while (NULL == pos->above)
            pos = pos->before;
        pos = pos->above;
        q = this->insert(pos, q, key, value);
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
