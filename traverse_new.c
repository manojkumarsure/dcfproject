#include<stdio.h>
#include<dirent.h>
#include "Queue/Queue.h"
#include<string.h>
#include<malloc.h>
char* ret_dir(char *parent,char* child){
 char* temp=malloc(sizeof(char)*(strlen(parent)+strlen(child)+3));
strcpy(temp,parent); 
strcat(temp,"/");
strcat(temp,child);
return temp;
  
}
void traverse(char* directory){
 printf("\n\n{-%s----------------\n\n",directory);
  Queue* q;int i;
q=queue_new();
DIR* dirp=NULL;
struct dirent * entry=NULL;
dirp=opendir(directory);
if(dirp==NULL){printf("Problem in opening the Directory");return;}
while((entry=readdir(dirp))!=NULL){
 if(strcmp(entry->d_name,".")==0)continue;
 else
  if(strcmp(entry->d_name,"..")==0)continue;
  else
    if(entry->d_type==DT_DIR)queue_enqueue(q,entry->d_name);
 printf("[ %s ]",entry->d_name);  
}
printf("\n\n-------------------------------}\n\n");
  while(queue_size(q)>0){
    traverse(ret_dir(directory,queue_top(q,&i)));queue_dequeue(q);
  }
}

main(int argc,char *argv[]){
  traverse(argv[1]);
  
}
