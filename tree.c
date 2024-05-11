#include <stdlib.h>
#include <stdio.h>

// Bigger or equal goes to right

typedef struct node {
  int value;
  struct node* left;
  struct node* right;
} node ;

typedef struct tree{
  node* root;
} tree;

int max(int a, int b){
 return ((a) > (b) ? (a) : (b));
}

node* init_node(int value){
  node* new = malloc(sizeof(node));
  new->value = value;
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
        break;
      }
    }
    else {
      if (aux->left)
        aux = aux->left;
      else {
        aux->left = init_node(value);
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
    return max(node_h(node->left), node_h(node->right))+1;
  }
}

int tree_h(tree* tree){
  return node_h(tree->root);
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
  insert(my_tree, 5);
  print_tree(my_tree);
  printf("\n");
  printf("Altura: %d\n", tree_h(my_tree));
 
  return 0;
}
