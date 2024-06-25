#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "ArvoreBinariaDeBusca.h"

/**
 * @brief Representa uma árvore AVL.
 *
 * @tparam T O tipo de dado guardado na árvore.
 */
template <typename T>
class MinhaArvoreAVL final : public ArvoreBinariaDeBusca<T>
{
    virtual ~MinhaArvoreAVL(){
        // escreva o algoritmo esperado
        this->destrutor(this->raiz);
    };

    /**
     * @brief Verifica se a arvore esta vazia
     * @return Verdade se a arvore esta vazia.
     */
    virtual bool vazia() const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        return (this->raiz == nullptr);
    };

    /**
     * @brief Retornar quantidade de chaves na arvore
     * @return Numero natural que representa a quantidade de chaves na arvore
     */
    virtual int quantidade() const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        return this->indiceNodo(this->raiz);
    };

    /**
     * @brief Verifica se a arvore contem uma chave
     * @param chave chave a ser procurada na arvore
     * @return Verdade se a arvore contem a chave
     */
    virtual bool contem(T chave) const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        if(vazia()){
            return false;
        } else {
            Nodo<T> *nodo = this->raiz;

            while(nodo != nullptr){
                if(chave == nodo->chave){
                    return true;
                } else if(chave < nodo->chave) {
                    nodo = nodo->filhoEsquerda;
                } else {
                    nodo = nodo->filhoDireita;
                }
            }
            return false;
        }
    };

    /**
     * @brief Retorna a altura da (sub)arvore
     * @param chave chave que é raiz da (sub)arvore cuja altura queremos.
     * @return Numero inteiro representando a altura da (subarvore). Se chave nao esta na arvore, retorna std::nullopt
     */
    virtual std::optional<int> altura(T chave) const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        if(!vazia()){
            Nodo<T> *nodo = this->raiz;

            while(nodo != nullptr){
                if(chave == nodo->chave){
                    return nodo->altura;
                } else if(chave < nodo->chave) {
                    nodo = nodo->filhoEsquerda;
                } else {
                    nodo = nodo->filhoDireita;
                }
            }
        }
        return std::nullopt;
    };

    /**
     * @brief Insere uma chave na arvore
     * @param chave chave a ser inserida
     */
    virtual void inserir(T chave){
        // escreva o algoritmo esperado
        if(this->raiz == nullptr){
            this->raiz = new Nodo<T>{chave};
        } else {
            this->inserirRecursiva(this->raiz, chave);
        }
    };

    /**
     * @brief Remove uma chave da arvore
     * @param chave chave a removida
     */
    virtual void remover(T chave){
        // escreva o algoritmo esperado
        if(this->vazia() == true) {
            return;
        } else {
            this->raiz = removerRecursiva(this->raiz, chave);
        }
    };

    /**
     * @brief Busca a chave do filho a esquerda de uma (sub)arvore
     * @param chave chave da arvore que eh pai do filho a esquerda
     * @return Chave do filho a esquerda. Se chave nao esta na arvore, retorna std::nullopt
     */
    virtual std::optional<T> filhoEsquerdaDe(T chave) const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        Nodo<T> *nodo = this->raiz;
        while (nodo != nullptr){
            if(nodo->chave == chave && nodo->filhoEsquerda != nullptr){
                return nodo->filhoEsquerda->chave;
            }
            
            if (chave < nodo->chave){
                nodo = nodo->filhoEsquerda;
            } else {
                nodo = nodo->filhoDireita;
            }
        }
        return std::nullopt;
    };

    /**
     * @brief Busca a chave do filho a direita de uma (sub)arvore
     * @param chave chave da arvore que eh pai do filho a direita
     * @return Chave do filho a direita. Se chave nao esta na arvore, retorna nullptr
     */
    virtual std::optional<T> filhoDireitaDe(T chave) const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        Nodo<T> *nodo = this->raiz;
        while (nodo != nullptr){
            if(nodo->chave == chave && nodo->filhoDireita != nullptr){
                return nodo->filhoDireita->chave;
            }
            
            if (chave >= nodo->chave){
                nodo = nodo->filhoDireita;
            } else {
                nodo = nodo->filhoEsquerda;
            }
        }
        return std::nullopt;
    };

    /**
     * @brief Lista chaves visitando a arvore em ordem
     * @return Lista encadeada contendo as chaves em ordem.
     */
    virtual ListaEncadeadaAbstrata<T> *emOrdem() const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>;
        emOrdemRecursivo(lista, this->raiz);
        return lista;
    };

    /**
     * @brief Lista chaves visitando a arvore em pre-ordem
     * @return Lista encadeada contendo as chaves em pre-ordem.
     */
    virtual ListaEncadeadaAbstrata<T> *preOrdem() const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>;
        preOrdemRecursivo(lista, this->raiz);
        return lista;
    };

    /**
     * @brief Lista chaves visitando a arvore em pos-ordem
     * @return Lista encadeada contendo as chaves em pos ordem.
     */
    virtual ListaEncadeadaAbstrata<T> *posOrdem() const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>;
        posOrdemRecursivo(lista, this->raiz);
        return lista;
    };

