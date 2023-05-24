void MorrisInorder() {
	ArvoreNo<T> *p=root, *temp;
	while(p!=0){
		if(p->left==0){
			visit(p);
			p=p->right;
		}else{
			tmp = p->left;
			while(tmp->right!=0 && tmp->right!=p) {
				tmp=tmp->right;
			}
			if(tmp->right==0) {
				tmp->right=p;
				p=p->left;
			}else{
				visit(p);
				tmp->right==0;
				p=p->right;
			}
		}
	}
}
