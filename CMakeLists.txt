# Versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(Restaurante)

# Versão do padrão da linguagem C
set(CMAKE_C_STANDARD 11)

# Adiciona a pasta src como lugar onde estão os .h
include_directories(src)

# Cria o executável restaurante a partir dos arquivos .c
add_executable(restaurante
    src/main.cpp
    src/reservas.cpp
)
