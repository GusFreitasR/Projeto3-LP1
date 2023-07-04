#include <iostream>
#include "utils/util.hpp"
#include "funcionario.hpp"
using namespace std;

// Implementando os getter e setters de funcionario
string Funcionario::getSalario()
{
    return this->salario;
}

void Funcionario::setSalario(string salario)
{
    this->salario = salario;
}

string Funcionario::getMatricula()
{
    return this->matricula;
}

void Funcionario::setMatricula(string matricula)
{
    this->matricula = matricula;
}

Date Funcionario::getIngressoEmpresa()
{
    return this->ingressoEmpresa;
}

void Funcionario::setIngressoEmpresa(Date ingressoEmpresa)
{
    this->ingressoEmpresa = ingressoEmpresa;
}

int Funcionario::getFaltas()
{
    return this->faltas;
}

void Funcionario::setFaltas(int diasfaltas)
{
    this->faltas = diasfaltas;
}