#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* prev;
	Node* left;
	Node* right;
};

struct Result {
	Node* node;
	bool success;
	int comparisons;
};

class BinaryTree {
    public:
        Node *root;
    public:
        BinaryTree(){
            root = nullptr;
        };
        ~BinaryTree(){};

        Result insertKey(int k)
        {
            /*Rückgabe Vergleiche*/
            int comp = 0;
	    /*Zum durchlaufen*/	
            Node *walk = new Node();
		
            /*Wenn die Liste leer ist*/
            if(root == nullptr)
            {
                root = new Node();
                root->key = k;
                root->left = nullptr;
                root->right = nullptr;
                comp = 1;
            }
            else
            {
                /*Zum durchlaufen des Baumes*/
                walk = root;

                /* Den Knoten finden dem wir 'key' hinzuf. möchten */
                while((walk->left != nullptr) && (walk->right != nullptr))
                {
                    if(k < walk->key)
                    {
                        walk = walk->left;
                        comp = comp + 1;
                    }
                    if(k > walk->key)
                    {
                        walk = walk->right;
                        comp = comp + 1;
                    }
                }
            }
		
            /* Ist der Vorgänger größer */
	    if(k < walk->key)
            {
	    	Node *add = new Node();
		add->key = k;
		add->prev = walk;
		add->left = nullptr;
		add->right = nullptr;

		walk->left = add;

		walk = walk->left;
	    }
		
	    /* Ist der Vorgänger kleiner */
	    if(k > walk->key)
	    {
            	Node *add = new Node();
		add->key = k;
		add->prev = walk;
		add->left = nullptr;
		add->right = nullptr;

		walk->right = add;

		walk = walk->right;
	    }
		
            /*Rückgabe Objekt konstruieren*/
	    Result res;
	    res.comparisons = comp;
	    res.node = walk;
	    res.success = true;

	    return res;
        };
};


int main() {

    BinaryTree *t = new BinaryTree();
    Result i = t->insertKey(16);
    Result ii = t->insertKey(32);
    Result iii = t->insertKey(8);

    cout << i.comparisons << ", " << i.node->key << ", " << i.success << endl;
    cout << ii.comparisons << ", " << ii.node->key << ", " << ii.success << endl;
    cout << iii.comparisons << ", " << iii.node->key << ", " << iii.success << endl;
}
