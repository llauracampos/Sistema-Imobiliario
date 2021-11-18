#include "SistemaImobiliario.h"

using namespace std;


void SistemaImobiliario::cadastraCasa(){

    int nP,nQ,tO, tam;
    float aT,aC, v;
    string ti;

    Casa novaCasa;
    Endereco endereco;

    //tam = listaCasa.size();

   // novaCasa.setTam(tam);
    cout << "Dados do imovel" << endl;
    cout << "Digite o titulo do imovel" << endl;
    cin.ignore();
    getline(cin, ti);
    novaCasa.setDescricao(ti);
    cout << "Digite o numero de pavimentos" << endl;
    cin >> nP;
    novaCasa.setNumPavimentos(nP);
    cout << "Digite o numero de quartos " << endl;
    cin >> nQ;
    novaCasa.setNumQuartos(nQ);
    cout << "Digite a area do terreno" << endl;
    cin >>  aT;
    novaCasa.setAreaTerreno(aT);
    cout << "Digite a area construida" << endl;
    cin >> aC;
    novaCasa.setAreaConstruida(aC);
    cout << "Digite o tipo de transacao" << endl;
    cout << "1 - Venda" << endl;
    cout << "2 - Aluguel" << endl;
    cin >> tO;
    novaCasa.setTipoOferta(tO);
    cout << "Digite o valor do imovel" << endl;
    cin >> v;
    novaCasa.setValor(v);
    cout << "Localizacao do imovel" << endl;
    cout << "Digite o logradouro" << endl;
    cin.ignore();
    getline(cin, endereco.logradouro);
    cout << "Digite o bairro" << endl;
    getline(cin, endereco.bairro);
    cout << "Digite a cidade" << endl;
    getline(cin, endereco.cidade);
    cout << "Digite o numero da casa" << endl;
    cin >> endereco.numero;
    cout << "Digite o CEP" << endl;
    cin >> endereco.cep;

    novaCasa.setEndereco(endereco);

    listaCasa.push_back(novaCasa);

}

/*
 REGULAMENTAÇÃO DO ID:

    TIPO DO IMOVEL:

    CASA = 013;
    APARTAMENTO = 024;
    TERRENO = 072;

    ID = TIPO DO IMOVEL + ORDEM DE CRONOLOGICA DE CADASTRO;

*/

void SistemaImobiliario::salvarCasa(){

    ofstream arquivoSalvar;


    arquivoSalvar.open("Casa.txt");

    for (Casa novaCasa : listaCasa){

       // arquivoSalvar << novaCasa.getTam() << endl;
        arquivoSalvar << novaCasa.getDescricao() << endl;
        arquivoSalvar << novaCasa.getNumPavimentos() << endl;
        arquivoSalvar << novaCasa.getNumQuartos() << endl;
        arquivoSalvar << novaCasa.getAreaTerreno() << endl;
        arquivoSalvar << novaCasa.getAreaConstruida() << endl;
        arquivoSalvar << novaCasa.getTipoOferta() << endl;
        arquivoSalvar << novaCasa.getValor() << endl;
        arquivoSalvar << novaCasa.getEndereco().logradouro << endl;
        arquivoSalvar << novaCasa.getEndereco().bairro << endl;
        arquivoSalvar << novaCasa.getEndereco().cidade << endl;
        arquivoSalvar << novaCasa.getEndereco().numero << endl;
        arquivoSalvar << novaCasa.getEndereco().cep << endl;

    }

    arquivoSalvar.close();
}

