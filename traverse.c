//this is sample code but this is wrong
//give any one directory as command line argument

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

void traverse(char* directory)
{
DIR * dir=NULL;
chdir(directory);
dir=opendir(".");
char cwd[256];
getcwd(cwd,255);
printf("cwd:%s\n",cwd);

if(dir==NULL){printf("DIrectory not opened\n");return;}

struct dirent *entry=NULL;
struct stat file_status;
while((entry=readdir(dir))!=NULL){
if(strcmp(entry->d_name,".")==0)continue;
if(strcmp(entry->d_name,"..")==0)continue;
stat(entry->d_name,&file_status);
if(S_ISDIR(file_status.st_mode))
printf("Dir : %s\n",entry->d_name);
else
printf("File : %s\n",entry->d_name);
}
printf("--------------------------");
rewinddir(dir);
off_t loc;
while((entry=readdir(dir))!=NULL){
loc=telldir(dir);
//printf("loc:%ld\n",loc);
if(strcmp(entry->d_name,".")==0)continue;
if(strcmp(entry->d_name,"..")==0)continue;
stat(entry->d_name,&file_status);
if(S_ISDIR(file_status.st_mode))
traverse(entry->d_name);
chdir(directory);
dir=opendir(".");
seekdir(dir,loc);
}
getchar();

}

main(int argc,char* argv[]){
traverse(argv[1]);
}
