/*
 * Author: Vamsi Krishna.B
 * Binary Search Tree header file
 * 
 */
typedef struct node_struct{
    char* data;
    struct node_struct* left;
    struct node_struct* right;
} node;


node* new_node(node* left,node* right,char* key);

node* bst_add_num(node* root, char* data);

void print_treestyle(node* root);

node* right_rotation(node* root);

node* left_rotation(node* root);

int print_at_distance(node* root,int distance,int steps);

int max(int a,int b);

node* any_node_to_up(node* root,char* data);

node* delete_node(node* root,char* data);

void print_inorder(node* root);

node* destruct_node(node* root);
node* del_rec(node* root,node* main_root);
node* operate_on(node* root);
