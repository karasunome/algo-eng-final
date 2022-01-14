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
    
public:
    skiplist();
    ~skiplist();
    int insert(int value);
    int remove(int index);
    int search(int index);
    node *skip_search(int key);
    node *skip_insert(int key, int value);
    void print(void);
};

#endif /* SKIPLIST_H */