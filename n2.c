#include <stdint.h>
#include <stdio.h>

typedef struct aluno {
  char nome[100];
  int matricula;
  int carga_horaria_total;
  int quantidade_de_atividade;
} Aluno;

typedef struct atividade {
  int matricula;
  int numero_registro;
  int grupo_atividade;
  char descricao_atividade[100];
  int status;
  int carga_horaria_considerada;
} Atividade;

Aluno alunos[100];
int index_aluno = 0;

Atividade atividades[1000];
int index_atividade = 1;

int cadastrar_aluno() {
  Aluno new_aluno;
  int escolha;

  printf("digite o nome: ");
  scanf("%s", new_aluno.nome);

  printf("digite a matricula: ");
  scanf("%i", &new_aluno.matricula);

  printf("digite a carga horaria: ");
  scanf("%i", &new_aluno.carga_horaria_total);

  printf("digite a quantidade de atividades: ");
  scanf("%i", &new_aluno.quantidade_de_atividade);

  printf("quer salvar (1 ou 0): ");
  scanf("%i", &escolha);

  if (escolha == 1) {
    alunos[index_aluno] = new_aluno;
    index_aluno++;
    printf("salvo com sucesso\n");
  }

  return 0;
}

int cadastrar_atividade() {
  Atividade new_ativade;
  int escolha;

  printf("digite a matricula: ");
  scanf("%i", &new_ativade.matricula);

  new_ativade.numero_registro = index_atividade;

  printf("digite o grupo atividade: ");
  scanf("%i", &new_ativade.grupo_atividade);

  printf("digite a descrição: ");
  scanf("%s", new_ativade.descricao_atividade);

  printf("digite a carga horaria considerada: ");
  scanf("%i", &new_ativade.carga_horaria_considerada);

  printf("quer salvar (S ou N): ");
  scanf("%i", &escolha);

  if (escolha == 1) {
    atividades[index_atividade-1] = new_ativade;
    index_atividade++;
    printf("salvo com sucesso\n");
  }

  return 0;
}

int pesquisar_atividades_por_matricula_aluno() {
  int matricula;
  printf("Qual a matricula: ");
  scanf("%i", &matricula);

  for (int i = 0; i < index_atividade - 1; i++) {
    if (atividades[i].matricula == matricula) {
      printf("\nCarga horaria considerada: %i\n", atividades[i].carga_horaria_considerada);
      printf("Grupo atividade: %i\n", atividades[i].grupo_atividade);
      printf("Numero de registro: %i\n", atividades[i].numero_registro);
      printf("Status: %i\n", atividades[i].status);
      printf("Descrição: %s\n\n", atividades[i].descricao_atividade);
    }
  }
  return 0;
}
int alterar_status_atividade() {
  int matricula, numero_registro, escolha;

  printf("Qual a matricula: ");
  scanf("%i", &matricula);


  printf("Qual o numero de serie: ");
  scanf("%i", &numero_registro);

  for (int i = 0; i < index_atividade - 1; i++) {
    if (atividades[i].numero_registro == numero_registro) {
      if (atividades[i].matricula == matricula) {
        printf("Escolha '1' para aprovar ou '0' para reprovar: ");
        scanf("%i", &escolha);

        atividades[i].status = escolha;
        
      } else {
        printf("Não tem nenhum com esse numero de registro");
      }
    } else {
      printf("Não tem nenhum com esse numero de registro");
    }
  }

  return 0;
}

int mostrar_carga_horario() {

  for (int i_aluno = 0; i_aluno < index_aluno; i_aluno++) {
    printf("\nNome: %s\n", alunos[i_aluno].nome);
    printf("Matricula: %i\n", alunos[i_aluno].matricula);
    printf("Carga horaria total: %i\n\n", alunos[i_aluno].carga_horaria_total);
  }
  return 0;
}
int menu() {
  int escolha;
  while (1) {
    printf("1 - Cadastrar aluno\n");
    printf("2 - Cadastrar atividade\n");
    printf("3 - Pesquisar atividades complementares do aluno\n");
    printf("4 - Alterar status da atividade complementar\n");
    printf("5 - Mostrar a carga horaria total de todos os alunos\n");

    printf("digite aqui: ");
    scanf("%i", &escolha);

    switch (escolha) {
    case 1:
      cadastrar_aluno();
      break;
    case 2:
      cadastrar_atividade();
      break;

    case 3:
      pesquisar_atividades_por_matricula_aluno();
      break;

    case 4:
      alterar_status_atividade();
      break;

    case 5:
      mostrar_carga_horario();
      break;
    }
  }
}
int main() {

  menu();

  return 0;
}