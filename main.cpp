#include <iostream>

using namespace std;

struct Node 
{
	int key;
	Node* prev;
	Node* left;
	Node* right;
};

struct Result 
{
	Node* node;
	bool success;
	int comparisons;
};

class BinaryTree {
    public:
        Node* root;
    public:
        BinaryTree()
        {
            root = nullptr;
        };
        ~BinaryTree(){};

        void insertKey(int k)
        {
            if(root == nullptr)
            {
                root = new Node();
                root->key = k;
                root->left = nullptr;
                root->right = nullptr;
            }
            else
            {
                /* Durchlaufen des Baumes über 'temp' */
                Node *walk = root;

                /* Den Knoten finden dem wir 'key' hinzuf. möchten */
                while((walk->left != nullptr) && (walk->right != nullptr))
                {
                    if(k < walk->key)
                    {
                        walk = walk->left;
                    }
                    if(k > walk->key)
                    {
                        walk = walk->right;
                    }
                }
                /* Wenn new.key kleiner ist als sein Vorgänger */
                if(k < walk->key)
                {
                    Node *add = new Node();
                    add->key = k;
                    add->left = nullptr;
                    add->right = nullptr;

                    walk->left = add;
                }
                /* Wenn new.key größer ist als sein Vorgänger */
                if(k > walk->key)
                {
                    Node *add = new Node();
                    add->key = k;
                    add->left = nullptr;
                    add->right = nullptr;

                    walk->right = add;
                }
            }
        };

};

int main() 
{
    BinaryTree *test = new BinaryTree();

    test->insertKey(16);
    test->insertKey(32);
    test->insertKey(8);

    cout << test->root->left->key << endl;
    cout << test->root->right->key;

    delete test;
    test = nullptr;

    return 0;
}
