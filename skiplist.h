#ifndef SKIPLIST_H
#define SKIPLIST_H

struct node 
{
    int value;
    node *below;
    node *above;
    node *before;
    node *after;
};

class skiplist
{
private:
    int height;
    node *start_pos;
    node *head;
    node *tail;
    int total_items;
    bool randomize();
    node *insert(node *pos, node *q, int key, int value);
    
public:
    skiplist();
    ~skiplist();
    node *skip_search(int key);
    node *skip_insert(int key, int value);
    void print(void);
};

#endif /* SKIPLIST_H */