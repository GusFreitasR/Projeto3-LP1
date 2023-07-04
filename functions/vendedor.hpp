#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "..\utils\util.hpp"
#include "pessoa.hpp"
#include "funcionario.hpp"

//Criando a classe vendedor herdando de Pessoa e Funcionario
class Vendedor:public Pessoa, public Funcionario {
    private:
    char tipoVendedor;

    public:
    Vendedor();
    Vendedor(char tipo);
    char getTipoVendedor();
    void setTipoVendedor(char tipo);
    float calcularSalario();
    float calcularRecisao(Date desligamento);
};

#endif