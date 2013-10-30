/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : bst.c

* Purpose : To learn recursion.

* Last Modified : Monday 07 October 2013 01:32:57 PM IST

* Created By : Y Devesh

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include "bst.h"
#include<string.h>
int main(){
    node* root_ptr;
	int N_i,i;char str[20];
    root_ptr = NULL;
scanf("%d",&N_i);

for(i=0;i<N_i;i++){
	scanf("%s",str);
	root_ptr=bst_add_num(root_ptr,str);
//	root_ptr=any_node_to_up(root_ptr,str);
printf("\n----------------------------------------------------------------\n");
print_treestyle(root_ptr);
printf("\n----------------------------------------------------------------\n");
}
printf("delete");
for(i=0;i<N_i;i++){
scanf("%s",str);
root_ptr=delete_node(root_ptr,str);
printf("\n----------------------------------------------------------------\n");
print_treestyle(root_ptr);
printf("\n----------------------------------------------------------------\n");


}

/*for(i=0;i<N_s;i++){
	scanf("%s",str);
	root_ptr=any_node_to_up(root_ptr,str);
			if(strcmp(root_ptr->data,str)!=0){
				root_ptr=bst_add_num(root_ptr,str);
				root_ptr=any_node_to_up(root_ptr,str);
				}
print_treestyle(root_ptr);
}
*/
    return 0;
}
// That's all folks!
