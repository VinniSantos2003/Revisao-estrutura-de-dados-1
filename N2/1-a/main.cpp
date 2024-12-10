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
    FE * novaFilaEncadeada = (FE*)malloc(sizeof(FE));
    novaFilaEncadeada->dado = d;
    if(isEmpty(L)){//PRIMEIRA ENTRADA DE DADO
        novaFilaEncadeada->prox = novaFilaEncadeada;
        return novaFilaEncadeada;
    }
    //Condicional para dois dados
    if(L->prox == L){
        novaFilaEncadeada->prox = L;
        L->prox = novaFilaEncadeada;
    }else{//Condicional para 3 ou mais
        //Rodar um loop at achar o primeiro dado da fila(primeiro a sair [é o cara que aponta pro ultimo que entrou])
        FE * temp = L;
        while(temp->prox != L){
            temp = temp->prox;
        }
        novaFilaEncadeada->prox = L;
        temp->prox = novaFilaEncadeada;
        
    }
    return novaFilaEncadeada;
}

FE * dequeue(FE *L){
    //Ultimo dado a ser apagado, rodar loop até antes do ultimo dado;
    if(L->prox == L){
        free(L);
        return inicializar();
    }

    FE * temp = L;
    while(temp->prox->prox != L){
        temp = temp->prox;
    }
    free(temp->prox);
    temp->prox = L;
    return L;
}


int main(){

    FE * L = inicializar();
    int i=0;
    while(i!=1){
        L=enqueue(L,i);
        i++;
    }
    L=dequeue(L);
    return 0;
}