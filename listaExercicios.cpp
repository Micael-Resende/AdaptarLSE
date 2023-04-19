#include <iostream>
#include <string.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    No *proximo;
}No;

struct Lista{
    No *cabeca, *cauda;
    int tam;
    
    Lista(){
        cabeca = NULL;
        cauda = NULL;
        tam = 0;
    }
    
    bool vazia(){
        return (cabeca == NULL);
    }
    
    void inserirInicio(int val){
        No *novo = new No();
        novo->valor = val;
        
        if(vazia()){
            novo->proximo = NULL;
            cabeca = novo;
            cauda = novo;
        }else{
            novo->proximo = cabeca;
            cabeca = novo;
        }
        tam++;
    }
    
    
    void inserirFinal(int val){
        No *novo = new No();
        novo->valor = val;
        
        if(vazia()){
            novo->proximo = NULL;
            cabeca = novo;
            cauda = novo;
        }else{
            novo->proximo = NULL;
            cauda->proximo = novo;
            cauda = novo;
        }
        tam++;
    }
    
    void imprimir(){
        No *aux = cabeca;
        
        while(aux != NULL){
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }
    }
    
    int tamanho(){
        return tam;
    }
    
    
    void removerInicio(){
        if(!vazia()){
            if(tamanho() == 1){
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            }else{
                No *aux = cabeca;
                cabeca = cabeca->proximo;
                delete(aux);
            }
            tam--;
        }
    }
    
    
    
    void removerFinal(){
        if(!vazia()){
            if(tamanho() == 1){
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            }else{
                No *penultimo = cabeca;
                while(penultimo->proximo != cauda){
                    penultimo = penultimo->proximo;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->proximo = NULL;
            }
            tam--;
        }
    }
    
    
    void removerSegundo(){
        if(tamanho() == 2){
            removerFinal();
        }else{
            No *aux = cabeca->proximo;
            cabeca->proximo = aux->proximo;
            delete(aux);
            tam--;
        }
    }
    
    void inserirN(int x){
        for(int i = 1; i <= x; i++){
            inserirFinal(i);
        }
    }
    
    void inserirTamFinal(){
        inserirFinal(tamanho());
    }
    
    void inserirPenultima(int v){
        if(tamanho() > 1){
            No *penultimo = cabeca;
            
            while(penultimo->proximo != cauda){
                penultimo = penultimo->proximo;
            }
            
            No *novo = new No();
            novo->valor = v;
            novo->proximo = cauda;
            penultimo->proximo = novo;
        }
    }
    
    void inserirMeio(){
        
    }

    /*QUESTÃO 1*/
    bool buscarElemento(int val){
        No *atual = cabeca;
        while(atual != NULL){
            if(atual->valor == val){
                return true; //elemento encontrado
            }
            atual = atual->proximo;
        }
            return false; //elemento não encontrado
    }

    /*QUESTÃO 2*/
    void removerRepetidos(){
        if(vazia() || tamanho() == 1) {
            return; // não há repetidos em listas vazias ou com apenas um elemento
        }
        No *atual = cabeca;
        No *anterior = NULL;

        while(atual != NULL){
            No *aux = cabeca;
            while(aux != atual){ // percorre os elementos anteriores ao atual
                if (aux->valor == atual->valor){
                    // valor repetido, remove o nó atual
                    No *remover = atual;
                    anterior->proximo = atual->proximo;
                    if(remover == cauda){
                        cauda = anterior;
                    }
                    atual = atual->proximo;
                    free(remover);
                    tam--;
                    break; // sai do loop interno assim que encontrar um valor repetido
                }
                aux = aux->proximo;
            }
            if(aux == atual){ // valor não repetido, avança para o próximo nó
                anterior = atual;
                atual = atual->proximo;
            }
        }
    }

    /*QUESTÃO 3*/
    void inserirFinalSeNaoExistir(int val){
        No *atual = cabeca;

        while(atual != NULL){
            if(atual->valor == val){
                return; // Valor já está na lista, não faz nada
            }
            atual = atual->proximo;
        }
        // Se chegou aqui, o valor não está na lista, então adiciona no final
        No *novo = new No();
        novo->valor = val;

        if(vazia()){
            novo->proximo = NULL;
            cabeca = novo;
            cauda = novo;
        }else{
            novo->proximo = NULL;
            cauda->proximo = novo;
            cauda = novo;
        }
        tam++;
    }

};

int main() {
    Lista lista;
    
    lista.inserirInicio(2);
    lista.inserirInicio(1);
    lista.inserirInicio(1);
    lista.inserirFinal(3);
    lista.inserirFinal(4);
    lista.inserirFinal(4);

    lista.removerInicio();
    lista.removerFinal();

    int numProcurado;
    printf("Informe um numero: ");
    scanf("%d", &numProcurado);

    if(lista.buscarElemento(numProcurado)){// if(buscarValor(&l, 5))
        printf("O %d esta na lista\n", numProcurado);
    }else{
        printf("O %d nao esta na lista\n", numProcurado);
    }

    
    lista.buscarElemento();
    lista.removerRepetidos();
    lista.inserirFinalSeNaoExistir(2);

    lista.imprimir();

    return 0;
}