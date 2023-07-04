#include <iostream>
#include "utils/util.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "gerente.hpp"
#include "vendedor.hpp"
#include "empresa.hpp"
#include <fstream>
#include <vector>

using namespace std;

// Implementando os construtores
Empresa::Empresa() {}
Empresa::Empresa(string nome, string cnpj, float faturamento)
{
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamento;
    this->nomeEmpresa = nome;
}

// Implementando os getters e setters da empresa
float Empresa::getFaturamentoMensal()
{
    return this->faturamentoMensal;
}
void Empresa::setFaturamentoMensal(float faturamento)
{
    this->faturamentoMensal = faturamento;
}
string Empresa::getNomeEmpresa()
{
    return this->nomeEmpresa;
}
void Empresa::setNomeEmpresa(string nome)
{
    this->nomeEmpresa = nome;
}
string Empresa::getCnpj()
{
    return this->cnpj;
}
void Empresa::setCnpj(string cnpj)
{
    this->cnpj = cnpj;
}
vector<Asg> Empresa::getAsgs()
{
    return this->asgs;
}
vector<Vendedor> Empresa::getVendedores()
{
    return this->vendedores;
}
vector<Gerente> Empresa::getGerentes()
{
    return this->gerentes;
}

//Implementando as funcoes da empresa
//Implementação da função em que carrega as chamadas de funcoes do arquivo 'funcoes.txt'
void Empresa::carregarFuncoes()
{
    ifstream file("funcoes.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    while (getline(file, line))
    {
        if (line == "carregarEmpresa()")
            carregarEmpresa();
        else if (line == "carregarAsg()")
            carregarAsg();
        else if (line == "carregarVendedor()")
            carregarVendedor();
        else if (line == "carregarGerente()")
            carregarGerente();
        else if (line == "carregaDono()")
            carregaDono();
        else if (line == "imprimeAsgs()")
            imprimeAsgs();
        else if (line == "imprimeVendedores()")
            imprimeVendedores();
        else if (line == "imprimeGerentes()")
            imprimeGerentes();
        else if (line == "imprimeDono()")
            imprimeDono();
        else if (line == "buscaFuncionario()")
        {
            string parametro;
            getline(file, parametro);
            buscaFuncionario(parametro);
        }
        else if (line == "calculaSalarioFuncionario()")
        {
            string parametro;
            getline(file, parametro);
            calculaSalarioFuncionario(parametro);
        }
        else if (line == "calculaTodoOsSalarios()")
        {
            calculaTodosOsSalarios();
        }

        else if (line == "calcularRecisao()")
        {
            string matricula;
            string datas;
            Date data;

            getline(file, matricula);

            getline(file, datas);
            data.ano = stoi(datas);
            getline(file, datas);
            data.mes = stoi(datas);
            getline(file, datas);
            data.dia = stoi(datas);

            calcularRecisao(matricula, data);
        }
    }
}
//implementação da função em que carrega as informacoes do dono da empresa
void Empresa::carregaDono()
{
    ifstream file("dono.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    getline(file, line);
    getline(file, line);

    getline(file, line);
    dono.setNome(line);

    getline(file, line);
    dono.setCpf(line);

    getline(file, line);
    int filhos = stoi(line);
    dono.setQntFilhos(filhos);

    getline(file, line);
    dono.setEstadoCivil(line);

    Endereco endereco;
    getline(file, line);
    endereco.cidade = line;
    getline(file, line);
    endereco.cep = line;
    getline(file, line);
    endereco.bairro = line;
    getline(file, line);
    endereco.rua = line;
    getline(file, line);
    int num = stoi(line);
    endereco.numero = num;
    dono.setEnderecoPessoal(endereco);

    Date date_nasc;
    getline(file, line);
    int ano = stoi(line);
    date_nasc.ano = ano;
    getline(file, line);
    int mes = stoi(line);
    date_nasc.mes = mes;
    getline(file, line);
    int dia = stoi(line);
    date_nasc.dia = dia;
    dono.setDataNascimento(date_nasc);

    file.close();
}
//implementação da função em que carrega as informacoes  da empresa

void Empresa::carregarEmpresa()
{
    ifstream file("empresa.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    getline(file, line);
    getline(file, line);

    getline(file, line);
    setNomeEmpresa(line);
    getline(file, line);
    setCnpj(line);
    getline(file, line);
    setFaturamentoMensal(stof(line));

    file.close();
}
//implementação da função em que carrega as informacoes dos asgs da empresa

void Empresa::carregarAsg()
{
    ifstream file("asg.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    Asg asg;
    Endereco endereco;
    Date data_nasc, data_ingresso;

    while (getline(file, line))
    {
        getline(file, line);
        getline(file, line);

        getline(file, line);
        asg.setNome(line);
        getline(file, line);
        asg.setCpf(line);
        getline(file, line);
        asg.setQntFilhos(stoi(line));
        getline(file, line);
        asg.setEstadoCivil(line);

        getline(file, line);

        getline(file, line);
        endereco.cidade = line;
        getline(file, line);
        endereco.cep = line;
        getline(file, line);
        endereco.bairro = line;
        getline(file, line);
        endereco.rua = line;
        getline(file, line);
        endereco.numero = stoi(line);
        asg.setEnderecoPessoal(endereco);

        getline(file, line);

        getline(file, line);
        data_nasc.ano = stoi(line);
        getline(file, line);
        data_nasc.mes = stoi(line);
        getline(file, line);
        data_nasc.dia = stoi(line);
        asg.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        asg.setMatricula(line);
        getline(file, line);
        asg.setSalario(line);
        getline(file, line);
        asg.setAdicionalInsalubridade(stof(line));
        getline(file, line);
        asg.setFaltas(stoi(line));

        getline(file, line);

        getline(file, line);
        data_ingresso.ano = stoi(line);
        getline(file, line);
        data_ingresso.mes = stoi(line);
        getline(file, line);
        data_ingresso.dia = stoi(line);
        asg.setIngressoEmpresa(data_ingresso);

        asgs.push_back(asg);
    }

    file.close();
}
//implementação da função em que carrega as informacoes dos vendedores da empresa

void Empresa::carregarVendedor()
{
    ifstream file("vendedor.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    Vendedor vendedor;
    Endereco endereco;
    Date data_nasc, data_ingresso;

    while (getline(file, line))
    {
        getline(file, line);
        getline(file, line);

        getline(file, line);
        vendedor.setNome(line);
        getline(file, line);
        vendedor.setCpf(line);
        getline(file, line);
        vendedor.setQntFilhos(stoi(line));
        getline(file, line);
        vendedor.setEstadoCivil(line);

        getline(file, line);

        getline(file, line);
        endereco.cidade = line;
        getline(file, line);
        endereco.cep = line;
        getline(file, line);
        endereco.bairro = line;
        getline(file, line);
        endereco.rua = line;
        getline(file, line);
        endereco.numero = stoi(line);
        vendedor.setEnderecoPessoal(endereco);

        getline(file, line);

        getline(file, line);
        data_nasc.ano = stoi(line);
        getline(file, line);
        data_nasc.mes = stoi(line);
        getline(file, line);
        data_nasc.dia = stoi(line);
        vendedor.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        vendedor.setMatricula(line);
        getline(file, line);
        vendedor.setSalario(line);
        getline(file, line);
        char tipo = line[0];
        vendedor.setTipoVendedor(tipo);
        getline(file, line);
        vendedor.setFaltas(stoi(line));

        getline(file, line);

        getline(file, line);
        data_ingresso.ano = stoi(line);
        getline(file, line);
        data_ingresso.mes = stoi(line);
        getline(file, line);
        data_ingresso.dia = stoi(line);
        vendedor.setIngressoEmpresa(data_ingresso);

        vendedores.push_back(vendedor);
    }

    file.close();
}
//implementação da função em que carrega as informacoes dos gerentes da empresa

void Empresa::carregarGerente()
{
    ifstream file("gerente.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    Gerente gerente;
    Endereco endereco;
    Date data_nasc, data_ingresso;

    while (getline(file, line))
    {
        getline(file, line);
        getline(file, line);

        getline(file, line);
        gerente.setNome(line);
        getline(file, line);
        gerente.setCpf(line);
        getline(file, line);
        gerente.setQntFilhos(stoi(line));
        getline(file, line);
        gerente.setEstadoCivil(line);

        getline(file, line);

        getline(file, line);
        endereco.cidade = line;
        getline(file, line);
        endereco.cep = line;
        getline(file, line);
        endereco.bairro = line;
        getline(file, line);
        endereco.rua = line;
        getline(file, line);
        endereco.numero = stoi(line);
        gerente.setEnderecoPessoal(endereco);

        getline(file, line);

        getline(file, line);
        data_nasc.ano = stoi(line);
        getline(file, line);
        data_nasc.mes = stoi(line);
        getline(file, line);
        data_nasc.dia = stoi(line);
        gerente.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        gerente.setMatricula(line);
        getline(file, line);
        gerente.setSalario(line);
        getline(file, line);
        gerente.setParticipacaoLucros(stof(line));
        getline(file, line);
        gerente.setFaltas(stoi(line));

        getline(file, line);

        getline(file, line);
        data_ingresso.ano = stoi(line);
        getline(file, line);
        data_ingresso.mes = stoi(line);
        getline(file, line);
        data_ingresso.dia = stoi(line);
        gerente.setIngressoEmpresa(data_ingresso);

        gerentes.push_back(gerente);
    }

    file.close();
}
//implementação da função em que faz a impressão dos asgs depois de carregados

void Empresa::imprimeAsgs()
{
    cout << "Lista de profissionais ASG:" << endl;
    cout << "****************************" << endl;
    for (auto i : asgs)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de Nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereco: Rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQntFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na empresa: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "**********************************" << endl;
    }
}
//implementação da função em que faz a impressão dos vendedores depois de carregados
void Empresa::imprimeVendedores()
{
    cout << "Lista de vendedores:" << endl;
    cout << "****************************" << endl;
    for (auto i : vendedores)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereco: Rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQntFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na empresa: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "**********************************" << endl;
    }
}
//implementação da função em que faz a impressão dos gerentes depois de carregados
void Empresa::imprimeGerentes()
{
    cout << "Lista de gerentes:" << endl;
    cout << "****************************" << endl;
    for (auto i : gerentes)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereço: Rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQntFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na empresa: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "**********************************" << endl;
    }
}
//implementação da função em que faz a impressão do dono da empresa
void Empresa::imprimeDono()
{
    cout << "****************************" << endl;
    cout << "Informacoes sobre dono:" << endl;
    cout << "Nome: " << dono.getNome() << endl;
    cout << "CPF: " << dono.getCpf() << endl;
    cout << "Data de date_nasc: " << dono.getDataNascimento().dia << "/" << dono.getDataNascimento().mes << "/" << dono.getDataNascimento().ano << endl;
    cout << "Endereco: Rua " << dono.getEnderecoPessoal().rua << ", " << dono.getEnderecoPessoal().numero << endl;
    cout << "Estado civil: " << dono.getEstadoCivil() << endl;
    cout << "Numero de filhos: " << dono.getQntFilhos() << endl;
    cout << "****************************" << endl;
}
//implementação da função em que faz a busca de uma matricula nos dados de funcionario da empresa

bool Empresa::buscaFuncionario(string matricula)
{
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario encontrado." << endl;
            return true;
        }
    }
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario encontrado." << endl;
            return true;
        }
    }
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario encontrado." << endl;
            return true;
        }
    }
    cout << "Nao existe um funcionario com essa matricula em nosso sistema" << endl;
    return false;
}
//implementação da função em que calcula o salario de um funcionario dado a matricula dele
float Empresa::calculaSalarioFuncionario(string matricula)
{
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario " << i.getNome() << " e: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario " << i.getNome() << " e: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario " << i.getNome() << " e: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }
    cout << "Nao existe um funcionario com essa matricula em nosso sistema" << endl;
    return -1;
}