void SistemaImobiliario::recuperarCasa(){

    Casa novaCasa;
    Endereco endereco;

    int nP,nQ,tO, tam;
    float aT,aC, v;
    string ti;

    ifstream arquivoLer;

    arquivoLer.open("Casa.txt");

   if(arquivoLer.is_open()){

        while(!arquivoLer.eof()){

           // arquivoLer >> tam;
            getline(arquivoLer, ti);
            arquivoLer >> nP;
            arquivoLer >> nQ;
            arquivoLer >> aT;
            arquivoLer >> aC;
            arquivoLer >> tO;
            arquivoLer >> v;
            arquivoLer.ignore();
            getline(arquivoLer, endereco.logradouro);
            getline(arquivoLer, endereco.bairro);
            getline(arquivoLer, endereco.cidade);
            arquivoLer >> endereco.numero;
            arquivoLer.ignore();
            getline(arquivoLer, endereco.cep);

         //   novaCasa.setTam(tam);
            novaCasa.setDescricao(ti);
            novaCasa.setNumPavimentos(nP);
            novaCasa.setNumQuartos(nQ);
            novaCasa.setAreaTerreno(aT);
            novaCasa.setAreaConstruida(aC);
            novaCasa.setTipoOferta(tO);
            novaCasa.setValor(v);
            novaCasa.setEndereco(endereco);

            listaCasa.push_back(novaCasa);

        }

        listaCasa.pop_back();

    }
}

void SistemaImobiliario::exibirCasa(){

    cout << "teste tamanho: " << listaCasa.size()<< endl;

    for (Casa novaCasa : listaCasa){

        cout << "\t\t--------------------------------------------------" << endl;
        cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
        cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
        cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
        cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
        cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
        cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
        cout << "\t\tValor: " << novaCasa.getValor() << endl;
        cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
        cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
        cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
        cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
        cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
        cout << "\t\t--------------------------------------------------" << endl;

    }

}

void SistemaImobiliario::cadastraAp(){

    int nQ, tO, vG;
    float a, v;
    string ti, p;

    Apartamento novoAp;
    Endereco endereco;

    cout << "Dados do imovel\n" << endl;
    cout << "Digite o titulo do imovel:" << endl;
    cin.ignore();
    getline(cin, ti);
    novoAp.setDescricao(ti);
    cout << "Digite a posicao em relacao ao sol:" << endl;
    getline(cin, p);
    novoAp.setPosicao(p);
    cout << "Digite o numero de quartos:" << endl;
    cin >> nQ;
    novoAp.setNumQuartos(nQ);
    cout << "Digite a area do apartamento:" << endl;
    cin >> a;
    novoAp.setArea(a);
    cout << "Digite a quantidade de vagas na garagem:" << endl;
    cin >> vG;
    novoAp.setVagasGaragem(vG);
    cout << "Digite o tipo de transacao:" << endl;
    cout << "1 - Venda" << endl;
    cout << "2 - Aluguel" << endl;
    cin >> tO;
    novoAp.setTipoOferta(tO);
    cout << "Digite o valor do imovel:" << endl;
    cin >> v;
    novoAp.setValor(v);
    cin.ignore();

    cout << "Localizacao do imovel\n" << endl;
    cout << "Digite o logradouro:" << endl;
    getline(cin, endereco.logradouro);
    cout << "Digite o bairro:" << endl;
    getline(cin, endereco.bairro);
    cout << "Digite a cidade:" << endl;
    getline(cin, endereco.cidade);
    cout << "Digite o numero do apartamento:" << endl;
    cin >> endereco.numero;
    cin.ignore();
    cout << "Digite o CEP:" << endl;
    cin >> endereco.cep;

    novoAp.setEndereco(endereco);

    listaAp.push_back(novoAp);

}

void SistemaImobiliario::salvarAp(){

    ofstream arquivoSalvar;

    arquivoSalvar.open("Apartamento.txt", ios::app);

    for (Apartamento novoAp : listaAp){

        arquivoSalvar << novoAp.getDescricao() << endl;
        arquivoSalvar << novoAp.getPosicao() << endl;
        arquivoSalvar << novoAp.getNumQuartos() << endl;
        arquivoSalvar << novoAp.getArea() << endl;
        arquivoSalvar << novoAp.getVagasGaragem() << endl;
        arquivoSalvar << novoAp.getTipoOferta() << endl;
        arquivoSalvar << novoAp.getValor() << endl;
        arquivoSalvar << novoAp.getEndereco().logradouro << endl;
        arquivoSalvar << novoAp.getEndereco().bairro << endl;
        arquivoSalvar << novoAp.getEndereco().cidade << endl;
        arquivoSalvar << novoAp.getEndereco().numero << endl;
        arquivoSalvar << novoAp.getEndereco().cep << endl;

    }

    arquivoSalvar.close();
}

