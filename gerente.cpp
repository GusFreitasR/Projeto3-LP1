#include <iostream>
#include "gerente.hpp"
#include "utils/util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

//Implementando os construtores
Gerente::Gerente() {}

Gerente::Gerente(float lucro) {
     this->participacaoLucros=lucro;
      }

//Implementando os getters e setters da classe
float Gerente::getParticipacaoLucros() {
     return this->participacaoLucros; 
     }
void Gerente::setParticipacaoLucros(float lucro) { 
    this->participacaoLucros=lucro; 
    }

//Implementando os métodos herdados
float Gerente::calcularSalario() {

    int diasfaltas=getFaltas();

    float salario=stof(getSalario());

    salario-=(salario/30)*diasfaltas;

    salario+=getParticipacaoLucros();

    salario+=getQntFilhos()*100;

    return salario;
}

float Gerente::calcularRecisao(Date desligamento) {

    float dias_off, dias_ingresso;

    dias_ingresso=getIngressoEmpresa().ano*365+(getIngressoEmpresa().mes)*30+getIngressoEmpresa().dia;

    dias_off=desligamento.ano*365+desligamento.mes*30+desligamento.dia;

    float diff_ano=(dias_off-dias_ingresso)/365;

    float adicional=stof(getSalario())*diff_ano;

    return adicional;
}