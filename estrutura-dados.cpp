#include <bits/stdc++.h>
using namespace std;

// Site consultado: https://www.geeksforgeeks.org/data-structures/linked-list/?ref=lbp

class No
{
private:
  int dados;
  No *proximo;

public:
  // criação de um novo nó:
  // construtor
  No(int dados)
  {
    this->dados = dados;
    this->proximo = NULL;
  }
  // inserir informação na propriedade dados:
  void inserir_dados_no(int valor)
  {
    this->dados = valor;
  }
  // Pegar informação:
  int pegar_dados_no()
  {
    return dados;
  }
  // Inserir valor na propriedade próximo:
  void inserir_proximo_valor_no(No *proximo)
  {
    this->proximo = proximo;
  }
  // Pegar próximo nó:
  No *pegar_proximo_no()
  {
    return proximo;
  }
};

class Lista
{
private:
  No *cabeca = NULL;
  int tamanho = 0;

public:
  // Criar nova lista:
  // construtor
  Lista(int dados)
  {
    No *nova_cabeca = new No(dados);
    this->cabeca = nova_cabeca;
    this->tamanho++;
  };

  // default constructor para lista:
  Lista() {}

  void inserir_no_inicio(No *referencia_cabeca, int novos_dados)
  {
    No *novo_no = new No(novos_dados);
    novo_no->inserir_dados_no(novos_dados);
    novo_no->inserir_proximo_valor_no(referencia_cabeca);
    referencia_cabeca = novo_no;
    this->tamanho++;
  };

  void inserir_na_posicao(unsigned posicao, int novos_dados)
  {
    No *novo_no = new No(novos_dados);
    No *armazenador = this->cabeca;
    No *anterior;
    if (posicao == 0)
    {
      this->inserir_no_inicio(novo_no, novos_dados);
      return;
    }
    int i = 0;
    while (i != posicao && armazenador != NULL)
    {
      i++;
      anterior = armazenador;
      armazenador = armazenador->pegar_proximo_no();
    }
    if (i != posicao)
    {
      cout << "Nó não pode ser inserido.\n";
    }
    anterior->inserir_proximo_valor_no(novo_no);
    novo_no->inserir_proximo_valor_no(armazenador);
    this->tamanho++;
    return;
  };

  void inserir_no_final(int novos_dados)
  {
    No *novo_no = new No(novos_dados);
    No *armazenador = cabeca;
    if (armazenador == NULL)
    {
      this->cabeca = novo_no;
      return;
    }
    while (armazenador->pegar_proximo_no() != NULL)
    {
      armazenador = armazenador->pegar_proximo_no();
    }
    armazenador->inserir_proximo_valor_no(novo_no);
    this->tamanho++;
    return;
  }

  void retirar_no(int valor)
  {
    No *armazenador = cabeca;
    No *anterior;
    if (armazenador == NULL)
      return;
    if (armazenador != NULL && armazenador->pegar_dados_no() == valor)
    {
      this->cabeca = armazenador->pegar_proximo_no();
      free(armazenador);
      this->tamanho--;
      return;
    }
    while (armazenador != NULL && armazenador->pegar_dados_no() != valor)
    {
      anterior = armazenador;
      armazenador = armazenador->pegar_proximo_no();
    }
    armazenador->inserir_proximo_valor_no(anterior->pegar_proximo_no());
    free(armazenador);
    this->tamanho--;
    return;
  }

  void retirar_no_na_posicao(int posicao)
  {
    No *armazenador = this->cabeca;
    No *anterior;
    int i = 0;
    if (armazenador != NULL && i == posicao)
    {
      this->cabeca = armazenador->pegar_proximo_no();
      free(armazenador);
      this->tamanho--;
      return;
    }
    while (armazenador != NULL && i != posicao)
    {
      anterior = armazenador;
      armazenador = armazenador->pegar_proximo_no();
    }
  }

  No *retirar_primeiro()
  {
    No *armazenador = this->cabeca;
    if (armazenador == NULL)
    {
      cout << "Nó não pode ser retirado.\n";
    }
    this->cabeca = armazenador->pegar_proximo_no();
    this->tamanho--;
    return armazenador;
  }

  No *remover_ultimo_no()
  {
    No *armazenador = this->cabeca;
    No *anterior;
    if (armazenador == NULL)
    {
      cout << "Nó não pode ser retirado.\n";
    }
    while (armazenador->pegar_proximo_no() != NULL)
    {
      anterior = armazenador;
      armazenador = armazenador->pegar_proximo_no();
    }
    anterior->inserir_proximo_valor_no(NULL);
    this->tamanho--;
    return armazenador;
  }

  No *pega_primeiro_no()
  {
    if (this->cabeca == NULL)
      cout << "Nó não pode ser pego.\n";
    return this->cabeca;
  }

  No *pega_ultimo_no()
  {
    No *armazenador = this->cabeca;
    if (this->cabeca == NULL)
      cout << "Nó não pode ser pego.\n";
    while (armazenador->pegar_proximo_no() != NULL)
    {
      armazenador = armazenador->pegar_proximo_no();
    }
    return armazenador;
  }
};

class Fila
{
private:
  Lista *fila = NULL;
  int tamanho = 0;

public:
  Fila(int dados)
  {
    Lista *nova_lista = new Lista(dados);
    this->fila = nova_lista;
  }

  // Default constructor para fila:
  Fila()
  {
    Lista *nova_lista = new Lista;
    this->fila = nova_lista;
  }

  void acrescentar_fila(int dados)
  {
    this->fila->inserir_no_final(dados);
  }

  No *retira_no_fila()
  {
    return this->fila->retirar_primeiro();
  }

  No *pega_primeiro_no_fila()
  {
    return this->fila->pega_primeiro_no();
  }
};

class Pilha
{
private:
  Lista *pilha = NULL;
  int tamanho = 0;

public:
  Pilha(int data)
  {
    Lista *nova_lista = new Lista(data);
    this->pilha = nova_lista;
  }

  // Default constructor para pilha:
  Pilha()
  {
    Lista *nova_lista = new Lista;
    this->pilha = nova_lista;
  }

  void acrescentar_fila(int dados)
  {
    this->pilha->inserir_no_final(dados);
  }

  No *pegar_ultimo_no_pilha()
  {
    return this->pilha->remover_ultimo_no();
  }

  No *verificar_ultimo_no_pilha()
  {
    return this->pilha->pega_ultimo_no();
  }
};

int main()
{
  Lista *lista = new Lista;
  Fila *fila = new Fila;
  Pilha *pilha = new Pilha;

  lista->inserir_no_final(3);
  cout << "\nLista: " << lista->pega_ultimo_no()->pegar_dados_no();
}
