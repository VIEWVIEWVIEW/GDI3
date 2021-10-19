class BinaryTree() {

BinaryTree() {

    initialize();
};

~BinaryTree() {

    delete();
};

private:
Node *root;

pair<Node*, int> insert(int k);
pair<Node*, int> remove();
pair<bool,  int> contains();
pair<Node*, int> search(int k);

void initialize();
void delete();
}
