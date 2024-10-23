#include<stdio.h>
#include<stdlib.h>

//bt
struct bt
{
    int data;
    struct bt* left;
    struct bt* right;
};

struct bt *root = NULL;
struct bt *newnode;

int n = 0; 
int nl = 0;

//getbt
struct bt* getBt(){
    return ((struct bt*)malloc(sizeof(struct bt)));
}

//insert
void insert(struct bt* root,int x){
    if(root == NULL){
        newnode = getBt();
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
    } else if(root->data == x){
        printf("Duplicate Values");
    } else if (root->data > x){
        if(root->left == NULL){
            newnode = getBt();
            newnode->data = x;
            newnode->left = NULL;
            newnode->right = NULL;
            root->left = newnode;
        } else 
        insert(root->left,x);
    } else {
        if(root->right == NULL){
            newnode = getBt();
            newnode->data = x;
            newnode->left = NULL;
            newnode->right = NULL;
            root->right = newnode;
        } else 
        insert(root->right,x);
    }
}
//pre
void preorder(struct bt* root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//in
void inorder(struct bt* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
//post
void postorder(struct bt* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

//search
int search(struct bt *root,int x){
    int f = 0;
    if(root != NULL){
        if(root->data == x){
            printf("data found ");
            return 1;
        } else if (root->data > x){
            f= search(root->right,x);
            return f;
        } else{
            f = search(root->left,x);
            return f;
        }
    }
    if(f == 0){
        printf("Element Not Found");
    }
}

void countNodes(struct bt* root){
    if(root != NULL){
        n++;
        countNodes(root->left);
        countNodes(root->right);
    }
}

void main(){

	//Initializing variables
	int c,x;

	//Start of while loop
	while(1){
		printf("Operations\n");
		printf("1.Insert\n");
		printf("2.Inorder\n");
		printf("3.Preorder\n");
		printf("4.Postorder\n");
		printf("5.Search\n");
		printf("6.Count number of nodes\n");
		printf("7.Count number of leaf nodes\n");
		printf("8.Exit\n");
		
		//Accepting choice from user
		printf("Enter your choice : ");
		scanf("%d",&c);
		
		//Start of switch case
		switch(c)
		{
			case 1 : printf("Enter element to be inserted : ");
				scanf("%d",&x);
				insert(root,x);
				break;
				
			case 2 : inorder(root);
				break;
				
			case 3 : preorder(root);
				break;
				
			case 4 : postorder(root);
				break;
				
			case 5 : printf("Enter element that you want to search : ");
				scanf("%d",&x);
				search(root,x);
				break;
				
			case 6 : countnodes(root);
			    printf("There are %d nodes\n",n);
			    n = 0;
			    break;
			    
			case 7 : countleafnodes(root);
			    printf("There are %d leaf nodes\n",nl);
			    nl = 0;
			    break;
				
			case 8 : exit(1);
				break;
				
			default : printf("Invalid input\n");
				break;
		} //End of switch case

	} //End of while loop

}