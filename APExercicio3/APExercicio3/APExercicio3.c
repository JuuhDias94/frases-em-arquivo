#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para trabalhar com texto
#include <locale.h> //para poder usar palavras com acentua��o

int main() //in�cio da fun��o main
{
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentua��o

	FILE* arquivoUsuario; //ponteiro de arquivo
	char nomeArquivo[20]; //vari�vel do tipo caractere
	char fraseArquivo[50]; //vari�vel do tipo caractere
	int a; //vari�vel do tipo inteiro
	errno_t err; //para verificar se h� erro no fopen

	//pede para digitar nome desejado para o arquivo:
	printf("Digite o nome do arquivo: ");
	gets_s(nomeArquivo); //grava nome digitado
	fflush(stdin); //limpa buffer de teclado
	strcat_s(nomeArquivo, 50 - strlen(nomeArquivo) - 1, ".txt"); //colocando .txt no final do nome digitado para o arquivo

	//imprime na tela o nome digitado para o arquivo:
	printf("\nO nome escolhido para o arquivo �: %s\n\n", nomeArquivo);

	//verifica se o arquivo foi criado:
	err = fopen_s(&arquivoUsuario, nomeArquivo, "w+");
	if (err == 0)
	{
		printf("Arquivo criado com sucesso!\n\n");
	}
	else
	{
		printf("Erro na cria��o do arquivo!\n\n");
		exit(1);
	}

	//la�o de repeti��o para pedir 5 frases:
	for (a = 0; a < 5; a++) {
		printf("Digite uma frase com no m�ximo 50 caracteres: \n");
		fgets(fraseArquivo, 49, stdin);
		fflush(stdin);
		_strupr_s(fraseArquivo); //transforma frase em mai�sculo
		fprintf(arquivoUsuario, "%d - ", strlen(fraseArquivo), fraseArquivo);
		fputs(fraseArquivo, arquivoUsuario); //grava frase no arquivo
		//verifica o tamanho do texto a ser lido:
	}

	//imprime na tela que os dados foram gravados:
	printf(" \nDados gravados com sucesso!\n\n");

	//verifica se o arquivo foi fechado ou n�o:
	if (arquivoUsuario) {
		err = fclose(arquivoUsuario);
		if (err == 0) {
			printf("Arquivo fechado com sucesso!\n\n");
		}
		else {
			printf("O arquivo n�o foi fechado!\n\n");
		}
	}

	//abre arquivo para leitura:
	err = fopen_s(&arquivoUsuario, nomeArquivo, "r");

	//verifica se o arquivo foi aberto:
	if (arquivoUsuario == NULL) {
		printf("O arquivo n�o foi aberto!\n\n");
		getchar();
		exit(1);
	}
	else {
		printf("Lendo o arquivo...\n\n");
		printf("Frases digitadas:\n\n");
	}

	//imprime as frases na tela:
	while (fgets(fraseArquivo, 49, arquivoUsuario) != NULL) {
		printf("%s\n", fraseArquivo);
	}

	//fecha arquivo:
	fclose(arquivoUsuario);

	system("pause");
	return 0;
} //fim da fun��o main
