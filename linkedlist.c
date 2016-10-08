#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node{
  int i;
  struct node *next;
};

void print_list(struct node *p){
  struct node *tmp = p;
  printf("Data:[ ");
  while(tmp){
    printf("%d ",tmp->i);
    tmp = tmp->next;
  }
  printf("]\n");
}
struct node* insert_front(struct node *p,int data){
  struct node *head;
  head = (struct node*)malloc(sizeof(struct node));
  head->i=data;
  head->next=p;
  return head;
}

struct node* free_list(struct node* p){
  struct node *victim = p;
  struct node *nextVictim;
  while(victim){
    nextVictim = victim->next;
    free(victim);
    victim = nextVictim;
  }
  p=NULL;
  return p;
}
int main(){

  printf("Creating initial node...\n");
  srand(time(NULL));
  struct node *header = (struct node*)malloc(sizeof(struct node));
  header->i=rand()%43;
  header->next= NULL;
  print_list(header);
  printf("Adding random nodes...\n");
  int a;
  for(a=0;a<9;a++){
  header = insert_front(header,rand() % 43);
  print_list(header);
  }
  printf("Freeing the list...\n");
  header = free_list(header);
  printf("Header after freeing list: %p\n",header);
  return 0;
}
