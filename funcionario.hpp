#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <iostream>
#include "utils/util.hpp"

class Funcionario {
    // Criando a classe funcionario
    private:
    std::string salario;
    std::string matricula;
    Date ingressoEmpresa;
    int faltas;

    public:
    // Criando os getters e setters
    std::string getSalario();
    void setSalario(std::string salario);
    std::string getMatricula();
    void setMatricula(std::string matricula);
    Date getIngressoEmpresa();
    void setIngressoEmpresa(Date ingressoEmpresa);
    int getFaltas();
    void setFaltas(int diasfaltas);
    //Criando os metodos herdados

    virtual float calcularSalario()=0;
    virtual float calcularRecisao(Date desligamento)=0;
};

#endif