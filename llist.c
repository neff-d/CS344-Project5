#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "llist.h"




void llist_insert_head(struct node **head, struct node *n){
   
     if(*head == NULL){
          *head = n;
     }
     else{
          n -> next = *head;
	  *head = n; 
     }
}

struct node * llist_delete_head(struct node **head){
    
     if(*head == NULL){
          return NULL;
     }
     else{
       *head = (*head) -> next;  
     }
     return *head;
}

void llist_insert_tail(struct node **head, struct node *n){
     
     if(*head == NULL){
          *head = n;
     }
     else{
          struct node *currNode = *head;

	  while(currNode -> next != NULL){
	       currNode = currNode -> next;
	  }
	  currNode -> next = n;
     }
}

void llist_print(struct node *head){

     struct node *currNode = head;

     if(currNode == NULL){
	  printf("[empty]");
     }

     while(currNode != NULL){
	  if(currNode -> next == NULL){
	       printf("%d", currNode -> value);	
	  }
	  else{
               printf("%d -> ", currNode -> value);
	  }
	  currNode = currNode -> next;
     }
     printf("\n");
}

void llist_free(struct node **head){

     struct node *prevNode = *head;

     while(*head != NULL){
	  *head = (*head) -> next;
          node_free(prevNode);
          prevNode = *head;
     }

}

struct node * node_alloc(int value){

     struct node *newNode = malloc(sizeof(struct node));
     newNode -> value = value;

     return newNode;
}

void node_free(struct node *n){
     free(n);
}



int main(int argc, char *argv[]){

     argc = argc;
     struct node *head = NULL;
     int i = 1;

     while(argv[i] != NULL){
	  if(strcmp(argv[i], "ih") == 0){
	       int value = atoi(argv[i + 1]);
	       struct node *newNode = node_alloc(value);

	       llist_insert_head(&head, newNode);
	  }
	  else if(strcmp(argv[i], "it") == 0){
  	       int value = atoi(argv[i + 1]);
	       struct node *newNode = node_alloc(value);

	       llist_insert_tail(&head, newNode);
	  }
	  else if(strcmp(argv[i], "dh") == 0){
	       llist_delete_head(&head);
	  }
	  else if(strcmp(argv[i], "p") == 0){
	       llist_print(head);
	  }
   	  else if(strcmp(argv[i], "f") == 0){
	       llist_free(&head);
          }
          i++;
     }

} // main
