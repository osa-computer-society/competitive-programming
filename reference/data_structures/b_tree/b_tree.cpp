/**
 * @file b_tree.cpp
 * @author Alexander Cai
 * @brief An implementation of a B-Tree.
 * @version 0.1
 * @date 2022-02-13
 * 
 * See Chapter 18 of CLRS.
 * 
 * A B-Tree is designed to store data that mostly resides on disk.
 * 
 * Since disk reads are quite expensive, we want to think about the number of
 * disk reads in big oh notation as well as simply the time complexity.
 * 
 * Essentially, we reduce the height using a larger branching factor,
 * since most of our disk reads are done as we traverse downwards in the tree.
 */
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    int n;            // number of keys
    vector<T> key;    // n keys in nondecreasing order
    vector<Node *> c; // n+1 pointers to children, undefined for leaf nodes
    bool leaf;
};

template <typename T>
struct Tree
{
    Node<T> *root;
    int t; // minimum number of children, 2t is maximum

    Node<T> *allocate_node();
    Tree(int t_);
    pair<Node<T> *, int> search(Node<T> *root, T k);
    void split_child(Node<T> *x, int i);
    void insert_nonfull(Node<T> *x, T k);
    void insert(T k);
    void display(Node<T> *x, int depth);
    void merge(Node<T> *x, int i);
    pair<Node<T> *, int> predecessor(Node<T> *x, T k);
    void delete_key(Node<T> *x, T k);
};

template <typename T>
Node<T> *Tree<T>::allocate_node()
{
    Node<T> *x = new Node<T>;
    x->key.resize(2 * t);   // can have at most 2t-1 keys
    x->c.resize(2 * t + 1); // thus at most 2t children
    return x;
}

// O(1) disk operations
// O(1) CPU time
template <typename T>
Tree<T>::Tree(int t_)
{
    t = t_;
    Node<T> *x = allocate_node();
    x->leaf = true;
    x->n = 0;
    root = x;
    // "write x to disk"
}

/**
 * @brief Find key k in the subtree rooted at x.
 * 
 * O(th) = O(t log_t n) CPU time
 * O(h) = O(log_t n) disk accesses
 * since the else statement at end travels down in the tree
 * 
 * @param x the root of the subtree
 * @param k the key to search for
 * @return (y :: Node<T>, i :: int) such that y->c[i-1] == k
 */
template <typename T>
pair<Node<T> *, int> Tree<T>::search(Node<T> *x, T k)
{
    // if found, returns node and index of k in that node's keys
    // otherwise nil
    int i = 1;
    while (i <= x->n && k > x->key[i - 1])
        ++i;
    // alternatively could use binary search in keys of x

    // if key found
    if (i <= x->n && k == x->key[i - 1])
        return {x, i};
    else if (x->leaf)
        return {nullptr, 0};
    else
    {
        // "read x.c[i] from disk"
        return search(x->c[i - 1], k);
    }
}

/**
 * @brief Assuming the ith child of x is full, splits it into two children of x.
 * 
 * To split the root, we make it a child of a new empty root node, growing the tree.
 * This is the only way the tree grows.
 * 
 * Theta(t) CPU time, see loops
 * O(1) disk ops
 * 
 * @param x the parent, a nonfull internal node
 * @param i index of full child of x (ie x->c[i-1]->n == 2t - 1)
 */
template <typename T>
void Tree<T>::split_child(Node<T> *x, int i)
{
    // x's ith child, originally with 2t children,
    Node<T> *y = x->c[i - 1];

    // new node to contain the t largest children (ie t-1 keys) from y
    // becomes new child of x at index i+1
    Node<T> *z = allocate_node();
    z->leaf = y->leaf;
    z->n = t - 1;
    for (int j = 1; j <= t - 1; ++j)
        z->key[j - 1] = y->key[j + t - 1];
    if (!y->leaf)
        for (int j = 1; j <= t; ++j)
            z->c[j - 1] = y->c[j + t - 1];

    y->n = t - 1; // now y has t children, ie t-1 keys

    // insert z into index i+1 in x's children
    // insert the median key into index i in x's keys
    // alternative from CLRS
    if (false)
    {
        // insert z as the i+1th child of x, moving everything else down
        // remember assumption that x is not full, ie x->n < 2t-1
        for (int j = x->n + 1; j >= 1; --j)
            x->c[j + 1 - 1] = x->c[j - 1];
        x->c[i + 1 - 1] = z;

        for (int j = x->n; j >= i; --j)
            x->key[j + 1 - 1] = x->key[j - 1];
        x->key[i - 1] = y->key[t - 1];
    }
    else
    {
        x->c.insert(x->c.begin() + (i + 1 - 1), z);
        // the median key of y gets moved up into x
        x->key.insert(x->key.begin() + (i - 1), y->key[t - 1]);
    }

    ++x->n;

    // write x, y, z to disk
}

/**
 * @brief Inserts key k into node x, which is assumed to be nonfull
 * 
 * O(h) disk accesses, since O(1) per call
 * total CPU time is O(th) = O(t log_t n)
 * since it is tail recursive, main memory usage is only O(1)
 * 
 * @param x 
 * @param k 
 */
