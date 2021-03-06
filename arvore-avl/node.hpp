#include <iostream>
#pragma once

using namespace std;

template <typename T>
class Node
{
public:
  T info;
  long int altura = 0;
  Node *esquerda = nullptr, *direita = nullptr;

  Node(T novaInformacao, Node *novoEsquerda, Node *novoDireita)
  {
    setInfo(novaInformacao);
    setEsquerda(novoEsquerda);
    setDireita(novoDireita);
  }

  Node(T novaInformacao)
  {
    setInfo(novaInformacao);
  }

  ~Node()
  {
    if (this)
    {
      cout << "deletando: " << this->info << endl;

      cout << "deletando no esquerdo: " << this->info << endl;
      delete this->esquerda;

      cout << "deletando no direito: " << this->info << endl;
      delete this->direita;
    }
  }

  void setInfo(T novaInformacao)
  {
    this->info = novaInformacao;
  }

  void setEsquerda(Node *novoEsquerda)
  {
    this->esquerda = novoEsquerda;
    this->atualizaAltura();
  }

  void setEsquerda(T novaInformacao)
  {
    this->setEsquerda(new Node(novaInformacao));
  }

  void setDireita(Node *novoDireita)
  {
    this->direita = novoDireita;
    this->atualizaAltura();
  }

  void setDireita(T novaInformacao)
  {
    this->setDireita(new Node(novaInformacao));
  }

  Node *inserir(T novaInformacao)
  {
    Node *resultado = nullptr;
    if (this == nullptr)
    {
      Node *resultado = new Node(novaInformacao);
      return resultado;
    }

    if (novaInformacao < this->info)
    {
      Node *aux = this->esquerda->inserir(novaInformacao);
      this->setEsquerda(aux);
      resultado = this->verificaFatorBalanceamentoRotacaoDireita();
    }
    else
    {
      Node *aux = this->direita->inserir(novaInformacao);
      this->setDireita(aux);
      resultado = this->verificaFatorBalanceamentoRotacaoEsquerda();
    }
    return resultado;
  }

  Node *remover(T removeInfo)
  {
    Node *resultado = this;

    if (this)
    {
      if (removeInfo < resultado->info)
      {
        resultado->setEsquerda(resultado->esquerda->remover(removeInfo));
        resultado = resultado->verificaFatorBalanceamentoRotacaoEsquerda();
      }
      else if (removeInfo > resultado->info)
      {
        resultado->setDireita(resultado->direita->remover(removeInfo));
        resultado = resultado->verificaFatorBalanceamentoRotacaoDireita();
      }
      else
      {
        if (resultado->esquerda == nullptr && resultado->direita == nullptr)
        {
          delete resultado;
          resultado = nullptr;
        }
        else if (resultado->esquerda == nullptr)
        {
          Node *tmp = resultado->direita;
          delete resultado;
          resultado = tmp;
        }
        else if (resultado->direita == nullptr)
        {
          Node *tmp = resultado->esquerda;
          delete resultado;
          resultado = tmp;
        }
        else
        {

          Node *tmp = resultado->esquerda;
          while (tmp->direita != nullptr)
          {
            tmp = tmp->direita;
          }
          resultado->info = tmp->info;
          tmp->info = removeInfo;
          resultado->setEsquerda(resultado->esquerda->remover(removeInfo));
        }
      }
    }

    return resultado;
  }

  void marcadores(long int nivel = 0)
  {
    for (long int i = 0; i < nivel; i++)
    {
      cout << "------|";
    }
    cout << "<";

    if (this)
    {
      cout << "Chave: " << this->info
           << " - Fator de balanceamento: " << this->fatorBalanceamento()
           << " - Altura: " << this->getAltura()
           << " - Nivel: " << nivel
           << endl;

      this->esquerda->marcadores(nivel + 1);
      this->direita->marcadores(nivel + 1);

      for (long int i = 0; i < nivel; i++)
      {
        cout << "------|";
      }
    }
    cout << ">" << endl;
  }

  void preOrdem()
  {
    if (this)
    {
      cout << this->info;
      this->esquerda->preOrdem();
      this->direita->preOrdem();
    }
  }

  void inOrdem()
  {
    if (this)
    {
      this->esquerda->inOrdem();
      cout << this->info;
      this->direita->inOrdem();
    }
  }

  void posOrdem()
  {
    if (this)
    {
      this->esquerda->posOrdem();
      this->direita->posOrdem();
      cout << this->info;
    }
  }

