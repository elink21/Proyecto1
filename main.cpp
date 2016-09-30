#include <bits/stdc++.h>
using namespace std;
map<string, string> HexKeys;
map<string, string> BinKeys;

string decToBin(int decimal)
{
    string binWordInverse="",binWord="";
    int indexForComplete;

    while(decimal>1)
    {
        binWordInverse+=char(decimal%2)+'0';
        decimal/=2;
    }
    binWordInverse+=char(decimal)+'0';

    indexForComplete=binWordInverse.size();

    while(indexForComplete++%4!=0)binWordInverse+='0';

    for(int index=binWordInverse.size()-1;index>=0;index--)
    {
        binWord+=binWordInverse[index];
    }
    return binWord;
}

int binToDec(string binWord)
{
    int decimal=0,position=0;
    for(int index=binWord.length()-1;index>=0;index--)
    {
        if(binWord[index]!=' ')
        {
            decimal+=int(binWord[index]-'0')*pow(2,position++);
        }
    }
    return decimal;
}

string binToHex(string binWord)
{
    string partialBinaryWord="",hexWord="";
    for(int index=0;index<binWord.length();index++)
    {
        partialBinaryWord+=binWord[index];
        if((index+1)%4==0 && index!=0)
        {
            hexWord+=HexKeys[partialBinaryWord];
            partialBinaryWord="";
        }
    }
    return hexWord;
}

string hexToBin(string hexWord)
{
    string binWord="",hexKey="";
    for(int index=0;index<hexWord.length();index++)
    {
        hexKey+=hexWord[index];
        binWord+=BinKeys[hexKey];
        hexKey="";
    }
    return binWord;
}

int main()
{
    string optionWord,binWord,hexWord;
    int optionNumber,decimal;

    HexKeys["0000"]="0";
    HexKeys["0001"]="1";
    HexKeys["0010"]="2";
    HexKeys["0011"]="3";
    HexKeys["0100"]="4";
    HexKeys["0101"]="5";
    HexKeys["0110"]="6";
    HexKeys["0111"]="7";
    HexKeys["1000"]="8";
    HexKeys["1001"]="9";
    HexKeys["1010"]="A";
    HexKeys["1011"]="B";
    HexKeys["1100"]="C";
    HexKeys["1101"]="D";
    HexKeys["1110"]="E";
    HexKeys["1111"]="F";

    BinKeys["0"]="0000";
    BinKeys["1"]="0001";
    BinKeys["2"]="0010";
    BinKeys["3"]="0011";
    BinKeys["4"]="0100";
    BinKeys["5"]="0101";
    BinKeys["6"]="0110";
    BinKeys["7"]="0111";
    BinKeys["8"]="1000";
    BinKeys["9"]="1001";
    BinKeys["A"]="1010";
    BinKeys["B"]="1011";
    BinKeys["C"]="1100";
    BinKeys["D"]="1101";
    BinKeys["E"]="1110";
    BinKeys["F"]="1111";

    while(optionWord!="EXIT")
    {
        optionNumber=0;
        cout<<"\t**** Sistema de conversion de tipos numericos ****\n";
        cout<<"\n-Inserte el tipo de conversion deseada-\n";
        cout<<"\nHEX- Para convertir de decimal a hexadecimal y viceversa\n";
        cout<<"BIN-Para convertir de decimal a binario y viceversa\n";
        cout<<"EXIT-Para terminar y salir del programa\n\n";
        cin>>optionWord;

        if(optionWord=="HEX")
        {
            while(optionNumber!=3)
            {
                cout<<"\nInserte el numero de su tipo de conversion: \n";
                cout<<"1-Decimal a hexadecimal\n";
                cout<<"2-Hexadecimal  a decimal\n";
                cout<<"3-Regresar al menu principal\n\n";
                cin>>optionNumber;
                switch(optionNumber)
                {
                case 1:
                    cout<<"Inserte el numero decimal: ";
                    cin>>decimal;
                    binWord=decToBin(decimal);
                    cout<<"\nEl numero en hexadecimal es:"<<binToHex(binWord)<<"\n";
                break;

                case 2:
                    cout<<"Inserte el numero hexadecimal: ";
                    cin>>hexWord;
                    binWord=hexToBin(hexWord);
                    cout<<"\nEl numero en decimal es:"<<binToDec(binWord)<<"\n";
                break;

                default:
                    cout<<"\nInserte un numero valido de las opciones dadas\n";
                break;
                }
            }

        }
        else if(optionWord=="BIN")
        {
            while(optionNumber!=3)
            {
                cout<<"\nInserte el numero de su tipo de conversion: \n";
                cout<<"1-Decimal a binario \n";
                cout<<"2- Binario a decimal\n";
                cout<<"3-Regresar al menu principal\n\n";
                cin>>optionNumber;
                switch(optionNumber)
                {
                case 1:
                    cout<<"Inserte el numero decimal: ";
                    cin>>decimal;
                    cout<<"\nEl numero en binario es:"<<decToBin(decimal)<<"\n";
                break;

                case 2:
                    cout<<"Inserte el numero binario: ";
                    cin>>binWord;
                    cout<<"\nEl numero en decimal es:"<<binToDec(binWord)<<"\n";
                break;

                default:
                    cout<<"\nInserte un numero valido de las opciones dadas\n";
                break;
                }
            }
        }
        else if(optionWord!="EXIT") cout<<"La opcion no es valida,escriba una de las opciones mostradas\n";
    }

    cout<<"\nPrograma finalizado, presione cualquier tecla para cerrar\n";
    cin.get();
    return 0;
}
