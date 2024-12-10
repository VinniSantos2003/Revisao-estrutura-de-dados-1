/*
Um método/função "int contPares (lista *L) que retorne o número de ocorrencias de elementos pares na lista L"
 */
#include <iostream>
using namespace std;

struct lista{
    lista * prox;
    int dado;
};

lista * inicializar(){
    return nullptr;
}
lista * inserirElemento(lista *L,int d){
    if(L == nullptr){
        lista * newList = (lista*)malloc(sizeof(lista));
        newList->dado = d;
        newList->prox = nullptr;
        return newList;
    }
    //Rodar L->prox ser null
    lista * temp = L;
    while(temp->prox !=nullptr){
        temp = temp->prox;
    };
    lista * newList = (lista*)malloc(sizeof(lista));
    newList->dado = d;
    newList->prox = nullptr;
    temp->prox = newList;
    return L;//Retorna o primeiro nodo
}
bool isEmpty(lista *L){
    if(L == nullptr){
        return true;
    }else{
        return false;
    }
}

int Cont_Pares(lista *L){//Questão que foi solicitada
    if(isEmpty(L)){//Caso esteja vazia
        cout << "Lista vazia";
        return 0;
    }
    //Loop para contagem
    lista * temp = L;
    int qnt_pares = 0;
    do{
        temp= temp->prox;
        if(temp->dado%2 == 0){
            qnt_pares++;
        }
        
    }while(temp->prox !=nullptr);
    return qnt_pares;
}

int main(){
    lista * listaTeste = inicializar();
    listaTeste = inserirElemento(listaTeste,1);
    listaTeste = inserirElemento(listaTeste,2);
    listaTeste = inserirElemento(listaTeste,3);
    listaTeste = inserirElemento(listaTeste,4);
    listaTeste = inserirElemento(listaTeste,5);
    int qnt_pares = Cont_Pares(listaTeste) ;
    return 0;
}