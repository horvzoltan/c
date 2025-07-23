#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root,int value){
    if(root ==NULL){
        return createNode(value);
    }

    if(value < root->value){
        root->left = insert(root->left,value);
    }else if(value > root->value){
        root->right = insert(root->right,value);
    }

    return root;
}

void inOrderTraversal(Node* root){
 if(root != NULL){
    inOrderTraversal(root->left);
    printf("%d ", root->value);
    inOrderTraversal(root->right);
 }
}  

void freeTree(Node* root){
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    Node* root = NULL;

    int numbers[] = {10,5,15,2,7,20};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++)
    {
        root = insert(root,numbers[i]);
    }
   
    printf("In-order traversal: ");
    inOrderTraversal(root);

    printf("\n");

    freeTree(root);

    return 0;
}