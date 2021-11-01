#include <iostream>
using namespace std;

/*struct Node: Elemente vom Baum*/
template <typename A>
struct Node {
	A key;
	Node* prev;
	Node* left;
	Node* right;
};

/*struct Result: Rückgabeobjekt*/
template <typename B>
struct Result {
	Node<B> *node;
	bool success;
	int comparisons;
};

/*class BinaryTree: Implementation der Datenstruktur "Binärer Baum*"*/
template <typename C>
class BinaryTree {
    public:
        Node<C> *root;
    public:
        BinaryTree(){
            root = nullptr;
        };
        ~BinaryTree(){};

        Result<C> insertKey(C k)
        {
            /*Rückgabe Vergleiche*/
            int comp = 0;
	    /*Zum durchlaufen*/
            Node<C> *walk = new Node<C>();

            /*Wenn die Liste leer ist*/
            if(root == nullptr)
            {
                root = new Node<C>();
                root->key = k;
                root->left = nullptr;
                root->right = nullptr;
                comp = 1;
            }
            else
            {
                /*Zum Durchlaufen des Baumes*/
                walk = root;

                /* Den Knoten finden dem der Schlüssel hinzugefügt wird */
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
	    	Node<C> *add = new Node<C>();
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
            	Node<C> *add = new Node<C>();
		add->key = k;
		add->prev = walk;
		add->left = nullptr;
		add->right = nullptr;

		walk->right = add;

		walk = walk->right;
	    }

            /*Rückgabe Objekt konstruieren*/
	    Result<C> res;
	    res.comparisons = comp;
	    res.node = walk;
	    res.success = true;

	    return res;
        };
};


int main() {
    /*Driver Code*/
    BinaryTree<int> *t = new BinaryTree<int>();
    Result<int> i = t->insertKey(16);
    Result<int> ii = t->insertKey(32);
    Result<int> iii = t->insertKey(8);

    cout << i.comparisons << ", " << i.node->key << ", " << i.success << endl;
    cout << ii.comparisons << ", " << ii.node->key << ", " << ii.success << endl;
    cout << iii.comparisons << ", " << iii.node->key << ", " << iii.success << endl;
}
