#include <iostream>
#include <vector>

using namespace std;

class BinarySearchTree {
private:
    struct Node{
        int data;
        struct Node* left;
        struct Node* right;
    };


    Node* findMin(Node *node){
        if(node == NULL) // empty tree
            return NULL;
        else if(node -> left == NULL)
            return node; // leftmost element
        else
            return findMin(node -> left); // recursive call with left subtree
    }

    Node* findMax(Node *node){
        if(node == NULL) // empty tree
            return NULL;
        else if(node -> right == NULL)
            return node; // rightmost element
        else
            return findMin(node -> right); // recursive call with right subtree
    }

    Node* containsHelper(Node *node, int val) {
        if(node == NULL)
            return NULL;
        if(node -> data == val)
            return node;
        else if(node -> data < val)
            return containsHelper(node -> right, val); // check in right subtree
        else
            return containsHelper(node -> left, val); // check in left subtree
    }

    Node* insertHelper(Node *node, int val) {

        if(node == NULL){
            node = new Node;
            node -> data = val;
            node -> left = NULL;
            node -> right = NULL;
            return node;
        } // create new node

        if(node -> data < val){
            if(node -> right != NULL)
                insertHelper(node -> right, val);
            else{
                node -> right = new Node;
                node -> right -> data = val;
                node -> right -> right = NULL;
                node -> right -> left = NULL;
            } // create new node
        }
        else if(node -> data > val){
            if(node -> left != NULL)
                insertHelper(node -> left, val);
            else{
                node -> left = new Node;
                node -> left -> data = val;
                node -> left -> right = NULL;
                node -> left -> left = NULL;
            } // create new node
        }

        return node;
    }

    Node* deleteHelper(Node *node, int val){
        if(node == NULL)
            return NULL;
        else if(node -> data < val){
            node -> right = deleteHelper(node -> right, val);
        }
        else if(node -> data > val){
            node -> left = deleteHelper(node -> left, val);
        }
        else{
            if(node -> right == NULL && node -> left == NULL){ // check for leaf node
                delete node;
                node = NULL;
            }
            else if (node -> right == NULL){
                Node *temp1 = node -> left;
                delete node;
                node = temp1;
            }
            else if (node -> left == NULL){
                Node *temp1 = node -> right;
                delete node;
                node = temp1;
            }
            else{
                Node *temp1 = findMin(node -> right);
                node -> data = temp1 -> data;
                node -> right = deleteHelper(node -> right, temp1 -> data);
            } // if node has both children, we find the min value in the right subtree of the node
              // and set that as the parent for the two children
        }
        return node;
    }

    void destroyNodes(Node *node) {
        if(node == NULL)
            return;
        destroyNodes(node->left);
        destroyNodes(node->right);
        delete node;
    }

    // Question 4
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    Node *copyTree(Node *node) {
        if(node == NULL)
            return NULL; // base case

        // creating a new node
        Node *n = new Node;
        n->data = node->data;
        n->left = copyTree(node->left);
        n->right = copyTree(node->right);
        return n;
    } // Around 10 mins






public:
    Node* root;
    // Default Constructor
    BinarySearchTree() : root(NULL) { }

    // Destructor
    ~BinarySearchTree() {
        destroyNodes(root);
    }

    // Copy constructor
    BinarySearchTree(const BinarySearchTree &other)
            : root(copyTree(other.root)) { }

    // Overloaded Assignment operator
    BinarySearchTree &operator=(const BinarySearchTree &rhs) {
        if (this == &rhs) {
            return *this;
        }
        destroyNodes(root);
        root = copyTree(rhs.root);
        return *this;
    }

    // Time Complexity : O(n)
    // Space Complexity : O(n)
    int min(){
        Node *temp1 = findMin(root);
        if(temp1 != NULL)
            return temp1 -> data;
        else
            return -1;
    }

    // Time Complexity : O(n)
    // Space Complexity : O(n)
    int max(){
        Node *temp1 = findMax(root);
        if(temp1 != NULL)
            return temp1 -> data;
        else
            return -1;
    }

    // Time Complexity : O(n)
    // Space Complexity : O(n)
    bool contains(int val){
        Node *temp1 = containsHelper(root, val);
        if(temp1 != NULL)
            return true;
        else
            return false;
    }

    // Time Complexity : O(n)
    // Space Complexity : O(n)
    void insert(int val){
        root = insertHelper(root, val);
    }

    // Time Complexity : O(n)
    // Space Complexity : O(n)
    int Delete(int val){
        if(contains(val)){
            root = deleteHelper(root, val);
            return 1;
        }
        else
            return -1;
    }

    void traverseInorder(Node *node) {
        if(node == NULL)
            return;
        traverseInorder(node->left);
        cout << node->data << " ";
        traverseInorder(node->right);
    }

    // Question 5
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    bool isBst(Node *node, int min, int max) {
        if(node == NULL)
            return true;

        if(node -> data <= min || node -> data >= max)
            return false;

        return isBst(node -> left, min, node -> data)
               && isBst(node -> right, node -> data, max); // recursive calls for both subtrees

    } // Around 20 mins

    // Question 11
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    int floorInBst(Node *node, int val) {

        if(node == NULL) // if no larger value is found, return -1
            return -1;

        if(node -> data == val){
            return val;
        }
        else if(val < node -> data){
            int temp = floorInBst(node->left, val);
            if(temp != -1)
                return temp;
            else
                return node -> data;
        } // if no value in the left subtree is greater, return that nodes value
        else{
            return floorInBst(node->right, val);
        }

    } // Around 25 mins

    // Question 10
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    void leftView(Node *node, int height, vector<int> &a){
        if(node == NULL)
            return;

        if(a.size() == height) // checks if this is a new level
            a.push_back(node->data);

        leftView(node->left, height + 1, a); // first calls left subtree, then right
        leftView(node->right, height + 1, a);

    } // This was tough, took me almost 40 mins

};

int main() {
    // All my functions pass the tests I wrote
    // All the time and space complexities are for a worst-case scenario when the tree is skewed
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(25);
    bst.insert(5);
    bst.insert(60);
    bst.insert(55);
    bst.traverseInorder(bst.root);
    cout<<endl;
    cout<<bst.contains(50)<<endl; // 1
    cout<<bst.contains(60)<<endl; // 1
    cout<<bst.contains(5)<<endl; // 1
    cout<<bst.contains(45)<<endl; // 0
    cout<<bst.Delete(60)<<endl; // 1
    cout<<bst.Delete(50)<<endl; // 1
    cout<<bst.Delete(30)<<endl; // -1
    bst.traverseInorder(bst.root);
    cout<<endl;
    cout<<bst.contains(60)<<endl; // 0
    bst.insert(30);
    bst.insert(26);
    bst.insert(75);

    cout<<bst.isBst(bst.root, INT16_MIN, INT16_MAX)<<endl; // 1
    bst.root->data = 100;
    cout<<bst.isBst(bst.root, INT16_MIN, INT16_MAX)<<endl; // 0

    bst.root->data = 55;
    cout<<bst.floorInBst(bst.root, 25)<<endl; //25
    cout<<bst.floorInBst(bst.root, 27)<<endl; //30
    cout<<bst.floorInBst(bst.root, 75)<<endl; //75
    cout<<bst.floorInBst(bst.root, 80)<<endl; //-1

    cout<<bst.max()<<endl; // 75
    cout<<bst.min()<<endl; // 5

    vector<int> left_els;
    bst.leftView(bst.root, 0,left_els);
    for(int i=0; i<left_els.size(); i++){
        cout<<left_els[i]<<" ";
    }
    return 0;
}
