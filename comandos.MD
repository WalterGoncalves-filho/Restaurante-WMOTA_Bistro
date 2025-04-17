# Comandos

## Criando Ambiente .Bat
<!-- Este comando executa o script build_projeto.bat que prepara o ambiente de build do projeto, definindo variáveis e organizando dependências necessárias. -->
     .\build_projeto.bat

## Criando Ambiente virtual Build
<!-- Este comando configura o ambiente virtual de build usando CMake. O parâmetro -S define o diretório de origem, -B define o diretório de build e o parâmetro -G seleciona o gerador de Makefiles (neste caso, "MinGW Makefiles"). -->
     cmake -S . -B build -G "MinGW Makefiles"

## Pega todas as informações e gera um unico executavel
<!-- Este comando coleta todas as informações de configuração e compila o projeto, gerando um único executável a partir do ambiente configurado. -->
     cmake --build build
