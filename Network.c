#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Programa desenvolvido como atividade integrada e complementar
//para o curso técnico em informática integrado ao ensino médio
//
//Ryan.trompetista@gmail.com
//20172290558




int settingsOfNetwork();
int toListProfiles();
int showPasswordProfile();
int dominio();
int main(){
	int escolha;

	char cmd[256];
	printf("Ola, ");
	fflush(stdin);
	sprintf(cmd, "hostname");
	system(cmd);
	printf("\n");

	printf("Escolha uma opcao:\n");
	printf("1)Listar Redes Salvas\n");
	printf("2)Listar Senha da Rede\n");
	printf("3)Configuracao de Rede\n");
	printf("4)Exibir Configuracoes de Dominio\n");
	fflush(stdin);
	scanf("%d", &escolha);
	fflush(stdin);

	switch (escolha)
	{
	case 1:
		fflush(stdin);
		printf("\n");

		return toListProfiles();
		break;
	case 2:
		fflush(stdin);
		printf("\n");

		return showPasswordProfile();
		break;
	case 3:
		fflush(stdin);
		printf("\n");

		return settingsOfNetwork();
		break;
	case 4:
		fflush(stdin);
		printf("\n");

		return dominio();
		break;
	default:
		fflush(stdin);
		printf("\n");
		printf("\n");
		printf("OBRIGATORIO*\n");
		return main();
	}
}

int toListProfiles()
{
	char cmd[256];

	sprintf(cmd, "Netsh wlan show profile");
	system(cmd);
	printf("\n");

	return main();
}
int showPasswordProfile()
{
	fflush(stdin);
	char rede[30];
	char cmd[256];

	printf("Digite o Nome da Rede:\n");
	gets(rede);
	fflush(stdin);

	sprintf(cmd, "Netsh wlan show profile %s key=clear", rede);
	system(cmd);
	printf("\n");

	return main();
}
int settingsOfNetwork()
{
	int escolha;

	printf("Escolha Uma Opcao:\n");
	printf("1)Listar o Endereco Fisico da Maquina\n");
	printf("2)Liberar IP\n");
	printf("3)Renovar IP\n");
	printf("4)Limpar o Cache de DNS da Maquina\n");
	printf("5)Voltar ao Menu Inicial\n");
	fflush(stdin);
	scanf("%d", &escolha);
	fflush(stdin);

	switch (escolha)
	{

	case 1:
		fflush(stdin);
		printf("\n");
		char cmd[256];

		sprintf(cmd, "ipconfig /all");
		system(cmd);
		printf("\n");

		return settingsOfNetwork();
		break;
	case 2:
		fflush(stdin);
		printf("\n");
		cmd[256];

		sprintf(cmd, "ipconfig /release");
		system(cmd);
		printf("\n");

		return settingsOfNetwork();
		break;
	case 3:
		fflush(stdin);
		printf("\n");
		cmd[256];

		sprintf(cmd, "ipconfig /renew");
		system(cmd);
		printf("\n");
		return settingsOfNetwork();
		break;
	case 4:
		fflush(stdin);
		printf("\n");
		cmd[256];

		sprintf(cmd, "ipconfig /flushdns");
		system(cmd);
		printf("\n");

		return settingsOfNetwork();
		break;
	case 5:

		fflush(stdin);
		printf("\n");
		return main();

	default:
		fflush(stdin);
		printf("\n");
		printf("\n");
		printf("OBRIGATORIO*\n");
		return settingsOfNetwork();
	}
}
int dominio()
{
	int escolha;

	printf("Escolha Uma Opcao:\n");
	printf("1)Exibir os DNS do Dominio\n");
	printf("2)Mostrar os Servidores MX do Dominio\n");
	printf("3)Mostrar a Configuracao SPF do Dominio\n");
	printf("4)Voltar ao Menu inicial\n");

	fflush(stdin);
	scanf("%d", &escolha);
	fflush(stdin);

	switch (escolha)
	{
	case 1:
		fflush(stdin);
		char dominioz[30];
		char cmd[256];

		printf("Digite o Nome do Dominio:\n");
		gets(dominioz);
		fflush(stdin);

		sprintf(cmd, "nslookup -q=ns %s", dominioz);
		system(cmd);
		printf("\n");

		return dominio();
		break;
	case 2:
		if (escolha == 2)
		{
			fflush(stdin);
			char dominioz[30];
			char cmd[256];

			printf("Digite o Nome do Dominio:\n");
			gets(dominioz);
			fflush(stdin);

			sprintf(cmd, "nslookup -q=mx %s", dominioz);
			system(cmd);
			printf("\n");

			return dominio();
			break;
		case 3:
			fflush(stdin);
			dominioz[30];
			cmd[256];

			printf("Digite o Nome do Dominio:\n");
			gets(dominioz);
			fflush(stdin);

			sprintf(cmd, "nslookup -q=txt dominio.com.br %s", dominioz);
			system(cmd);
			printf("\n");

			return dominio();
			break;
		case 4:
			fflush(stdin);
			printf("\n");
			return main();
			break;
		default:
			fflush(stdin);
			printf("\n");
			printf("\n");
			printf("OBRIGATORIO*\n");
			return dominio();
		}
	}
}
