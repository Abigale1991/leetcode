#include <iostream>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int count(TreeNode* root)
{
    if(root == NULL) return 0;
    int len=1;
    stack<TreeNode*> st;
    TreeNode *p = root->left;
    st.push(root);
    while(!st.empty() || p)
    {
        while(p != NULL)
        {
            len++;
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        p = p->right;
    }
    return len;
}

int kthSmallest(TreeNode* root, int k) {
    int leftlen = count(root->left);
    if(leftlen >= k) return kthSmallest(root->left,k);
    else if(leftlen + 1 == k) return root->val;
    else return kthSmallest(root->right,k-1-leftlen);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << kthSmallest(root,4) << endl;
    return 0;
}