void SistemaImobiliario::recuperarAp(){

    Apartamento novoAp;
    Endereco endereco;

    int nQ, tO, vG;
    float a, v;
    string ti, p;

    ifstream arquivoLer;

    arquivoLer.open("Apartamento.txt");

    if(arquivoLer.is_open()){

        while (!arquivoLer.eof()){

            getline(arquivoLer, ti);
            getline(arquivoLer, p);
            arquivoLer >> nQ;
            arquivoLer >> a;
            arquivoLer >> vG;
            arquivoLer >> tO;
            arquivoLer >> v;
            arquivoLer.ignore();
            getline(arquivoLer, endereco.logradouro);
            getline(arquivoLer, endereco.bairro);
            getline(arquivoLer, endereco.cidade);
            arquivoLer >> endereco.numero;
            arquivoLer.ignore();
            getline(arquivoLer, endereco.cep);

            novoAp.setDescricao(ti);
            novoAp.setPosicao(p);
            novoAp.setNumQuartos(nQ);
            novoAp.setArea(a);
            novoAp.setVagasGaragem(vG);
            novoAp.setTipoOferta(tO);
            novoAp.setValor(v);
            novoAp.setEndereco(endereco);

            listaAp.push_back(novoAp);

        }

         listaAp.pop_back();
    }

}

void SistemaImobiliario::exibirAp(){

    cout << "teste tamanho: " << listaAp.size()<< endl;

    for (Apartamento novoAp : listaAp){
        cout << "\t\t--------------------------------------------------" << endl;
        cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
        cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
        cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
        cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
        cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
        cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
        cout << "\t\tValor: " << novoAp.getValor() << endl;
        cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
        cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
        cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
        cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
        cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
        cout << "\t\t--------------------------------------------------" << endl;
    }
}

void SistemaImobiliario::cadastraTerreno(){

    int tO;
    float a, v;
    string ti;

    Terreno novoTerreno;
    Endereco endereco;

    cout << "Dados do imovel\n" << endl;
    cout << "Digite o titulo do imovel:" << endl;
    cin.ignore();
    getline(cin, ti);
    novoTerreno.setDescricao(ti);
    cout << "Digite a area do terreno:" << endl;
    cin >>  a;
    novoTerreno.setArea(a);
    cout << "Digite o tipo de transacao:" << endl;
    cout << "1 - Venda" << endl;
    cout << "2 - Aluguel" << endl;
    cin >> tO;
    novoTerreno.setTipoOferta(tO);
    cout << "Digite o valor do imovel:" << endl;
    cin >> v;
    novoTerreno.setValor(v);

    cout << "Localizacao do imovel\n" << endl;
    cout << "Digite o logradouro:" << endl;
    cin.ignore();
    getline(cin, endereco.logradouro);
    cout << "Digite o bairro:" << endl;
    getline(cin, endereco.bairro);
    cout << "Digite a cidade:" << endl;
    getline(cin, endereco.cidade);
    cout << "Digite o numero do terreno:" << endl;
    cin >> endereco.numero;
    cin.ignore();
    cout << "Digite o CEP:" << endl;
    cin >> endereco.cep;

    novoTerreno.setEndereco(endereco);

    listaTerreno.push_back(novoTerreno);

}