//implementação da função em que calcula o salario de todos os funcionarios da empresa e salva em um arquivo 
void Empresa::calculaTodosOsSalarios()
{
    float total = 0, asg_total = 0, vendedor_total = 0, gerente_total = 0;
    ofstream file("salva_salarios.txt");
    if (!(file.is_open()))
    {
        cout << "Arquivo não pode ser aberto!" << endl;
        return;
    }

    for (auto i : asgs)
    {
        file << "Nome do funcionario: " << i.getNome() << endl;
        cout << "Nome do funcionario: " << i.getNome() << endl;
        file << "Cargo do funcionario: ASG" << endl;
        cout << "Cargo do funcionario: ASG" << endl;
        file << "Salario do funcionario: " << i.calcularSalario() << endl;
        cout << "Salario do funcionario: " << i.calcularSalario() << endl;
        file << "------------------------------------------" << endl;
        cout << "------------------------------------------" << endl;
        total += i.calcularSalario();
        asg_total += i.calcularSalario();
    }
    file << "******************************" << endl;
    cout << "******************************" << endl;
    for (auto i : vendedores)
    {
        file << "Nome do funcionario: " << i.getNome() << endl;
        cout << "Nome do funcionario: " << i.getNome() << endl;
        file << "Cargo do funcionario: vendedor" << endl;
        cout << "Cargo do funcionario: vendedor" << endl;
        file << "Salario do funcionario: " << i.calcularSalario() << endl;
        cout << "Salario do funcionario: " << i.calcularSalario() << endl;
        file << "------------------------------------------" << endl;
        cout << "------------------------------------------" << endl;
        total += i.calcularSalario();
        vendedor_total += i.calcularSalario();
    }
    file << "******************************" << endl;
    cout << "******************************" << endl;
    for (auto i : gerentes)
    {
        file << "Nome do funcionario: " << i.getNome() << endl;
        cout << "Nome do funcionario: " << i.getNome() << endl;
        file << "Cargo do funcionario: gerente" << endl;
        cout << "Cargo do funcionario: gerente" << endl;
        file << "Salario do funcionario: " << i.calcularSalario() << endl;
        cout << "Salario do funcionario: " << i.calcularSalario() << endl;
        file << "------------------------------------------" << endl;
        cout << "------------------------------------------" << endl;
        total += i.calcularSalario();
        gerente_total += i.calcularSalario();
    }
    file << "******************************" << endl;
    cout << "******************************" << endl;

    file << "Total de salarios dos funcionarios ASG: " << asg_total << endl;
    cout << "Total de salarios dos funcionarios ASG: " << asg_total << endl;
    file << "Total de salarios dos vendedores: " << vendedor_total << endl;
    cout << "Total de salarios dos vendedores: " << vendedor_total << endl;
    file << "Total de salarios dos gerentes: " << gerente_total << endl;
    cout << "Total de salarios dos gerentes: " << gerente_total << endl;

    file << "******************************" << endl;
    cout << "******************************" << endl;
    file << "Total de salarios dos funcionarios: " << total << endl;
    cout << "Total de salarios dos funcionarios: " << total << endl;

    file.close();
}
//Função que calcula os anos de estadia de um certo funcionario dado a sua matricula e data de saída 
int Empresa::calcularAnos(std::string matricula, Date data){
    for(auto asg = asgs.begin(); asg != asgs.end(); asg++) {
        if((*asg).getMatricula() == matricula){
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*asg).getIngressoEmpresa().ano*365 - (*asg).getIngressoEmpresa().mes*30 - (*asg).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            return anos;
        }
    }
    for(auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
        if((*vend).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*vend).getIngressoEmpresa().ano*365 - (*vend).getIngressoEmpresa().mes*30 - (*vend).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            return anos;
        }
    }

    for(auto ger = gerentes.begin(); ger != gerentes.end(); ger++) {
        if((*ger).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*ger).getIngressoEmpresa().ano*365 - (*ger).getIngressoEmpresa().mes*30 - (*ger).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            return anos;
        }
    }

    return 0;
}

