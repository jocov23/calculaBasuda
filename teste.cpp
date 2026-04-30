#include <iostream>
#include <vector>
#include <string>
#include <map>

//declaração de base de origem e base de destino
int baseOrigem, baseDestino;
std::string valor;

//dicionario para mapear Resto : RestoConvertido
std::map<std::string, std::string> valores = {
    {"0", "0"},
    {"1", "1"},
    {"2", "2"},
    {"3", "3"},
    {"4", "4"},
    {"5", "5"},
    {"6", "6"},
    {"7", "7"},
    {"8", "8"},
    {"9", "9"},
    {"10", "A"},
    {"11", "B"},
    {"12", "C"},
    {"13", "D"},
    {"14", "E"},
    {"15", "F"},
    {"16", "G"},
    {"17", "H"},
    {"18", "I"},    
    {"19", "J"},
    {"20", "K"},
    {"21", "L"},
    {"22", "M"},
    {"23", "N"},
    {"24", "O"},
    {"25", "P"},
    {"26", "Q"},
    {"27", "R"},
    {"28", "S"},
    {"29", "T"},
    {"30", "U"},
    {"31", "V"}
    
};

///std::vector<int> funcaoVetorParadecimal()
//{
   // return 0;
//}

std::vector<std::string> funcaoVetorDoDecimal (unsigned long long int valorDecimal){
    
    std::vector<std::string> valoresConvertidosDoDecimal = {"null"};
    //variavel de resto 
    unsigned long long int resto;
    //divisão inicial fora de loop para inicializar o vetor com valor valido(tirar o null)
    resto = valorDecimal% baseDestino; 
    //funcao to_string transforma o inteiro "resto" em string e atribui a variavel restoString
    std::string restoString = std::to_string(resto);
    //variavel do resto (como string) é adicionada ao vetor
    valoresConvertidosDoDecimal[0] = valores[restoString];
    //cout decimal para debug

    //std::cout << valorDecimal << std::endl;

    //valor decimal é dividido para continuar operação
    valorDecimal/=baseDestino;
    
    //enquanto decimal for maior que 0, será constantemente dividido
    //seu resto continuadamente guardado no vetorConvertido
    while (valorDecimal > 0){
            
            //divisao do decimal para atribuir resto
            resto = valorDecimal % baseDestino;  
            //converte o resto em uma variavel de String
            restoString = std::to_string(resto);
            //adiciona o resto no vetor de valores convertidos
            valoresConvertidosDoDecimal.push_back(valores[restoString]);
            //cout decimal para debug

            //std::cout << valorDecimal << std::endl;

            //valor decimal é dividido para continuar operação
            valorDecimal/=baseDestino;

    }
    //apos o fim do while, quando decimal chega a 0, a função retorna o vetor com os valores atribuidos
    return valoresConvertidosDoDecimal;
}

int main() {
    //numero maximo = 18446744073709551615 (18 quintilhões)
    unsigned long long int valordecimal;
    int parar = 0;
    //ciclo de repetição
    while (true) {
        std::cout << ("Digite a base de Origem: ");
        std::cin >> (baseOrigem);
        std::cout << ("Digite o valor desejado: ");
        std::cin >> (valor);
        std::cout << ("Digite a base de destino: ");
        std::cin >> (baseDestino);
        //chama função que converte (função de vetor)
        
        if (baseOrigem == 10){
            int negativo = valor.find('-');
            //validação de numero negativo
            if (negativo != std::string::npos){
                std::cout << ("\n\nInsira um valor positivo!\n\n");
            }else{
                //converte a string de valores para unsigned long long int
                valordecimal = std::stoull(valor);
                //atribui valores ao vetor de numeros convertidos
                std::vector <std::string> valoresConvertidosDodecimal = funcaoVetorDoDecimal (valordecimal);
                //itera sobre os valores convertidos e mostra no terminal
                std::cout << "valor convertido comeca aqui" << std::endl;
                for (int i = valoresConvertidosDodecimal.size()-1; i >= 0; i--){
                    std::cout << valoresConvertidosDodecimal[i];
                }
            
                std::cout << ("\n\n\nDigite 1 para interromper, qualquer outra tecla para continuar: ");
                std::cin >> (parar);
                if (parar == 1){
                    break;
                }
                std::cout << ("\n\n\n");
            }
        
        
        }
    
        //iteração sobre os binarios convertidos em ordem inversa do vetor
        // std::cout << "valor convertido comeca aqui" << std::endl;
        // for (int i = valoresConvertidosDodecimal.size()-1; i >= 0; i--){
        //     std::cout << valoresConvertidosDodecimal[i];
        // }
        // return 99999;
    }

}

