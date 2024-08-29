# ☯ Apresentação

![Banner do projeto](presentation/banner.png)

# 🍒 Badges

![badge top language](https://img.shields.io/github/languages/top/emilsonfilho/uno_c?style=flat-square&color=%23f8da27) 
![badge license](https://img.shields.io/github/license/emilsonfilho/uno_c?style=flat-square&color=%23ed1c24)
![badge tamanho do repositório](https://img.shields.io/github/repo-size/emilsonfilho/uno_c?style=flat-square&color=black)

# 🚎 Índice
* Apresentação
* Badges
* Descrição do Projeto
* Status do Projeto
* Funcionalidades
* Demonstrações

# 🎹 Descrição do Projeto

Este repositório contém a implementação de um jogo de Uno em linguagem C, desenvolvido como parte de um projeto acadêmico. O jogo simula as regras clássicas do Uno, permitindo que os jogadores interajam com o oponente (CPU) através de um terminal.

# 🎣 Status do Projeto

🍃 *Projeto sendo finalizado* 🍃

Contribuições construtivas sempre serão bem-vindas!

# 🌉 Como instalar?
1. Clone ou baixe o repositório: `git clone https://github.com/emilsonfilho/uno_c.git`
2. Abra a pasta do projeto:  `cd uno_c`
3. Dê permissão para o arquivo _builder_: `chmod +x ./build.sh`
4. Execute o arquivo: `./build.sh`
5. Abra o executável: `bin/exec`

# 🛬 De dev para dev
1. A pasta _bin_ contém todos os objetos `.o` dos arquivos do sistema
2. A pasta _src_ contém todos os arquivos de código `.c` do projeto. Todos os códigos são colocados em arquivos para cada função. 
3. A pasta _include_ contém todos os arquivos de cabeçalho `.h` do projeto. Todas as documentações, definições e _imports_ são feitos nesses arquivos.
4. As pastas _src_ e _include_ tem hierarquia de pastas semelhantes, sendo _include_ a pasta com mais arquivos, sendo alguns apenas de declarações de constantes para o sistema

## 🔦 Hierarquia de Pastas
1. `configs/`
    - Contém todos os aarquivos de configurações gerais do sistema, tais como constantes e variáveis globais 
2. `inits/`
    - Contém todos os arquivos relacionados à inicialização de várias partes do sistema
3. `mechanics/`
    - Contém todos os arquivos relacionados à maneira como o jogo se comporta em conjunto com suas regras
4. `prints/`
    - Contém todos os arquivos que servem para mostrar algo ao usuário, seja sua mão, seja uma mensagem em negrito
5. `screens/`
    - Contém todos os arquivos que exibem determinadas telas
6. `tests/`
    - Contém todos os arquivos relacionados aos testes feitos
7. `updates/`
    - Contém todos os arquivos que atualizam pelo menos uma parte do sistema
8. `utils/`
    - Contém todos os arquivos de micro-serviços do projeto, seja uma validação, seja uma verificação


# 📥 Funcionalidades

* `Funcionalidade 1`: Construção de jogo e cenário
* `Funcionalidade 2`: Fluxo de telas
* `Funcionalidade 3`: Jogar cartas
* `Funcionalidade 4`: Animações 
* `Funcionalidade 5`: Puxar cartas
* `Funcionalidade 6`: Começar uma nova partida
* `Funcionalidade 7`: Vencer ou ser vencido haha

Made with ❤️ by [Emilson Filho](https://github.com/emilsonfilho)
