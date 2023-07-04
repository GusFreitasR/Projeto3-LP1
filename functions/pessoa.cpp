#include <iostream>
#include "..\utils\util.hpp"
#include "pessoa.hpp"
using namespace std;

//=== Construtores

/// \brief Construtor vazio. 
Pessoa::Pessoa() {}

/// \brief Construtor parametrizado com todos os atributos da classe pessoa.
Pessoa::Pessoa(string nome, string cpf, Date dataNascimento, Endereco enderecoPessoal, string estadocivil, int qntFilhos)
{
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadocivil;
    this->qntFilhos = qntFilhos;
}

//=== Getters e setters

/// \brief Método get do atributo nome.  
string Pessoa::getNome()
{
    return this->nome;
}
/// \brief Método set do atributo nome.
void Pessoa::setNome(string nome)
{
    this->nome = nome;
}

/// \brief Método get do atributo CPF.
string Pessoa::getCpf()
{
    return this->cpf;
}
/// \brief Método set do atributo CPF.
void Pessoa::setCpf(string cpf)
{
    this->cpf = cpf;
}
/// \brief Método get do atributo data de nascimento.
Date Pessoa::getDataNascimento()
{
    return this->dataNascimento;
}
/// \brief Método set do atributo data de nascimento.
void Pessoa::setDataNascimento(Date dataNascimento)
{
    this->dataNascimento = dataNascimento;
}

/// \brief Método get do atributo endereço pessoal.
Endereco Pessoa::getEnderecoPessoal()
{
    return this->enderecoPessoal;
}
/// \brief Método set do atributo endereço pessoal.
void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal)
{
    this->enderecoPessoal = enderecoPessoal;
}
/// \brief Método get do atributo estado civil.
string Pessoa::getEstadoCivil()
{
    return this->estadoCivil;
}
/// \brief Método set do atributo estado civil.
void Pessoa::setEstadoCivil(string estadoCivil)
{
    this->estadoCivil = estadoCivil;
}
/// \brief Método get do atributo quantidade de filhos.
int Pessoa::getQntFilhos()
{
    return this->qntFilhos;
}
/// \brief Método set do atributo quantidade de filhos.
void Pessoa::setQntFilhos(int qtdFilhos)
{
    this->qntFilhos = qtdFilhos;
}