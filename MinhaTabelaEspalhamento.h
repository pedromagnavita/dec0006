#ifndef MINHA_TABELA_ESPALHAMENTO_H
#define MINHA_TABELA_ESPALHAMENTO_H

#include "MinhaListaEncadeada.h"
// MinhaListaEncadeada
#include "TabelaEspalhamentoAbstrata.h"
// TabelaEspalhamentoAbstrata
#include "excecoes.h"
// ExcecaoDadoInexistente

template<typename T, std::size_t capac>
class MinhaTabelaEspalhamento final:
    public TabelaEspalhamentoAbstrata<T, capac>
{
    public:
        //Implemente as funções públicas aqui
    
    protected:
        //Implemente as funções protegidas aqui
    
    private:
        /**
         * @brief Calcula a representação numérica de um tipo integral.
         * 
         * @tparam U O tipo integral.
         * @param integral Um valor integral.
         * @return Um inteiro calculado através de static_cast<std::size_t>(integral)
         */
        template<typename U>
        std::size_t codigoEspalhamento(U integral) const
        {
            //Implemente aqui. Dica use std::is_integral_v<U> para garantir que U é um tipo integral
        }
        
    
        /**
         * @brief Calcula a representação numérica de um string.
         * 
         * @param s um string.
         * @return Um inteiro calculado conforme s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1].
         */
        std::size_t codigoEspalhamento(std::string const& string) const
        {
            //Implemente aqui.
        }
    };

#endif
