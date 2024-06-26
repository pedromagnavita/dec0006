#ifndef MINHA_TABELA_ESPALHAMENTO_H
#define MINHA_TABELA_ESPALHAMENTO_H

#include "MinhaListaEncadeada.h"
// MinhaListaEncadeada
#include "TabelaEspalhamentoAbstrata.h"
// TabelaEspalhamentoAbstrata
#include "excecoes.h"
// ExcecaoDadoInexistente
#include <cmath>
#include <string>

template <typename T, std::size_t capac>
class MinhaTabelaEspalhamento final : public TabelaEspalhamentoAbstrata<T, capac>
{
public:

    /**
     * @brief Obtém a capacidade da tabela.
     * 
     * @return Um inteiro maior do que 0.
     */
    virtual std::size_t capacidade() const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        return capac;
    };

    /**
     * @brief Insere um dado na tabela. Se a tabela já contiver o dado, ele não
     * é inserido novamente.
     *
     * @param dado O dado a ser inserido.
     */
    virtual void inserir(T dado) 
    {
        // escreva o algoritmo esperado
        std::size_t posicao = funcaoEspalhamento(dado);
        if(!this->tabela[posicao].contem(dado)) {
            this->tabela[posicao].inserirNoFim(dado); 
            totalElementos++;
        }
    };

    /**
     * @brief Remove um dado da tabela. Se a tabela não contiver o dado, uma
     * exceção ExcecaoDadoInexistente é lançada.
     *
     * @param dado O dado a ser removido.
     */
    virtual void remover(T dado) {
        // escreva o algoritmo esperado
        size_t posicao = funcaoEspalhamento(dado);
        if(this->tabela[posicao].contem(dado)) {
        this->tabela[posicao].remover(dado);
        totalElementos--;
        } else {
            throw ExcecaoDadoInexistente();
        }
    };

    /**
     * @brief Verifica se \p dado está contido na tabela.
     *
     * @param dado O dado sendo buscado.
     * @return true se o dado está contido na tabela; false caso contrário.
     */
    virtual bool contem(T dado) const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        std::size_t posicao = funcaoEspalhamento(dado);
        return this->tabela[posicao].contem(dado);
    };

    /**
     * @brief Obtém a quantidade de dados contidos na árvore.
     *
     * @return Um inteiro maior ou igual a 0.
     */
    virtual std::size_t quantidade() const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        return totalElementos;
    };

protected:
    /**
     * @brief Obtém a posição correspondente na tabela para o dado.
     * 
     * @param dado O dado.
     * @return Um inteiro na faixa [0, capacidade).
     */

    int totalElementos = 0;

    virtual std::size_t funcaoEspalhamento(T dado) const
    {
        // substitua a linha abaixo pelo algoritmo esperado
        if constexpr(!std::is_integral<T>::value){
                size_t result = codigoEspalhamento(dado);
                return (result % capac);
            }
            else{
                return (static_cast<size_t>(dado) % capac); 
            }
    };

private:
    /**
     * @brief Calcula a representação numérica de um tipo integral.
     *
     * @tparam U O tipo integral.
     * @param integral Um valor integral.
     * @return Um inteiro calculado através de static_cast<std::size_t>(integral)
     */
    template <typename U>
    std::size_t codigoEspalhamento(U integral) const
    {
        // substitua a linha abaixo pelo algoritmo esperado. Dica use std::is_integral_v<U> para garantir que U é um tipo integral
        return static_cast<size_t>(integral);
    };

    /**
     * @brief Calcula a representação numérica de um string.
     *
     * @param s um string.
     * @return Um inteiro calculado conforme s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1].
     */
    std::size_t codigoEspalhamento(std::string const &string) const
    {
        // Implemente aqui.
        size_t hash = 0;
        size_t expoente = string.size() - 1;

        for(char c : string) {
            hash += static_cast<std::size_t>(c) * pow(31, expoente);
            expoente --;
        }
        return hash;
    }
};

#endif
