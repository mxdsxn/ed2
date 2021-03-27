#include <iostream>
#include <string.h>

#pragma once

using namespace std;

class NodeString
{
public:
  char *info;
  long int altura = 0;
  NodeString *esquerda = nullptr, *direita = nullptr;

  NodeString(char *novaInformacao, NodeString *novoEsquerda, NodeString *novoDireita)
  {
    setInfo(novaInformacao);
    setEsquerda(novoEsquerda);
    setDireita(novoDireita);
  }

  NodeString(char *novaInformacao)
  {
    setInfo(novaInformacao);
  }

  ~NodeString()
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

  void setInfo(char *novaInformacao)
  {
    this->info = novaInformacao;
  }

  void setEsquerda(NodeString *novoEsquerda)
  {
    this->esquerda = novoEsquerda;
    this->atualizaAltura();
  }

  void setEsquerda(char *novaInformacao)
  {
    this->setEsquerda(new NodeString(novaInformacao));
  }

  void setDireita(NodeString *novoDireita)
  {
    this->direita = novoDireita;
    this->atualizaAltura();
  }

  void setDireita(char *novaInformacao)
  {
    this->setDireita(new NodeString(novaInformacao));
  }

  NodeString *inserir(char *novaInformacao)
  {
    NodeString *resultado = nullptr;
    if (this == nullptr)
    {
      NodeString *resultado = new NodeString(novaInformacao);
      return resultado;
    }

    if (strcmp(novaInformacao, this->info) < 0)
    {
      NodeString *aux = this->esquerda->inserir(novaInformacao);
      this->setEsquerda(aux);
      resultado = this->verificaFatorBalanceamentoRotacaoDireita();
    }
    else
    {
      NodeString *aux = this->direita->inserir(novaInformacao);
      this->setDireita(aux);
      resultado = this->verificaFatorBalanceamentoRotacaoEsquerda();
    }
    return resultado;
  }

  NodeString *remover(char *removeInfo)
  {
    NodeString *resultado = this;

    if (this)
    {
      if (strcmp(removeInfo, resultado->info) < 0)
      {
        resultado->setEsquerda(resultado->esquerda->remover(removeInfo));
        resultado = resultado->verificaFatorBalanceamentoRotacaoEsquerda();
      }
      else if (strcmp(removeInfo, resultado->info) > 0)
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
          NodeString *tmp = resultado->direita;
          delete resultado;
          resultado = tmp;
        }
        else if (resultado->direita == nullptr)
        {
          NodeString *tmp = resultado->esquerda;
          delete resultado;
          resultado = tmp;
        }
        else
        {

          NodeString *tmp = resultado->esquerda;
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

  bool pertence(char *informacaoParaEncontrar)
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

  char *buscar(char *info)
  {
    if (this == nullptr)
    {
      return NULL;
    }
    else if (info == this->info)
    {
      return this->info;
    }

    if (strcmp(info, this->info) < 0)
    {
      return (this->esquerda)->buscar(info);
    }
    else if (strcmp(info, this->info) > 0)
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

  NodeString *verificaFatorBalanceamentoRotacaoDireita()
  {
    long int fb = this->fatorBalanceamento();
    long int fbEsquerda = this->esquerda->fatorBalanceamento();

    NodeString *resultado = this;

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

  NodeString *verificaFatorBalanceamentoRotacaoEsquerda()
  {
    long int fb = this->fatorBalanceamento();
    long int fbDireita = this->direita->fatorBalanceamento();

    NodeString *resultado = this;

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

  NodeString *rotacaoEsquerda()
  {
    NodeString *root = this->direita;
    this->setDireita(root->esquerda);

    NodeString *esquerdaRoot = this;
    root->setEsquerda(esquerdaRoot);

    return root;
  }

  NodeString *rotacaoDireita()
  {
    NodeString *root = this->esquerda;
    this->setEsquerda(root->direita);

    NodeString *direitaRoot = this;
    root->setDireita(direitaRoot);

    return root;
  }

  NodeString *rotacaoDuplaEsquerda()
  {
    NodeString *resultado = this;
    resultado->setDireita(resultado->direita->rotacaoDireita());
    resultado = resultado->rotacaoEsquerda();

    return resultado;
  }

  NodeString *rotacaoDuplaDireita()
  {
    NodeString *resultado = this;
    resultado->setEsquerda(resultado->esquerda->rotacaoEsquerda());
    resultado = resultado->rotacaoDireita();

    return resultado;
  }

  NodeString *arvoreEspelho()
  {
    NodeString *noEspelhado = nullptr;
    if (this)
    {
      noEspelhado = new NodeString(this);

      noEspelhado->inverter();

      noEspelhado->espelhar();
    }
    return noEspelhado;
  }

  void inverter()
  {
    if (this)
    {
      NodeString *tmpNode = this->esquerda;

      this->setEsquerda(this->direita);
      this->setDireita(tmpNode);
    }
  }

private:
  NodeString(NodeString *outroNo)
  {
    setInfo(outroNo->info);
    setEsquerda(outroNo->esquerda);
    setDireita(outroNo->direita);
  }

  void espelhar()
  {
    if (this)
    {
      NodeString *tmpEsq = this->esquerda;
      NodeString *tmpDir = this->direita;

      this->setEsquerda(tmpEsq->arvoreEspelho());
      this->setDireita(tmpDir->arvoreEspelho());
    }
  }
};
