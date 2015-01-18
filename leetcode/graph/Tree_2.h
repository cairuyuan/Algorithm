#ifndef __TREE_2_
#define __TREE_2_

#include "head.h"



vector<vector<int> > levelOrder2(TreeNode *root);

vector<vector<int> > levelOrder1(TreeNode *root);

int maxPathSum(TreeNode *root);
void recoverTree(TreeNode* root);

void  print(vector<TreeNode *> v);
TreeNode *  delete_bst(TreeNode *t, int target);

void insert_bst(TreeNode *root, int target);
TreeNode * searchinbst(TreeNode *root, int target);
vector<TreeNode *>  morritra(TreeNode *root);
bool isBalanced(TreeNode *root);

TreeNode *sortedArrayToBST(int *arr, unsigned int n);

TreeNode *sortedArrayToBST(vector<int> &num);

TreeNode *sortedArrayToBST(vector<int> &num, int start, int end);
void connect2(TreeNode *root);

inline TreeNode *whohaschild(TreeNode *start);

void connect1(TreeNode *root);

TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder);
TreeNode *buildTree2(vector<int> &inorder, int istart, int iend, vector<int> &postorder, int pstart, int pend);

TreeNode *buildTree2(TreeNode ** in, TreeNode ** po, int count);

TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder);

TreeNode *buildTree1(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend);
TreeNode *buildTree1(TreeNode ** pr, TreeNode ** in, int count);

void flatten(TreeNode *root);


bool hasNext();
int next();

#endif