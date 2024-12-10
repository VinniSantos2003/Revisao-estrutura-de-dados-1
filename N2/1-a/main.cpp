#include <iostream>
using namespace std;
//Lista encadeada simples circular com referencia ao ultimo Nó (o nó mais recente)

struct filaEncadeada {
    filaEncadeada * prox;
    int dado;

}typedef FE;

FE * inicializar(){
    return nullptr;
}


bool isEmpty(FE * L){
    if(L == nullptr){
        return true;
    }else{
        return false;
    }
}

FE * enqueue(FE *L,int d){
    FE * newFE = (FE*)malloc(sizeof(FE));
    newFE->dado = d;
    if(isEmpty(L)){
        newFE->prox = newFE;
        return newFE;
    }
    //Condicional para dois dados
    if(L->prox == L){
        newFE->prox = L;
        L->prox = newFE;
    }else{//Condicional para 3 ou mais
        //Rodar um loop at achar o primeiro dado da fila(primeiro a sair [é o cara que aponta pro ultimo que entrou])
        FE * temp = L;
        while(temp->prox !=L){
            temp = temp->prox;
        }
        newFE->prox = L;
        temp->prox = newFE;
        
    }

    return newFE;

}

int main(){

    FE * L = inicializar();
    L = enqueue(L,1);
    L = enqueue(L,2);
    L = enqueue(L,3);
    return 0;
}