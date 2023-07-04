#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "utils/util.hpp"


class Pessoa {
    // Criando  a classe pessoa
    private:
    std::string nome;
    std::string cpf;
    Date dataNascimento;
    Endereco enderecoPessoal;
    std::string estadoCivil;
    int qntFilhos;

    public:
    //Construtores de Pessoa
    Pessoa();
    Pessoa(std::string nome, std::string cpf, Date dataNascimento, Endereco enderecoPessoal, std::string estadocivil, int qntFilhos);

    //Métodos de getters e setters
    std::string getNome();

    void setNome(std::string nome);

    std::string getCpf();

    void setCpf(std::string cpf);

    Date getDataNascimento();

    void setDataNascimento(Date dataNascimento);

    Endereco getEnderecoPessoal();

    void setEnderecoPessoal(Endereco enderecoPessoal);

    std::string getEstadoCivil();

    void setEstadoCivil(std::string estadoCivil);

    int getQntFilhos();

    void setQntFilhos(int qntFilhos);
};


#endif