  bool pertence(T informacaoParaEncontrar)
  {
    if (this)
    {
      if (this->info == informacaoParaEncontrar)
      {
        return true;
      }
      bool infoEsquerdaPertence = this->esquerda->pertence(informacaoParaEncontrar);
      bool infoDireitaPertence = this->direita->pertence(informacaoParaEncontrar);

      return (infoEsquerdaPertence || infoDireitaPertence);
    }
    return false;
  }

  T buscar(T info)
  {
    if (this == nullptr)
    {
      return NULL;
    }
    else if (info == this->info)
    {
      return this->info;
    }

    if (info < this->info)
    {
      return (this->esquerda)->buscar(info);
    }
    else if (info > this->info)
    {
      return (this->direita)->buscar(info);
    }

    return NULL;
  }

  long int totalElementos()
  {
    if (this)
    {
      long int totalEsquerda = this->esquerda->totalElementos();
      long int totalDireita = this->direita->totalElementos();
      return (1 + totalEsquerda + totalDireita);
    }
    return 0;
  }

  long int getAltura(bool raiz = true)
  {
    if (this)
    {
      return this->altura;
    }
    return -1;
  }

  void atualizaAltura()
  {
    long int alturaEsquerda = 0, alturaDireita = 0;

    alturaEsquerda = this->esquerda->getAltura();
    alturaDireita = this->direita->getAltura();

    this->altura = (alturaDireita > alturaEsquerda
                        ? alturaDireita
                        : alturaEsquerda) +
                   1;
  }

  long int fatorBalanceamento()
  {
    return (this->direita->getAltura()) - (this->esquerda->getAltura());
  }

  Node *verificaFatorBalanceamentoRotacaoDireita()
  {
    long int fb = this->fatorBalanceamento();
    long int fbEsquerda = this->esquerda->fatorBalanceamento();

    Node *resultado = this;

    if (fb == -2)
    {
      if (fbEsquerda <= 0)
      {
        resultado = resultado->rotacaoDireita();
      }
      else
      {
        resultado = resultado->rotacaoDuplaDireita();
      }
    }

    return resultado;
  }

  Node *verificaFatorBalanceamentoRotacaoEsquerda()
  {
    long int fb = this->fatorBalanceamento();
    long int fbDireita = this->direita->fatorBalanceamento();

    Node *resultado = this;

    if (fb == +2)
    {
      if (fbDireita >= 0)
      {
        resultado = resultado->rotacaoEsquerda();
      }
      else
      {
        resultado = resultado->rotacaoDuplaEsquerda();
      }
    }

    return resultado;
  }

  Node *rotacaoEsquerda()
  {
    Node *root = this->direita;
    this->setDireita(root->esquerda);

    Node *esquerdaRoot = this;
    root->setEsquerda(esquerdaRoot);

    return root;
  }

  Node *rotacaoDireita()
  {
    Node *root = this->esquerda;
    this->setEsquerda(root->direita);

    Node *direitaRoot = this;
    root->setDireita(direitaRoot);

    return root;
  }

  Node *rotacaoDuplaEsquerda()
  {
    Node *resultado = this;
    resultado->setDireita(resultado->direita->rotacaoDireita());
    resultado = resultado->rotacaoEsquerda();

    return resultado;
  }

  Node *rotacaoDuplaDireita()
  {
    Node *resultado = this;
    resultado->setEsquerda(resultado->esquerda->rotacaoEsquerda());
    resultado = resultado->rotacaoDireita();

    return resultado;
  }

  Node *arvoreEspelho()
  {
    Node *noEspelhado = nullptr;
    if (this)
    {
      noEspelhado = new Node(this);

      noEspelhado->inverter();

      noEspelhado->espelhar();
    }
    return noEspelhado;
  }

  void inverter()
  {
    if (this)
    {
      Node *tmpNode = this->esquerda;

      this->setEsquerda(this->direita);
      this->setDireita(tmpNode);
    }
  }

private:
  Node(Node *outroNo)
  {
    setInfo(outroNo->info);
    setEsquerda(outroNo->esquerda);
    setDireita(outroNo->direita);
  }

  void espelhar()
  {
    if (this)
    {
      Node *tmpEsq = this->esquerda;
      Node *tmpDir = this->direita;

      this->setEsquerda(tmpEsq->arvoreEspelho());
      this->setDireita(tmpDir->arvoreEspelho());
    }
  }
};