//Função que calcula os meses de estadia de um certo funcionario dado a sua matricula e data de saída 

int Empresa::calcularMeses(std::string matricula, Date data){
    for(auto asg = asgs.begin(); asg != asgs.end(); asg++) {
        if((*asg).getMatricula() == matricula){
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*asg).getIngressoEmpresa().ano*365 - (*asg).getIngressoEmpresa().mes*30 - (*asg).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            int meses = diastotais/30;
            return meses;
        }
    }
    for(auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
        if((*vend).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*vend).getIngressoEmpresa().ano*365 - (*vend).getIngressoEmpresa().mes*30 - (*vend).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            int meses = diastotais/30;
            return meses;
        }
    }

    for(auto ger = gerentes.begin(); ger != gerentes.end(); ger++) {
        if((*ger).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*ger).getIngressoEmpresa().ano*365 - (*ger).getIngressoEmpresa().mes*30 - (*ger).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            int meses = diastotais/30;
            return meses;
        }
    }

    return 0;
}
//Função que calcula os dias de estadia de um certo funcionario dado a sua matricula e data de saída 

int Empresa::calcularDias(std::string matricula, Date data){
    for(auto asg = asgs.begin(); asg != asgs.end(); asg++) {
        if((*asg).getMatricula() == matricula){
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*asg).getIngressoEmpresa().ano*365 - (*asg).getIngressoEmpresa().mes*30 - (*asg).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            diastotais -= 30*calcularMeses(matricula, data);
            return diastotais;
        }
    }
    for(auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
        if((*vend).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*vend).getIngressoEmpresa().ano*365 - (*vend).getIngressoEmpresa().mes*30 - (*vend).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            diastotais -= 30*calcularMeses(matricula, data);
            return diastotais;
        }
    }

    for(auto ger = gerentes.begin(); ger != gerentes.end(); ger++) {
        if((*ger).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*ger).getIngressoEmpresa().ano*365 - (*ger).getIngressoEmpresa().mes*30 - (*ger).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            diastotais -= 30*calcularMeses(matricula, data);
            return diastotais;
        }
    }

    return 0;
}


