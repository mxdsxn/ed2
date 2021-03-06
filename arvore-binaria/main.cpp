#include "./node.hpp"

int main()
{
     int menuOption = 0;

     Node<char> *tree =
         new Node<char>('a',
                        new Node<char>('b',
                                       nullptr,
                                       new Node<char>('d')),
                        new Node<char>('c',
                                       new Node<char>('e'),
                                       new Node<char>('f')));

     do
     {
          cout << "Exercicio 1" << endl
               << " 1 - Pre Ordem" << endl
               << " 2 - In Ordem" << endl
               << " 3 - Pos Ordem" << endl
               << "Exercicio 2" << endl
               << " 4 - Marcadores" << endl
               << "Exercicio 3" << endl
               << " 5 - Total de Nos" << endl
               << "Exercicio 5" << endl
               << " 6 - Altura" << endl
               // EXERCICIO 6: GERAR ARVORE ESPELHO(TROCAR O NO DA DIREITA COM DA ESQUERDA E VICE-VERSA, ATE O NO MAIS BAIXO)
               << "Exercicio 6" << endl
               << " 7 - Arvore Espelho" << endl
               << " 0 - Encerrar" << endl
               << " Escolha uma opcao: ";

          cin >> menuOption;
          getchar();

          switch (menuOption)
          {
          case 1:
               cout << "Pre Ordem: ";
               tree->preOrder();
               cout << endl
                    << endl;
               break;
          case 2:
               cout << "In Ordem: ";
               tree->inOrder();
               cout << endl
                    << endl;
               break;
          case 3:
               cout << "Pos Ordem: ";
               tree->posOrder();
               cout << endl
                    << endl;
               break;
          case 4:
               cout << "Marcadores: ";
               tree->mark();
               cout << endl
                    << endl;
               break;
          case 5:
               cout << "Total de Nos: " << tree->totalNode();
               cout << endl
                    << endl;
               break;
          case 6:
               cout << "Altura: " << tree->getLevel();
               cout << endl
                    << endl;
               break;
          case 7:
               cout << "Arvore Espelho: ";
               tree->mirrorTree()->mark();
               cout << endl
                    << endl;
          default:
               break;
          }
          getchar();
     } while (menuOption);
     delete tree;

     return 0;
}