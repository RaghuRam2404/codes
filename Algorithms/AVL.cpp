#include <bits/stdc++.h>
using namespace std;

struct AVLNode{
	int nodeValue;
	struct AVLNode* parent;
	struct AVLNode* right;
	struct AVLNode* left;
	int lchild, rchild;
	int ht;
};
typedef AVLNode node;

node* createNode(int val, node* parent){
	node *n = new node();
	n->parent=parent;
	n->right = n->left = 0;
	n->ht = 1;
	n->nodeValue = val;
	return n;
}

class AVL{
	node* head;
	public:
		AVL(){
			head = 0;
		}
		void insert(int val){
			cout<<"INSERT "<<val<<endl;
			node* p;
			if(head == 0){
				head = createNode(val,0);
			}else{
				p = in(head, val);
				checkNode(p, val);
			}
		}

		int ht(node* n){
			if(n==0) return 0;
			return n->ht;
		}

		int balanced(node* p){
			if(p==0) return 1;
			return (abs(ht(p->right)-ht(p->left)) <= 1);
		}

		void updateHt(node *y){
			y->ht = max(ht(y->left), ht(y->right))+1;
		}

		void right_rotate(node* y, node* z){
			cout<<"RIGHT ROTATE"<<endl;
			node* temp = z->parent;
			z->parent = y;
			y->parent = temp;
			z->left = y->right;
			y->right = z;
			// update heights
			updateHt(y);
			updateHt(z);
		}

		void left_rotate(node* y, node* z){
			cout<<"LEFT ROTATE"<<endl;
			node* temp = z->parent;
			z->parent = y;
			y->parent = temp;
			y->right = y->left;
			y->left = z;
			// update heights
			updateHt(y);
			updateHt(z);
		}

		node* in(node* n, int val){
			if(n->nodeValue > val){
				if(n->left == 0){ n->left = createNode(val, n); updateHt(n); return n->left; }
				else{ node* p = in(n->left, val); updateHt(n); return p; }
			}else{
				if(n->right == 0){ n->right = createNode(val, n); updateHt(n); return n->right; }
				else{ node* p = in(n->right, val); updateHt(n); return p; }
			}
		}

		void checkNode(node* p, int val){
			if(p == 0) return;
			cout<<"CHECKING : "<<p->nodeValue<<"ht : "<<balanced(p)<<endl;
			if(!balanced(p)){
				if(p->nodeValue>val){
					// left
					if(p->left->nodeValue>val){
						// right rotation
						right_rotate(p->left, p);
					}else{
						// left and then right
						left_rotate(p->left->right, p->left);
						right_rotate(p->left, p);
					}
				}else if(p->nodeValue<val){
					// right
					if(p->right->nodeValue<val){
						// left rotation
						left_rotate(p->right,p);
					}else{
						//right and then left
						right_rotate(p->right->left, p->right);
						left_rotate(p->right,p);
					}
				}
				if(p!=0) checkNode(p->parent, p->parent->nodeValue);
			}else{
				if(p!=0) checkNode(p->parent, p->parent->nodeValue);
			}
		}

		void inorderPrint(){
			fflush(stdout);
			printin(head);
			cout<<endl;
		}
		void printin(node* n){
			if(n==0){ return; }
			printin(n->left);
			cout<<n->nodeValue<<":"<<ht(n)<<" ";
			printin(n->right);
		}
};

int main(){
	AVL a;
	a.insert(10);
	a.inorderPrint();
	a.insert(5);
	a.inorderPrint();
	a.insert(7);
	a.inorderPrint();
	a.insert(11);
	a.inorderPrint();
}