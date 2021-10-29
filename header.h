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
        
        Result insertKey(int k);
        Result searchKey(int k);
        Result removeKey(int k);
};
