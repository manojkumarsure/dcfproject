#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
   char tag[3];
   char title[30];
   char artist[30];
   char album[30];
   char year[4];
   char comment[30];
   unsigned char genre;
}mp3Tags;
main(int argc,char* argv[])
{
	mp3Tags currentTags;
	FILE* fp;
	FILE* fa;
	fp=fopen(argv[1],"rb");
	fa=fopen("a.txt","a");
	fseek(fp,0,SEEK_END);
	long pos=ftell(fp);
	fseek(fp, (pos - sizeof(mp3Tags)), SEEK_SET);
	if(fread(&currentTags, sizeof(mp3Tags),1, fp) != 1)
    {
      printf("\nUnable to read tags!\n");
      exit(0);
    }
   fprintf(fa,"Title: %s\n", currentTags.title);
   fprintf(fa,"Artist: %s\n", currentTags.artist);
   fprintf(fa,"Album: %s\n", currentTags.album);
   fprintf(fa,"Year: %c%c%c%c\n", currentTags.year[0],currentTags.year[1],currentTags.year[2],currentTags.year[3]);
   fclose(fp);
   fclose(fa);
}
