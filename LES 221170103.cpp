#include <iostream>
#include <vector>
#define MAX 100
using namespace std;
//Thomas Dumont das Neves R.A 22117010-3

class LES {
private:
    int n=0;
    int v[MAX];

public:
    LES() : n(0){

    }

    int getN(){
        return n;
    }

    bool inserir(int valor) {
        if (n==MAX)
            return false;

        int i;
        for (i=0;i<n && v[i] < valor;i++);

        for(int j=n;j>i;j--){
            v[j] = v[j-1];
        }
        v[i]=valor;
        n++;
        return true;
    }
		bool busca(int valor){
        if (n<=0){
            cout << "Ainda nao foram introduzidos valores ao seu vetor" << endl;
            return false;
        }
        int i;
        for(i=0;i<n && v[i]!=valor;i++);
        if(i>=n){
            cout << "Valor nao encontrado, foi deletado ou nao existe" << endl;
            return false;
        }else {
            cout << "o valor esta na posição  " << i << "  e é igual a  " << valor << endl;
        }
        return true;
    }

    void print() const{
        for(int i=0;i<n;i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }


    bool remove(int valor){
        if (n<=0){
            return false;
        }
        int i;
        for(i=0;i<n && v[i]<valor;i++);

        for(int j=i;j<n;j++){
            v[j] = v[j+1];
        }
        n--;
        return true;
    }
	};
    

void operator<<(ostream& a, const LES& b){
    b.print();
}

int main() {
    LES v;
   
    v.busca(1);

    v.inserir(20);
    v.inserir(5);
    v.inserir(7);
    v.inserir(8);
		v.inserir(6);

    cout << v;
  
    v.busca(7);
    v.remove(6);
		
    cout << v;
    v.busca(6);


    return 0;

}