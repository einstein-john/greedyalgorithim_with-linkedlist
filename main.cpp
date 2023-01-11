#include <cstdlib>
#include <iostream>
#include "Trees.h"
#include "LinkedL_Queue.h"


using namespace std;

void algorithim(struct node *);

int main(int argc, char *argv[])
{
    struct Qnode *queue=NULL;

	


    struct node *tree=newNode(8);
    struct node *a=newNode(4);	
    struct node *b=newNode(2);
    struct node *c=newNode(2);
    struct node *d=newNode(3);
    struct node *g=newNode(0);
	
	

//create the branches of the  nodes
	 //s->a
    tree->left = a;
  //s->g
    tree->right = g;
    
    	 //s->a->c
    tree->left->left = g;
    	 //s->a->b
    tree->left->right = b;

   	 //s->a->c->g
    tree->left->left->left = c;
     	 //s->a->c->d
    tree->left->left->right = d;
   //s->a->b->d
    tree->left->right->right = d;
      
      	 //s->a->c->d->g
    tree->left->left->right->right = g;
   //s->a->b->d
    tree->left->right->right->right = g;


   //displayAllTree(tree, "tree");

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
//ensuer you are not pointing to a null node
  if (temp->left == NULL) {
    a = temp->right->data;
  } else {
    a = temp->left->data;
  } 

  if (temp->right == NULL) {
    b = a;
  } else {
    b = temp->right->data;
  }
//compare heuristic values
  if (a < b) {
    cout << "L -> \n";
    if(a == 0)
    return;
    if (temp->left != NULL) {
      algorithim(temp->left);
    }
  } else {
    cout << "R -> \n";
     if(b == 0)
    return;
    if (temp->right != NULL) {
      algorithim(temp->right);
    }
  }
}