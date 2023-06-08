#include <queue>
#include <iostream>

using namespace std;


template<class T>
class ArvoreNo {
	public:
		T el;
		ArvoreNo<T> *left,*right;
		ArvoreNo(){
			left=right=0;			
		}
		ArvoreNo(T e,ArvoreNo<T> *l=0,ArvoreNo<T> *r=0){
			el=e;
			left=l;
			right=r;
		}
};

template<class T>
class Arvore {
	protected:
		ArvoreNo<T> *root;
	public:
		Arvore(){
			root = 0;			
		}
		~Arvore(){
			clear();
		}
		void clear(){
			clear(root);
			root=0;
		}
		
		ArvoreNo<T>* getRoot(){
			return root;
		}
		bool isEmpty() const {
		   return root=0;
		   }
		   
		void visit(ArvoreNo<T> *p){
			cout<<p->el<<" ";
		} 
		
		T search(T el) {
			ArvoreNo<T> *p=root;
			while (p!=0){
				
				if (el==p->el)		
					return p->el;								    
				else{					
					if (el < p->el)
				       p=p->left;
				   else p=p->right;
			 	}
		    }
			return 0;			
			
		}
		 //obs: pg 209 figura 6.23
		void insert(T el){
			ArvoreNo<T> *p=root,*prev=0;
			while (p!=0){
				prev=p;
				if (el<p->el)
					p=p->left;
				else p=p->right;
			}
			if (root==0) //a arvore esta vazia
			   root=new ArvoreNo<T>(el);
			else if (el < prev->el)
				prev->left=new ArvoreNo<T>(el);
			else prev->right=new ArvoreNo<T>(el);
					
			}
		
		void percusoExtensao(){
			queue<ArvoreNo<T>*> f;
			ArvoreNo<T> *p=root;
			if (p!=NULL){
				f.push(p);
				while (!f.empty()){
					p=f.front();					
					visit(p);
					f.pop();
					if (p->left!=0)
						f.push(p->left);
					if (p->right!=0)
						f.push(p->right);
				}	}
		}
		
		int alturaArvore(ArvoreNo<T> *root){
			if(root == NULL){
				return 0;
			}
			
			int left_height = alturaArvore(root->left);
			int right_height = alturaArvore(root->right);
			
			if(left_height > right_height){
				return left_height + 1;
			}
		}
		
		
		void preorder(ArvoreNo<T> *p){
			if (p!=0) {
				visit(p);
				preorder(p->left);
				preorder(p->right);
			}
			
		}
		
			
		void backbone(ArvoreNo<T> *p){
			ArvoreNo<T> *tmp = p;
			ArvoreNo<T> *noAnterior = NULL;
			ArvoreNo<T> *leftNode = NULL;
			
			while(tmp != 0) {
				if(tmp->left != 0) {
					leftNode = tmp->left;
					tmp->left = leftNode->right;
					leftNode->right = tmp;
					
					if(noAnterior == NULL){
						p = leftNode;
					}else{
						noAnterior->right = leftNode;
					}
				}else{
					noAnterior = tmp;
					tmp = tmp->right;
				}
			}
		}
	};
	
	
main(){
	
	Arvore<int> *a=new Arvore<int>();
	
	a->insert(7);
	a->insert(14);
	a->insert(22);
	a->insert(30);
	a->insert(40);
	a->insert(63);
	a->insert(80);

	// a->insert(20);
	
	//1.1) Qual a altura da árvore resultante?
	
	  // Resposta: 5
	
	//1.2) Mostre a árvore resultante:
	
	  // Resposta:  7 14 22 30 40 63 80
	
	//1.3) A árvore resultante está balanceada ou não?
	
	  // Resposta: Não está balanceada.
	
	
	a->preorder(a->getRoot());

		
	
	
	cout<<"---Apos as rotacoes -----"<<endl;
	a->preorder(a->getRoot());
	


	

	
   	
   	
}

