/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QNode {
    struct TreeNode* node;
    int hd;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct TreeNode* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

void verticalOrder(struct TreeNode* root) {
    if (!root) return;
    int offset = 100;
    int result[201][100];
    int count[201] = {0};
    struct QNode queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (struct QNode){root, 0};
    int min_hd = 0, max_hd = 0;
    while (front < rear) {
        struct QNode temp = queue[front++];
        struct TreeNode* curr = temp.node;
        int hd = temp.hd;
        int idx = hd + offset;
        result[idx][count[idx]++] = curr->val;
        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;
        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }
    for (int i = min_hd; i <= max_hd; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", result[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct TreeNode* root = buildTree(arr, n);
    verticalOrder(root);
    return 0;
}