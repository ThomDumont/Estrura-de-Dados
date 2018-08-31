#include <iostream>
#define MAX 5
using namespace std;
//Thomas Dumont das Neves

class Fila{
	private:
		int v[MAX+1];
		int i;
		int f;
		int n;
	public:
		Fila(): i(0), f(0), n(MAX+1){
		}
		bool enfileira(int valor){
			if( ( ( f+1 ) %n ) == i){
				return false;
			}

			v[f] = valor;
			f= (f+1)%n;
			return true;	
		
		}
		
		bool desenfileira(int* desenfileirado=NULL){
			if(i==f)
				return false;
		
			if(desenfileirado){
				*desenfileirado = v[i];
			}
			i=(i+1)%n;
			return true;
		}

		void imprime(){
			for(int k = i; k % n != f ; k = (k+1 )% n){
				cout << v[k] << endl;

			}
			cout << "---------" << endl;
		}
	
};


int main() {
	Fila f;
	f.enfileira(9);
	f.enfileira(8);
	f.enfileira(3);
	f.enfileira(48);
	f.enfileira(102);
	f.imprime();
	f.desenfileira();
	
	int temp;
	while(f.desenfileira(&temp)){
		cout << temp << endl;
	}
	

}
