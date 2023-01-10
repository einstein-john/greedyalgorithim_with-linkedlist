/* Trees.h
 * Definitions of type and functions for
 * Tree implementations.*/

struct  node {
	int data;
	struct node * left;
	struct node * right;
};

int is_empty(struct mode *tree)
{
	if(tree==NULL)
		return 1;
	else
		return 0;
}

struct node * newNode(int d)
{
	struct node *temp;
	temp=(struct node *) malloc(sizeof(node));
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorderTraverse(struct node *tree)
{
	if(tree==NULL)
		return;
	inorderTraverse(tree->left);
	std::cout<<tree->data<<" ";
	inorderTraverse(tree->right);
}

void preorderTraverse(struct node * tree)
{
	if(tree==NULL)
		return;
	std::cout<<tree->data<<" ";
	preorderTraverse(tree->left);
	preorderTraverse(tree->right);
}

void postorderTraverse(struct node * tree)
{
	if(tree==NULL)
		return;
	postorderTraverse(tree->left);
	postorderTraverse(tree->right);
	std::cout<<tree->data<<" ";
}

int height(struct node * tree)
{
	if(tree==NULL)
		return -1;
	else if (height(tree->left)>height(tree->right))
			return height(tree->left)+1;
		else
			return height(tree->right)+1;
}

int size(struct node * tree)
{
	if(tree==NULL)
		return 0;
	return (size(tree->left) +size(tree->right) + 1);
}

int sum(struct node * tree)
{
	if(tree==NULL)
		return 0;
	return ((sum(tree->left) + sum(tree->right)) + tree->data);
}


struct node * insertLeft(struct node * tree, struct node *p)
{
	if(tree ==NULL)
		return p;
	tree->left=insertLeft(tree->left, p);
	return tree;
}

struct node * insertRight(struct node * tree, struct node *p)
{
	if(tree ==NULL)
		return p;
	tree->right=insertRight(tree->right, p);
	return tree;
}

int search(struct node * tree, int d)
{
	if(tree==NULL)
		return 0; //not found
	if(tree->data==d)
		return 1; //found
	if(d < tree->data)
		return (search(tree->left, d));
	return (search(tree->right, d));
}


int largest(struct node * tree)
{
	if(tree->right==NULL)
		return tree->data;
	return (largest(tree->right));
}


int smallest(struct node * tree)
{
	if(tree->left==NULL)
		return tree->data;
	return (smallest(tree-> left));
}


struct node * insertion(struct node * tree, int d)
{
	struct node * temp;
	if(tree ==NULL)
  	{
		temp=newNode(d);
		return temp;
	}
	if(d < tree->data)
	{
		tree->left = insertion(tree->left, d);
		return tree;
	}
	tree->right = insertion(tree->right, d);
	return tree;
}


struct node * deletion(struct node * tree, int d)
{
	struct node * temp;
	if(tree ==NULL)
				return NULL;
	if(d < tree->data)
	{
		tree->left = deletion(tree->left, d);
		return tree;
	}
	if(d > tree->data)
	{
		tree->right = deletion(tree->right, d);
		return tree;
	}
	/*at this point, we know that d=tree->data*/
	if(tree->left==NULL && tree->right==NULL)
	{
		free(tree);
		return NULL;
	}
	if(tree->left==NULL)
	{
		temp=tree->right;
		free(temp);
		return temp;
	}
	if(tree->right==NULL)
	{
		temp=tree->left;
		free(temp);
		return temp;
	}
	temp=tree->left;
	temp=insertRight(temp, tree->right);
	free(tree);
	return temp;
}

void displayTree(struct node *header,int depth, char leaf)
{
    if (header==NULL)
        return;
    else
    {
        for(int i=0;i<depth;i++)
            std::cout<<"-";
        std::cout<<header->data<<"("<<leaf<<")"<<"\n";
        displayTree(header->left,depth+1,'L');
    }   displayTree(header->right,depth+1,'R');
}
void displayAllTree(struct node *header, char *title)
{
    struct node*temp;
    std::cout<<title<<"\n";
    displayTree(header,0,'T');
    std::cout<<"\n";
}
