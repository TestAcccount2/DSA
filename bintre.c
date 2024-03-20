#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
struct node *root;

struct node *create(void);
void insert(struct node **, int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void search(struct node *, int);

void main() {
    int ch;
    do {
        printf("Enter the choice\n 1-Create BST\n 2-Traverse \n 3-Search \n 4-EXIT\n");
        scanf("%d", &ch);
        if (ch == 1) {
            root = NULL;
            root = create();
        } else if (ch == 2) {
            printf("\nInorder Traversal\n\n");
            inorder(root);
            printf("\npreorder Traversal\n\n");
            preorder(root);
            printf("\npostorder Traversal\n\n");
            postorder(root);
            printf("\n\n");
        } else if (ch == 3) {
            int key;
            printf("Enter the element to be searched in BST\n");
            scanf("%d", &key);
            search(root, key);
        } else if (ch == 4) {
            exit(0);
        }
    } while (1);
}

struct node *create() {
    int value, choice;
    struct node *newNode;
    do {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->left = NULL;
        newNode->right = NULL;
        printf("Enter data for new node\n");
        scanf("%d", &value);
        newNode->data = value;
        if (root == NULL) {
            root = newNode;
        } else {
            insert(&root, value);
        }
        printf(" 1- Continue , 2-Exit\n");
        scanf("%d", &choice);
    } while (choice == 1);
    return root;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = (struct node *)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (data < (*root)->data) {
            insert(&((*root)->left), data);
        } else if (data > (*root)->data) {
            insert(&((*root)->right), data);
        }
    }
}

void inorder(struct node *ptr) {
    if (ptr) {
        inorder(ptr->left);
        printf("%d\t", ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr) {
    if (ptr) {
        printf("%d\t", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr) {
    if (ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\t", ptr->data);
    }
}

void search(struct node *root, int key) {
    if (root == NULL) {
        printf("Key element is not Found in BST\n");
    } else {
        if (key < root->data) {
            search(root->left, key);
        } else if (key > root->data) {
            search(root->right, key);
        } else {
            printf("Key element %d is found in BST\n", key);
        }
    }
}
