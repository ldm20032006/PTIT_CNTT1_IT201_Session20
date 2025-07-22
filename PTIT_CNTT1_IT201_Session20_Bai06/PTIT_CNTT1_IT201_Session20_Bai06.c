#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findLevel(Node* root, int value, int level) {
    if (root == NULL) return -1;

    if (root->data == value)
        return level;

    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != -1)
        return leftLevel;

    return findLevel(root->right, value, level + 1);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int value = 3;
    int level = findLevel(root, value, 0);

    if (level != -1)
        printf("Node level: %d\n", level);
    else
        printf("Value not found in tree.\n");

    return 0;
}
