#include <iostream>
#include "asg.hpp"
#include "Utils/util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

// Implementando os construtores
Asg::Asg() {

}
Asg::Asg(float adicional) {
     this->adicionalInsalubridade=adicional;
      }

// Implementando getters e setters 
float Asg::getAdicionalInsalubridade() { 
    return this->adicionalInsalubridade; 
    }
void Asg::setAdicionalInsalubridade(float adicional) { 
    this->adicionalInsalubridade=adicional;
     }

// Implementando os métodos herdados

float Asg::calcularSalario() {

    float salario=stof(getSalario());

    salario-=(salario/30)*getFaltas();

    salario=salario*(1+ getAdicionalInsalubridade());

    salario=salario+getQntFilhos()*100;
    return salario;
}

float Asg::calcularRecisao(Date desligamento) {
    float dias_off, dias_ingresso;

    dias_ingresso=getIngressoEmpresa().ano*365+(getIngressoEmpresa().mes)*30+getIngressoEmpresa().dia;

    dias_off=desligamento.ano*365+desligamento.mes*30+desligamento.dia;

    float diff_ano=(dias_off-dias_ingresso)/365;
    
    float adicional=stof(getSalario())*diff_ano;

    return adicional;
}