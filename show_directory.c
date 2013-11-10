#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

//It wil print the files in the given directory
int main()
{
   DIR *d;
   char *dir_name="/home";
   d=opendir(dir_name);
   
   if(!d)
   {
      fprintf(stderr,"can't open the directory '%s'\n",dir_name);
      exit(EXIT_FAILURE);
   }
     while(1)
     {
         struct dirent *entry;
         entry=readdir(d);
         if(!entry)
         break;
         printf("%s \n",entry->d_name);
     }
     
    if(closedir(d)){
      fprintf(stderr,"could noe close directory '%s' \n",dir_name);
      exit(EXIT_FAILURE);
     }
     return 0;
}
