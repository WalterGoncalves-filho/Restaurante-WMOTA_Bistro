@echo off
echo ====================================
echo Compilando RestauranteWMotaBistro...
echo ====================================

:: Passo 1: sincronizar o CMakeLists.txt
python sync_cmake.py

:: Passo 2: apagar build antigo
echo Limpando build antigo...
rmdir /s /q dist\build

:: Passo 3: recriar a pasta de build
mkdir dist\build

:: Passo 4: configurar o CMake
cmake -S dist -B dist\build -G "MinGW Makefiles"

:: Passo 5: compilar
cmake --build dist\build

echo.
echo ====================================
echo ✅ Build finalizado!
echo Executável gerado em:
echo   - dist\build\
echo   - raiz do projeto\
echo   - APP\
echo ====================================
pause
