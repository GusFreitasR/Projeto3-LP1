#include <iostream>
#include "asg.hpp"
#include "..\utils\util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

/// \brief Construtor vazio
Asg::Asg() {}

/**
* \brief Construtor com atributo de adicional de insalubridade.
* \param adicional valor do adicional.
*/
Asg::Asg(float adicional) {
     this->adicionalInsalubridade=adicional;
      }

/// @brief Método get do atributo adicional de insalubridade. 
float Asg::getAdicionalInsalubridade() { 
    return this->adicionalInsalubridade; 
    }
/**
* \brief Método set do atributo adicional de insalubridade.  
* \param adicional valor do adicional.
*/
void Asg::setAdicionalInsalubridade(float adicional) { 
    this->adicionalInsalubridade=adicional;
     }

// Implementando os métodos herdados

/**
* \brief Cálcula o salário final, levando em conta faltas e adicionais.
* \return O valor final do salário.
*/
float Asg::calcularSalario() {

    float salario=stof(getSalario());

    salario-=(salario/30)*getFaltas();

    salario=salario*(1+ getAdicionalInsalubridade());

    salario=salario+getQntFilhos()*100;
    return salario;
}

/**
* \brief Calcula o valor da recisão de um funcionário em função de uma data.
* \param desligamento Data do desligamento do funcionário.
* \return O valor da recisão.
*/
float Asg::calcularRecisao(Date desligamento) {
    float dias_off, dias_ingresso;

    dias_ingresso=getIngressoEmpresa().ano*365+(getIngressoEmpresa().mes)*30+getIngressoEmpresa().dia;

    dias_off=desligamento.ano*365+desligamento.mes*30+desligamento.dia;

    float diff_ano=(dias_off-dias_ingresso)/365;
    
    float adicional=stof(getSalario())*diff_ano;

    return adicional;
}