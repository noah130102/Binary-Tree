#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    node() {}
    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

void flatten(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *test = root->right;
        while (test->right != NULL)
        {
            test = test->right;
        }
        test->right = temp;
    }

    flatten(root->right);
}

void nodesAtDisK(node *root, node *target, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    nodesAtDisK(root->right, target, k - 1);
    nodesAtDisK(root->left, target, k - 1);
}
int distFromAnces(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        nodesAtDisK(root, target, k);
        return 0;
    }

    // for left
    int dl = distFromAnces(root->left, target, k);
    if (dl != -1)
    {
        if (k - dl == 1)
        {
            cout << root->data << " ";
        }
        else
        {
            nodesAtDisK(root->right, target, k - dl - 2);
        }
    }

    // for right
    int dr = distFromAnces(root->right, target, k);
    if (dr != -1)
    {
        if (k - dr == 1)
        {
            cout << root->data << " ";
        }
        else
        {
            nodesAtDisK(root->left, target, k - dr - 2);
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->left);
}

bool getPath(node *root, int n, vector<int> &v)
{
    if (root == NULL)
    {
        return false;
    }
    v.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }
    if (getPath(root->left, n, v) || getPath(root->right, n, v))
    {
        return true;
    }
    v.pop_back();
    return false;
}
int LCA(node *root, int n1, int n2)
{
    vector<int> v1, v2;
    if (!getPath(root, n1, v1) || !getPath(root, n2, v2))
    {
        return -1;
    }
    int p;
    for (p = 0; p < v1.size(); p++)
    {
        if (v1[p] != v2[p])
        {
            break;
        }
    }

    return v1[p - 1];
}

int maxPathSumCalculate(node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = maxPathSumCalculate(root->right, ans);
    int r = maxPathSumCalculate(root->left, ans);
    int maxAns = max(max(root->data, root->data + l + r),
                     max(root->data + l, root->data + r));
    ans = max(ans, maxAns);

    int singlePath = max(root->data, max(root->data + l, root->data + r));

    return singlePath;
}
int maxPathSum(node *root)
{

    int ans = INT_MIN;
    maxPathSumCalculate(root, ans);
    return ans;
}

int main()
{
    #pragma region
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    int n1 = 7;
    int n2 = 6;
    int l = LCA(root, n1, n2);

// if (l == -1)
// {
//     cout << "LCA doesnt exist" << endl;
// }
// else
// {
//     cout << "LCA: " << l << endl;
// }
#pragma endregion

   
     #pragma region
    // node *root1 = new node(1);
    // root1->left = new node(2);
    // root1->right = new node(3);
    // root1->left->left = new node(4);
    // root1->right->right = new node(5);

    // cout << maxPathSum(root1) << endl;
#pragma endregion

    
    
    return 0;
}