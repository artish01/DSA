#include <iostream>
#include <queue>
using namespace std;
template <typename T>

class BinaryTree
{

public:
    T data;
    BinaryTree<int> *left;
    BinaryTree<int> *right;

    BinaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTree()
    {
        delete left;
        delete right;
    }
};

class BST
{
public:
    BinaryTree<int> *root;

    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTree<int> *delete_data_main(int data, BinaryTree<int> *root)
    {

        if (root == NULL)
        {
            return NULL;
        }

        if (data > root->data)
        {
            this->root = delete_data_main(data, root->right);
        }
        if (data < root->data)
        {
            this->root = delete_data_main(data, root->left);
        }

        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            else if (root->left == NULL)
            {
                BinaryTree<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                BinaryTree<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTree<int> *rightmin = root->right;
                while (rightmin->left != NULL)
                {
                    rightmin = rightmin->left;
                }

                int r_mindata = rightmin->data;
                root->data = r_mindata;
                root->right = delete_data_main(r_mindata, root->right);
                return root;
            }
        }
    }

    BinaryTree<int> *insert_main(int data, BinaryTree<int> *root)
    {
        if (root == NULL)
        {
            BinaryTree<int> *newnode = new BinaryTree<int>(data);
            return newnode;
        }
        else if (data > root->data)
        {
            root->right = insert_main(data, root->right);
        }
        else if (data < root->data)
        {
            root->left = insert_main(data, root->left);
        }
        return root;
    }

    bool has_data_main(int data, BinaryTree<int> *root)
    {
        if (root == NULL)
        {
            return false;
        }

        else if (root->data == data)
        {
            return true;
        }

        else if (root->data < data)
        {
            return has_data_main(data, root->right);
        }
        else if (root->data > data)
        {
            return has_data_main(data, root->left);
        }

        return false;
    }

    void pre(BinaryTree<int> *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << " ";
        pre(root->left);
        pre(root->right);
    }

public:
    void delete_data(int data)
    {
        this->root = delete_data_main(data, root);
    }

    void insert(int data)
    {
        this->root = insert_main(data, root);
    }
    bool has_data(int data)
    {
        return has_data_main(data, root);
    }

    void print_level_wise(BinaryTree<int> *root)
    {
        if(root==NULL)
        {
            return;
        }
        queue<BinaryTree<int> *> pn;
        pn.push(root);

        while(!pn.empty())
        {
            BinaryTree<int>* front = pn.front();
            pn.pop();
            cout<<front->data;

            if(front->left)
            {
                pn.push(front->left);
            }
            if(front->right)
            {
                pn.push(front->right);
            }
            cout<<endl;

        }
    }

    int find_height(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = find_height(root->left); // storing root's lefts
    int right = find_height(root->right);

    return max(left, right) + 1;
}

    void print()
    {

        // pre(root);
        // print_level_wise(root);
        cout<<find_height(root);
        
    }
    
};

int main()
{
    BST b1;
    b1.insert(100);
    b1.insert(130);
    b1.insert(50);
    b1.insert(120);

    // b1.print();
   b1.print();
   

    return 0;
}