void Empresa::demitirFuncionario(string matricula, Date desligamento) {
    for(auto asg = asgs.begin(); asg != asgs.end(); asg++) {
        if((*asg).getMatricula() == matricula) {
            

            cout<< "##############################"<<endl;
            cout<< "    Relatorio Demissional    "<<endl;
            cout<< "##############################"<<endl;
            cout<< "Cargo: ASG"<<endl;
            cout<< "Nome: "<<(*asg).getNome()<<endl;
            cout<< "CPF: "<<(*asg).getCpf()<<endl;
            cout<< "Matrícula: "<<(*asg).getMatricula()<<endl;
            cout<< "Data de ingresso: "<<(*asg).getIngressoEmpresa().dia<<"/"<<(*asg).getIngressoEmpresa().mes<<"/"<<(*asg).getIngressoEmpresa().ano<<endl;
            cout<< "Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<< "******************************"<<endl;
            cout<< "Valor de recisão: "<<(*asg).calcularRecisao(desligamento)<<endl;
            cout<< "******************************"<<endl;
            cout<< "Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: ASG"<<endl;
            file<<"Nome: "<<(*asg).getNome()<<endl;
            file<<"CPF: "<<(*asg).getCpf()<<endl;
            file<<"Matrícula: "<<(*asg).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*asg).getIngressoEmpresa().dia<<"/"<<(*asg).getIngressoEmpresa().mes<<"/"<<(*asg).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*asg).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;
            file.close();

            asgs.erase(asg);
            return;
        }
    }

    for(auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
        if((*vend).getMatricula() == matricula) {

            cout<<"##############################"<<endl;
            cout<<"    Relatorio Demissional    "<<endl;
            cout<<"##############################"<<endl;
            cout<<"Cargo: Vendedor"<<endl;
            cout<<"Nome: "<<(*vend).getNome()<<endl;
            cout<<"CPF: "<<(*vend).getCpf()<<endl;
            cout<<"Matrícula: "<<(*vend).getMatricula()<<endl;
            cout<<"Data de ingresso: "<<(*vend).getIngressoEmpresa().dia<<"/"<<(*vend).getIngressoEmpresa().mes<<"/"<<(*vend).getIngressoEmpresa().ano<<endl;
            cout<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<<"******************************"<<endl;
            cout<<"Valor de recisão: "<<(*vend).calcularRecisao(desligamento)<<endl;
            cout<<"******************************"<<endl;
            cout<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: Vendedor"<<endl;
            file<<"Nome: "<<(*vend).getNome()<<endl;
            file<<"CPF: "<<(*vend).getCpf()<<endl;
            file<<"Matrícula: "<<(*vend).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*vend).getIngressoEmpresa().dia<<"/"<<(*vend).getIngressoEmpresa().mes<<"/"<<(*vend).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*vend).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;
            file.close();

            vendedores.erase(vend);
            return;
        }
    }

    for(auto ger = gerentes.begin(); ger != gerentes.end(); ger++) {
        if((*ger).getMatricula() == matricula) {

            cout<<"##############################"<<endl;
            cout<<"    Relatorio Demissional    "<<endl;
            cout<<"##############################"<<endl;
            cout<<"Cargo: Gerente"<<endl;
            cout<<"Nome: "<<(*ger).getNome()<<endl;
            cout<<"CPF: "<<(*ger).getCpf()<<endl;
            cout<<"Matrícula: "<<(*ger).getMatricula()<<endl;
            cout<<"Data de ingresso: "<<(*ger).getIngressoEmpresa().dia<<"/"<<(*ger).getIngressoEmpresa().mes<<"/"<<(*ger).getIngressoEmpresa().ano<<endl;
            cout<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<<"******************************"<<endl;
            cout<<"Valor de recisão: "<<(*ger).calcularRecisao(desligamento)<<endl;
            cout<<"******************************"<<endl;
            cout<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: Gerente"<<endl;
            file<<"Nome: "<<(*ger).getNome()<<endl;
            file<<"CPF: "<<(*ger).getCpf()<<endl;
            file<<"Matrícula: "<<(*ger).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*ger).getIngressoEmpresa().dia<<"/"<<(*ger).getIngressoEmpresa().mes<<"/"<<(*ger).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*ger).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;
            file.close();

            gerentes.erase(ger);
            return;
        }
    }
}

