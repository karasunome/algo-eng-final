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
    node *head;
    node *tail;
    int total_items;
    
public:
    skiplist();
    ~skiplist();
    int insert(int value);
    int remove(int index);
    int search(int index);
    void print(void);
};

#endif /* SKIPLIST_H */