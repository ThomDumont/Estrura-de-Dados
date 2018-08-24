#include <iostream>

//Thomas Dumont das Neves 221070103

using namespace std;

class LDDE;

class No{
    public:
      int valor;
      No* proximo;
      No* anterior;

      No(int valor):proximo(NULL), anterior(NULL), valor(valor){}
     
      friend class LDDE;
};

class LDDE{
    private:
      No* primeiro;
      No* ultimo;
      int n;

    public:
      LDDE():primeiro(NULL), ultimo(NULL), n(0){

      }
      
      bool insere(int valor){
        No* novo = new No(valor);
        if(!novo){
          return false;
        }
        No* ptrAnt = NULL;
        No* ptrAtual = primeiro;
        while(ptrAtual && ptrAtual->valor < valor){
          ptrAnt = ptrAtual;
          ptrAtual = ptrAtual->proximo;
        }
        novo->anterior = ptrAnt;

        if(ptrAnt){
          ptrAnt->proximo = novo;
        }else{
          primeiro = novo;
        }
        novo->proximo = ptrAtual;
        if(ptrAtual){
          ptrAtual->anterior=novo;
        }else{
          ultimo = novo;
        }
				cout << "Adicionando o valor: " << valor <<endl;
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
        No* ptrAtual = primeiro;

        //busca
        while(ptrAtual && ptrAtual->valor < valor){
          ptrAtual = ptrAtual->proximo;
        }
        if(!ptrAtual || ptrAtual->valor != valor){
          return false;
        }
        No* ptrAnt = ptrAtual->anterior;
        No* ptrProximo = ptrAtual->proximo;
        if(ptrAnt){
          ptrAnt->proximo=ptrProximo;
        }else{
          primeiro = ptrProximo;
        }
        if(ptrProximo){
          ptrProximo->anterior=ptrAnt;
        }else{
          ultimo = ptrAnt;
        }
				cout << "apagando o valor " <<  ptrAtual->valor << endl;
        delete ptrAtual;
        n--;
        return true;
      }

};


int main() {
  LDDE l;	
	l.insere(5);
	l.insere(8);
	l.insere(7);
	l.insere(4);
	l.insere(1);
	l.imprime();
	l.remove(1);
	l.imprime();
	l.insere(6);
	l.imprime();
	l.busca(4);
	l.busca(6);
	l.busca(8);
}