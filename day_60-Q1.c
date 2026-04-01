/**Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n) return NULL;
    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}

int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(struct Node* root, int index, int totalNodes) {
    if (!root) return true;
    if (index >= totalNodes) return false;
    return isComplete(root->left, 2*index + 1, totalNodes) &&
           isComplete(root->right, 2*index + 2, totalNodes);
}

bool isMinHeap(struct Node* root) {
    if (!root->left && !root->right)
        return true;
    if (!root->right) {
        return (root->data <= root->left->data);
    } else {
        if (root->data <= root->left->data &&
            root->data <= root->right->data) {
            return isMinHeap(root->left) &&
                   isMinHeap(root->right);
        } else {
            return false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n, 0);
    int totalNodes = countNodes(root);
    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}