template <typename T>
void Tree<T>::insert_nonfull(Node<T> *x, T k)
{
    cout << "inserting " << k << " into " << x << '\n';
    int i = x->n;
    // if x is a leaf, we just insert it
    if (x->leaf)
    {
        while (i >= 1 && k < x->key[i - 1])
        {
            x->key[i + 1 - 1] = x->key[i - 1];
            --i;
        }
        x->key[i + 1 - 1] = k;
        ++x->n;
        // "write x to disk"
    }
    // otherwise we need to insert it
    // into the appropriate leaf node in the subtree rooted at x
    else
    {
        // find largest i such that k >= the ith key
        while (i >= 1 && k < x->key[i - 1])
            --i;
        ++i;
        // "read x.c[i-1] from disk"

        // ensure that we never recurse to a full node
        if (x->c[i - 1]->n == 2 * t - 1) // if the ith child of x is full
        {
            split_child(x, i);
            if (k > x->key[i - 1])
                ++i;
        }
        insert_nonfull(x->c[i - 1], k);
    }
}

template <typename T>
void Tree<T>::insert(T k)
{
    Node<T> *r = root;
    if (r->n == 2 * t - 1) // if the root is full
    {
        Node<T> *s = allocate_node();
        root = s;
        s->leaf = false;
        s->n = 0;
        s->c[1 - 1] = r;
        split_child(s, 1);
        insert_nonfull(s, k);
    }
    else
        insert_nonfull(r, k);
}

template <typename T>
void Tree<T>::display(Node<T> *x, int depth)
{
    for (int i = 1; i <= x->n + 1; ++i)
    {
        if (i > 1)
        {
            for (int _ = 1; _ <= depth; ++_)
                cout << '\t';
            cout << x->key[i - 1 - 1] << '\n';
        }
        if (!x->leaf)
        {
            display(x->c[i - 1], depth + 1);
        }
    }
}

/**
 * @brief Assumes that the ith and (i+1)th children of x both have t-1 keys. Merges them and the ith key of x into a new node with 2t-1 keys.
 * 
 * @param x 
 * @param k 
 */
template <typename T>
void Tree<T>::merge(Node<T> *x, int i)
{
    Node<T> *y = x->c[i - 1], *z = x->c[i + 1 - 1];

    // y and z both have only t-1 keys
    // append k and all of z's keys to the end of y
    y->key[t - 1] = k;
    for (int i = 1; i <= t - 1; ++i)
        y->key[t + i - 1] = z->key[i - 1];
    // if z is an internal node, copy it over
    if (!z->leaf)
        for (int i = 1; i <= t; ++i)
            y->c[t + i - 1] = z->c[i - 1];
    y->n = 2 * t - 1;

    free(z);

    // delete z from x's children and k from x's keys
    x->key.erase(x->key.begin() + (i - 1));
    x->c.erase(x->c.begin() + (i + 1 - 1));
    --x->n;
}

/**
 * @brief Deletes k from the subtree rooted at x. Guarantees that whenever it is called on x, the number of keys in x is at least t.
 * 
 * If the root node becoems an internal node with no keys, we delete it and make its only child the new root.
 * 
 * O(h) io operations, since O(1) rw ops are made for each call
 * O(th) = O(t log_t n) CPU time
 * 
 * @param x 
 * @param k 
 */
template <typename T>
void Tree<T>::delete_key(Node<T> *x, T k)
{
    int i = 1;
    while (i <= n && k > x->key[i - 1])
        ++i;

    // key found
    if (i <= x->n && k == x->key[i - 1])
    {
        if (x->leaf)
        {
            x->key.erase(x->key.begin() + (i - 1));
        }
        else
        {
            Node<T> *y = x->c[i - 1];
            if (y->n >= t)
            {
                // delete the rightmost key in the child
                delete_key(y, y->key[y->n - 1]);
            }
            else
            {
                // "read x->c[i+1-1] from disk"
                Node<T> *z = x->c[i + 1 - 1];

                if (z->n >= t)
                {
                    // delete the leftmost key in the child
                    delete_key(z, z->key[1 - 1]);
                }
                else
                {
                    merge(x, i);

                    delete_key(y, k);
                }
            }
        }
    }
    // if k is not present, i is the index of the child that will contain k
    else
    {
        Node<T> *y = x->c[i - 1];
        if (y->n == t - 1)
        {
            // if the left neighbour has more than t keys,
            // we move the ith key of x (the divider between them) into this node,
            // and move the rightmost key of that neighbour into x
            if (i > 1 && x->c[i - 1 - 1]->n >= t)
            {
                Node<T> *z = x->c[i - 1 - 1];
                y->key.insert(y->key.begin(), x->key[i - 1]);
                y->c.insert(y->c.begin(), z->c[z->n + 1 - 1]);
                x->key[i - 1] = z->c[z->n - 1];
                ++y->n;
                --z->n;
            }
            // similarly for the right neighbour
            else if (i < t - 1 && x->c[i + 1 - 1]->n >= t)
            {
                Node<T> *z = x->c[i + 1 - 1];
                y->key[t - 1] = x->key[i + 1 - 1];
                y->c[t + 1 - 1] = z->c[1 - 1];
                x->key[i + 1 - 1] = z->c[1 - 1];
                ++y->n;
                --z->n;
            }
            // otherwise, all neighbours have t-1 keys, so merge with right neighbour (arbitrary)
            else
                merge(x, i);
        }
        delete_key(x->c[i - 1], k);
    }
}

int main()
{
    Tree<int> tree(2);

    // vector<int> vals{1, 2, 3, 4, 5, 6};
    for (int x = 1; x <= 10; ++x)
        tree.insert(x);
    tree.display(tree.root, 0);

    return 0;
}