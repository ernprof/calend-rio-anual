#include<iostream>
#include <iomanip>

/*
Dados dia, mês e ano de uma data gregoriana, escreva uma função que converta essa data para data juliana correspondente. Use a seguinte fórmula:
Data juliana = (1461*(ano + 4800 +(mes - 14)/12) )/4 + (367 * (mes - 2 - 12 * (( mes - 14)/12)))/ 12 - (3*((ano+4900+(mes-14)/12)/100))/4+dia-32075.

Escreva uma função que receba dia, mês e ano e calcule o dia da semana em que caiu essa data. Para isso, basta transformar a data gregoriana em
juliana e calcular o resto da divisão da data juliana por 7. A função deverá retornar um número entre 0 e 6 indicando os seguintes resultados:
0 - Segunda-feira
1 - Terça-feira
2 - Quarta-feira
3 - Quinta-feira
4 - Sexta-feira
5 - Sábado
6 - Domingo
Faça um calendario anual

Autor: Ernandes em 16/02/2018
*/

using namespace std;

int juliana(int dia, int mes, int ano);
int diadasemana(int numero);
string meses(int m);
int dia_mes(int a);
bool bissexto(int n);

static int ano;

int main(){

    setlocale(LC_ALL, "Portuguese");

    int conv=0;
    int diames=0;

    cout<<"Ano: ";

    cin>>ano;

    cout<<endl;

    for(int mes=1; mes<=12; mes++){

        cout<<meses(mes);

        cout<<"\nSeg Ter Qua Qui Sex Sab Dom\n";

        diames = dia_mes(mes);

        //Salta os dias da semana que precisar para coincidir com o ultimo dia da semana do mes anterior.
        conv = juliana(1, mes, ano) % 7;

        for(int j=0; j<conv; j++){

            cout<<"    ";
        }

        for(int dia=1; dia<=diames; dia++){

            printf("3%d ", dia);

            conv++;

            if(conv % 7 == 0){

                cout<<endl;

            }
        }

        cout<<endl;

    }

    return 0;
}

//-------------------------------------------------------//

int juliana(int dia, int mes, int ano){

   return (1461*(ano + 4800 +(mes - 14)/12) )/4 + (367 * (mes - 2 - 12 * (( mes - 14)/12)))/ 12 - (3*((ano+4900+(mes-14)/12)/100))/4+dia-32075;

}

//-------------------------------------------------------//

int diadasemana(int numero){

    return numero % 7;
}

//-------------------------------------------------------//

string meses(int m){

    switch(m){

        case 1: return "Janeiro";

        case 2: return "\nFevereiro";

        case 3: return "\nMarço";

        case 4: return "\nAbril";

        case 5: return "\nMaio";

        case 6: return "\nJunho";

        case 7: return "\nJulho";

        case 8: return "\nAgosto";

        case 9: return "\nSetembro";

        case 10: return "\nOutubro";

        case 11: return "\nNovembro";

    default: return "\nDezembro";

    }
}

//-------------------------------------------------------//


int dia_mes(int a){

    if(a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12){

        return 31;

    }else if(a == 2){

        if(bissexto(ano) == true){

            return 29;

        }else{

            return 28;

        }


    }else{

        return 30;
    }
}

//-------------------------------------------------------//

bool bissexto(int n){

    if((n % 4 == 0) &&
       (n % 100 != 0)){

        return true;

    }else if(n % 400 == 0){

        return true;

    }else{

        return false;
    }

}














