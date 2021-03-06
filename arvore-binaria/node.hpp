#include <iostream>
#pragma once

using namespace std;

template <typename TypeInfo>
class Node
{
private:
  TypeInfo info;
  Node *leftNode = nullptr, *rightNode = nullptr;

  void mirror()
  {
    if (this)
    {
      Node *tmpLeftNode = this->leftNode;
      Node *tmpRightNode = this->rightNode;

      this->setLeftNode(tmpLeftNode->mirrorTree());
      this->setRightNode(tmpRightNode->mirrorTree());
    }
  }

public:
  Node(TypeInfo newInfo, Node *newLeftNode, Node *newRightNode)
  {
    setInfo(newInfo);
    setLeftNode(newLeftNode);
    setRightNode(newRightNode);
  }

  Node(TypeInfo newInfo)
  {
    setInfo(newInfo);
  }

  Node(Node *otherNode)
  {
    setInfo(otherNode->getInfo());
    setLeftNode(otherNode->getLeftNode());
    setRightNode(otherNode->getRightNode());
  }

  ~Node()
  {
    if (this)
    {
      cout << "deleting: " << this->info << endl;

      cout << "deleting left Node:" << this->info << endl;
      delete this->leftNode;

      cout << "deleting right Node:" << this->info << endl;
      delete this->rightNode;
    }
  }

  void setInfo(TypeInfo newInfo)
  {
    this->info = newInfo;
  }

  void setLeftNode(Node *newLeftNode)
  {
    this->leftNode = newLeftNode;
  }

  void setLeftNode(TypeInfo newInfo)
  {
    this->setLeftNode(new Node(newInfo));
  }

  void setRightNode(Node *newRightNode)
  {
    this->rightNode = newRightNode;
  }

  void setRightNode(TypeInfo newInfo)
  {
    this->setRightNode(new Node(newInfo));
  }

  TypeInfo getInfo()
  {
    TypeInfo result = this->info;
    return result;
  }

  Node *getLeftNode()
  {
    Node *result = this->leftNode;
    return result;
  }

  Node *getRightNode()
  {
    Node *result = this->rightNode;
    return result;
  }

  void mark()
  {
    cout << "<";
    if (this)
    {
      cout << this->info;
      this->leftNode->mark();
      this->rightNode->mark();
    }
    cout << ">";
  }

  void preOrder()
  {
    if (this)
    {
      cout << this->info;
      this->leftNode->preOrder();
      this->rightNode->preOrder();
    }
  }

  void inOrder()
  {
    if (this)
    {
      this->leftNode->inOrder();
      cout << this->info;
      this->rightNode->inOrder();
    }
  }

  void posOrder()
  {
    if (this)
    {
      this->leftNode->posOrder();
      this->rightNode->posOrder();
      cout << this->info;
    }
  }

  bool belong(TypeInfo infoToFind)
  {
    if (this)
    {
      if (this->info == infoToFind)
      {
        return true;
      }
      bool infoInLeftNode = this->leftNode->belong(infoToFind);
      bool infoInRightNode = this->rightNode->belong(infoToFind);

      return (infoInLeftNode || infoInRightNode);
    }
    return false;
  }

  int totalNode()
  {
    if (this)
    {
      int totalLeft = this->leftNode->totalNode();
      int totalRight = this->rightNode->totalNode();
      return (1 + totalLeft + totalRight);
    }
    return 0;
  }

  int getLevel(bool root = true)
  {
    int level = (root ? 0 : 1);
    int leftLevel = 0, rightLevel = 0;

    if (this)
    {
      if (this->rightNode || this->leftNode)
      {
        if (this->leftNode)
          leftLevel = this->leftNode->getLevel(false);
        if (this->rightNode)
          rightLevel = this->rightNode->getLevel(false);

        level += (leftLevel >= rightLevel ? leftLevel : rightLevel);
      }
    }

    return level;
  }

  // EXERCICIO 6: GERAR ARVORE ESPELHO(TROCAR O NO DA DIREITA COM DA ESQUERDA E VICE-VERSA, ATE O NO MAIS BAIXO)
  Node *mirrorTree()
  {
    Node *nodeMirror = nullptr;
    if (this)
    {
      nodeMirror = new Node(this);

      nodeMirror->invert();

      nodeMirror->mirror();
    }
    return nodeMirror;
  }

  void invert()
  {
    if (this)
    {
      Node *tmpNode = this->leftNode;

      this->setLeftNode(this->rightNode);
      this->setRightNode(tmpNode);
    }
  }
};
