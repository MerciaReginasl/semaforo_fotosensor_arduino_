         +--------------------+
         |    Usuário do       |
         |     Semáforo        |
         +--------------------+
                  |
                  |
         +--------------------+
         | Sistema de Controle |
         |      do Semáforo    |
         +--------------------+
        /         |             \
       /          |              \
+--------------------+  +--------------------+  +--------------------+
| Detectar Nível de  |  | Ativar Sinal de    |  | Desativar Modo     |
| Luz                |  | Atenção            |  | Noturno            |
+--------------------+  +--------------------+  +--------------------+
       \          |              /              /
        \         |             /              /
         +--------------------+              /
         |     Sensor de      |             /
         |    Luminosidade    |            /
         +--------------------+           /
                  |                   /
                  |                  /
                  |                 /
                  +-----------------+


                  
Main
directionalAssociation Pessoa
association ContaBancaria
---
- pessoas: Pessoa[]
---
+ main(): int
---

ContaBancaria
---
- static PROX_NUM_CONTA: int
- static TOTAL_DE_CONTAS: int
- proprietario: Pessoa
- numero: int
- saldo: float
---
+ ContaBancaria(proprietario: Pessoa)
+ ~ContaBancaria(): void
+ static visualizarTotalDeContas(): int
+ sacar(valor: float): void
+ depositar(valor: float): void
+ visualizar(): void
+ getProprietario(): Pessoa
+ getNumero(): int
+ getSaldo(): float
---

Pessoa
composes ContaBancaria
---
- contasBancaria: ContaBancaria
---
+ adicionarContaBancaria(): void
---
