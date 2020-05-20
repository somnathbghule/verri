#include <tree.h>

tree::tree(){
	DEBUG();
	root_=NULL;
}
tree::~tree(){
	DEBUG();
}
bst::bst(){
	DEBUG();
}
node * bst::insert(node *root, int val) {
	if(root) {

		if ( val < root->key_ ){
			root->left_=insert( root->left_, val );		
		}else 			
			root->right_=insert( root->right_, val );		
	} else
		return new node(val);
}

void bst::inorder(node *root){
	if(root) {
		inorder(root->left_);
		cout<<root->key_<<" ";
		inorder(root->right_);
	} 
}
int  bst::totalNodes(node *root) {
	if (root){
		int totalnodes=0;
		if (root->left_ && root->right_)
			totalnodes++;

		totalnodes+=totalNodes(root->right_)+totalNodes(root->left_);
		return totalnodes;
	} else 
		return 0;

}
//using inorder left, root, right
bool bst::isBST( node *root ) {
	static node *prev=NULL;
	if ( root ){
		if (!isBST(root->left_))
			return false;

		if ( prev && prev->key_ >= root->key_ )
			return false;

		prev=root;

		return isBST(root->right_);
	} else
		return true;
}
bst::~bst(){
	DEBUG();
}
void bst_test() {
 	bst b;
	b.root(b.insert(NULL, 10));
	b.insert(b.root(), 15);
	b.insert(b.root(), 5);
	b.insert(b.root(), 4);
	b.insert(b.root(), 6);
	b.inorder(b.root());
	cout<<endl;
	//cout<<"totalNodes: "<<b.totalNodes(b.root())<<endl;;
	cout<<"isbst: "<<b.isBST(b.root())<<endl;;
}