// FUNCOES

    void destrutor(Nodo<T> *nodo) const {
        if(nodo != nullptr){
            destrutor(nodo->filhoEsquerda);
            destrutor(nodo->filhoDireita);
            delete nodo;
        }
    }

    int indiceNodo(Nodo<T> *nodo) const {
        if(nodo == nullptr){
            return 0;
        } else {
            return 1 + indiceNodo(nodo->filhoEsquerda) + indiceNodo(nodo->filhoDireita);
        }
    }

    int atualizarAltura(Nodo<T> *nodo) const {
        if(nodo == nullptr){
            return -1;
        } else {
            nodo->altura = 1 + std::max(atualizarAltura(nodo->filhoEsquerda), atualizarAltura(nodo->filhoDireita));
            return nodo->altura;
        }
    }

    Nodo<T> *inserirRecursiva(Nodo<T> *nodo, T novachave) {
        if (novachave <= nodo->chave) {
            if (nodo->filhoEsquerda == nullptr) {
                nodo->filhoEsquerda = new Nodo<T>{novachave};
            } else { 
                inserirRecursiva(nodo->filhoEsquerda, novachave);
            }
        } else {
            if (nodo->filhoDireita == nullptr) {
                nodo->filhoDireita = new Nodo<T>{novachave};
            } else {
                inserirRecursiva(nodo->filhoDireita, novachave);
            }
        }
        nodo->altura = atualizarAltura(nodo);
        balanceamento(this->raiz);
        return nodo;
    }

    Nodo<T>* removerRecursiva(Nodo<T> *nodo, T chave) {
        if (nodo == nullptr) {
            return nullptr;
        }

        if (chave < nodo->chave) {
            nodo->filhoEsquerda = removerRecursiva(nodo->filhoEsquerda, chave);
        } else if (chave > nodo->chave) {
            nodo->filhoDireita = removerRecursiva(nodo->filhoDireita, chave);
        } else {
            if (nodo->filhoEsquerda == nullptr) {
                Nodo<T> *temp = nodo->filhoDireita;
                delete nodo;
                return temp;
            } else if (nodo->filhoDireita == nullptr) {
                Nodo<T> *temp = nodo->filhoEsquerda;
                delete nodo;
                return temp;
            }

            Nodo<T> *temp = minValueNode(nodo->filhoDireita);
            nodo->chave = temp->chave;
            nodo->filhoDireita = removerRecursiva(nodo->filhoDireita, temp->chave);
        }

        if (nodo == nullptr) {
            return nodo;
        }

        nodo->altura = atualizarAltura(nodo);
        balanceamento(nodo);
        return nodo;
    }

    Nodo<T>* minValueNode(Nodo<T> *nodo) const {
        Nodo<T> *atual = nodo;
        while (atual->filhoEsquerda != nullptr) {
            atual = atual->filhoEsquerda;
        }
        return atual;
    }

    void emOrdemRecursivo(ListaEncadeadaAbstrata<T> *lista, Nodo<T> *nodo) const {
        if(nodo != nullptr){
            emOrdemRecursivo(lista, nodo->filhoEsquerda);
            lista->inserirNoFim(nodo->chave);
            emOrdemRecursivo(lista, nodo->filhoDireita);
        }
    }

    void preOrdemRecursivo(ListaEncadeadaAbstrata<T> *lista, Nodo<T> *nodo) const {
        if(nodo != nullptr){
            lista->inserirNoFim(nodo->chave);
            preOrdemRecursivo(lista, nodo->filhoEsquerda);
            preOrdemRecursivo(lista, nodo->filhoDireita);
        }
    }

    void posOrdemRecursivo(ListaEncadeadaAbstrata<T> *lista, Nodo<T> *nodo) const {
        if(nodo != nullptr){
            posOrdemRecursivo(lista, nodo->filhoEsquerda);
            posOrdemRecursivo(lista, nodo->filhoDireita);
            lista->inserirNoFim(nodo->chave);
        }
    }

    void rotacaoEsquerda(Nodo<T> *&nodo) {
        Nodo<T> *newRaiz = nodo->filhoDireita;
        nodo->filhoDireita = newRaiz->filhoEsquerda;

        newRaiz->filhoEsquerda = nodo;
        nodo = newRaiz;

        atualizarAltura(nodo->filhoEsquerda);
        atualizarAltura(nodo);
    }

    void rotacaoDireita(Nodo<T> *&nodo) {
        Nodo<T> *newRaiz = nodo->filhoEsquerda;
        nodo->filhoEsquerda = newRaiz->filhoDireita;

        newRaiz->filhoDireita = nodo;
        nodo = newRaiz;

        atualizarAltura(nodo->filhoDireita);
        atualizarAltura(nodo);
    }

    void rotacaoEsquerdaDireita(Nodo<T> *& nodo) {
        rotacaoEsquerda(nodo->filhoEsquerda);
        rotacaoDireita(nodo);
    }

    void rotacaoDireitaEsquerda(Nodo<T> *& nodo) {
        rotacaoDireita(nodo->filhoDireita);
        rotacaoEsquerda(nodo);
    }

    void balanceamento(Nodo<T>*& nodo) {
        if (nodo == nullptr) {
            return;
        }

        balanceamento(nodo->filhoEsquerda);
        balanceamento(nodo->filhoDireita);

        if (nodo->filhoEsquerda == nullptr && nodo->filhoDireita == nullptr) {
            return;
        }

        if (nodo->filhoEsquerda == nullptr) {
            if (nodo->filhoDireita != nullptr) {
                if (nodo->filhoDireita->filhoEsquerda != nullptr && nodo->filhoDireita->filhoDireita != nullptr) {
                    if (nodo->filhoDireita->filhoEsquerda->altura > nodo->filhoDireita->filhoDireita->altura) {
                        rotacaoDireitaEsquerda(nodo);
                    } else {
                        rotacaoEsquerda(nodo);
                    }
                } else if (nodo->filhoDireita->filhoEsquerda != nullptr) {
                    rotacaoDireitaEsquerda(nodo);
                } else if (nodo->filhoDireita->filhoDireita != nullptr) {
                    rotacaoEsquerda(nodo);
                }
            }
        } else if (nodo->filhoDireita == nullptr) {
            if (nodo->filhoEsquerda != nullptr) {
                if (nodo->filhoEsquerda->filhoDireita != nullptr && nodo->filhoEsquerda->filhoEsquerda != nullptr) {
                    if (nodo->filhoEsquerda->filhoDireita->altura > nodo->filhoEsquerda->filhoEsquerda->altura) {
                        rotacaoEsquerdaDireita(nodo);
                    } else {
                        rotacaoDireita(nodo);
                    }
                } else if (nodo->filhoEsquerda->filhoDireita != nullptr) {
                    rotacaoEsquerdaDireita(nodo);
                } else if (nodo->filhoEsquerda->filhoEsquerda != nullptr) {
                    rotacaoDireita(nodo);
                }
            }
        } else {
            if (nodo->filhoEsquerda->altura - nodo->filhoDireita->altura > 1) {
                rotacaoDireita(nodo);
            } else if (nodo->filhoDireita->altura - nodo->filhoEsquerda->altura > 1) {
                rotacaoEsquerda(nodo);
            }
        }
        atualizarAltura(nodo);
    }
};

#endif
