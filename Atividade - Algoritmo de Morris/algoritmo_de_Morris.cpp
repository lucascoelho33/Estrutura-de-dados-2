#include <iostream>
#include <queue>
using namespace std;


template<class T>
class ArvoreNo {
	public:
		T el;
		ArvoreNo<T> *left, *right;

		ArvoreNo(){
			left = right = 0;			
		}

		ArvoreNo(T e, ArvoreNo<T> *l = 0, ArvoreNo<T> *r = 0){
			el = e;
			left = l;
			right = r;
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
		
		
		ArvoreNo<T>* getRoot(){
			return root;
		}
		bool isEmpty() const {
		   return root=0;
		   }
		   
		void visit(ArvoreNo<T> *p){
			cout<<p->el<<" ";
		}
		void MorrisInOrder() {
		    ArvoreNo<T> *p = root, *tmp;
		    
		    while(p != 0) {
		        if(p->left == 0) {
		            visit(p);
		            p = p->right;
		        }
		        else {
		            tmp = p->left;
		        
		            while(tmp->right != 0 && tmp->right != p){
		                tmp = tmp->right;
		            }

		            if(tmp->right == 0) {
                        tmp->right = p;
                        p = p->left;
                    } else {
		                visit(p);
		                tmp->right = 0;
		                p = p->right;
		            }
		            
		        }
		    }
		}
		
	void MorrisPreOrder() {
            ArvoreNo<T> *p = root, *tmp;
            
            while (p != 0) {
                if (p->left == 0) {
                    visit(p);
                    p = p->right;
                } else {
                    tmp = p->left;
                    
                    while (tmp->right != 0 && tmp->right != p) {
                        tmp = tmp->right;
                    }
                    
                    if (tmp->right == 0) {
                        visit(p);
                        tmp->right = p;
                        p = p->left;
                    } else {
                        tmp->right = 0;
                        p = p->right;
                    }
                }
            }
        }
	};
	
	main(){
	
		Arvore<int> *tree = new Arvore<int>();
	
	    tree->insert(10);        
	    tree->insert(5);
	    tree->insert(20);
	    tree->insert(4);
	    tree->insert(7);
	    tree->insert(15);
	    tree->insert(25);
	    tree->insert(6);
	    tree->insert(8);
	    tree->insert(14);
	    
	    
	    cout << "preorder" << endl;
	    tree->MorrisPreOrder();
	    
	}
	
	/*
	Caracter�sticas:
	1) Sem uso de pilha expl�cita
	2) A Complexidade � de tempo linear
	3) N�o utiliza espa�o adicional
	4) Capaz de preservar a estrutura original da �rvore. 
	
	*/

