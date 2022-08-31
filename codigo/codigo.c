#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"pt_br"); // FAZ COM QUE O PROGRAMA ACEITE ACENTUA��ES.
	int i,a; //CONTADOR (CONTROLE) PARA OS COMANDOS FOR;
	int linha_sorteada, tam_palavra, tentativa; // COMPLEMENTO
	char palavra[18]; // PALAVRA SORTEADA
	char resposta [18], erros[6];
	char letra, erro, repet, nao_tem, tem;
	char palavras[1800]; // MATRIZ UNIDIMENSIONAL (VETOR)

	do   //FAZ ENQUANTO O QUE ESTIVER DENTRO WHILE FOR VERDADEIRO OU 1.
	{
		system("cls");
		FILE *p;    
		p=fopen("database.txt","r");
		if(p==NULL)         //RETORNA A CONSTANTE NULL EM CASO DE ERRO DA ABERTURA DO ARQUIVO.
		{
			printf("NAO FOI POSSIVEL ABRIR O ARQUIVO."); // INFORMA SE HOUVE ERRO NA ABERTURA DO ARQUIVO.
			exit(0); //FINALIZA O PROGRAMA IMEDIATAMENTE SE HOUVE ERRO NA ABERTURA DO ARQUIVO.
		}
		srand(time(NULL)); //ALTERA A SEMENTE DA FUN��O RAND, FAZ COM QUE A PALAVRA SORTEADA SEJA MAIS ALEATORIA POSSIVEL.
		linha_sorteada=(rand()%100); //SORTEIA A LINHA DA PALAVRA CONTIDA NO ARQUIVO.
		for(i=0;i<linha_sorteada;i++)
		{
			fscanf(p,"%s",palavra); // L� DO ARQUIVO A PALAVRA NA LINHA SORTEADA;
		}
		
		tam_palavra=strlen(palavra); // TAM_PALAVRA RECEBE O TAMANHA DA PALAVRA SORTEADA POR MEIO DA FUN��O STRLEN.
		
		//printf("%s\n",palavra); // EXCLUSIVO PARA A EQUIPE, MOSTRA A PALAVRA SORTEADA IMEDIATAMENTE PARA MANUTEN��O OU TESTES DO PROGRAMA.

		for(i=0;palavra[i] != '\0';i++)
		{
			resposta[i]='_';  // FAZ COM QUE A PALAVRA SORTEADA INICIE ESCONDIA PELO SIMBOLO '_' (UNDERLINE).
				
			if(palavra[i]=='-')  //CASO SEJA UMA PALAVRA COM HIF�N, J� MOSTRAR� O MESMO. 
				resposta[i]='-';
			
			printf("%c ",resposta[i]); // MOSTRA NA TELA A QUANTIDADE DE LETRAS QUE A PALAVRA SORTEADA TEM.
		}
		tentativa=0; // ATRIBUI��O.
		nao_tem='N'; // ATRIBUI��O.
		a=0;//USADO FUTURAMENTE PARA O CONTROLE DE ERROS.
		for(i=0;i<6;i++) // INICIALIZA TODOS OS ERROS SEM LETRAS, SOMENTE 6 ERROS POIS S� A 6 CHANCES.
			erros[i]= ' ';
		
		
		//IN�CIO CORA��O DO PROGRAMA.
		while(tentativa<6 && nao_tem == 'N'){ 
	
			printf("\nCHANCES: %d",6-tentativa);  // INFORMA AO USU�RIA SUAS CHANCES ATUAL.
			printf("\nDIGITE UMA LETRA: "); // SOLICITA O USU�RIO PARA DIGITAR UMA LETRA.
			fflush(stdin);            //� USADA PARA LIMPAR O BUFFER DO TECLADO.
			scanf("%c",&letra);   //l� A LETRA DE CHUTE DO USU�RIO.
			system("cls");      //LIMPA A TELA APOS A TENTATIVA.
			letra=toupper(letra);   //PARA QUE N�O TENHA PROBLEMA AO DIGITAR LETRA MAIUSCULA OU MINUSCULA ,
								   //TRANSFORMA TUDO PARA MAIUSCULA, ASSIM CASANDO COM AS PALAVRAS NO ARQUIVO ONDE EST�O AS PALAVRAS.
			
			tem = 'N';    //ATRIBUI��O.
			nao_tem = 'S';     //ATRIBUI��O.
	
			for(i=0;i<tam_palavra;i++) // INICIO DO PROCESSO ONDE VERIFICA SE A LETRA DIGITADA EXISTE NA PALAVRA SORTEADA.
			{
				if(palavra[i]== letra){      //SE A LETRA EXISTE EM DETERMINADA POSI��O DA PALAVRA SORTEADA ELA SER� ATRIBUIDA PARA RESPOSTA.
					resposta[i]=palavra[i];
					tem='S';
				}
				if(resposta[i]=='_') //ENQUANTO HOUVER UNDERLINE, SIGNIFICA QUE A PALAVRA AINDA N�O EST� COMPLETA.
					nao_tem='N';
		
				printf("%c ",resposta[i]); // ALTERA NA TELA SE O USU�RIO ACERTOU A LETRA;
				
			}
			if(letra == erros[0] || letra == erros[1] || letra == erros[2] || letra == erros[3] || letra == erros[4] || letra == erros[5])
				printf("\nVOC%c J%c DIGITOU ESSA LETRA!",210,181); // 210 � O CODIGO NA TABELA ASCII DO CARACTERE '�' 181 � O CODIGO DO CARACTERE '�'.
				
			printf("\nCHUTES ERRADOS: ");
			if(tem == 'N' && (letra != erros[0] && letra != erros[1] && letra != erros[2] && letra != erros[3] && letra != erros[4] && letra != erros[5]) && letra != '\n')
			{
					erros[a]=letra; // ERRO NA POSI��O 'a' RECEBE A LETRA DE CHUTE QUE N�O EST� NA PALAVRA.
					a++; // 'a' RECEBE SEU VALOR ATUAL MAIS UM, NA MEDIDA EM QUE V�O APARECENDO CHUTES ERRADOS.
					tentativa++; // TENTATIVA RECEBE SEU VALOR ATUAL MAIS UM.
			}
			
			printf("%c %c %c %c %c %c",erros[0],erros[1],erros[2],erros[3],erros[4],erros[5]); // VAI EXIBINDO NA TELA OS ERROS A CADA CHUTE DADO.
		
		}
		//FIM DO CORA��O.
		
		
		if(nao_tem=='S')
			printf("\nVOC%c ACERTOU!\n",210); //210 � O CODIGO NA TABELA ASCII DO CARACTERE '�'.
		else
		{
			printf("\nVOC%c ERROU! \nA PALAVRA ERA: ",210); // 210 � O CODIGO NA TABELA ASCII DO CARACTERE '�'.
			puts(palavra);
		}
			
		fclose(p);    //FECHA O ARQUIVO;
		printf("DESEJA JOGAR NOVAMENTE? (S/N)");
		fflush(stdin); //� USADA PARA LIMPAR O BUFFER DO TECLADO.
		scanf("%c",&repet);
		if(repet== 'N' || repet== 'n'){
			printf("SAINDO DO PROGRAMA");
			for(i=0;i<3;i++){ //ANIMA��O AO USU�RIO SAIR DO PROGRAMA
				sleep(1);
				printf(".");
			}
			printf("\n****** ATE MAIS! ******");
		}
		
		
	}while(repet =='S' || repet =='s'); // SE ESSAS CONDI��ES FOREM V�LIDAS, INICIA O PROGRAMA NOVAMENTE.
}	
