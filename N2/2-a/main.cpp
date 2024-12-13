#include <iostream>
using namespace std;

struct listaDuplamenteEncadeada{
    
    int dado;
    listaDuplamenteEncadeada *prox;
    listaDuplamenteEncadeada * ant;
}typedef LDE;

LDE * inicializar(){
    return nullptr;
}

bool isEmpty(LDE* L){
    if(L == nullptr){
        return true;
    }else{
        return false;
    }

}

LDE * inserirInicio(LDE * L,int valor){
    LDE * newLDE =(LDE*)malloc(sizeof(LDE));
    if(newLDE == nullptr){
        cout << "Erro ao alocar memoria";
        return L;
    }
    newLDE->dado = valor;
    if(isEmpty(L)){
        newLDE->prox = newLDE;
        newLDE->ant = newLDE;
        return newLDE;
    }
    newLDE->prox = L;
    newLDE->ant = L->ant;
    L->ant->prox = newLDE;
    L->ant = newLDE;
    return newLDE;

}

LDE * inserirFim(LDE* L,int value){
    LDE * newLDE = (LDE*)malloc(sizeof(LDE));
    if(newLDE == nullptr){
        cout << "Erro ao alocar memoria";
        return L;
    }
    newLDE->dado = value;
    if(isEmpty(L)){
        newLDE->prox = newLDE;
        newLDE->ant = newLDE;
        return newLDE;
    }
    newLDE->prox = L;
    newLDE->ant = L->ant;
    L->ant->prox = newLDE;
    L->ant = newLDE;
    return L;

}

void imprimir(LDE *L){
    LDE * temp = L;
    do{
        cout << temp->dado << " | ";
        temp = temp->prox;
    }while(temp != L);
}

int main(){
    LDE * L = inicializar();

    L = inserirInicio(L,1);//L será 1
    L = inserirInicio(L,2);//L será 2
    L = inserirInicio(L,3);//L será 3
    L = inserirFim(L,-1);//L será 3
    L = inserirFim(L,-2);//L será 3
    L = inserirFim(L,-3);//L será 3
    imprimir(L);
    return 0;
}