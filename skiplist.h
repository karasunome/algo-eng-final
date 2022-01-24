#ifndef SKIPLIST_H
#define SKIPLIST_H

/* node structure */
struct node 
{
    int value;      /* value of node */
    node *below;    /* below node pointer */
    node *above;    /* above node pointer */
    node *before;   /* before node pointer */
    node *after;    /* after node pointer */
};

/* skiplist class */
class skiplist
{
private:
    /* private variable declerations */
    int height; /* height of the list */
    node *start_pos; /* top and left most position */
    int total_items; /* total node counts */

    /* private function declerations */
    bool randomize();
    node *insert(node *pos, node *q, int key, int value);
    
public:
    /* public function declerations */
    skiplist();
    ~skiplist();
    node *skip_search(int key);
    node *skip_insert(int key, int value);
    int skip_get_item_index(int key);
    int skip_remove(int value);
    void print(void);
    int get_total_items();
};

#endif /* SKIPLIST_H */