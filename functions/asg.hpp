#ifndef ASG_HPP
#define ASG_HPP
#include <iostream>
#include "..\utils\util.hpp"
#include "pessoa.hpp"
#include "funcionario.hpp"


class Asg:public Pessoa, public Funcionario {
    // Criando a classe de as herdando de pessoa, e funcionario ao mesmo tempo
    private:
    float adicionalInsalubridade;

    public:
    //Criando os construtores
    Asg();
    Asg(float adicional);

    //Criando os getters e setters
    float getAdicionalInsalubridade();
    void setAdicionalInsalubridade(float adicional);
    //Criando os metodos herdados

    float calcularSalario();
    float calcularRecisao(Date desligamento);
};

#endif