void Empresa::contratarFuncionario() {
    ifstream file("novoFuncionario.txt");
    string line;
    getline(file, line);
    if(line == "ASG"){
        Asg asg;
        getline(file, line);
        asg.setNome(line);
        getline(file, line);
        asg.setCpf(line);
        getline(file, line);
        asg.setQntFilhos(stoi(line));
        getline(file, line);
        asg.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        asg.setEnderecoPessoal(endereco);

        getline(file, line);

        Date data_nasc;
        getline(file, line);
        data_nasc.ano=stoi(line);
        getline(file, line);
        data_nasc.mes=stoi(line);
        getline(file, line);
        data_nasc.dia=stoi(line);
        asg.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        asg.setMatricula(line);
        getline(file, line);
        asg.setSalario(line);
        getline(file, line);
        asg.setAdicionalInsalubridade(stof(line));
        getline(file, line);
        asg.setFaltas(stoi(line));

        getline(file, line);

        Date date_ing;
        getline(file, line);
        date_ing.ano=stoi(line);
        getline(file, line);
        date_ing.mes=stoi(line);
        getline(file, line);
        date_ing.dia=stoi(line);
        asg.setIngressoEmpresa(date_ing);

        asgs.push_back(asg);

        return;
    }
    if(line == "Vendedor") {
        Vendedor vendedor;
        getline(file, line);
        vendedor.setNome(line);
        getline(file, line);
        vendedor.setCpf(line);
        getline(file, line);
        vendedor.setQntFilhos(stoi(line));
        getline(file, line);
        vendedor.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        vendedor.setEnderecoPessoal(endereco);

        getline(file, line);

        Date data_nasc;
        getline(file, line);
        data_nasc.ano=stoi(line);
        getline(file, line);
        data_nasc.mes=stoi(line);
        getline(file, line);
        data_nasc.dia=stoi(line);
        vendedor.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        vendedor.setMatricula(line);
        getline(file, line);
        vendedor.setSalario(line);
        getline(file, line);
        vendedor.setTipoVendedor(line[0]);
        getline(file, line);
        vendedor.setFaltas(stoi(line));

        getline(file, line);

        Date date_ing;
        getline(file, line);
        date_ing.ano=stoi(line);
        getline(file, line);
        date_ing.mes=stoi(line);
        getline(file, line);
        date_ing.dia=stoi(line);
        vendedor.setIngressoEmpresa(date_ing);

        vendedores.push_back(vendedor);

        return;
    }
    if(line == "Gerente") {
        Gerente gerente;
        getline(file, line);
        gerente.setNome(line);
        getline(file, line);
        gerente.setCpf(line);
        getline(file, line);
        gerente.setQntFilhos(stoi(line));
        getline(file, line);
        gerente.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        gerente.setEnderecoPessoal(endereco);

        getline(file, line);

        Date data_nasc;
        getline(file, line);
        data_nasc.ano=stoi(line);
        getline(file, line);
        data_nasc.mes=stoi(line);
        getline(file, line);
        data_nasc.dia=stoi(line);
        gerente.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        gerente.setMatricula(line);
        getline(file, line);
        gerente.setSalario(line);
        getline(file, line);
        gerente.setParticipacaoLucros(stof(line));
        getline(file, line);
        gerente.setFaltas(stoi(line));

        getline(file, line);

        Date date_ing;
        getline(file, line);
        date_ing.ano=stoi(line);
        getline(file, line);
        date_ing.mes=stoi(line);
        getline(file, line);
        date_ing.dia=stoi(line);
        gerente.setIngressoEmpresa(date_ing);

        gerentes.push_back(gerente);

        return;
    }
}
//implementação da função em que se tem o calcula da recisão de algum funcionario dado sua matricula e a data de seu desligamento 
float Empresa::calcularRecisao(string matricula, Date date_off)
{
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisao do funcionario "<< i.getNome() <<" e: " << i.calcularRecisao(date_off) << endl;
            return i.calcularRecisao(date_off);
        }
    }
    
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisao do funcionario " << i.getNome() <<" e: "<< i.calcularRecisao(date_off) << endl;
            return i.calcularRecisao(date_off);
        }
    }
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisao do funcionario "<< i.getNome() <<" e: " << i.calcularRecisao(date_off) << endl;
            return i.calcularRecisao(date_off);
        }
    }
    cout << "Nao existe um funcionario com essa matricula em nosso sistema" << endl;
    return -1;
}