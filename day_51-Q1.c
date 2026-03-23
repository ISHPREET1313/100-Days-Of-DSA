/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);    
    return root;
}

struct TreeNode* LCA(struct TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;
    if (p < root->val && q < root->val)
        return LCA(root->left, p, q);
    if (p > root->val && q > root->val)
        return LCA(root->right, p, q);
    return root;
}

int main() {
    int n, x, p, q;
    struct TreeNode* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    scanf("%d %d", &p, &q);
    struct TreeNode* lca = LCA(root, p, q);
    if (lca != NULL)
        printf("%d\n", lca->val);
    return 0;
}