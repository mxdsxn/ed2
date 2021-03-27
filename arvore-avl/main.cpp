#include "./node.hpp"
#include "./node-string.hpp"

int main()
{
     int menuOption = 0;
     do
     {
          cout << "1- Exercicio 1: Arvore com letras" << endl
               << "2- Exercicio 2: Arvore com numeros inteiros e removendo o numero (1)" << endl
               << "3- Exercicio 3: Arvore com nome de pessoas" << endl
               << "0- Exercicio 1: Arvore com letras" << endl
               << endl;

          cin >> menuOption;
          getchar();
          cout << endl;

          switch (menuOption)
          {
          case 1:
          {
               cout << "Exercicio 1: Arvore com letras:" << endl;

               Node<char> *treeChar = nullptr;

               char arrayChar[] = {'Q', 'Z', 'B', 'Y', 'T', 'M', 'E', 'W', 'X', 'S', 'F', 'G', 'A', 'H', 'N', 'O', 'P', 'R'};

               for (const char i : arrayChar)
               {
                    treeChar = treeChar->inserir(i);
               }

               treeChar->marcadores();
          }
          break;

          case 2:
          {
               cout << "Exercicio 2: Arvore com numeros inteiros e removendo o numero (1):" << endl;

               Node<int> *treeInt = nullptr;

               int arrayInt[] = {14, 5, 28, 2, 8, 18, 33, 1, 3, 6, 11, 15, 20, 30, 38, 4, 7, 10, 12, 16, 19, 21, 29, 31, 35, 39, 13, 22, 32, 34, 36, 40, 37};

               for (const int i : arrayInt)
               {
                    treeInt = treeInt->inserir(i);
               }

               cout << "Removendo (1)..." << endl;

               treeInt = treeInt->remover(1);

               treeInt->marcadores();
          }
          break;

          case 3:
          {
               cout << "Exercicio 3: Arvore com nome de pessoas:" << endl;

               NodeString *treeNomes = nullptr;

               char *arrayNomes[] = {
                   (char *)"Pedro",
                   (char *)"Joaquim",
                   (char *)"Sandra",
                   (char *)"Daniele",
                   (char *)"Jhony",
                   (char *)"Bruna",
                   (char *)"Roberto",
                   (char *)"Ricardo",
                   (char *)"Rafael",
                   (char *)"Hayana",
                   (char *)"Lorena",
                   (char *)"Mariana",
                   (char *)"Marina",
                   (char *)"Roberta",
                   (char *)"Chayene",
                   (char *)"Edmundo",
               };

               for (char *i : arrayNomes)
               {
                    treeNomes = treeNomes->inserir(i);
               }

               treeNomes->marcadores();
          }
          break;

          default:
               break;
          }
          cout << endl
               << "-- tecle alguma botao --";
          getchar();
     } while (menuOption != 0);
     return 0;
}