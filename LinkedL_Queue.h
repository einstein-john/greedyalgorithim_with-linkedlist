/* LinkedL_Queue.h
 * Definitions of type and functions for
 * Linked lists Queueu implementations.*/

struct Qnode{
	struct node *node;
	struct Qnode *next;
};
int is_empty(struct Qnode *header)
{
	if(header==NULL)
        return 1;
    else
		return 0;
}
struct Qnode* new_node(struct node* d)
{
	struct Qnode* temp;
	temp=(struct Qnode *)malloc(sizeof(struct Qnode));
	temp->node=d;
	temp->next=NULL;
	return temp;
}
struct Qnode* insertBack(struct Qnode *header, struct node *d)
{
	struct Qnode *temp, *headertemp;
	temp=new_node(d);
	if(header==NULL)
	{
		header=temp;
		return header;
	}
	headertemp=header;
	while(headertemp->next!=NULL)
		headertemp=headertemp->next;
	headertemp->next=temp;
	return header;
}
struct Qnode * deleteFront(struct Qnode *header)
{
	struct Qnode *temp;
	if(header==NULL)
		return header;
	temp=header;
	header=header->next;
	free(temp);
	return header;
}
void displayLL(struct Qnode *header, char *title)
{
    struct Qnode*temp;
    std::cout<<title<<"\n";
	for(temp=header; temp!=NULL; temp=temp->next)
        std::cout<<temp->node->data<<" ";
    std::cout<<"\n";
}
