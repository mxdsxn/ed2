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
      resultado = this->verificaFatorBalanceamentoInsercaoEsquerda();
    }
    else
    {
      Node *aux = this->direita->inserir(novaInformacao);
      this->setDireita(aux);
      resultado = this->verificaFatorBalanceamentoInsercaoDireito();
    }
    return resultado;
  }

  Node *remover(T removeInfo)
  {
  }

  void marcadores(long int espaco = 0)
  {
    for (long int i = 0; i < espaco; i++)
    {
      cout << " ";
    }
    cout << "<";

    if (this)
    {
      cout << this->info << endl;

      this->esquerda->marcadores(espaco + 1);
      this->direita->marcadores(espaco + 1);

      for (long int i = 0; i < espaco; i++)
      {
        cout << " ";
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
      return this->altura
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
    return (this->direta->getAltura()) - (this->esquerda->getAltura());
  }

  Node *verificaFatorBalanceamentoInsercaoEsquerda()
  {
    long int fb = this->fatorBalanceamento();
    long int fbEsquerda = this->esquerda->fatorBalanceamento();

    Node *resultado = this;

    if (fb == -2)
    {
      if (fbEsquerda <= 0)
      {
        /*rotacao_para_direita*/
      }
      else
      {
        /*rotacao_dupla_direta*/
      }
    }

    return resultado;
  }

  Node *verificaFatorBalanceamentoInsercaoDireita()
  {
    long int fb = this->fatorBalanceamento();
    long int fbDireita = this->direita->fatorBalanceamento();

    Node *resultado = this;

    if (fb == +2)
    {
      if (fbDireita >= 0)
      {
        /*rotacao_para_esquerda*/
      }
      else
      {
        /*rotacao_dupla_esquerda*/
      }
    }

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
