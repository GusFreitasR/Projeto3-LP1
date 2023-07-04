#include <iostream>
#include "vendedor.hpp"
#include "..\utils\util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

//=== Construtores

/// \brief Construtor vazio. 
Vendedor::Vendedor(){}

/// \brief Construtor parametrizado com o tipo do vendedor.
Vendedor::Vendedor(char tipo)
{
    this->tipoVendedor = tipo;
}

//=== Getters e setters

/// \brief Método get do atributo tipo do vendedor.
char Vendedor::getTipoVendedor()
{
    return this->tipoVendedor;
}

/// \brief Método set do atributo tipo do vendedor.
void Vendedor::setTipoVendedor(char tipo)
{
    this->tipoVendedor = tipo;
}

//=== Métodos herdados

/**
* \brief Calcula o salário final de um vendedor levando em conta faltas, quantidade de filhos e adicional por tipo de vendedor.
* \return O valor final do salário.
*/
float Vendedor::calcularSalario()
{
    int diasFaltas = getFaltas();
    float salario = stof(getSalario());
    salario -= (salario / 30) * diasFaltas;

    if (getTipoVendedor() == 'A')
    {
        salario *= 1.25;
    }
    else if (getTipoVendedor() == 'B')
    {
        salario *= 1.1;
    }

    else if (getTipoVendedor() == 'C')
    {
        salario *= 1.05;
    }

    salario += getQntFilhos() * 100;
    return salario;
}

/**
* \brief Calcula o valor da recisão de um funcionário a partir de uma data desligamento.
* \param desligamento Data de desligamento.
* \return O valor final da recisão.
*/
float Vendedor::calcularRecisao(Date desligamento)
{
    float dias_off, dias_ingresso;

    dias_ingresso = getIngressoEmpresa().ano * 365 + (getIngressoEmpresa().mes) * 30 + getIngressoEmpresa().dia;

    dias_off = desligamento.ano * 365 + desligamento.mes * 30 + desligamento.dia;

    float diff_ano = (dias_off - dias_ingresso) / 365;

    float adicional = stof(getSalario()) * diff_ano;

    return adicional;
}