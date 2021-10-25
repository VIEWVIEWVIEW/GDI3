struct Node
{
	int key;
	Node* prev;
	Node* left;
	Node* right;
}

struct Result
{
	Node* node;
	bool success;
	int comparisons;
}

class BinaryTree

{
    private:
        Node* root;

    public:
        BinaryTree();
        ~BinaryTree();
        
        Result insertKey(int key);
        Result searchKey(int key);
        Result removeKey(int key);
};
