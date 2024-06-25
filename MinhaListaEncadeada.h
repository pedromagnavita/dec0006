#ifndef DEC0006_MINHA_LISTA_ENCADEADA_H
#define DEC0006_MINHA_LISTA_ENCADEADA_H

#include <cstddef>
// std::size_t

#include "Elemento.h"
// Elemento
#include "ListaEncadeadaAbstrata.h"
#include "excecoes.h"
// ExcecaoDadoInexistente
// ExcecaoListaEncadeadaVazia
// ExcecaoNaoImplementado
// ExcecaoPosicaoInvalida

/**
 * @brief Uma lista encadeada de dados.
 * 
 * @tparam T O tipo dos dados armazenados na lista.
 */
template<typename T>
class MinhaListaEncadeada: public ListaEncadeadaAbstrata<T>
{
    /**
     * @brief Destrutor. Destroi todos os elementos da lista
     */
    virtual ~MinhaListaEncadeada() {
        //escreva o algoritmo esperado
        while ( this->_tamanho > 0) {
            this->removerDoInicio();
        }
    }

    /**
     * @brief Obtém a quantidade de itens na lista.
     * 
     * @return Um inteiro maior ou igual a 0.
     */
    virtual std::size_t tamanho() const
    {
        //substitua a linha abaixo pelo algoritmo esperado
        return this->_tamanho;
    };
    
    /**
     * @brief Indica se há algum item na lista ou não.
     * 
     * @return false se houver algum item na lista; true caso contrário.
     */
    virtual bool vazia() const 
    {
        //substitua a linha abaixo pelo algoritmo esperado
        return this->_tamanho == 0;
    };

    /**
     * @brief Obtém a posição de um item na lista. Lança
     * ExcecaoListaEncadeadaVazia caso a lista esteja vazia ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item cuja posição deseja-se obter.
     * @return Um inteiro na faixa [0, tamanho); se houver mais que um mesmo
     * item na lista, a posição da primeira ocorrência.
     */
    virtual std::size_t posicao(T dado) const 
    {
        //substitua a linha abaixo pelo algoritmo esperado
        if (this->vazia()) {
            throw ExcecaoListaEncadeadaVazia();
        }

        Elemento<T> *atual = this->_primeiro;
        std::size_t pos = 0;

        while (atual != nullptr) {
            if (atual->dado == dado) {
                return pos;
            }
            atual = atual->proximo;
            ++pos;
        }

        throw ExcecaoDadoInexistente();
    };
    
    /**
     * @brief Indica se um dado item está contido na lista ou não.
     * 
     * @param dado O item sendo buscado.
     * @return true se o item está contido na lista; false caso contrário.
     */
    virtual bool contem(T dado) const
    {
        //substitua a linha abaixo pelo algoritmo esperado
        std::size_t pos = 0;
        Elemento<T> *atual = this->_primeiro;

        while (atual != nullptr) {
            if (atual->dado == dado) {
                return true;
            }

            atual = atual->proximo;
            ++pos;
        }

        return false;
    };

    /**
     * @brief Insere um item no início da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoInicio(T dado) 
    {
        //escreva o algoritmo esperado
        Elemento<T> *novoElemento = new Elemento<T>(dado, this->_primeiro);
        this->_primeiro = novoElemento;
        this->_tamanho++;
    };

    /**
     * @brief Insere um item em uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa
     * [0, tamanho].
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho]. Ao se inserir em
     * uma posição já ocupada, a posição do item que já estava naquela posição
     * será posicao + 1; inserir-se na posicao tamanho significa inserir-se no
     * fim da lista.
     * @param dado O item sendo inserido.
     */
    virtual void inserir(std::size_t posicao, T dado)
    {
        //escreva o algoritmo esperado
        if (posicao < 0 || posicao > this->_tamanho) {
            throw ExcecaoPosicaoInvalida();
        }

        if (posicao == 0) {
            inserirNoInicio(dado);
        } else {
            Elemento<T> *atual = this->_primeiro;
            
            for (std::size_t i = 1; i < posicao; ++i) {
                atual = atual->proximo;
            }
            
            Elemento<T> *novo = new Elemento<T>(dado, atual->proximo);
            atual->proximo = novo;
            this->_tamanho++;
        }
    };


    /**
     * @brief Insere um item no fim da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoFim(T dado)
    {
        //escreva o algoritmo esperado
        if (this->vazia()) {
            inserirNoInicio(dado);
        } else {
            this->inserir(this->_tamanho, dado);
        }
    };

    /**
     * @brief Remove o primeiro item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoInicio()
    {
        //substitua a linha abaixo pelo algoritmo esperado
        if (vazia()){
            throw ExcecaoListaEncadeadaVazia();
        }

        Elemento<T> *removido = this->_primeiro;
        T dado = removido->dado;
        this->_primeiro = removido->proximo;
        delete removido;
        this->_tamanho--;
        return dado;
    };

    /**
     * @brief Remove um item de uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa [0, tamanho).
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho).
     * @return O item removido.
     */
    virtual T removerDe(std::size_t posicao)
    {
        //substitua a linha abaixo pelo algoritmo esperado
        if (posicao < 0 || posicao >= this->_tamanho) {
            throw ExcecaoPosicaoInvalida();
        }

        if (posicao == 0) {
            return this->removerDoInicio();
        } else {
            Elemento<T> *atual = this->_primeiro;

            for (std::size_t i = 1; i < posicao; i++) {
                atual = atual->proximo;
            }

            Elemento<T> *removido = atual->proximo;
            T dado = removido->dado;
            atual->proximo = removido->proximo;
            delete removido;
            this->_tamanho--;
            return dado;
        }
    };

    /**
     * @brief Remove o último item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoFim()
    {
        //substitua a linha abaixo pelo algoritmo esperado
        if (this->vazia()) {
            throw ExcecaoListaEncadeadaVazia();
        }

        if (this->_primeiro->proximo == nullptr) {
            return this->removerDoInicio();
        } else {
            return this->removerDe(this->_tamanho - 1);
        }
    };

    /**
     * @brief Remove um item específico da lista. Lança
     * ExcecaoListaEncadeadaVazia caso não haja nenhum item na lista ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item a ser removido. Se houver mais que um item com
     * o mesmo valor, remove a primeira ocorrência.
     */
    virtual void remover(T dado)
    {
        //escreva o algoritmo esperado
        if (this->vazia()) {
            throw ExcecaoListaEncadeadaVazia();
        }

        if (!contem(dado)) {
            throw ExcecaoDadoInexistente();
        }

        if (this->_primeiro->dado == dado) {
            removerDoInicio();
        } else {
        this->removerDe(posicao(dado));
        };
    };
};

#endif
