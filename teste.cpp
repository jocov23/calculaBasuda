#include <iostream>
#include <limits> //para limpar buffer
#include <vector>
#include <string>
#include <map>


int baseOrigem, baseDestino;
std::string valor;
std::string caracteresEspeciais ="-+_!@#$%¨&*(){}[]<>:;?^~´`.|'""'\0'' ',\\";
std::string caractereInvalido = "";
bool validacao = false;


std::string valores = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int limitesDigitos[] = {0, 0, 64, 40, 32, 27, 24, 22, 21, 20, 19, 19, 18, 18, 17, 17, 16, 16, 16, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12};

std::map<std::string, std::string> valoresInverso = {
    {"0", "0"}, {"1", "1"},{"2", "2"},{"3", "3"},{"4", "4"},{"5", "5"},{"6", "6"},{"7", "7"},
    {"8", "8"},{"9", "9"},{"A", "10"},{"B", "11"},{"C", "12"},{"D", "13"},{"E", "14"},
    {"F", "15"},{"G", "16"},{"H", "17"},{"I", "18"},{"J", "19"},{"K", "20"},{"L", "21"},
    {"M", "22"},{"N", "23"},{"O", "24"},{"P", "25"},{"Q", "26"},{"R", "27"},{"S", "28"},
    {"T", "29"},{"U", "30"},{"V", "31"}, {"W", "32"}, {"X", "33"}, {"Y", "34"}, {"Z", "35"}
    
};


void InputBaseOrigem(){
    std::cout << ("Digite a base de Origem[2-36] ou '1' para sair: ");
        std::cin >> (baseOrigem);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //validacao de base valida
        if (baseOrigem < 1 || baseOrigem > 36) {
        std::cout << "\n\nERRO: Base de origem invalida (deve ser entre 2 e 36)!\n\n" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        validacao = true;
        }
}
void inputBaseDestino(){
    
        std::cout << ("Digite a base de destino[2-36]: ");
        std::cin >> (baseDestino);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //validacao de base valida
        if (baseDestino < 2 || baseDestino > 36) {
            std::cout << "\n\nERRO: Base de destino invalida (deve ser entre 2 e 36)!\n\n" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            validacao = true;
        }
}
void inputValor(){
    caractereInvalido = "";
    std::cout << "Digite o numero para converter: ";
        std::cin >> valor;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //range loop que modifica cada caractere da string 'valor' para uppercase
        for (char& caractere : valor){
            caractere = std::toupper(static_cast<unsigned char>(caractere));
        }
        
        //validação de valor inserido pelo usuario
        for (int i = baseOrigem; i < 36; i++ ){
            std::string numeroString = std::to_string(i);
            caractereInvalido += valores[i];
        }
        if (valor.find_first_of(caracteresEspeciais) != std::string::npos){
            std::cout << ("\n\nInsira um valor valido sem caracteres especiais!\n\n");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            validacao = true;
        }else if(valor.find_first_of(caractereInvalido) != std::string::npos){
            std::cout << ("\n\nInsira um valor valido da base de origem!\n\n");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            validacao = true;
        }else if ((int)valor.size() > limitesDigitos[baseOrigem]){
    std::cout << "\n\nAVISO: numero possui " << valor.size() << " digitos mas a base "
              << baseOrigem << " suporta no maximo " << limitesDigitos[baseOrigem]
              << " digitos antes de causar overflow do tipo unsigned long long int (2^64 - 1).\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        validacao = true;
    }
}

unsigned long long int potenciaInteira(int base, int exp) {
    unsigned long long int resultado = 1;
    for (int i = 0; i < exp; i++)
        resultado *= base;
    return resultado;
}

std::string funcaoParaDecimal (std::string valor, int baseOrigem){
    unsigned long long int valorDecimal=0;
    int expoente = valor.size()-1;
    for (int i = 0; i< valor.size(); i++){
        char valorChar = valor[i];
        std::string valorString(1, valorChar);
        std::string caractereConvertido = valoresInverso[valorString];
        int inteiroCaractere = std::stoi(caractereConvertido);
        valorDecimal += inteiroCaractere * potenciaInteira(baseOrigem, expoente);
        expoente-=1;
    }
    valor = std::to_string(valorDecimal);
    return valor;
}

std::vector<std::string> funcaoVetorDoDecimal (std::string valor){
    
    //converte a string de valores para unsigned long long int
    unsigned long long int valorDecimal = std::stoull(valor);
    std::vector<std::string> valoresConvertidosDoDecimal = {"null"};
    //variavel de resto 
    unsigned long long int resto;
    //divisão inicial fora de loop para inicializar o vetor com valor valido(tirar o null)
    resto = valorDecimal% baseDestino; 
    //funcao to_string transforma o inteiro "resto" em string e atribui a variavel restoString
    std::string restoString = std::to_string(resto);
    //variavel do resto (como string) é adicionada ao vetor
    valoresConvertidosDoDecimal[0] = std::string(1, valores[resto]);
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
            valoresConvertidosDoDecimal.push_back(std::string(1, valores[resto]));
            //cout decimal para debug

            //std::cout << valorDecimal << std::endl;

            //valor decimal é dividido para continuar operação
            valorDecimal/=baseDestino;

    }
    //apos o fim do while, quando decimal chega a 0, a função retorna o vetor com os valores atribuidos
    return valoresConvertidosDoDecimal;
}


int main() {
    //numero decimal maximo = 18446744073709551615 (18 quintilhões)
    //ciclo de repetição
    while (true) {
        try{
        validacao = false;
        InputBaseOrigem();
        if (validacao){continue;}
        //termino do programa
        if (baseOrigem == 1){
            std::cout << ("\n\nEncerrando o programa..");
            break;
        }
        
        inputBaseDestino();
        if (validacao){continue;}
        
        
        inputValor();
        if (validacao){continue;}
        
        
        if (baseOrigem == 10){
            //atribui valores ao vetor de numeros convertidos
            std::vector <std::string> valoresConvertidosDodecimal = funcaoVetorDoDecimal (valor);
            
            //itera sobre os valores convertidos e mostra no terminal
            std::cout << "\n\n---------------valor convertido abaixo---------------\n\n" << std::endl;
            for (int i = valoresConvertidosDodecimal.size()-1; i >= 0; i--){
                std::cout << valoresConvertidosDodecimal[i];
            }
            std::cout << ("\n\n-------------------------------------\n\n");
        
        }else{
            valor = funcaoParaDecimal(valor, baseOrigem);
            std::vector <std::string> valoresConvertidosDodecimal = funcaoVetorDoDecimal (valor);
           
            //itera sobre os valores convertidos e mostra no terminal
            std::cout << "\n\n---------------valor convertido abaixo---------------\n\n" << std::endl;
            for (int i = valoresConvertidosDodecimal.size()-1; i >= 0; i--){
                std::cout << valoresConvertidosDodecimal[i];
            }
            std::cout << ("\n\n-----------------------------------------------------\n\n");
        }
        }catch(const std::out_of_range& e){
            std::cout << "\n\nERRO: valor fora do intervalo suportado.\n\n";
        validacao=true;

        }
        
    }
    return 0;
}
