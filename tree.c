#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Bigger or equal goes to right

typedef struct node {
  int value;
  struct node* parent;
  struct node* left;
  struct node* right;
} node;

typedef struct tree{
  node* root;
} tree;

int max_int(int a, int b){
 return ((a) > (b) ? (a) : (b));
}

node* init_node(int value){
  node* new = malloc(sizeof(node));
  new->value = value;
  new->parent = NULL;
  new->left = NULL;
  new->right = NULL;

  return new;
}

tree* init_tree(int value){
  tree* new = malloc(sizeof(tree));
  new->root = init_node(value);

  return new;
}

void insert(tree* tree, int value){
  node* aux = tree->root;

  while(aux){
    if (value >= aux->value) {
      if (aux->right)
        aux = aux->right;
      else {
        aux->right = init_node(value);
        aux->right->parent = aux->right;
        break;
      }
    }
    else {
      if (aux->left)
        aux = aux->left;
      else {
        aux->left = init_node(value);
        aux->left->parent = aux->left;
        break;
      }
    }
  }
}

void print_node(node* node){
  if (node->left) {
    print_node(node->left);
  }

  printf("%d ", node->value);

  if (node->right) {
    print_node(node->right);
  }
}

void print_tree(tree* tree){
  print_node(tree->root);
}

int node_h(node* node){
  if (!node){
    return -1;
  }
  else {
    return max_int(node_h(node->left), node_h(node->right))+1;
  }
}

int tree_h(tree* tree){
  return node_h(tree->root);
}

node* search(node* node, int value){
  if (node->value == value) {
    return node;
  }
  else {
    if (node->value < value){
      if (node->right) {
        return search(node->right, value);
      }
      else {
        return NULL;
      }
    }
    else {
      if (node->left) {
        return search(node->left, value);
      }
      else {
        return NULL;
      }
    }
  }
}

node* min(node* node){
  while (node->left != NULL){
    node = node->left;
  }

  return node;
}

node* max(node* node){
  while (node->right != NULL){
    node = node->right;
  }

  return node;
}

node* sucessor(node* node, int x){
  node = search(node, x);

  if (!node){
    return NULL;
  }

  else {
    if (node->right){
      return min(node->right);
    }
    else {
      struct node* aux = node->parent;
      while (aux != NULL && node == aux->right) {
        node = aux;
        aux = aux->parent;
      }
      return aux;
    }
  }

}

int main(){
  tree* my_tree = init_tree(10);
  print_tree(my_tree);
  printf("\n");
  insert(my_tree, 5);
  insert(my_tree, 8);
  insert(my_tree, 3);
  insert(my_tree, 1);
  insert(my_tree, 7);
  insert(my_tree, 11);
  insert(my_tree, 3);
  insert(my_tree, 15);
  print_tree(my_tree);
  printf("\n");
  printf("Altura: %d\n", tree_h(my_tree));
  printf("Altura: %p\n", search(my_tree->root,8));
  printf("Altura: %d\n", min(my_tree->root)->value);
  printf("Altura: %d\n", max(my_tree->root)->value);
  printf("Sucessor: %d\n", sucessor(my_tree->root, 5)->value);
 
  return 0;
}
