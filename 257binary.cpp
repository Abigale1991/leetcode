#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

string itoa(int num)
{
    string s = "",temp="";
    if(num < 0) 
    {
        num = -num;
        s += '-';
    }
    while(num > 0)
    {
        temp += (num % 10 + '0');
        num /= 10;
    }
    for(int i = temp.size()-1; i >= 0; i--)
    {
        s += temp[i];
    }
    return s;
}

void checkPaths(TreeNode* root,vector<string> &res,string s)
{
    s+="->";
    s+=itoa(root->val);
    if(root->left == NULL && root->right == NULL) 
    {
        res.push_back(s); 
        return;
    }
    if(root->left) checkPaths(root->left,res,s);
    if(root->right) checkPaths(root->right,res,s);
}

void binaryTreePaths(TreeNode* root) {
	cout << "进入函数" << endl;
    vector<string> res;
    if(root == NULL) return;
    string s = "";
    cout << "root->val:" << root->val << endl;
    s+=itoa(root->val);
    cout << "s:" << s << endl;
    if(!root->left && !root->right) res.push_back(s);
    if(root->left) checkPaths(root->left,res,s);
    if(root->right) checkPaths(root->right,res,s);
    if(res.size() == 0) cout << "没有答案" <<endl;
    for(int i = 0; i < res.size(); i++)
    {
    	for(int j = 0; j < res[i].size(); j++)
    	{
    		cout << res[i][j];
    	}
    	cout << endl;
    }
}



int main()
{
	TreeNode *root = new TreeNode(1);
	cout << "即将开始" << endl;
	root->left = new TreeNode(21);
	root->right = new TreeNode(37);
	TreeNode *left = root->left;
	TreeNode *right = root->right;
	left->left = new TreeNode(-1);
	left->right = new TreeNode(-1000);
	left->right->right = new TreeNode(3);
	right->left = new TreeNode(66);
	binaryTreePaths(root);
}