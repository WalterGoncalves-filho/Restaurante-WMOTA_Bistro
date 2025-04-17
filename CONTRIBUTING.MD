# Guia de Contribuição

Este documento descreve as diretrizes e processos que nossa equipe utiliza para garantir um fluxo de trabalho organizado e colaborativo.

## 1. Fluxo de Trabalho com GitFlow

Utilizamos o **GitFlow** como metodologia de desenvolvimento. A estrutura dos branches é a seguinte:

- **main:** Branch principal, sempre com o código em produção.
- **develop:** Branch de integração, onde novas funcionalidades e correções são mescladas antes de serem lançadas.
- **feature:** Branches temporárias para o desenvolvimento de novas funcionalidades. Devem ser criadas a partir de `develop` e, após finalizadas, mescladas de volta em `develop`.
- **hotfix:** Branches para correções emergenciais em `main`. Devem ser criadas a partir de `main` e, depois de finalizadas, mescladas em `main` e `develop`.
- **release:** Branches para preparar uma nova versão. São criadas a partir de `develop` e, quando finalizadas, mescladas em `main` e `develop`.

## 2. Pull Requests (PRs)

- **Revisão:**  
  Cada Pull Request deve ser submetido para revisão por um ou mais revisores designados.
  
- **Descrição do PR:**  
  Ao abrir um PR, inclua:
  - Um resumo breve das mudanças.
  - Referências a issues, se aplicável (por exemplo, "Fixes #123").
  - Uma breve descrição do impacto e testes realizados, se houver.

**Exemplo simples de descrição:**

> **Resumo:**  
> Adiciona funcionalidade X para melhorar Y.
>
> **Detalhes:**  
> - Implementa o novo método Z.
> - Corrige bug relacionado a A.
>
> **Referência:**  
> Fixes #123

## 3. Convenção de Mensagens de Commit

Para manter um histórico de commits claro e consistente, utilizamos uma convenção simples baseada em prefixos. Por favor, inicie cada mensagem de commit com um dos seguintes prefixos:

- **feat:** para novos recursos.
- **fix:** para correções de bugs.
- **docs:** para alterações na documentação.
- **style:** para ajustes de formatação e código sem alterações lógicas.
- **refactor:** para refatoração de código.
- **chore:** para tarefas de manutenção e configurações.

**Exemplos:**

- `feat: adiciona suporte a nova API de faturamento`
- `fix: corrige erro de validação no formulário de login`
- `docs: atualiza README com instruções de instalação`

## 4. Testes e Integração Contínua

Atualmente, não possuímos uma suíte de testes ou integração contínua configurada. No entanto, ao contribuir, **garanta que o código esteja funcionando** e siga os padrões de qualidade definidos pela equipe.

## 5. Documentação

- A documentação do projeto pode ser feita utilizando ferramentas de IA e está disponível na [Wiki do Projeto](https://github.com/SupreLogic/zfmpro/wiki) (ou por meio de outro canal interno).
- Caso você adicione ou modifique uma funcionalidade, atualize a documentação correspondente para manter tudo sincronizado.

## 6. Reportando Problemas e Solicitando Funcionalidades

- **Issues:**  
  Para reportar bugs ou sugerir novas funcionalidades, abra uma issue no GitHub.
- **Comunicação:**  
  Além disso, informe a equipe via reuniões presenciais ou chamadas remotas para discutir problemas críticos ou novas ideias.

## 7. Ferramentas e Recursos de Aprendizado

- **Chat do ChatGPT:**  
  Temos uma licença OpenAI do ChatGPT com chats específicos para o projeto. Novos membros (estagiários) podem utilizar esse recurso para acelerar seu aprendizado.
- **Documentação Interna:**  
  Consulte os documentos e guias disponíveis na Wiki.

## 8. Outras Considerações

**Padrão de Código:**  
 - Siga os padrões de código do Python (PEP8) para manter o código limpo e legível.
 - Utilize palavras em Português para variáveis, métodos, classes, declarações etc...
 - Utilizar partials para todas as páginas HTML.
 - Urls com palavras compostas utilize "-" (Hífen), e para o nome utilize "_" (sublinhado/underscore). Ex: path('cadastro-clientes', name='cadastro_de_clientes')

**Padrão de Libs:**
 - Javascript: Axios para requisições, priorizar as libs do template como: SweetAlert para alertas, DataTables para tabelas, Inputmask para máscaras, Daterangepicker para datas, Dropzone para upload de arquivos.
 - Python/Django: para APIs utilizar ModelViewSet.
  
**Revisões e Feedback:**  
  Esteja aberto a feedbacks durante as revisões de código para melhorar a qualidade e a consistência do projeto.