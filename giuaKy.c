#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// treeNode
struct tnode {
    int letter;
    struct tnode *left;
    struct tnode *right;
};
typedef struct tnode treeNode;

// dem so nhanh cua treeNoint demCanh(treeNode *root) {
int count = 0;
if ((root->left == NULL) && (root->right == NULL))
    return 0;
if (root->left != NULL)
    count += (1 + demCanh(root->left));
if (root->right != NULL)
    count += (1 + demCanh(root->right));
return count;
}

// kiem tra tang deu
int isIncreased(int A[], int n) {
    if (n == 1)
        return 1;
    static int step;
    if (n == 2) {
        step = A[1] - A[0];
        if (step > 0)
            return 1;
        else
            return 0;
    }
    if (isIncreased(A, n - 1)) {
        if (A[n - 1] - A[n - 2] == step)
            return 1;
    }
    return 0;
}

// decode ma Hufman
void printHuffman(treeNode *root, char *binCode, int len) {
    treeNode *temp = root;
    for (int i = 0; i < len; i++) {
        if (binCode[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        if ((temp->left == NULL) && (temp->right == NULL)) {
            putchar(temp->letter);
            temp = root;
        }
    }
}

// tao cay huffman voi 1 ki tu cho truoc
treeNode *makeHNode(char x) {
    treeNode *newNode = malloc(sizeof(treeNode));
    if (newNode == NULL) {
        printf("Het bo nho \n");
        exit(1);
    } else {
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->letter = x;
    }
    return newNode;
}

// tao 1  cay voi 2 cay trai va phai cho truoc
treeNode *tree(treeNode *left, treeNode *right) {
    treeNode *newNode = malloc(sizeof(treeNode));
    if (newNode == NULL)
        exit(1);
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

// in bin code cua cac la trong cay
void printHuffmanCode(treeNode *root, char *binCode, int len) {
    if ((root->left == NULL) && (root->right == NULL)) {
        binCode[len] = '\0';
        printf("%c: %s  \n", root->letter, binCode);
    } else {
        char temp1[6];
        strcpy(temp1, binCode);
        temp1[len] = '0';
        char temp2[6];
        strcpy(temp2, binCode);
        temp2[len] = '1';
        printHuffmanCode(root->right, temp2, len + 1);
        printHuffmanCode(root->left, temp1, len + 1);
    }
}

int main() {
    // int a[] = {1, 3, 6, 7, 9};
    treeNode *e;
    e = tree(tree(makeHNode('L'), tree(makeHNode('E'), makeHNode('P'))),
             tree(makeHNode('O'), tree(makeHNode('H'), makeHNode('C'))));
    printf("so nhanh cay : %d \n", demCanh(e));
    char *binCode = "       ";
    printHuffmanCode(e, binCode, 0);
    return 0;
}
