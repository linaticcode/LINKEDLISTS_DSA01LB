#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    int height;
    node *left;
    node *right;
};
class BinaryTree
{
public:
    node *root;
    BinaryTree()
    {
        root = NULL;
    }
    // Function to search given value in AVL tree and return the node if value is found
    node *search(node *root, int sv)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == sv)
        {
            return root;
        }
        else if (root->data < sv)
        {
            return search(root->right, sv);
        }
        else if (root->data > sv)
        {
            return search(root->left, sv);
        }
    }
    bool search(int sv)
    {
        node *searchNode = search(root, sv);
        if (searchNode == NULL)
        {
            return false;
        }
        else if (searchNode->data == sv)
        {
            return true;
        }
        return false;
    }
    // Function to calculate the height of tree
    int height(struct node *p)
    {
        if (p == NULL)
        {
            return -1;
        }
        int hleft, hright;
        if (p && p->left)
        {
            hleft = p->left->height;
        }
        else
        {
            hleft = 0;
        }
        if (p && p->right)
        {
            hright = p->right->height;
        }
        else
        {
            hright = 0;
        }
        return max(hleft, hright) + 1;
    }
    
    // function to insert a given element in AVL tree
    node *insert(node *root, int v)
    {
        if (root == NULL)
        {
            node *nn = new node;
            nn->data = v;
            nn->left = NULL;
            nn->right = NULL;
            nn->height = 1;
            root = nn;
            return root;
        }
        if (v < root->data)
        {
            root->left = insert(root->left, v);
        }
        else if (v > root->data)
        {
            root->right = insert(root->right, v);
        }
        return root;
    }
    bool insert(int val)
    {
        root = insert(root, val);
        return search(val);
    }
    // Function to print the inorder traversal of the AVL tree
    void inorderTraversal(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorderTraversal(root->left);
        cout << "[" << root->data << "]";
        inorderTraversal(root->right);
    }
    // Function to find the maximum value present in given AVL tree
    int maxValue(node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->right == NULL)
        {
            return root->data;
        }
        return maxValue(root->right);
    }
    // Function to find the minimum value present in given AVL tre
    int minValue(node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->left == NULL)
        {
            return root->data;
        }
        return minValue(root->left);
    }
    // Function to print the preorder traversal of tree
    void preorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << "[" << root->data << "]";
        preorder(root->left);
        preorder(root->right);
    }
    // Function tp print the postorder traversal of tree
    void postorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << "[" << root->data << "]";
    }

    // Function to find out the predecessor of given value present in AVL tree
    int predecessor(node *curNode, int val)

    {
        node *temp = curNode;
        int pred = -1;
        while (temp->data != val)
        {
            if (temp->data > val)
            {
                temp = temp->left;
            }
            else
            {
                pred = temp->data;
                temp = temp->right;
            }
        }
        node *leftsubtree = temp->left;
        while (leftsubtree != NULL)
        {
            pred = leftsubtree->data;
            leftsubtree = leftsubtree->right;
        }
        return pred;
    }
    // Function to find out the successor of given value present in AVL tree
    int successor(node *curNode, int val)
    {
        int succ = -1;
        node *temp = curNode;
        while (temp->data != val)
        {
            if (temp->data < val)
            {
                temp = temp->right;
            }
            else
            {
                succ = temp->data;
                temp = temp->left;
            }
        }
        node *rightTree = temp->right;
        while (rightTree != NULL)
        {
            succ = rightTree->data;
            rightTree = rightTree->left;
        }
        return succ;
    }
    // function  to delete the given value present in AVL tree
    node *deleteNode(node *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (val < root->data)
        {
            root->left = deleteNode(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = deleteNode(root->right, val);
        }
        else if (root->data == val)
        {
            // Node with one child
            if (root->left == NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children
            else
            {
                if (height(root->left) >= height(root->right))
                {
                    int predval = maxValue(root->left);
                    root->data = predval;
                    root->left = deleteNode(root->left, predval);
                }
                else
                {
                    int succval = minValue(root->right);
                    root->data = succval;
                    root->right = deleteNode(root->right, succval);
                }
            }
        }
        return root;
    }
    // Function to print the tree as a tree structure
    void levelOrderTraversal(node *root)
    {
        queue<node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
};
int main()
{
    BinaryTree b;
    cout << "1.Insert 2. Delete 3. Search 4. Minimum Value 5. Maximum Value 6. Predecessor 7. Successor 8. InOrder 9.PreOrder 10.PostOrder 11. Print Tree 12. Exit " << endl;
    int o;
    cout << "Enter the operation Number" << endl;
    cin >> o;
    if (o > 12 || o <= 0)
    {
        cout << "Invalid Operation Number " << endl;
    }
    while (o <= 12 && o >= 0 && o != 12)
    {
        switch (o)
        {
        case 1:
        {
            cout << "Enter the Number to insert in AVL" << endl;
            int n;
            cin >> n;
            if (b.insert(n))
            {
                cout << "Number Inserted Successfully in AVL" << endl;
            }
            else
            {
                cout << "Number Insertion in AVL was Unsuccessful" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Enter the Number to  be DELETED from AVL " << endl;
            int n;
            cin >> n;
            if (b.deleteNode(b.root, n) == NULL)
            {
                cout << "Number Deletion in AVL  was Unsuccessful" << endl;
            }
            else
            {
                cout << "Number DELETED from AVL Successfully" << endl;
            }
            break;
        }

        case 3:
        {
            cout << "Enter the Number to SEARCH in AVL " << endl;
            int n;
            cin >> n;
            if (b.search(n))
            {
                cout << "Number is Present in AVL" << endl;
            }
            else
            {
                cout << "Number is not present in AVL" << endl;
            }
            break;
        }
        case 4:
        {
            int c = b.minValue(b.root);
            if (c == -1)
            {
                cout << "AVL Tree is Empty" << endl;
            }
            else
            {
                cout << "Minimum Value in Tree is: " << c << endl;
            }
            break;
        }

        case 5:
        {
            int c = b.maxValue(b.root);
            if (c == -1)
            {
                cout << "AVL Tree is Empty" << endl;
            }
            else
            {
                cout << "Maximum Value in  AVL Tree is: " << c << endl;
            }
            break;
        }
        case 6:
        {
            int n;
            cin >> n;
            int pred = b.predecessor(b.root, n);
            if (pred == -1)
            {
                cout << "The Predecessor for given value doesn't exist" << endl;
            }
            else
            {
                cout << "The Predecessor of " << n << " is:" << pred << endl;
            }

            break;
        }
        case 7:
        {
            int n;
            cin >> n;
            int succ = b.successor(b.root, n);
            if (succ == -1)
            {
                cout << "The Successor for given value doesn't exist" << endl;
            }
            else
            {
                cout << "The Successor of " << n << " is:" << succ << endl;
            }
            break;
        }
        case 8:
        {
            cout << "Inorder Traversal of Tree is:" << endl;
            b.inorderTraversal(b.root);
            cout << endl;
            break;
        }

        case 9:
        {
            cout << "PreOrder Traversal of Tree is:" << endl;
            b.preorder(b.root);
            cout << endl;
            break;
        }
        case 10:
        {
            cout << "PostOrder Traversal of Tree is:" << endl;
            b.postorder(b.root);
            cout << endl;
            break;
        }
        case 11:
        {
            cout << "The Tree is : " << endl;
            b.levelOrderTraversal(b.root);
            break;
        }
        }
        cout << "1.Insert 2. Delete 3. Search 4. Minimum Value 5. Maximum Value 6. Predecessor 7. Successor 8. InOrder 9.PreOrder 10.PostOrder 11. Print Tree 12. Exit " << endl;
        cout << "Enter the Operation number:" << endl;
        cin >> o;
        if (o > 12 || o <= 0)
        {
            cout << "Invalid Operation Number " << endl;
        }
    }
    cout << "Exit" << endl;
}