void SistemaImobiliario::salvarTerreno(){

    ofstream arquivoSalvar;

    arquivoSalvar.open("Terreno.txt", ios::app);

    for (Terreno novoTerreno : listaTerreno){

        arquivoSalvar << novoTerreno.getDescricao() << endl;
        arquivoSalvar << novoTerreno.getArea() << endl;
        arquivoSalvar << novoTerreno.getTipoOferta() << endl;
        arquivoSalvar << novoTerreno.getValor() << endl;
        arquivoSalvar << novoTerreno.getEndereco().logradouro << endl;
        arquivoSalvar << novoTerreno.getEndereco().bairro << endl;
        arquivoSalvar << novoTerreno.getEndereco().cidade << endl;
        arquivoSalvar << novoTerreno.getEndereco().numero << endl;
        arquivoSalvar << novoTerreno.getEndereco().cep << endl;

    }

    arquivoSalvar.close();
}

void SistemaImobiliario::recuperarTerreno(){

    Terreno novoTerreno;
    Endereco endereco;

    int tO;
    float a, v;
    string ti;

    ifstream arquivoLer;

    arquivoLer.open("Terreno.txt");

    if(arquivoLer.is_open()){

        while (!arquivoLer.eof()){

            getline(arquivoLer, ti);
            arquivoLer >> a;
            arquivoLer >> tO;
            arquivoLer >> v;
            arquivoLer.ignore();
            getline(arquivoLer, endereco.logradouro);
            getline(arquivoLer, endereco.bairro);
            getline(arquivoLer, endereco.cidade);
            arquivoLer >> endereco.numero;
            arquivoLer.ignore();
            getline(arquivoLer, endereco.cep);

            novoTerreno.setDescricao(ti);
            novoTerreno.setArea(a);
            novoTerreno.setTipoOferta(tO);
            novoTerreno.setValor(v);
            novoTerreno.setEndereco(endereco);

            listaTerreno.push_back(novoTerreno);

        }

         listaTerreno.pop_back();
    }
}

void SistemaImobiliario::exibirTerreno(){

    cout << "teste tamanho: " << listaTerreno.size()<< endl;

    for (Terreno novoTerreno : listaTerreno){
        cout << "\t\t--------------------------------------------------" << endl;
        cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
        cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
        cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
        cout << "\t\tValor: " << novoTerreno.getValor() << endl;
        cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
        cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
        cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
        cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
        cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
        cout << "\t\t--------------------------------------------------" << endl;
    }
}

void SistemaImobiliario::exibirImoveis(){

    for (Casa novaCasa : listaCasa){

        cout << "\t\t--------------------------------------------------" << endl;
        cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
        cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
        cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
        cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
        cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
        cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
        cout << "\t\tValor: " << novaCasa.getValor() << endl;
        cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
        cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
        cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
        cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
        cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
        cout << "\t\t--------------------------------------------------" << endl;
    }

    for (Apartamento novoAp : listaAp){
        cout << "\t\t--------------------------------------------------" << endl;
        cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
        cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
        cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
        cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
        cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
        cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
        cout << "\t\tValor: " << novoAp.getValor() << endl;
        cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
        cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
        cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
        cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
        cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
        cout << "\t\t--------------------------------------------------" << endl;
    }

    for (Terreno novoTerreno : listaTerreno){
        cout << "\t\t--------------------------------------------------" << endl;
        cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
        cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
        cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
        cout << "\t\tValor: " << novoTerreno.getValor() << endl;
        cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
        cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
        cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
        cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
        cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
        cout << "\t\t--------------------------------------------------" << endl;
    }

}

