#include <cstdlib>
#include <iostream>
#include "Trees.h"
#include "LinkedL_Queue.h"


using namespace std;

void algorithim(struct node *);

int main(int argc, char *argv[])
{
    struct Qnode *queue=NULL;

	


    struct node *tree=NULL;
    struct node *a=NULL;	
	tree=newNode(5);
	

//create the branches of the  nodes
	 //s->a
tree->left = tree;
a = newNode(5);
tree->left->left = a;

a = newNode(2);
tree->right = a;

tree->right->left = a;
a = newNode(1);
tree->right->right = a;

a = newNode(2);
tree->right->left->left = a;
a = newNode(5);
tree->right->right->right = a;
	 
   displayAllTree(tree, "tree");

	 algorithim(tree);

	 

    system("PAUSE");
    return EXIT_SUCCESS;
}


void algorithim(struct node *temp){
  int a, b;
  if (temp == NULL)
    return;

  if (temp->left == NULL && temp->right == NULL) {
    cout << "End of tree \n";
    return;
  }

  if (temp->left == NULL) {
    a = temp->right->data;
  } else if (temp->right == NULL) {
    a = temp->left->data;
  } else {
    a = temp->data;
  }

  if (temp->right == NULL) {
    b = a;
  } else {
    b = temp->right->data;
  }

  if (a < b) {
    cout << "L "<<a<<"\n";
    if (temp->left != NULL) {
      algorithim(temp->left);
    }
  } else {
    cout << "R "<<b<<"\n";
    if (temp->right != NULL) {
      algorithim(temp->right);
    }
  }
}