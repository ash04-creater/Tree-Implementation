
#include<bits/stdc++.h>
using namespace std;


typedef struct local_node *local_ptr;
struct local_node
{
int data;
local_ptr left;
local_ptr right;
local_ptr parent;

local_node(int value){
	data=value;
	left=NULL;
	right=NULL;
	parent=NULL;
}
};


local_ptr right_rotate(local_ptr node){
	
        local_ptr x= node->left;
        local_ptr y=x->right;
        
        
        x->right=node;
        node->parent=x;
        x->parent=NULL;
        
        node->left=y;
    
        if(y!=NULL)
        y->parent=node;
        
        return x;
		
}

local_ptr left_rotate( local_ptr node){
	
	local_ptr x= node->right;
    local_ptr y=x->left;
        
        x->left=node;
        node->parent=x;
        x->parent=NULL;
        
        node->right=y;
        
        if(y!=NULL)
        y->parent=node;
        
        return x;
}

local_ptr insert( local_node *node ,int a){
	

	if(node==NULL){
	return new local_node(a);
    }
	if(a<node->data){
		
		node->left=insert(node->left,a);
		node->left->parent=node;
		
	}
	else if(a> node->data){
		node->right=insert(node->right,a);
		node->right->parent=node;
		//cout<<node->right->parent->data<<"\n";
	}
	
    if(node->parent== NULL){
    	
    	if(node->left!=NULL){
    	if(node->left->data==a)
    	return right_rotate(node);
        }
    	
    	if(node->right!=NULL){
    	if(node->right->data == a)
    	return left_rotate(node);
        }
	}
	
	if(node->right != NULL && node->right->right !=NULL){

	if(node->right->right->data==a){
		
	local_ptr x=left_rotate(node);
	return left_rotate(x);
	
    }
    }
    
    if(node->left != NULL && node->left->left !=NULL){
    	
    if(node->left->left->data==a){
		
	local_ptr x=right_rotate(node);
	
	return right_rotate(x);
	
    }
    }
    
    if(node->left != NULL && node->left->right !=NULL){
    
    if(node->left->right->data==a){
    	
    	node->left =left_rotate(node->left); 
        return right_rotate(node); 
	}
    }
    
    if(node->right != NULL && node->right->left !=NULL){
	if(node->right->left->data==a){
		
		node->right = right_rotate(node->right); 
        return left_rotate(node); 
	}
    }
	
	return node;
}

void preOrder(local_ptr root) 
{ 
    if(root != NULL) 
    { 
        cout <<root->data<< " "; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

local_ptr search(local_node *node ,int a){
	
	
	if(node->data==a || node==NULL)
	return node;
	
	if(a>node->data)
	return search(node->right,a);
	else
	return search(node->left,a);
		
}

local_ptr search2( local_node *node ,int a){
	

	if(node->data==a){
	return node;
    }
	if(a<node->data){
		
		node->left=search2(node->left,a);
		node->left->parent=node;
		
	}
	else if(a> node->data){
		node->right=search2(node->right,a);
		node->right->parent=node;
		//cout<<node->right->parent->data<<"\n";
	}
	
    if(node->parent== NULL){
    	
    	if(node->left!=NULL){
    	if(node->left->data==a)
    	return right_rotate(node);
        }
    	
    	if(node->right!=NULL){
    	if(node->right->data == a)
    	return left_rotate(node);
        }
	}
	
	if(node->right != NULL && node->right->right !=NULL){

	if(node->right->right->data==a){
		
	local_ptr x=left_rotate(node);
	return left_rotate(x);
	
    }
    }
    
    if(node->left != NULL && node->left->left !=NULL){
    	
    if(node->left->left->data==a){
		
	local_ptr x=right_rotate(node);
	
	return right_rotate(x);
	
    }
    }
    
    if(node->left != NULL && node->left->right !=NULL){
    
    if(node->left->right->data==a){
    	
    	node->left =left_rotate(node->left); 
        return right_rotate(node); 
	}
    }
    
    if(node->right != NULL && node->right->left !=NULL){
	if(node->right->left->data==a){
		
		node->right = right_rotate(node->right); 
        return left_rotate(node); 
	}
    }
	
	return node;
}

int main(){
	
	local_ptr root=NULL;
	
	cout<<"enter choice\n";
	
	int ch;
	
	do{
	
	cin>>ch;
	if(ch==1){
		cout<<"enter element \n";
		int a; cin>>a;
		
		root=insert(root,a);	
		cout<<"Preoder\n";
	preOrder(root);
	cout<<"\n";
    }
    if(ch==2){
    	cout<<"enter element \n";
    	int a; cin>>a;
    	if(search(root,a)!=NULL){
    	
		root=search2(root,a);	
		
		}
		cout<<"Preoder\n";
		preOrder(root);
	    cout<<"\n";
	}
	
    }while(ch!=3);
}