void SistemaImobiliario::imoveisVender(){

    Casa novaCasa;
    Apartamento novoAp;
    Terreno novoTerreno;

        for (Casa novaCasa : listaCasa){

            if(novaCasa.getTipoOferta() == 1){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
            cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
            cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
            cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
            cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
            cout << "\t\tValor: " << novaCasa.getValor() << endl;
            cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
            cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }


        for (Apartamento novoAp : listaAp){

            if(novoAp.getTipoOferta() == 1){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
            cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
            cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
            cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
            cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoAp.getValor() << endl;
            cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
            cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }



         for (Terreno novoTerreno : listaTerreno){

            if(novoTerreno.getTipoOferta() == 1){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
            cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoTerreno.getValor() << endl;
            cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
            cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
     }
}

void SistemaImobiliario::imoveisAlugar(){

    Casa novaCasa;
    Apartamento novoAp;
    Terreno novoTerreno;

        for (Casa novaCasa : listaCasa){

            if(novaCasa.getTipoOferta() == 2){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
            cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
            cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
            cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
            cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
            cout << "\t\tValor: " << novaCasa.getValor() << endl;
            cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
            cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }


        for (Apartamento novoAp : listaAp){

            if(novoAp.getTipoOferta() == 2){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
            cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
            cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
            cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
            cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoAp.getValor() << endl;
            cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
            cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }



         for (Terreno novoTerreno : listaTerreno){

            if(novoTerreno.getTipoOferta() == 2){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
            cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoTerreno.getValor() << endl;
            cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
            cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
     }
}

void SistemaImobiliario::buscarPorBairro(){

    Casa novaCasa;
    Apartamento novoAp;
    Terreno novoTerreno;

    cout << "\nDigite o bairro que deseja pesquisar: " << endl;
    string str;

    getline(cin, str);

        for (Casa novaCasa : listaCasa){

            size_t found = novaCasa.getEndereco().bairro.find(str);

            if(found!=string::npos){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
            cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
            cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
            cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
            cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
            cout << "\t\tValor: " << novaCasa.getValor() << endl;
            cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
            cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }


        for (Apartamento novoAp : listaAp){

            size_t found = novoAp.getEndereco().bairro.find(str);

            if(found!=string::npos){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
            cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
            cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
            cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
            cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoAp.getValor() << endl;
            cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
            cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }



         for (Terreno novoTerreno : listaTerreno){

            size_t found = novoTerreno.getEndereco().bairro.find(str);

            if(found!=string::npos){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
            cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoTerreno.getValor() << endl;
            cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
            cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
     }
}

void SistemaImobiliario::buscarPorCidade(){

    Casa novaCasa;
    Apartamento novoAp;
    Terreno novoTerreno;

    cout << "\nDigite a cidade que deseja pesquisar: " << endl;
    string str;

    getline(cin, str);

        for (Casa novaCasa : listaCasa){

            size_t found = novaCasa.getEndereco().cidade.find(str);

            if(found!=string::npos){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
            cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
            cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
            cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
            cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
            cout << "\t\tValor: " << novaCasa.getValor() << endl;
            cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
            cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }


        for (Apartamento novoAp : listaAp){

            size_t found = novoAp.getEndereco().cidade.find(str);

            if(found!=string::npos){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
            cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
            cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
            cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
            cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoAp.getValor() << endl;
            cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
            cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }



         for (Terreno novoTerreno : listaTerreno){

            size_t found = novoTerreno.getEndereco().cidade.find(str);

            if(found!=string::npos){

            cout << "\t\t-------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
            cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoTerreno.getValor() << endl;
            cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
            cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
     }
}


void SistemaImobiliario::buscarPorTitulo(){

    Casa novaCasa;
    Apartamento novoAp;
    Terreno novoTerreno;

    cout << "\nDigite o titulo que deseja pesquisar: " << endl;
    string str;

    getline(cin, str);

        for (Casa novaCasa : listaCasa){

            size_t found = novaCasa.getDescricao().find(str);

            if(found!=string::npos){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
            cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
            cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
            cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
            cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
            cout << "\t\tValor: " << novaCasa.getValor() << endl;
            cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
            cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }


        for (Apartamento novoAp : listaAp){

            size_t found = novoAp.getDescricao().find(str);

            if(found!=string::npos){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
            cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
            cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
            cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
            cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoAp.getValor() << endl;
            cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
            cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }



         for (Terreno novoTerreno : listaTerreno){

            size_t found = novoTerreno.getDescricao().find(str);

            if(found!=string::npos){

            cout << "\t\t-------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
            cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoTerreno.getValor() << endl;
            cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
            cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
     }
}


void SistemaImobiliario::buscarPorValorMaior(){

    Casa novaCasa;
    Apartamento novoAp;
    Terreno novoTerreno;

    cout << "\nDigite o valor que deseja pesquisar: " << endl;
    float valor;

    cin >> valor;


        for (Casa novaCasa : listaCasa){

            if(valor >= novaCasa.getValor()){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
            cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
            cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
            cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
            cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
            cout << "\t\tValor: " << novaCasa.getValor() << endl;
            cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
            cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }


        for (Apartamento novoAp : listaAp){


            if(valor >= novoAp.getValor()){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
            cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
            cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
            cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
            cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoAp.getValor() << endl;
            cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
            cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }



         for (Terreno novoTerreno : listaTerreno){

            if( valor >= novoTerreno.getValor()){

            cout << "\t\t-------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
            cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoTerreno.getValor() << endl;
            cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
            cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
     }
}

void SistemaImobiliario::buscarPorValorMenor(){

    Casa novaCasa;
    Apartamento novoAp;
    Terreno novoTerreno;

    cout << "\nDigite o valor que deseja pesquisar: " << endl;
    float valor;

    cin >> valor;


        for (Casa novaCasa : listaCasa){

            if(valor <= novaCasa.getValor()){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novaCasa.getDescricao() << endl;
            cout << "\t\tNumero de pavimentos: " << novaCasa.getNumPavimentos() << endl;
            cout << "\t\tNumero de quartos: " << novaCasa.getNumQuartos() << endl;
            cout << "\t\tArea do Terreno: " << novaCasa.getAreaTerreno() << endl;
            cout << "\t\tArea construida: " << novaCasa.getAreaConstruida() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novaCasa.getTipoOferta() << endl;
            cout << "\t\tValor: " << novaCasa.getValor() << endl;
            cout << "\t\tLogradouro: " << novaCasa.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novaCasa.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novaCasa.getEndereco().cidade << endl;
            cout << "\t\tNumero da casa: " << novaCasa.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novaCasa.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }


        for (Apartamento novoAp : listaAp){


            if(valor <= novoAp.getValor()){

            cout << "\t\t--------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoAp.getDescricao() << endl;
            cout << "\t\tPosicao em relacao ao sol: " << novoAp.getPosicao() << endl;
            cout << "\t\tNumero de quartos: " << novoAp.getNumQuartos() << endl;
            cout << "\t\tArea do apartamento: " << novoAp.getArea() << endl;
            cout << "\t\tNumero de vagas na garagem: " << novoAp.getVagasGaragem() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoAp.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoAp.getValor() << endl;
            cout << "\t\tLogradouro: " << novoAp.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoAp.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoAp.getEndereco().cidade << endl;
            cout << "\t\tNumero do apartamento: " << novoAp.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoAp.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
    }



         for (Terreno novoTerreno : listaTerreno){

            if( valor <= novoTerreno.getValor()){

            cout << "\t\t-------------------------------------------------" << endl;
            cout << "\t\tTitulo: " << novoTerreno.getDescricao() << endl;
            cout << "\t\tArea do Terreno: " << novoTerreno.getArea() << endl;
            cout << "\t\tTipo de oferta (1.VENDA/2.ALUGUEL): " << novoTerreno.getTipoOferta() << endl;
            cout << "\t\tValor: " << novoTerreno.getValor() << endl;
            cout << "\t\tLogradouro: " << novoTerreno.getEndereco().logradouro << endl;
            cout << "\t\tBairro: " << novoTerreno.getEndereco().bairro << endl;
            cout << "\t\tCidade: " << novoTerreno.getEndereco().cidade << endl;
            cout << "\t\tNumero do terreno: " << novoTerreno.getEndereco().numero << endl;
            cout << "\t\tCEP: " << novoTerreno.getEndereco().cep << endl;
            cout << "\t\t--------------------------------------------------" << endl;
        }
     }
}

void SistemaImobiliario::remover(){


}




