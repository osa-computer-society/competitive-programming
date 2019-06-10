#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct node {
    int n;
    node* left = nullptr;
    node* right = nullptr;
};

string traverse(node* root, int depth) {
    if (root == nullptr)
        return "";
    
    string ans;
    ans += traverse(root->left, depth + 1);
    ans += char(depth);
    ans += traverse(root->right, depth + 1);
    return ans;
}

void insert(node* root, int n)
{
    if (n > root->n)
    {
        if (root->right == nullptr)
        {
            node* temp = new node;
            temp->n = n;
            root->right = temp;
        }
        else
        {
            insert(root->right, n);
        }
    }

    else if (n < root->n)
    {
        if (root->left == nullptr)
        {
            node* temp = new node;
            temp->n = n;
            root->left = temp;
        }
        else
        {
            insert(root->left, n);
        }
    }
}

int main()
{
    int trees, nodes, t;
    cin >> trees >> nodes;

    unordered_map<string, int> designs;

    for (int i = 0; i < trees; i++) {
        node* n = new node;
        n->n = -1;
        for (int j = 0; j < nodes; j++) {
            cin >> t;
            insert(n, t);
        }

        string s = traverse(n, 0);
        designs[s]++;
    }

    int total;
    for (auto i : designs) {
        total++;
    }

    cout << total << endl;
}