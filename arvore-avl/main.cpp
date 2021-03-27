#include "./node.hpp"

int main()
{
     Node<int> *tree = nullptr;

     int teste[10] = {
         5,
         3,
         6,
         1,
         7,
         2,
         4,
         0,
         8,
         9,
     };

     for (int i = 0; i < 10; i++)
     {
          tree = tree->inserir(teste[i]);
     }

     // delete tree;

     return 0;
}