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
    if(novaFilaEncadeada == nullptr){
        cout << "Erro ao alocar memoria\n";
        return L;
    }
    novaFilaEncadeada->dado = d;
    if(isEmpty(L)){//PRIMEIRA ENTRADA DE DADO
        novaFilaEncadeada->prox = novaFilaEncadeada;
        return novaFilaEncadeada;
    }else{
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
    if(L == nullptr){
        cout << "Lista vazia\n";
        return L;
    }
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
    //int i=0;
    /*
    while(i!=3){
        L=enqueue(L,i);
        i++;
    }*/
    L=enqueue(L,1); //entra o 1 (primeiro dado a ser inserido)
    L=enqueue(L,2);// entra o 2
    L=enqueue(L,3);//entra o 3
    L=enqueue(L,4);//entra o 4
    L=dequeue(L);//Sai o 1
    L=enqueue(L,5);//entrao 5
    return 0;
}