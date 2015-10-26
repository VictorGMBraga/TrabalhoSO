UNIVERSIDADE DE BRAS�LIA
DEPARTAMENTO DE CI�NCIA DA COMPUTA��O
SISTEMAS OPERACIONAIS - 02/2015
PROFESSORA: ALBA MELO
ALUNO: VICTOR GUERESI DE MELLO BRAGA - 10/0126481

--= Gerente de execu��o postergada de processos =--

[ARQUIVOS]

-> servidor.cpp :
    Servidor de execu��o postergada de processos.
    Utiliza uma fila de mensagens para receber comandos dos outros execut�veis.
    Guarda processos postergados numa estrutura do tipo Vector.
    Guarda processos em execu��o em uma estrutura do tipo Queue.

    Compilar usando: "g++ servidor.cpp -o servidor"
    Executar usando: "./servidor &"

-> executa_postergado.cpp:
    Manda ao servidor comandos para executar processos via fila de mensagens.
    Mostra o job id, caminho do execut�vel, hora da execu��o e n�mero de execu��es que ser�o realizadas.

    Compilar usando: "g++ executa_postergado.cpp -o executa_postergado"
    Executar usando: "./executa_postergado <hora:min> <vezes> <arq_exec>"
    * Favor usar o caminho absoluto em <arq_exec>

-> shutdown_postergado.cpp
    Manda uma mensagem para o servidor parar a execu��o e mostrar o relat�rio de processos
    executados e que n�o ser�o executados.

    Compilar usando: "g++ shutdown_postergado.cpp -o shutdown_postergado"
    Executar usando: "./shutdown_postergado"

-> lista_postergados.cpp
    Manda uma mensagem para o servidor listar os processos postergados ainda n�o executados.

    Compilar usando: "g++ lista_postergados.cpp -o lista_postergados"
    Executar usando: "./lista_postergados"

-> remove_postergado.cpp
    Manda uma mensagem com um id de um job para que o servidor remova esse job da lista de postergados.

    Compilar usando: "g++ remove_postergado.cpp -o remove_postergado"
    Executar usando: "./remove_postergado <job_id>"

-> hello.cpp
    Hello World para uso com o servidor de execu��o postergada.

    Compilar usando: "g++ hello.cpp -o hello"
    Utilizar como argumento para o "executa_postergado"
