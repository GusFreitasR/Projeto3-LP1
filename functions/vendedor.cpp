#include <iostream>
#include "vendedor.hpp"
#include "..\utils\util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

// Implementando os construtores
Vendedor::Vendedor()
{
}
Vendedor::Vendedor(char tipo)
{
    this->tipoVendedor = tipo;
}

// implementando os getters e setters
char Vendedor::getTipoVendedor()
{
    return this->tipoVendedor;
}
void Vendedor::setTipoVendedor(char tipo)
{
    this->tipoVendedor = tipo;
}

// implementando os métodos herdados

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
float Vendedor::calcularRecisao(Date desligamento)
{
    float dias_off, dias_ingresso;

    dias_ingresso = getIngressoEmpresa().ano * 365 + (getIngressoEmpresa().mes) * 30 + getIngressoEmpresa().dia;

    dias_off = desligamento.ano * 365 + desligamento.mes * 30 + desligamento.dia;

    float diff_ano = (dias_off - dias_ingresso) / 365;

    float adicional = stof(getSalario()) * diff_ano;

    return adicional;
}