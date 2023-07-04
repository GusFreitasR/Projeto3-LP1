#include <iostream>
#include "..\utils\util.hpp"
#include "funcionario.hpp"
using namespace std;

//=== Getter e setters de funcionário

/// \brief Método get do atributo salário.
string Funcionario::getSalario()
{
    return this->salario;
}

/// \brief Método set do atributo salário.
void Funcionario::setSalario(string salario)
{
    this->salario = salario;
}

/// \brief Método get do atributo matrícula.
string Funcionario::getMatricula()
{
    return this->matricula;
}

/// \brief Método set do atributo matrícula.
void Funcionario::setMatricula(string matricula)
{
    this->matricula = matricula;
}

/// \brief Método get do atributo data de ingresso na empresa.
Date Funcionario::getIngressoEmpresa()
{
    return this->ingressoEmpresa;
}

/// \brief Método set do atributo data de ingresso na empresa.
void Funcionario::setIngressoEmpresa(Date ingressoEmpresa)
{
    this->ingressoEmpresa = ingressoEmpresa;
}

/// \brief Método get do atributo faltas.
int Funcionario::getFaltas()
{
    return this->faltas;
}

/// \brief Método set do atributo faltas.
void Funcionario::setFaltas(int diasfaltas)
{
    this->faltas = diasfaltas;
}