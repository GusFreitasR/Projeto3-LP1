#include <iostream>
#include "gerente.hpp"
#include "..\utils\util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

//=== Construtores

/// \brief Construtor vazio.
Gerente::Gerente() {}

/**
* \brief Construtor parametrizado com o atributo lucro da empresa. 
* \param lucro lucro da empresa.
*/  
Gerente::Gerente(float lucro) {
     this->participacaoLucros=lucro;
}

//=== Getters e setters da classe Gerente

/// \brief Método get do atributo participação nos lucros. 
float Gerente::getParticipacaoLucros() {
     return this->participacaoLucros; 
}

/// \brief Método set do atributo participação nos lucros.
void Gerente::setParticipacaoLucros(float lucro) { 
    this->participacaoLucros=lucro; 
    }

//=== Métodos herdados

/**
* \brief Calcula o salário final de um gerente levando em conta faltas, quantidade de filhos e participação nos lucros.
* \return Salário final do gerente.
*/ 
float Gerente::calcularSalario() {

    int diasfaltas=getFaltas();

    float salario=stof(getSalario());

    salario-=(salario/30)*diasfaltas;

    salario+=getParticipacaoLucros();

    salario+=getQntFilhos()*100;

    return salario;
}

/**
* \brief Calcula valor da recisão de um gerente a partir de sua data de desligamento.
* \param desligamento Data de desligamento.
* \return Valor final da recisão.
*/
float Gerente::calcularRecisao(Date desligamento) {

    float dias_off, dias_ingresso;

    dias_ingresso=getIngressoEmpresa().ano*365+(getIngressoEmpresa().mes)*30+getIngressoEmpresa().dia;

    dias_off=desligamento.ano*365+desligamento.mes*30+desligamento.dia;

    float diff_ano=(dias_off-dias_ingresso)/365;

    float adicional=stof(getSalario())*diff_ano;

    return adicional;
}