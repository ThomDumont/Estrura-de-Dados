#include <iostream>
//Thomas Dumont das Neves 221170103
using namespace std;

class LDE;

class No{
    private:
        int valor;
        No* proximo;
        No(int valor): valor(valor), proximo(NULL){

        }
    public:
        ~No(){
          
        }

    friend class LDE;

};
class LDE{
    private:
        int n;
        No* primeiro;

    public:
        LDE(): n(0), primeiro(NULL){

        }

			bool insere(int valor){
				No* novo = new No(valor);
				if(novo == NULL){
					return false;
				}
						

				No* anterior = NULL;
				No* atual = primeiro;

				while(atual && valor > atual->valor){
						anterior = atual;
						atual = atual->proximo;
				}

				novo->proximo = atual;
				if(anterior!=NULL){
						anterior->proximo = novo;
				}else{
						primeiro = novo;
				}
				n++;
				return true;
			}

    	void imprime(){
        No* atual = primeiro;
        while(atual){
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    	}
  	bool busca(int valor){
    	No* atual = primeiro;
    	No* anterior = NULL;

    	while(atual && atual->valor != valor){  
      	  anterior = atual;
        	atual = atual->proximo;
      	}
      	if(atual->valor == valor){
        	  cout << "Valor: " << atual->valor << " achado!"<<endl;
          	return true;
      	}else{
        	return false;
      	}
           
  	}

		bool remove(int valor){
			No* atual = primeiro;
			No* anterior = NULL;

			while(atual && atual->valor != valor){
				anterior = atual;
				atual = atual->proximo;
			}
			if(atual && atual->valor == valor){
						anterior->proximo = atual->proximo;
						delete atual;
						return true;
				}else{
					return false;
				}
			
			
		}
		virtual ~LDE(){
			No* atual = primeiro;
			No* prox;
			while(atual){
					prox = atual->proximo;
					delete atual;
					atual = prox;
			}
		}


};

int main() {
	LDE l;
	l.insere(5);
	l.insere(3);
	l.insere(7);
	l.insere(4);
  l.imprime();
	l.busca(7);
	l.remove(5);
	l.imprime();
}