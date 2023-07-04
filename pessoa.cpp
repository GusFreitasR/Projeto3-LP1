#include <iostream>
#include "utils/util.hpp"
#include "pessoa.hpp"
using namespace std;

// Criando os construtores
Pessoa::Pessoa() {}

Pessoa::Pessoa(string nome, string cpf, Date dataNascimento, Endereco enderecoPessoal, string estadocivil, int qntFilhos)
{
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadocivil;
    this->qntFilhos = qntFilhos;
}

// Implementando os getters e setters
string Pessoa::getNome()
{
    return this->nome;
}

void Pessoa::setNome(string nome)
{
    this->nome = nome;
}

string Pessoa::getCpf()
{
    return this->cpf;
}

void Pessoa::setCpf(string cpf)
{
    this->cpf = cpf;
}

Date Pessoa::getDataNascimento()
{
    return this->dataNascimento;
}

void Pessoa::setDataNascimento(Date dataNascimento)
{
    this->dataNascimento = dataNascimento;
}

Endereco Pessoa::getEnderecoPessoal()
{
    return this->enderecoPessoal;
}

void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal)
{
    this->enderecoPessoal = enderecoPessoal;
}

string Pessoa::getEstadoCivil()
{
    return this->estadoCivil;
}

void Pessoa::setEstadoCivil(string estadoCivil)
{
    this->estadoCivil = estadoCivil;
}

int Pessoa::getQntFilhos()
{
    return this->qntFilhos;
}

void Pessoa::setQntFilhos(int qtdFilhos)
{
    this->qntFilhos = qtdFilhos;
}