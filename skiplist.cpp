/*
 BBL553E Algorithm Engineering Final Project
 README: report.pdf
 */

#include <iostream>
#include <bits/stdc++.h>
#include "skiplist.h"

using namespace std;

/*
 randomize - this function generates a random integer, then
 if for odd value returns true otherwise false. This used for
 randomization.
 */
bool skiplist::randomize()
{
    if (rand()%2)
        return true;
    return false; 
}

int skiplist::get_total_items()
{
    return this->total_items;
}

/*
 This function finds and returns skip list node has value 
 equal or lesser than given key value.
 */
node *skiplist::skip_search(int key)
{
    node *pos = start_pos;

    while (pos->below != NULL)
    {
        pos = pos->below;
        while (key >= pos->after->value)
            pos = pos->after;
    }

    return pos;
}

/*
 This function finds firstly trying to find given key value
 in S0 serie. If it is failed then function returns -1. After
 that, this function finds S0 index value and returns this.
 */
int skiplist::skip_get_item_index(int key)
{
    int index = 0;
    node *pos = this->skip_search(key);

    if (pos->value != key)
        return -1;

    while (pos->before != NULL)
    {
        pos = pos->before;
        index++;
    }

    return (index);
}

/*
 This function remove the tower owns to given key value.
 Also it returns -1 when if the value is inappropriated
 or can not be found.
 */
int skiplist::skip_remove(int value)
{
    node *pos;

    if ((INT_MAX == value) || (-INT_MAX == value))
        return -1;
    
    pos = this->skip_search(value);
    if (pos->value != value)
        return -1;

    while (NULL != pos)
    {
        pos->before->after = pos->after;
        pos->after->before = pos->before;
        pos = pos->above;
    }

    return 0;
}

/*
 This function adds given value after node p and above node q.
 If p is NULL, this is for adding first node of new level to skip list.
 If q is NULL, this is another special state for adding end node to new level.
 Otherwise when this function called, new node is created and before, after,
 above and below positions are assigned.
 */
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

    this->total_items++;

    return new_node;
}

/*
 This function inserts a new value to the skip list.
 The insertion algorithm is explained step by step below.
 i - Position for new value is found by skip_search. pos pointer
   initialized to this positon. q pointer is null at the begining.
 ii - Every time i and height of skip list are compared and
   if no enough level exists, new level is added to skiplist.
   value i is incremented every loop.
 iii - After that, given value is added to current level. Then pos
   pointer is moved to before positon of value on the higher level.
 iv - This steps repeats until the randomize function returns true.
 */
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

    return q;
}

/*
 This function prints value from the higher level left most position
 of skip list to the last item of skiplist.
 */
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

/*
 construction function for skiplist. This function create first level.
 this level only consists of -INT_MAX and +INT_MAX values.
 */
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

/*
 
 */
skiplist::~skiplist()
{
}
