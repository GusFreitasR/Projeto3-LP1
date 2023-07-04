#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include <vector>
#include "..\utils\util.hpp"
#include "gerente.hpp"
#include "vendedor.hpp"
#include "pessoa.hpp"
#include "asg.hpp"

// Criando a classe da empresa
class Empresa
{
private:
    float faturamentoMensal;
    std::string nomeEmpresa;
    std::string cnpj;
    Pessoa dono;
    vector<Asg> asgs;
    vector<Vendedor> vendedores;
    vector<Gerente> gerentes;

public:
    // Criando os construtores da classe
    Empresa();
    Empresa(std::string nome, std::string cnpj, float faturamento);
    // Criando os getters e setters
    float getFaturamentoMensal();

    void setFaturamentoMensal(float faturamento);

    std::string getNomeEmpresa();

    void setNomeEmpresa(std::string nome);

    std::string getCnpj();

    void setCnpj(std::string cnpj);

    vector<Asg> getAsgs();

    vector<Vendedor> getVendedores();

    vector<Gerente> getGerentes();
    
    // Criando as funções necessárias para a classe

    void carregarFuncoes();

    void carregarEmpresa();

    void carregarAsg();

    void carregaDono();

    void carregarVendedor();

    void carregarGerente();

    void imprimeAsgs();

    void imprimeVendedores();

    void imprimeGerentes();

    void imprimeDono();

    bool buscaFuncionario(std::string matricula);

    void demitirFuncionario(std::string matricula,  Date data_desligamento);

    void contratarFuncionario();
    
    int calcularAnos(std::string matricula, Date data);

    int calcularMeses(std::string matricula, Date data);

    int calcularDias(std::string matricula, Date data);
    
    float calculaSalarioFuncionario(std::string matricula);

    void atualizarAsg();

    void atualizarVendedor();

    void atualizarGerente();

    void calculaTodosOsSalarios();

    float calcularRecisao(std::string matricula, Date desligamento);

};

#endif