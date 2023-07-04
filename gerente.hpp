#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include "funcionario.hpp"
#include "pessoa.hpp"
#include "utils/util.hpp"
using namespace std;

// Criando a classe gerente herdando das classes pessoa e funcionario
class Gerente:public Pessoa, public Funcionario {
    
    private:
    float participacaoLucros;

    public:
    //Criando os construtores
    Gerente();

    Gerente(float lucro);
    //Criando os metodos getters e setters
    float getParticipacaoLucros();
    
    void setParticipacaoLucros(float lucro);

    //Criando os metodos herdados
    float calcularSalario();

    float calcularRecisao(Date desligamento);
};

#endif