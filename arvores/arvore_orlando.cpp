/*
 * Árvore Binária.
 *
 * Prof. Me. Orlando Saraiva Jr
 *
 */
#include <iostream>

using namespace std;

struct node{
 	int valor;
 	node *left;
 	node *right;
};

node * inicializar(int valor){
 	node *root = new node();
  root->valor = valor;
  root->left = NULL;
  root->right = NULL;
  return root;
 }
void destruir_arvore(node *leaf){
 	if(leaf != NULL){
 		destruir_arvore(leaf->left);
 		destruir_arvore(leaf->right);
 		delete leaf;
 	}
 }
void inserir(int key, node *leaf){
 	if(key < leaf->valor){
 		if(leaf->left != NULL){
 			inserir(key, leaf->left);
 		}else{
 			leaf->left = new node;
 			leaf->left->valor = key;
 			leaf->left->left = NULL;
 			leaf->left->right = NULL;
 		}
 	}else if(key >= leaf->valor){
 		if(leaf->right != NULL){
 			inserir(key, leaf->right);
 		}else{
 			leaf->right = new node;
 			leaf->right->valor = key;
 			leaf->right->right = NULL;
 			leaf->right->left = NULL;
 		}
 	}
}
node * search(int key, node *leaf){
 	if(leaf != NULL){
 		if(key == leaf->valor){
 			return leaf;
 		}
 		if(key < leaf->valor){
 			return search(key, leaf->left);
 		}else{
 			return search(key, leaf->right);
 		}
 	}else{
 		return NULL;
 	}
}
void ordem(node *leaf){
 	if(leaf != NULL){
 		ordem(leaf->left);
 		cout << leaf->valor << ",";
 		ordem(leaf->right);
 	}
}
void pos_ordem(node *leaf){
 	if(leaf != NULL){
 		ordem(leaf->left);
 		ordem(leaf->right);
 		cout << leaf->valor << ",";
 	}
}
void pre_ordem(node *leaf){
 	if(leaf != NULL){
 		cout << leaf->valor << ",";
 		ordem(leaf->left);
 		ordem(leaf->right);
 	}
}
node* encontrar_menor(node* leaf){
    if(leaf == NULL) {
        return NULL;
    }else if(leaf->left == NULL) {
        return leaf;
    }else {
        return encontrar_menor(leaf->left);
    }
}
node* remover(int x, node* leaf){
    node* temp;
    if(leaf == NULL){
        return NULL;
    }else if(x < leaf->valor) {
        leaf->left = remover(x, leaf->left);
    }else if(x > leaf->valor){
        leaf->right = remover(x, leaf->right);
    }else if(leaf->left && leaf->right){
        temp = encontrar_menor(leaf->right);
        leaf->valor = temp->valor;
        leaf->right = remover(leaf->valor, leaf->right);
    }else{
        temp = leaf;
        if(leaf->left == NULL)
            leaf = leaf->right;
        else if(leaf->right == NULL)
            leaf = leaf->left;
        delete temp;
    }

    return leaf;
}

int main(){

  node *root = NULL;
  node *no_encontrado = NULL;

  root = inicializar(29);

 	inserir(10, root);
 	inserir(6, root);
 	inserir(14, root);
 	inserir(50, root);
  inserir(55, root);
  inserir(8, root);
 	inserir(11, root);
  inserir(45, root);
 	inserir(3, root);
 	inserir(18, root);
  inserir(99, root);
 	inserir(1, root);

  cout << "Pré-ordem:  \t";
 	pre_ordem(root);
  cout << endl;
  cout << "Ordem:  \t";
 	ordem(root);
  cout << endl;
  cout << "Pós-ordem:\t";
 	pos_ordem(root);
  cout << endl;

  no_encontrado == NULL;
  no_encontrado = search(50, root);
  if (no_encontrado == NULL) {
    cout << " Não encontrado o valor 50 na árvore " << endl;
  } else {
    cout << " O valor 50 foi encontrado na árvore " << endl;
  }
  no_encontrado == NULL;
  no_encontrado = search(5, root);
  if (no_encontrado == NULL) {
    cout << " Não encontrado o valor 5 na árvore " << endl;
  } else {
    cout << " O valor 5 foi encontrado na árvore " << endl;
  }

  no_encontrado == NULL;
  no_encontrado = encontrar_menor(root);
  cout << " Menor valor encontrado: " << no_encontrado->valor << endl;

  remover(50, root);
  cout << "Ordem:  \t";
  ordem(root);
  destruir_arvore(root);
}
