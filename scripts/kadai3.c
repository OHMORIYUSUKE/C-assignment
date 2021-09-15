#include<stdio.h>
#include<stdlib.h>

struct Link{
	    int data;
	    struct Link *next;
	    };

struct Link *head;
struct Link *newLink(int);

void view();
void insert(int);
int main();
void deleteHead();
void deleteValue(int);
void deleteAll(); 
void input(int);


int main(){
	   insert(3);
	   insert(1);
	   insert(4);
	   insert(2);

	   view();

       deleteHead();
	   
	   //input(1);

       view();

       deleteValue(3);

	   //input(3);

       view();

       deleteAll();

	   //input(2);
	   //input(4);

       view();

       return 0;
	   }

struct Link *newLink(int data){
	 		       struct Link *nLink=(struct Link*)malloc(sizeof(struct Link));
			       nLink->data=data;
			       nLink->next=NULL;
			       return nLink;
			       }

void view(){
	    struct Link *itr=head;
	    while(itr!=NULL){
				 printf("(%p)%d=>(%p)\n",itr,itr->data,itr->next);
			     itr=itr->next;
			     }
            }

void insert(int data){
	struct Link *nLink;
	struct Link *itr;
	          nLink=newLink(data);
		  if(head==NULL){
				head=nLink;
				return;
				}
		   else if(head->data>=nLink->data){
				  nLink->next=head;
				  head=nLink;
				  return;
				  }
                   else{
					    itr=head;
		   while(1){
			    if(itr->next==NULL){
					       itr->next=nLink;
						   break;
					       }
			    else{
					if(nLink->data<=itr->next->data){
						  nLink->next=itr->next;
						  itr->next=nLink;
						  break;
						  }
						  else{
							  itr=itr->next;
                              }
			    
			
	 		     }
				
		  }
		  
}
}

/*void input(int n){
	printf("DELETE:%d\n",n);
}*/

void deleteHead(){
	struct Link *next;
	if(head!=NULL){
		next=head->next;
		printf("(%p)%d_DELETE\n",head,head->data);
		free(head);
		head=next;

	}
	return;
}

void deleteValue(int data){
	struct Link *next;
	struct Link *itr=head;

	if (head==NULL)
	{
		return;
	}
	
	else if(head->data==data){
		deleteHead();
	}

	else{
		while (itr->next!=NULL)
		{
			next=itr->next;
			if (itr->next->data==data)
			{
				head->next = next->next;
				printf("(%p)%d_DELETE\n",next,next->data);
				free(next);
				
			}
			itr=itr->next;
		}
		

	}
		
}

void deleteAll(){
	while (head!=NULL)
	{
	    deleteHead();
	}
	
} 