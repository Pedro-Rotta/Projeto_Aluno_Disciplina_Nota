#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


#define TFAluno 60
#define TFDisciplina 10
#define TFNota 100


struct _Aluno{
	char RA[13];
	char Nome[20];
};

struct _Disciplina{
	int CodDisciplina;
	char Disciplina[30];
};

struct _Nota{
	char RA[13];
	int CodDisciplina;
	float Nota;
};


void Alteracao_Aluno(int &TLRA, int &TLNOTA, _Aluno Aluno[TFAluno], _Nota Nota[TFNota]);
void Alteracao_Disciplina(int &TLCOD, int &TLNOTA, _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]);
void Alteracao_Nota(_Nota Nota[TFNota], int TLNOTA);
void Borda_Menu();
void Busca_Aluno(int TL, _Aluno Aluno[TFAluno], char RAaux[13], int &i);
void Busca_Disciplina(int TL, _Disciplina Disciplina[TFDisciplina], int CODaux, int &i);
void Busca_Nota_Disciplina(int TLNOTA, _Nota Nota[TFNota], int &i, int CODaux);
void Busca_Nota_RA(int TLNOTA, _Nota Nota[TFNota], int &i, char RAaux[13]);
void Busca_Nota_RA_COD(int TL, _Nota Nota[TFNota], int CODaux, char RAaux[13], int &i);
int Busca_Termo_Disciplina(char Nomeaux[30], char AuxTermo[30]);
void Cadastro_Aluno(int &TLRA, _Aluno Aluno[TFAluno]);
void Cadastro_Disciplina(int &TLCOD, _Disciplina Disciplina[TFDisciplina]);
void Cadastro_Nota(int TLRA, int TLCOD, int &TLNOTA, _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]);
void Clear_Fora();
void Clear_Mensagem();
void Clear_op();
void Consulta_Aluno(_Aluno Aluno[TFAluno], int TLRA);
void Consulta_Alunos_Por_Letra(_Aluno Aluno[TFAluno], int TLRA, char Letra);
void Consulta_Disciplina(_Disciplina Disciplina[TFDisciplina], int TLCOD);
void Consulta_Disciplinas_Media_Alta(_Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota], int TLCOD, int TLNOTA);
void Consulta_Disciplinas_Media_Baixa(_Nota Nota[TFNota], _Disciplina Disciplina[TFDisciplina], _Aluno Alunos[TFAluno], int TLNOTA, int TLCOD, int TLRA);
void Consulta_Disciplinas_Por_Termo(_Disciplina Disciplina[TFDisciplina], int TLCOD);
void Consulta_Nota(_Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota],  int TLRA, int TLCOD, int TLNOTA);
void Consulta_Reprovados(_Nota Nota[TFNota], _Aluno Aluno[TFAluno], int TLNOTA, int TLRA);
void Contador_Digits(int numero, int &contador);
void Escolha_Alteracao_Aluno(_Aluno Aluno[TFAluno], int &i, char RAaux[13], int TLNOTA, _Nota Nota[TFNota]);
void Escolha_Alteracao_Disciplina(_Disciplina Disciplina[TFDisciplina], int &i, int &CODaux, int TLNOTA, _Nota Nota[TFNota]);
void Escolha_Dado_Sensivel(char &op);
void Exclusao_Aluno(int &TLRA, int &TLNOTA, _Aluno Aluno[TFAluno], _Nota Nota[TFNota]);
void Exclusao_Disciplina(int &TLCOD, int &TLNOTA, _Disciplina[TFDisciplina], _Nota Nota[TFNota]);
void Exclusao_Nota(int &TLNOTA, int TLRA, int TLCOD, _Nota Nota[TFNota], _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina]);
void Executar(int &TLRA, int &TLCOD, int &TLNOTA, _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]);
void Exibir_Alunos_Completo(_Nota Nota[TFNota], _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], int TLNOTA, int TLRA, int TLCOD);
void Insercao_Dados_Cadastro_Aluno(_Aluno Aluno[TFAluno], int &TLRA);
void Insercao_Dados_Cadastro_Disciplina(_Disciplina Disciplina[TFDisciplina], int &TLCOD);
void Insercao_Todos_Dados_Cadastro(_Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota], int &TLRA, int &TLCOD, int &TLNOTA);
void Menu_Consultas(char &op);
void Menu_Consultas_Color(char &op);
void Menu_Funcoes(char &op);
void Menu_Funcoes_Color(char &op);
void Menu_Outros(char &op);
void Menu_Outros_Color(char &op);
void Menu_Principal(char &op);
void Menu_Relatorios(char &op);
void Ordenacao_Aluno(_Aluno Aluno[TFAluno], int &TLRA, char RAaux[13], char Nomeaux[20]);
void Ordenacao_Disciplina(_Disciplina Disciplina[TFDisciplina], int &TLCOD, int CODaux, char Disciplinaaux[30]);
void Ordenacao_Nota(_Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota], int &TLRA, int &TLCOD, int &TLNOTA, char RAaux[13], int CODaux, float Notaaux);
void Preenchimento_Menu();
void Relatorios(int &TLRA, int &TLCOD, int &TLNOTA, _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]);
void TabASCII();
void Todas_Disciplinas(int &TLRA, _Disciplina Disciplina[TFDisciplina]);
void Todas_Notas(int &TLNOTA, _Nota Nota[TFNota]);
void Todos_Alunos(int &TLRA, _Aluno Aluno[TFAluno]);
void Busca_Nome_Com_RA(_Aluno Aluno[TFAluno], int TLRA, char Nomeaux[20], char RAaux[13]);
void Ir_Relatorios(char &op);


int main(void) {
	int TLRA = 0, TLCOD = 0, TLNOTA = 0;
	_Aluno Aluno[TFAluno];
	_Disciplina Disciplina[TFDisciplina];
	_Nota Nota[TFNota];
	Executar(TLRA, TLCOD, TLNOTA, Aluno, Disciplina, Nota);
	Relatorios(TLRA, TLCOD, TLNOTA, Aluno, Disciplina, Nota);
	system("CLS");
	return 0;
}

void Alteracao_Aluno(int &TLRA, int &TLNOTA, _Aluno Aluno[TFAluno], _Nota Nota[TFNota]){
	int i, j, k;
	char op, RAaux[13], Nomeaux[20], RAauxAntigo[13];
	if(TLRA>0){
		textcolor(YELLOW);
		gotoxy(52,5);
		printf("Tabela Alteracao Aluno");
		textcolor(WHITE);
		gotoxy(52,7);
		printf("RA no formato 'xx.xx.xxxx-x'");
        gotoxy(52,9);
        printf("Digite o RA: ");;
		fflush(stdin);
		gets(RAaux);
		if(strlen(RAaux) == 12){
			Busca_Aluno(TLRA, Aluno, RAaux, i);
			if(i<TLRA){
				strcpy(RAauxAntigo, RAaux);
				Escolha_Alteracao_Aluno(Aluno, i, RAaux, TLNOTA, Nota);
				if(i==1 && TLNOTA>0){
					for(k=0;k<TLNOTA;k++){
						if(stricmp(RAauxAntigo, Nota[k].RA) == 0){
							strcpy(Nota[k].RA, RAaux);
						}
					}
					gotoxy(52,23);
					printf("Mensagem: Notas alteradas com sucesso");
				}
			}
			else{
				textcolor(YELLOW);
				gotoxy(52,25);
				printf("Mensagem: RA nao encontrado");
			}
		}
		else{
			textcolor(YELLOW);
			gotoxy(52,25);
			printf("Mensagem: Formato do RA errado");
		}
	}
	else{
		textcolor(YELLOW);
		gotoxy(52,25);
		printf("Mensagem: Nao ha alunos cadastrados");
	}
}

void Alteracao_Disciplina(int &TLCOD, int &TLNOTA, _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]){
	int i, j, k, contador, CODaux, CODauxAntigo;
	char op, Disciplinaaux[30];
	if(TLCOD>0){
		textcolor(YELLOW);
		gotoxy(50,5);
		printf("Tabela Alteracao Disciplina");
		textcolor(WHITE);
		gotoxy(52,7);
		printf("Codigo de 3 Digits da materia: ");
		fflush(stdin);
		scanf("%d", &CODaux);
		Contador_Digits(CODaux, contador);
		if(contador == 3){
			Busca_Disciplina(TLCOD, Disciplina, CODaux, i);
			if(i<TLCOD){
				CODauxAntigo = CODaux;
				Escolha_Alteracao_Disciplina(Disciplina, i, CODaux, TLNOTA, Nota);
				if(i==1 && TLNOTA > 0){
					for(k=0;k<TLNOTA;k++){
						if(Nota[k].CodDisciplina == CODauxAntigo){
							Nota[k].CodDisciplina = CODaux;
						}
					}
					textcolor(YELLOW);
					gotoxy(52,23);
					printf("Mensagem: Notas alterada com sucesso");
				}
			}
			else{
				textcolor(YELLOW);
				gotoxy(52,25);
				printf("Mensagem: codigo nao encontrado");
			}
		}
		else{
			textcolor(YELLOW);
			gotoxy(52,25);
			printf("Mensagem: Formato do codigo errado");
		}
	}
	else{
		textcolor(YELLOW);
		gotoxy(52,25);
		printf("Mensagem: Nao ha disciplinas cadastrados");
	}
}

void Alteracao_Nota(_Nota Nota[TFNota], int TLNOTA){
	int CODaux, contador, i;
	float Notaaux;
	char RAaux[13];
	textcolor(YELLOW);
	gotoxy(50,5);
	printf("Tabela Alteracao Nota");
	textcolor(WHITE);
	if(TLNOTA > 0){
		gotoxy(52,7);
		printf("RA no formato 'xx.xx.xxxx-x'");
        gotoxy(52,9);
        printf("Digite o RA: ");;
		fflush(stdin);
		gets(RAaux);
		if(strlen(RAaux) == 12){
			Busca_Nota_RA(TLNOTA, Nota, i, RAaux);
			if(i<TLNOTA){
				gotoxy(52,11);
				printf("Codigo de 3 Digits da materia: ");
				scanf("%d", &CODaux);
				Contador_Digits(CODaux, contador);
				if(contador == 3){
					Busca_Nota_Disciplina(TLNOTA, Nota, i, CODaux);
					if(i < TLNOTA){
						Busca_Nota_RA_COD(TLNOTA,Nota,CODaux, RAaux, i);
						if(i<TLNOTA){
							gotoxy(52,13);
							printf("Nova Nota: ");
							scanf("%f", &Notaaux);
							if(Notaaux >= 0 && Notaaux <= 10){
								Nota[i].Nota = Notaaux;
								textcolor(YELLOW);
								gotoxy(52,25);
								printf("Mensagem: Alteracao feita com sucesso");
							}
							else{
								textcolor(YELLOW);
								gotoxy(52,25);
								printf("Mensagem: Formato invalido, 0 a 10");
							}
						}
						else{
							textcolor(YELLOW);
							gotoxy(52,25);
							printf("Mensagem: Nota nao atribuida a aluno na disc");
						}
					}
					else{
						textcolor(YELLOW);
						gotoxy(52,25);
						printf("Mensagem: Codigo nao encontrado");
					}
				}
				else{
					textcolor(YELLOW);
					gotoxy(52,25);
					printf("Mensagem: Formato invalido");
				}
			}
			else{
				textcolor(YELLOW);
				gotoxy(52,25);
				printf("Mensagem: RA nao encontrado");
			}
		}
		else{
			textcolor(YELLOW);
			gotoxy(52,25);
			printf("Mensagem: Formato invalido");
		}
	}
	else{
		textcolor(YELLOW);
		gotoxy(52,25);
		printf("Mensagem: Nao ha notas cadastradas");
	}
	
}

void Borda_Menu(){
	int x, y;
	
	textcolor(YELLOW);
	for(x=21;x<100;x++){
		gotoxy(x, 5);
		printf("%c", '-');
		gotoxy(x, 27);
		printf("%c", '-');
	}
    textcolor(WHITE);
    textcolor(GREEN);
    gotoxy(20, 4);  printf("%c", 201);
    gotoxy(100, 4); printf("%c", 187);
    gotoxy(20, 28); printf("%c", 200);
    gotoxy(100, 28); printf("%c", 188);
    
    for (int i = 21; i < 100; i++) {
        gotoxy(i, 4);  printf("%c", 205);
        gotoxy(i, 28); printf("%c", 205);
    }
    
    for (int i = 5; i < 28; i++) {
        gotoxy(20, i);  printf("%c", 186);
        gotoxy(100, i); printf("%c", 186);
    }
    
    textcolor(RED);
    gotoxy(22, 6);  printf("%c", 201);
    gotoxy(98, 6);  printf("%c", 187);
    gotoxy(22, 26); printf("%c", 200);
    gotoxy(98, 26); printf("%c", 188);
    
    for (int i = 23; i < 98; i++) {
        gotoxy(i, 6);  printf("%c", 205);
        gotoxy(i, 26); printf("%c", 205); 
    }
    
    for (int i = 7; i < 26; i++) {
        gotoxy(22, i);  printf("%c", 186);
        gotoxy(98, i);  printf("%c", 186);
    }
}

void Busca_Aluno(int TL, _Aluno Aluno[TFAluno], char RAaux[13], int &i){
	for(i=0;i<TL && stricmp(RAaux, Aluno[i].RA) != 0;i++);
}

void Busca_Disciplina(int TL, _Disciplina Disciplina[TFDisciplina], int CODaux, int &i){
	for(i=0;i<TL && CODaux != Disciplina[i].CodDisciplina;i++);
}

void Busca_Nome_Com_RA(_Aluno Aluno[TFAluno], int TLRA, char Nomeaux[20], char RAaux[13]){
	int i, achou = 0;
	for(i=0;i<TLRA && achou == 0;i++){
		if(stricmp(RAaux, Aluno[i].RA) == 0){
			strcpy(Nomeaux, Aluno[i].Nome);
			achou = 1;
		}
	}
}

void Busca_Nota_Disciplina(int TLNOTA, _Nota Nota[TFNota], int &i, int CODaux){
	for(i=0;i<TLNOTA && CODaux != Nota[i].CodDisciplina;i++);
}

void Busca_Nota_RA(int TLNOTA, _Nota Nota[TFNota], int &i, char RAaux[13]){
	for(i=0;i<TLNOTA && stricmp(RAaux, Nota[i].RA);i++);
}

void Busca_Nota_RA_COD(int TL, _Nota Nota[TFNota], int CODaux, char RAaux[13], int &i){
	for(i=0;i<TL && (CODaux != Nota[i].CodDisciplina || stricmp(RAaux, Nota[i].RA) != 0);i++);
}

void Cadastro_Aluno(int &TLRA, _Aluno Aluno[TFAluno]){
	int i, maiusculo, minusculo;
	char RAaux[13], Nomeaux[20];
	if(TLRA < TFAluno){
		textcolor(YELLOW);
		gotoxy(50,5);
		printf("Tabela Cadastro Aluno");
		textcolor(WHITE);
		gotoxy(52,7);
		fflush(stdin);
		printf("RA no formato 'xx.xx.xxxx-x'");
        gotoxy(52,9);
        printf("Digite o RA: ");;
		gets(RAaux);
		if(strlen(RAaux) == 12){
			Busca_Aluno(TLRA, Aluno, RAaux, i);
			if(i==TLRA){
				gotoxy(52,11);
				printf("Nome: ");
				fflush(stdin);
				gets(Nomeaux);
				Nomeaux[0] = toupper(Nomeaux[0]);
				if(stricmp(Nomeaux, "") != 0){
					Ordenacao_Aluno(Aluno, TLRA, RAaux, Nomeaux);
					textcolor(YELLOW);
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Aluno cadastrado com sucesso");
				}
				else{
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Nome invalido");
				}
			}
			else{
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: RA ja cadastrado");
			}
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Formato do RA errado");
		}
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Sem armazenamento para alunos");
	}
}

void Cadastro_Disciplina(int &TLCOD, _Disciplina Disciplina[TFDisciplina]){
	int CODaux, Contador = 0, i;
	char Disciplinaaux[30];
	if(TLCOD < TFDisciplina){
		textcolor(YELLOW);
		gotoxy(50,5);
		printf("Tabela Cadastro Disciplina");
		textcolor(WHITE);
		gotoxy(52,7);
		fflush(stdin);
		printf("Codigo de 3 Digits da materia: ");
		scanf("%d", &CODaux);
		Contador_Digits(CODaux, Contador);
		if(Contador == 3){
			Busca_Disciplina(TLCOD, Disciplina, CODaux, i);
			if(i==TLCOD){
				gotoxy(52,9);
				printf("Nome da disciplina: ");
				fflush(stdin);
				gets(Disciplinaaux);
				Disciplinaaux[0] = toupper(Disciplinaaux[0]);
				if(stricmp(Disciplinaaux, "") != 0){
					Ordenacao_Disciplina(Disciplina, TLCOD, CODaux, Disciplinaaux);
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Disciplina cadastrada com sucesso");
				}
				else{
					textcolor(YELLOW);
					gotoxy(52,25);
					printf("Mensagem: Disciplina invalida");
				}
			}
			else{
				textcolor(YELLOW);
				gotoxy(52,25);
				printf("Mensagem: Codigo ja utilizado");
			}
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Quantidade de Digits invalido");
		}
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Sem armazenamento para disciplinas");
	}
}
	
void Cadastro_Nota(int TLRA, int TLCOD, int &TLNOTA, _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]){
	int CODaux, Contador, i;
	float Notaaux;
	char RAaux[13];
	if(TLRA < TFNota){
		if(TLRA > 0 && TLCOD > 0){
			textcolor(YELLOW);
			gotoxy(52,5);
			printf("Tabela Cadastro Nota");
			textcolor(WHITE);
			gotoxy(52,7);
			printf("RA no formato 'xx.xx.xxxx-x'");
	        gotoxy(52,9);
	        printf("Digite o RA: ");
			fflush(stdin);
			gets(RAaux);
			if(strlen(RAaux) == 12){
				Busca_Aluno(TLRA, Aluno, RAaux, i);
				if(i<TLRA){
					gotoxy(52,11);
					printf("Codigo de 3 Digits da materia: ");
					scanf("%d", &CODaux);
					Contador_Digits(CODaux, Contador);
					if(Contador == 3){
						Busca_Disciplina(TLCOD, Disciplina, CODaux, i);
						if(i<TLCOD){
							Busca_Nota_RA_COD(TLNOTA, Nota, CODaux, RAaux, i);
							if(i==TLNOTA){
								gotoxy(52,13);
								printf("Nota do aluno: ");
								if(scanf("%f", &Notaaux)==1){
									if(Notaaux >= 0 && Notaaux <= 10){
										Ordenacao_Nota(Aluno, Disciplina, Nota, TLRA, TLCOD, TLNOTA, RAaux, CODaux, Notaaux);
										gotoxy(52,25);
										textcolor(YELLOW);
										printf("Mensagem: Nota cadastrada com sucesso");
									}
									else{
										gotoxy(52,25);
										textcolor(YELLOW);
										printf("Mensagem: Formato invalido");
									}
								}
								else{
									textcolor(YELLOW);
									gotoxy(52,25);
									printf("Mensagem: Formato invalido");
								}
							}
							else{
								textcolor(YELLOW);
								gotoxy(52,25);
								printf("Mensagem: Nota ja atribuida a aluno na disc");
							}
						}
						else{
							textcolor(YELLOW);
							gotoxy(52,25);
							printf("Mensagem: Codigo de disciplina nao encontrado");
						}
					}
					else{
						textcolor(YELLOW);
						gotoxy(52,25);
						printf("Mensagem: Codigo invalido");
					}
				}
				else{
					textcolor(YELLOW);
					gotoxy(52,25);
					printf("Mensagem: RA nao encontrado");
				}
			}
			else{
				textcolor(YELLOW);
				gotoxy(52,25);
				printf("Mensagem: Formato do RA errado");
			}
		}
		else{
			textcolor(YELLOW);
			gotoxy(52,25);
			printf("Mensagem: Dados insuficiente para notas");
		}
	}
	else{
		textcolor(YELLOW);
		gotoxy(52,25);
		printf("Mensagem: Sem armazenamento para mais notas");
	}
}

void Clear_Fora(){
int x, y, xi, yi, xf, yf;
	xi = 0;
	xf = 20;
	yi = 0;
	yf = 30;
	
	for(x=xi;x<xf;x++){
		for(y=yi;y<yf;y++){
			gotoxy(x,y);
			printf(" ");
		}
	}
	
	for(x=40,y=3;x<70;x++){
		gotoxy(x,y);
		printf(" ");
	}
}

void Clear_Mensagem(){
	int x, y, xi, yi, xf, yf;
	xi = 51;
	yi = 23;
	xf = 97;
	yf = 25;
	
	for (y = yi; y <= yf; y++) {
        gotoxy(xi, y);
        for (x = xi; x <= xf; x++) {
            printf(" ");
        }
    }
}

void Clear_Display(){
	int x, y, xi, yi, xf, yf;
	xi = 51;
	yi = 7;
	xf = 97;
	yf = 20;
	for (y = yi; y <= yf; y++) {
        gotoxy(xi, y);
        for (x = xi; x <= xf; x++) {
            printf(" ");
        }
    }
}

void Clear_op(){
	int x, y, xi, yi, xf, yf;
	xi = 23;
	yi = 7;
	xf = 49;
	yf = 25;
	for (y = yi; y <= yf; y++) {
        gotoxy(xi, y);
        for (x = xi; x <= xf; x++) {
            printf(" ");
        }
    }
}

void Consulta_Aluno(_Aluno Aluno[TFAluno], int TLRA){
	int i, x;
	char RAaux[13];
	
	if(TLRA > 0){
		textcolor(YELLOW);
		gotoxy(52,5);
		printf("Tabela Consulta Aluno");
		textcolor(WHITE);
		gotoxy(52,7);
		printf("RA no formato 'xx.xx.xxxx-x'");
	    gotoxy(52,9);
	    printf("Digite o RA: ");
		fflush(stdin);
		gets(RAaux);
		if(strlen(RAaux) == 12){
			Busca_Aluno(TLRA, Aluno, RAaux, i);
			if(i<TLRA){
				gotoxy(52,12);
				printf("RA: %s", Aluno[i].RA);
				gotoxy(52,13);
				printf("Nome: %s", Aluno[i].Nome);
				gotoxy(52,14);
				for(x=52;x<97;x++){
						printf("%c", 196);
					}
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: ENTER para voltar ao menu");
				getch();
				Clear_Mensagem();
			}
			else{
				textcolor(YELLOW);
				gotoxy(52,25);
				printf("Mensagem: RA nao encontrado");
			}
		}
		else{
			textcolor(YELLOW);
			gotoxy(52,25);
			printf("Mensagem: Formato do RA errado");
		}
	}
	else{
		textcolor(YELLOW);
		gotoxy(52,25);
		printf("Nao ha alunos cadastrados");
	}
}

void Consulta_Alunos_Por_Letra(_Aluno Aluno[TFAluno], int TLRA) {
    int i, Letra, y = 7, x, cont=0;
    textcolor(YELLOW);
    gotoxy(55,5);
    printf("Tabela Consulta Por Letra");
    textcolor(WHITE);
    gotoxy(52,7);
    printf("Letra a ser procurada: ");
    Letra = toupper(getch());
    for (i = 0; i < TLRA; i++) {
        if (Aluno[i].Nome[0] == Letra) {
        	cont++;
        	gotoxy(52,y++);
            printf("RA: %s | Nome: %s\n", Aluno[i].RA, Aluno[i].Nome);
            gotoxy(52,y++);
			for(x=52;x<98;x++){
				printf("%c", 196);
			}
        }
    }
    if(cont==0){
    	gotoxy(52,23);
    	textcolor(YELLOW);
    	printf("Mensagem: Nao ha alunos com essa letra");
	}
    gotoxy(52,25);
    textcolor(YELLOW);
	printf("Mensagem: ENTER para voltar ao menu");
	getch();
	Clear_Mensagem();
}

void Consulta_Disciplina(_Disciplina Disciplina[TFDisciplina], int TLCOD){
	int i, x, Contador;
	char CODaux;
	
	if(TLCOD>0){
		textcolor(YELLOW);
		gotoxy(48,5);
		printf("Tabela Consulta Disciplina");
		textcolor(WHITE);
		gotoxy(52,7);
		printf("Codigo de 3 Digits da materia: ");
		scanf("%d", &CODaux);
		Contador_Digits(CODaux, Contador);
		if(Contador == 3){
			Busca_Disciplina(TLCOD, Disciplina, CODaux, i);
			if(i<TLCOD){
				gotoxy(52,9);
				printf("Codigo: %d", Disciplina[i].CodDisciplina);
				gotoxy(52,10);
				printf("Disciplina: %s", Disciplina[i].Disciplina);
				gotoxy(52,11);
				for(x=51;x<97;x++){
						printf("%c", 196);
					}
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: ENTER para voltar ao menu");
				getch();
				Clear_Mensagem();
			}
			else{
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: Codigo nao encontrado");
			}
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Formato do codigo errado");
		}
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Nao ha disciplinas cadastradas");
	}
}

void Consulta_Disciplinas_Media_Alta(_Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota], int TLCOD, int TLNOTA) {
    int i, j, sum, cont, CODaux, y=7, Jafoi[9], jafoi = 0, k, t;
	float media;
	textcolor(YELLOW);
	gotoxy(50,5);
	printf("Tabela Consulta Media Baixa");
	for(i=0,t=0;i<TLNOTA;i++){
	    CODaux = Nota[i].CodDisciplina;
	    for(k=0;k<jafoi&&CODaux!=Jafoi[k];k++);
	    if(k==jafoi){
	        sum = 0;
	        cont = 0;
	        for(j=0;j<TLNOTA;j++){
	            if(Nota[j].CodDisciplina==CODaux){
	                sum += Nota[j].Nota;
	                cont++;
	            }
	        }
	        textcolor(WHITE);
	        media = sum/cont;
	        Jafoi[jafoi++] = CODaux;
	        if(media>=6){
	            gotoxy(52, y);
	            printf("Codigo: %d: Media: %.2f", CODaux, media);
	        	y+=2;
	        	t++;
			}
			
			if(i!=0 && t%7==0){
				y=7;
				gotoxy(52,23);
				textcolor(YELLOW);
				printf("Mensagem: Pressione ENTER para proxima tela");
				textcolor(WHITE);
				getch();
				t=0;
				Clear_Display();
				Clear_Mensagem();
			}
	    }
	}
	gotoxy(52,25);
	textcolor(YELLOW);
	printf("Mensagem: Pressione ENTER para voltar ao menu");
	textcolor(WHITE);
	getch();
	Clear_Mensagem();
}

void Consulta_Disciplinas_Media_Baixa(_Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota], int TLCOD, int TLNOTA){
	int i, j, sum, cont, CODaux, y=7, Jafoi[9], jafoi = 0, k, t;
	float media;
	textcolor(YELLOW);
	gotoxy(50,5);
	printf("Tabela Consulta Media Baixa");
	for(i=0,t=0;i<TLNOTA;i++){
	    CODaux = Nota[i].CodDisciplina;
	    for(k=0;k<jafoi&&CODaux!=Jafoi[k];k++);
	    if(k==jafoi){
	        sum = 0;
	        cont = 0;
	        for(j=0;j<TLNOTA;j++){
	            if(Nota[j].CodDisciplina==CODaux){
	                sum += Nota[j].Nota;
	                cont++;
	            }
	        }
	        textcolor(WHITE);
	        media = sum/cont;
	        Jafoi[jafoi++] = CODaux;
	        if(media<6){
	            gotoxy(52, y);
	            printf("Codigo: %d: Media: %.2f", CODaux, media);
	        	y+=2;
	        	t++;
			}
			
			if(i!=0 && t%7==0){
				y=7;
				gotoxy(52,23);
				textcolor(YELLOW);
				printf("Mensagem: Pressione ENTER para proxima tela");
				textcolor(WHITE);
				getch();
				t=0;
				Clear_Display();
				Clear_Mensagem();
			}
	    }
	}
	gotoxy(52,25);
	textcolor(YELLOW);
	printf("Mensagem: Pressione ENTER para voltar ao menu");
	textcolor(WHITE);
	getch();
	Clear_Mensagem();
}

void Consulta_Disciplinas_Por_Termo(_Disciplina Disciplina[TFDisciplina], int TLCOD) {
    int i, y = 7, cont = 0, x;
    char AuxTermo[30];
    textcolor(YELLOW);
    gotoxy(55,5);
    printf("Tabela Consulta Por Termo");
    
    textcolor(WHITE);
    gotoxy(52, y++);
    printf("Termo: ");
    fflush(stdin);
    gets(AuxTermo);
    for (i = 0; i < TLCOD; i++) {
        if (Busca_Termo_Disciplina(Disciplina[i].Disciplina, AuxTermo)) {
            gotoxy(52, y++);
            printf("Codigo: %d | Disciplina: %s\n", Disciplina[i].CodDisciplina, Disciplina[i].Disciplina);
            gotoxy(52, y++);
            for (x = 51; x < 97; x++) {
                printf("%c", 196);
            }
            cont++;
        }
    }
    if (cont == 0) {
        gotoxy(52, 23);
        textcolor(YELLOW);
        printf("Mensagem: Nao ha disciplinas com esse termo");
    }
    gotoxy(52, 25);
    textcolor(YELLOW);
    printf("Mensagem: ENTER para voltar ao menu");
    getch();
    Clear_Mensagem();
}

int Busca_Termo_Disciplina(char NomeDisciplina[30], char AuxTermo[30]) {
    int i = 0, j = 0;
    while (NomeDisciplina[i] != '\0') {
        while (NomeDisciplina[i + j] != '\0' && AuxTermo[j] != '\0' && NomeDisciplina[i + j] == AuxTermo[j]) {
            j++;
        }
        if (AuxTermo[j] == '\0') {
            return 1; 
        }
        j = 0;
        i++;
    }
	return 0;
}

void Consulta_Nota(_Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota],  int TLRA, int TLCOD, int TLNOTA){
	int CODaux, Contador, i, x;
	char RAaux[13];
	
	if(TLNOTA>0){
		textcolor(YELLOW);
		gotoxy(52,5);
		printf("Tabela Consulta Nota");
		textcolor(WHITE);
		gotoxy(52,7);
		printf("RA no formato 'xx.xx.xxxx-x'");
	    gotoxy(52,9);
	    printf("Digite o RA: ");
		fflush(stdin);
		gets(RAaux);
		if(strlen(RAaux) == 12){
			Busca_Aluno(TLRA, Aluno, RAaux, i);
			if(i<TLRA){	
				gotoxy(52,11);
					printf("Codigo de 3 Digits da materia: ");
					scanf("%d", &CODaux);
					Contador_Digits(CODaux, Contador);
					if(Contador == 3){
						Busca_Disciplina(TLCOD, Disciplina, CODaux, i);
						if(i<TLCOD){
							Busca_Nota_RA_COD(TLNOTA, Nota, CODaux, RAaux, i);
							if(i<TLNOTA){
								gotoxy(52,13);
								printf("RA: %s", Nota[i].RA);
								Busca_Disciplina(TLCOD, Disciplina, CODaux, x);
								gotoxy(52,14);
								printf("Disciplina: %s", Disciplina[x].Disciplina);
								gotoxy(52,15);
								printf("Nota: %.2f", Nota[i].Nota);
								gotoxy(52,16);
								for(x=51;x<97;x++){
										printf("%c", 196);
									}
								gotoxy(52,25);
								textcolor(YELLOW);
								printf("Mensagem: ENTER para voltar ao menu");
								getch();
								Clear_Mensagem();
							}
							else{
								gotoxy(52,25);
								textcolor(YELLOW);
								printf("Mensagem: Nota nao atribuida a aluno na disc");
							}
						}
						else{
							gotoxy(52,25);
							textcolor(YELLOW);
							printf("Mensagem: Codigo de disciplina nao encontrado");
						}
					}
					else{
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Codigo invalido");
					}
			}
			else{
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: RA nao enContrado");
			}
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Formato do RA errado");
		}
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Nao ha notas cadastradas");
	}
}

void Consulta_Reprovados(_Nota Nota[TFNota], _Aluno Aluno[TFAluno], int TLNOTA, int TLRA){
    int i, j, reprovados, y= 7, x, Cont;
    float Media;
    textcolor(YELLOW);
    gotoxy(55,5);
    printf("Tabela Reprovados");
    textcolor(WHITE);
    for(i=0;i<TLRA;i++) {
        reprovados=0;
        Media = 0;
        Cont = 0;
        for(j=0;j<TLNOTA;j++) {
            if(stricmp(Aluno[i].RA, Nota[j].RA) == 0 && Nota[j].Nota < 6.0) {
            	Cont++;
            	Media += Nota[j].Nota;
                reprovados++;
            }
        }
        Media = Media/Cont;
        if(reprovados >= 2) {
        	gotoxy(52,y++);
            printf("RA: %s | Nome: %s | Media: %.2f\n", Aluno[i].RA, Aluno[i].Nome, Media);
            gotoxy(52,y++);
			for(x=51;x<97 && y < 21;x++){
				printf("%c", 196);
			}
			
        }
    }
    gotoxy(52,25);
    textcolor(YELLOW);
	printf("Mensagem: ENTER para voltar ao menu");
	getch();
	Clear_Mensagem();
}

void Contador_Digits(int numero, int &Contador){
	Contador = 0;
	while (numero != 0) {
        numero /= 10; 
        Contador++; 
    }
}

void Escolha_Alteracao_Aluno(_Aluno Aluno[TFAluno], int &i, char RAaux[13], int TLNOTA, _Nota Nota[TFNota]){
	char op, Nomeaux[20];
	
	Clear_Display();
	Borda_Menu();
	textcolor(YELLOW);
	gotoxy(50,5);
	printf("Tabela Alteracao Aluno");
	textcolor(WHITE);
	gotoxy(52,7);
	printf("[A] Alterar nome");
	gotoxy(52,9);
	printf("[B] Alterar RA");
	op = toupper(getch());
	Clear_Display();
	switch(op){
		case 'A':{
			gotoxy(52,11);
			printf("Digite o nome para ser inserido: ");
			fflush(stdin);
			gets(Nomeaux);
			Nomeaux[0] = toupper(Nomeaux[0]);
			if(strlen(Nomeaux) > 0 && strlen(Nomeaux) <20){
				strcpy(Aluno[i].Nome, Nomeaux);	
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: Alteracao de nome feita com sucesso");
				i=0;
			}
			else{
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: Nome invalido");
				i=0;
			}
			break;
		}
		case 'B':{
			Busca_Nota_RA(TLNOTA, Nota, i, RAaux);
			if(i<TLNOTA){
				Escolha_Dado_Sensivel(op);
				if(op == 'S'){
					gotoxy(52,7);
					printf("Digite o RA para ser inserido: ");
					fflush(stdin);
					gets(RAaux);
					if(strlen(RAaux) == 12){
						strcpy(Aluno[i].RA, RAaux);	
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Alteracao de RA feita com sucesso");
						i=1;
					}
					else{
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Formato invalido");
					}
				}
				else{
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Alteracao cancelada");
				}
			}
			else{
				gotoxy(52,7);
				printf("Digite o RA para ser inserido: ");
				fflush(stdin);
				gets(RAaux);
				if(strlen(RAaux) == 12){
					strcpy(Aluno[i].RA, RAaux);	
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Alteracao de RA feita com sucesso");
					i=1;
				}
				else{
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Formato invalido");
				}
			}
			break;
		}
			
			default:{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Escolha invalida");
			break;
			}
	}	
}

void Escolha_Alteracao_Disciplina(_Disciplina Disciplina[TFDisciplina], int &i, int &CODaux, int TLNOTA, _Nota Nota[TFNota]){
	int Contador;
	char op, Disciplinaaux[30];
	Clear_Display();
	gotoxy(52,7);;
	printf("[A] Alterar codigo");
	gotoxy(52,9);
	printf("[B] Alterar disciplina");
	op = toupper(getch());
	Clear_Display();
	switch(op){
		case 'A':{
			Busca_Nota_Disciplina(TLNOTA, Nota, i, CODaux);
				if(i<TLNOTA){
					Escolha_Dado_Sensivel(op);
					if(op == 'S'){
						gotoxy(52,7);
						printf("Codigo para ser inserido: ");
						fflush(stdin);
						scanf("%d", &CODaux);
						Contador_Digits(CODaux, Contador);
						if(Contador == 3){
							Disciplina[i].CodDisciplina = CODaux;
							gotoxy(52,25);
							textcolor(YELLOW);
							printf("Mensagem: Alteracao de codigo feita com sucesso");
							i=1;
						}
						else{
							gotoxy(52,25);
							textcolor(YELLOW);
							printf("Mensagem: Codigo invalido");
							i=0;
						}
					}
					else{
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Alteracao cancelada");
					}
				}
				else{
					gotoxy(52,7);
					printf("Codigo para ser inserido: ");
					fflush(stdin);
					scanf("%d", &CODaux);
					Contador_Digits(CODaux, Contador);
					if(Contador == 3){
						Disciplina[i].CodDisciplina = CODaux;
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Alteracao de codigo feita com sucesso");
						i=0;
					}
					else{
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Codigo invalido");
						i=0;
					}
				}
			
			break;
		}
		case 'B':{
			gotoxy(52,7);
			printf("Disciplina para ser inserida: ");
			fflush(stdin);
			gets(Disciplinaaux);
			if(stricmp(Disciplinaaux, "") != 0){
				strcpy(Disciplina[i].Disciplina, Disciplinaaux);	
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: Alteracao feita com sucesso");
				i=1;
			}
			else{
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: Disciplina no formato invalido");
				i=0;
			}
			break;
		}
		default:{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Escolha invalida");
			break;
		}
	}
}

void Escolha_Dado_Sensivel(char &op){
	gotoxy(52,7);
	printf("Dado sensivel presente em outras tabelas");
	gotoxy(52,9);
	printf("Deseja realmente Continuar a acao?");
	gotoxy(52,11);
	printf("Excluira tambem os dados na tabela Notas");
	gotoxy(52,13);
	printf("[S] SIM");
	gotoxy(52,15);
	printf("[N] NAO");
	fflush(stdin);
	op = toupper(getch());
	Clear_Display();
}

void Exclusao_Aluno(int &TLRA, int &TLNOTA, _Aluno Aluno[TFAluno], _Nota Nota[TFNota]){
	int i, j, k;
	char op, RAaux[13];
	if(TLRA>0){
		textcolor(YELLOW);
		gotoxy(50,5);
		printf("Tabela Exclusao Aluno");
		textcolor(WHITE);
		gotoxy(52,7);
		printf("RA no formato 'xx.xx.xxxx-x'");
        gotoxy(52,9);
        printf("Digite o RA: ");
		fflush(stdin);
		gets(RAaux);
		if(strlen(RAaux) == 12){
			Busca_Aluno(TLRA, Aluno, RAaux, i);
			if(i<TLRA){
				Busca_Nota_RA(TLNOTA, Nota, k, RAaux);
				if(k<TLNOTA){
					Escolha_Dado_Sensivel(op);
					if(op == 'S'){
						for(;i<TLRA-1;i++){
							strcpy(Aluno[i].Nome, Aluno[i+1].Nome); 
							strcpy(Aluno[i].RA, Aluno[i+1].RA); 
						}
						gotoxy(52,23);
						textcolor(YELLOW);
						printf("Mensagem: Exclusao em alunos feita com sucesso");
						for(;k<TLNOTA;k++){
							if(stricmp(RAaux, Nota[k].RA) == 0){
								for(j=k;j<TLNOTA;j++){
									Nota[j].CodDisciplina = Nota[j+1].CodDisciplina;
									Nota[j].Nota = Nota[j+1].Nota;
									strcpy(Nota[j].RA, Nota[j+1].RA);
								}
								k--;
								TLNOTA--;
							}
						}
						TLRA--;
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Exclus�o em notas feita com sucesso");
					}
					else{
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Exclusao cancelada com sucesso");
					}
				}
				else{
					for(;i<TLRA;i++){
						strcpy(Aluno[i].Nome, Aluno[i+1].Nome); 
						strcpy(Aluno[i].RA, Aluno[i+1].RA);
						TLRA--;
					}
					gotoxy(52,23);
					textcolor(YELLOW);
					printf("Mensagem: Exclusao em alunos feita com sucesso");
				}
			}
			else{
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: RA nao encontrado");
			}
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Formato do RA errado");
		}
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Nao ha alunos cadastrados");
	}
}

void Exclusao_Disciplina(int &TLCOD, int &TLNOTA, _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]){
	int i, CODaux, j, k;
	char op;
	if(TLCOD > 0){
		textcolor(YELLOW);
		gotoxy(48,5);
		printf("Tabela Exclusao Disciplina");
		textcolor(WHITE);
		gotoxy(52,7);
		printf("Codigo de 3 Digits da materia: ");
		fflush(stdin);
		scanf("%d", &CODaux);
		Busca_Disciplina(TLCOD, Disciplina, CODaux, i);
		if(i<TLCOD){
			Busca_Nota_Disciplina(TLNOTA, Nota, k, CODaux);
			if(k<TLNOTA){
				Escolha_Dado_Sensivel(op);
				if(op == 'S'){
					for(;i<TLCOD-1;i++){
						Disciplina[i].CodDisciplina = Disciplina[i+1].CodDisciplina;
						strcpy(Disciplina[i].Disciplina, Disciplina[i+1].Disciplina);
					}
					TLCOD--;
					gotoxy(52,23);
					textcolor(YELLOW);					
					printf("Mensagem: Exclusao em disci feita com sucesso");
					for(;k<TLNOTA;k++){
						if(CODaux == Nota[k].CodDisciplina){
							for(j=k;j<TLNOTA;j++){
								Nota[j].CodDisciplina = Nota[j+1].CodDisciplina;
								Nota[j].Nota = Nota[j+1].Nota;
								strcpy(Nota[j].RA, Nota[j+1].RA);
							}
							k--;
							TLNOTA--;
						}
					}
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Exclusao em notas feita com sucesso");
				}
				else{
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Exclusao cancelada com sucesso");
				}
			}
			else{
				for(;i<TLCOD-1;i++){
						Disciplina[i].CodDisciplina = Disciplina[i+1].CodDisciplina;
						strcpy(Disciplina[i].Disciplina, Disciplina[i+1].Disciplina);
					}
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Exclusao em discip feita com sucesso");
					TLCOD--;
			}
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Codigo nao enContrado");
		}
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Nao ha disciplinas cadastradas");
	}
}

void Exclusao_Nota(int &TLNOTA, int TLRA, int TLCOD, _Nota Nota[TFNota], _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina]){
	int CODaux, Contador, i;
	float Notaaux;
	char RAaux[13];
	if(TLNOTA > 0){
		textcolor(YELLOW);
		gotoxy(53,5);
		printf("Tabela Exclusao Nota");
		textcolor(WHITE);
		gotoxy(52,7);
		printf("RA no formato 'xx.xx.xxxx-x'");
        gotoxy(52,9);
        printf("Digite o RA: ");
		fflush(stdin);
		gets(RAaux);
		if(strlen(RAaux) == 12){
			Busca_Aluno(TLRA, Aluno, RAaux, i);
			if(i<TLRA){
				gotoxy(52,11);
				printf("Codigo de 3 Digits da materia: ");
				scanf("%d", &CODaux);
				Contador_Digits(CODaux, Contador);
				if(Contador == 3){
					Busca_Disciplina(TLCOD, Disciplina, CODaux, i);
					if(i<TLCOD){
						Busca_Nota_RA_COD(TLNOTA, Nota, CODaux, RAaux, i);
						if(i<TLNOTA){
							for(;i<TLNOTA-1;i++){
								Nota[i].CodDisciplina = Nota[i+1].CodDisciplina;
								Nota[i].Nota = Nota[i+1].Nota;
								strcpy(Nota[i].RA, Nota[i+1].RA);
							}
							gotoxy(52,25);
							textcolor(YELLOW);
							printf("Mensagem: Nota excluida com sucesso");
							TLNOTA--;
						}
						else{
							gotoxy(52,25);
							textcolor(YELLOW);
							printf("Mensagem: Nao ha nota deste aluno");
						}
					}
					else{
						gotoxy(52,25);
						textcolor(YELLOW);
						printf("Mensagem: Codigo de disciplina nao encontrado");
					}
				}
				else{
					gotoxy(52,25);
					textcolor(YELLOW);
					printf("Mensagem: Codigo invalido");
				}
				
			}
			else{
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: RA nao enContrado");
			}
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Formato do RA errado");
		}
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Nao a notas cadastradas");
	}
}

void Executar(int &TLRA, int &TLCOD, int &TLNOTA, _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]) {
    int i, CODaux, Contador, Flag_Menu = 0;
    float n;
    char op;
    bool ContinuarMenu = true;
	Flag_Menu = 0;
    do {

        switch(op) {
            case 'A': {
                Menu_Funcoes(op);
                while(op != 27) {
                    switch(op) {
                        case 'A': { Cadastro_Aluno(TLRA, Aluno); break; }
                        case 'B': { Cadastro_Disciplina(TLCOD, Disciplina); break; }
                        case 'C': { Cadastro_Nota(TLRA, TLCOD, TLNOTA, Aluno, Disciplina, Nota); break; }
                        case 'D': { Exclusao_Aluno(TLRA, TLNOTA, Aluno, Nota); break; }
                        case 'E': { Exclusao_Disciplina(TLCOD, TLNOTA, Disciplina, Nota); break; }
                        case 'F': { Exclusao_Nota(TLNOTA, TLRA, TLCOD, Nota, Aluno, Disciplina); break; }
                        case 'G': { Alteracao_Aluno(TLRA, TLNOTA, Aluno, Nota); break; }
                        case 'H': { Alteracao_Disciplina(TLCOD, TLNOTA, Disciplina, Nota); break; }
                        case 'I': { Alteracao_Nota(Nota, TLNOTA); break; }
                        default: {
                            gotoxy(52, 25);
                            textcolor(YELLOW);
                            printf("Mensagem: Escolha invalida\n");
                        }
                    }
                    Menu_Funcoes(op);
                }
                break;
            }
            case 'B': {
                Menu_Consultas(op);
                while(op != 27) {
                    switch(op) {
                        case 'A': { Consulta_Aluno(Aluno, TLRA); break; }
                        case 'B': { Consulta_Disciplina(Disciplina, TLCOD); break; }
                        case 'C': { Consulta_Nota(Aluno, Disciplina, Nota, TLRA, TLCOD, TLNOTA); break; }
                        case 'D': { Todos_Alunos(TLRA, Aluno); break; }
                        case 'E': { Todas_Disciplinas(TLCOD, Disciplina); break; }
                        case 'F': { Todas_Notas(TLNOTA, Nota); break; }
                        default: {
                        	
                            gotoxy(52, 25);
                            textcolor(YELLOW);
                            printf("Mensagem: Escolha invalida\n");
                        }
                    }
                    Menu_Consultas(op);
                }
                break;
            }
            case 'C': {
                Menu_Outros(op);
                while(op != 27) {
                    switch(op) {
                        case 'A': { Insercao_Dados_Cadastro_Aluno(Aluno, TLRA); break; }
                        case 'B': { Insercao_Dados_Cadastro_Disciplina(Disciplina, TLCOD); break; }
                        case 'C': { Insercao_Todos_Dados_Cadastro(Aluno, Disciplina, Nota, TLRA, TLCOD, TLNOTA); break; }
                        case 'D': { break; }
                        case 'E': { break; }
                        case 'F': { break; }
                        default: {
                            gotoxy(52, 25);
                            textcolor(YELLOW);
                            printf("Mensagem: Escolha invalida\n");
                        }
                    }
                    Menu_Outros(op);
                }
                break;
            }
            default: {
                if (Flag_Menu == 1) {
                    gotoxy(52, 25);
                    textcolor(YELLOW);
                    printf("Mensagem: Escolha invalida\n");
                }                
            }
        }


		Menu_Principal(op);
		Flag_Menu = 1;
        if (op == 27) {
        	Clear_op();
        	Clear_Display();
        	Clear_Mensagem();
            Ir_Relatorios(op);
            if (op == 'S') {
                if (TLRA > 0 || TLCOD > 0) {
                    ContinuarMenu = false;
                } else{
                    gotoxy(52, 25);
                    textcolor(YELLOW);
                    printf("Mensagem: Nao ha dados para gerar relatorios");
                }
            } else if (op == 'N') {
                gotoxy(52, 25);
                textcolor(YELLOW);
                printf("Mensagem: Relatorios cancelado com sucesso");
            } else {
                gotoxy(52, 25);
                textcolor(YELLOW);
                printf("Mensagem: Opcao invalida");
            }
        }

    } while (ContinuarMenu);
}

void Exibir_Alunos_Completo(_Nota Nota[TFNota], _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], int TLNOTA, int TLRA, int TLCOD) {
    int i, j, k, x, y = 7, t, encontrouNotas;
    textcolor(YELLOW);	
    gotoxy(55, 5);
    printf("Tabela Exibir Alunos");
    textcolor(WHITE);
    t = 0;
    for(i = 0; i < TLRA; i++) {
    	encontrouNotas = 0;
        gotoxy(52, y++);
        printf("RA: %s | Nome: %s\n", Aluno[i].RA, Aluno[i].Nome);
        for(j = 0; j < TLNOTA; j++) {
            if(strcmp(Aluno[i].RA, Nota[j].RA) == 0) {
                encontrouNotas = 1;
                for(k = 0; k < TLCOD; k++) {
                    if(Disciplina[k].CodDisciplina == Nota[j].CodDisciplina) {
                        gotoxy(52, y++);
                        printf("Disciplina: %d - %s | Nota: %.2f\n", Disciplina[k].CodDisciplina, Disciplina[k].Disciplina, Nota[j].Nota);
                        gotoxy(52, y++);
                        printf("Situacao: ");
                        if(Nota[j].Nota >= 6.0) {
                        	textcolor(GREEN);
                            printf("Aprovado");
                            textcolor(WHITE);
                        } else {
                        	textcolor(RED);
                            printf("Reprovado");
                            textcolor(WHITE);
                        }
                        gotoxy(52, y++);
                        for(x = 52; x < 97; x++) {
                            printf("%c", 196);
                        }
                        t++;
                        if(t % 4 == 0) {
                        	textcolor(YELLOW);
                            gotoxy(52, 23);
                            printf("Pressione ENTER para continuar...");
                            getch();
                            Clear_Display(); 
                            Clear_Mensagem();
                            y = 7;
                            textcolor(WHITE);
                        }
                    }
                }
            }
        }
        if (encontrouNotas == 0) {
            gotoxy(52, y++);
            printf("Nenhuma nota encontrada para este aluno.\n");
            gotoxy(52, y++);
            for(x = 52; x < 97; x++) {
                printf("%c", 196);
            }
            t++;
        }
    }
    gotoxy(52, 25);
    textcolor(YELLOW);
    printf("Mensagem: ENTER para voltar ao menu");
    getch();
    Clear_Mensagem();
}

void Insercao_Dados_Cadastro_Aluno(_Aluno Aluno[TFAluno], int &TLRA){
	if(TLRA == 0){
		strcpy(Aluno[TLRA].RA, "26.24.1257-9");
		strcpy(Aluno[TLRA++].Nome, "Jessica");
		strcpy(Aluno[TLRA].RA, "26.24.1227-9");
		strcpy(Aluno[TLRA++].Nome, "Joao");
		strcpy(Aluno[TLRA].RA, "26.24.1247-9");
		strcpy(Aluno[TLRA++].Nome, "Jose");
		strcpy(Aluno[TLRA].RA, "26.24.1237-9");
		strcpy(Aluno[TLRA++].Nome, "Maria");
		strcpy(Aluno[TLRA].RA, "26.24.1217-9");
		strcpy(Aluno[TLRA++].Nome, "Pedro");
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Dados de alunos cadastrados");
	}
	else{
		textcolor(YELLOW);
		gotoxy(52,25);
		printf("Nao eh possivel apos cadastrar aluno");
	}
}

void Insercao_Dados_Cadastro_Disciplina(_Disciplina Disciplina[TFDisciplina], int &TLCOD){
	
	if(TLCOD == 0){
		Disciplina[TLCOD].CodDisciplina = 123;
		strcpy(Disciplina[TLCOD++].Disciplina, "ATP1");
		Disciplina[TLCOD].CodDisciplina = 321;
		strcpy(Disciplina[TLCOD++].Disciplina, "ATP2");
		Disciplina[TLCOD].CodDisciplina = 456;
		strcpy(Disciplina[TLCOD++].Disciplina, "ED1");
		Disciplina[TLCOD].CodDisciplina = 654;
		strcpy(Disciplina[TLCOD++].Disciplina, "ED2");
		Disciplina[TLCOD].CodDisciplina = 789;
		strcpy(Disciplina[TLCOD++].Disciplina, "SO1");
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Dados de disciplinas cadastrados");
	}
	else{
		textcolor(YELLOW);
		gotoxy(52,25);
		printf("Nao eh possivel apos cadastrar disciplina");
	}
}

void Insercao_Todos_Dados_Cadastro(_Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota], int &TLRA, int &TLCOD, int &TLNOTA){	
	if(TLRA==0 && TLCOD == 0){
		Insercao_Dados_Cadastro_Aluno(Aluno, TLRA);
		Insercao_Dados_Cadastro_Disciplina(Disciplina, TLCOD);
		strcpy(Nota[TLNOTA].RA, "26.24.1227-9");
		Nota[TLNOTA].CodDisciplina = 123;
		Nota[TLNOTA++].Nota = 8;
		strcpy(Nota[TLNOTA].RA, "26.24.1227-9");
		Nota[TLNOTA].CodDisciplina = 321;
		Nota[TLNOTA++].Nota = 10;
		strcpy(Nota[TLNOTA].RA, "26.24.1247-9");
		Nota[TLNOTA].CodDisciplina = 123;
		Nota[TLNOTA++].Nota = 3;
		strcpy(Nota[TLNOTA].RA, "26.24.1247-9");
		Nota[TLNOTA].CodDisciplina = 321;
		Nota[TLNOTA++].Nota = 5;
		strcpy(Nota[TLNOTA].RA, "26.24.1257-9");
		Nota[TLNOTA].CodDisciplina = 456;
		Nota[TLNOTA++].Nota = 2;
		strcpy(Nota[TLNOTA].RA, "26.24.1257-9");
		Nota[TLNOTA].CodDisciplina = 654;
		Nota[TLNOTA++].Nota = 7.50;
		strcpy(Nota[TLNOTA].RA, "26.24.1237-9");
		Nota[TLNOTA].CodDisciplina = 456;
		Nota[TLNOTA++].Nota = 4.30;
		strcpy(Nota[TLNOTA].RA, "26.24.1237-9");
		Nota[TLNOTA].CodDisciplina = 654;
		Nota[TLNOTA++].Nota = 1;
		strcpy(Nota[TLNOTA].RA, "26.24.1217-9");
		Nota[TLNOTA].CodDisciplina = 789;
		Nota[TLNOTA++].Nota = 7;
		strcpy(Nota[TLNOTA].RA, "26.24.1217-9");
		Nota[TLNOTA].CodDisciplina = 654;
		Nota[TLNOTA++].Nota = 4;
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Todos os dados cadastrados");
	}
	else{
		textcolor(YELLOW);
		gotoxy(52,25);
		printf("Nao eh possivel apos cadastrar dados");
	}
}

void Ir_Relatorios(char &op) {
	system("CLS");
	Borda_Menu();
	Preenchimento_Menu();
    gotoxy(52, 7);
    printf("Ir para relatorios?");
    gotoxy(52, 9);
    printf("[S] Sim");
    gotoxy(52, 11);
    printf("[N] Nao");
    gotoxy(52, 13);
    printf("OBS: Nao podera retornar ao menu principal");
    fflush(stdin);
    op = (toupper(getch()));
}

void Menu_Consultas(char &op){
	Clear_Fora();
	Clear_Display();
	Clear_op();
	Borda_Menu();
	Preenchimento_Menu();
	textcolor(YELLOW);
	gotoxy(65,12);
	printf("ESCOLHA UMA OPCAO");
	gotoxy(55,5);
	printf("MENU CONSULTAS");
	gotoxy(23,7);
	textcolor(WHITE);
	printf("[A] CONSULTA ALUNO");
	gotoxy(23,9);
	printf("[B] CONSULTA DISCIPLINA");
	gotoxy(23,11);
	printf("[C] CONSULTA NOTA");
	gotoxy(23,13);
	printf("[D] EXIBIR ALUNOS");
	gotoxy(23,15);
	printf("[E] EXIBIR DISCIPLINAS");
	gotoxy(23,17);
	printf("[F] EXIBIR NOTAS");
	gotoxy(23,19);
	printf("[ESC] MENU PRINCIPAL");
	op=toupper(getch());
	Clear_Mensagem();
	Clear_Display();
	Menu_Consultas_Color(op);
}

void Menu_Consultas_Color(char &op){
	
	textcolor(YELLOW);
	switch(op){
		case 'A':{
			gotoxy(23,7);
			printf("[A] CONSULTA ALUNO");
			break;
		}
		case 'B':{
			
			gotoxy(23,9);
			printf("[B] CONSULTA DISCIPLINA");
			break;
		}
		case 'C':{
			gotoxy(23,11);
			printf("[C] CONSULTA NOTA");
			break;
		}
		case 'D':{
			gotoxy(23,13);
			printf("[D] EXIBIR ALUNOS");
			break;
		}
		case 'E':{
			gotoxy(23,15);
			printf("[E] EXIBIR DISCIPLINAS");
			break;
		}
		case 'F':{
			gotoxy(23,17);
			printf("[F] EXIBIR NOTAS");
			break;
		}
	}
}

void Menu_Funcoes(char &op) {
	
	Clear_Fora();
	Clear_op();
	Clear_Display();
	Borda_Menu();
	Preenchimento_Menu();
	textcolor(YELLOW);
	gotoxy(65,12);
	printf("ESCOLHA UMA OPCAO");
	gotoxy(55,5);
	printf("MENU DE CONTROLE");
	gotoxy(23,7);
	textcolor(WHITE);
	printf("[A] CADASTRO ALUNO");
	gotoxy(23,9);
	printf("[B] CADASTRO DISCIPLINA");
	gotoxy(23,11);
	printf("[C] CADASTRO NOTAS");
	gotoxy(23,13);
	printf("[D] EXCLUSAO ALUNO");
	gotoxy(23,15);
	printf("[E] EXCLUSAO DISCIPLINA");
	gotoxy(23,17);
	printf("[F] EXCLUSAO NOTA");
	gotoxy(23,19);
	printf("[G] ALTERACAO ALUNO");
	gotoxy(23,21);
	printf("[H] ALTERACAO DISCIPLINA");
	gotoxy(23,23);
	printf("[I] ALTERACAO NOTA");
	gotoxy(23,25);
	printf("[ESC] MENU PRINCIPAL");
	op=toupper(getch());
	Clear_Mensagem();
	Borda_Menu();
	Preenchimento_Menu();
	Clear_Display();
	Menu_Funcoes_Color(op);
}

void Menu_Funcoes_Color(char &op){
	
	textcolor(YELLOW);
	switch(op){
		case 'A':{
			gotoxy(23,7);
			printf("[A] CADASTRO ALUNO");
			break;
		}
		case 'B':{
			
			gotoxy(23,9);
			printf("[B] CADASTRO DISCIPLINA");
			break;
		}
		case 'C':{
			gotoxy(23,11);
			printf("[C] CADASTRO NOTAS");
			break;
		}
		case 'D':{
			gotoxy(23,13);
			printf("[D] EXCLUSAO ALUNO");
			break;
		}
		case 'E':{
			gotoxy(23,15);
			printf("[E] EXCLUSAO DISCIPLINA");
			break;
		}
		case 'F':{
			gotoxy(23,17);
			printf("[F] EXCLUSAO NOTA");
			break;
		}
		case 'G':{
			gotoxy(23,19);
			printf("[G] ALTERACAO ALUNO");
			break;
		}
		case 'H':{
			gotoxy(23,21);
			printf("[H] ALTERACAO DISCIPLINA");
			break;
		}
		case 'I':{
			gotoxy(23,23);
			printf("[I] ALTERACAO NOTA");
			break;
		}
	}
}

void Menu_Outros(char &op){
	Clear_Fora();
	Clear_op();
	Clear_Display();
	Borda_Menu();
	Preenchimento_Menu();
	textcolor(YELLOW);
	gotoxy(65,12);
	printf("ESCOLHA UMA OPCAO");
	gotoxy(55, 5); 
	printf("CADASTRO AUTOMATICO");
	gotoxy(24,8);
	textcolor(WHITE);
	printf("[A] INSERIR ALUNOS");
	gotoxy(24,10);
	printf("[B] INSERIR DISCIPLINAS");
	gotoxy(24,12);
	printf("[C] INSERIR TODOS");
	gotoxy(24,14);
	printf("[ESC] MENU PRINCIPAL");
	op=toupper(getch());
	Clear_Mensagem();
	Borda_Menu();
	Preenchimento_Menu();
	Clear_Display();
	Menu_Outros_Color(op);
}

void Menu_Outros_Color(char &op){
	textcolor(YELLOW);
	switch(op){
		case 'A':{
			gotoxy(24,8);
			printf("[A] INSERIR ALUNOS");
			break;
		}
		case 'B':{
			gotoxy(24,10);
			printf("[B] INSERIR DISCIPLINAS");
			break;
		}
		case 'C':{
			gotoxy(24,12);
			printf("[C] INSERIR TODOS");
			break;
		}
		
	}
}

void Preenchimento_Menu(){
	int i, x, y;
	textcolor(RED);
	gotoxy(50,6);
	printf("%c", 203);
	gotoxy(50,26);
	printf("%c", 202);
	
	for(i=0, y= 7;i<19;i++, y++){
		gotoxy(50,y);
		printf("%c", 186);
	}
	for(i=0, x=51;i<47;i++, x++){
		gotoxy(x,21); 
		printf("%c", 205);
	}
	gotoxy(50,21);
	printf("%c", 204);
	gotoxy(98, 21);
	printf("%c", 185);
	gotoxy(70, 22);
	printf("MENSAGENS");
}

void Menu_Principal(char &op){
	Clear_Fora();
	system("CLS");
	Borda_Menu();
    gotoxy(55, 5);
    textcolor(YELLOW);
    printf("NOME TABELA");
    gotoxy(50, 12);
    textcolor(WHITE);
    printf("[A] MENU CADASTRO");
    gotoxy(50, 14);
    printf("[B] MENU VISUALIZACAO");
    gotoxy(50, 16);
    printf("[C] CADASTRO AUTOMATICO");
    gotoxy(50, 18);
    printf("[ESC] RELATORIOS");
    gotoxy(50, 24);
    textcolor(YELLOW);
    printf("BOM PROVEITO!");
    gotoxy(45,24);
    printf("AUTORES: PEDRO, NICOLY, LEANDRO");
	op=toupper(getch());
	Clear_Mensagem();
}

void Menu_Relatorios(char &op){
	Clear_Fora();
	Clear_op();
	Clear_Display();
	Borda_Menu();
	Preenchimento_Menu();
	textcolor(YELLOW);
	gotoxy(55,5);
	printf("MENU DE RELATORIOS");
	gotoxy(24,10);
	textcolor(WHITE);
	printf("[A] ALUNOS REPROVADOS");
	gotoxy(24,12);
	printf("[B] ALUNOS DETER. LETRA");
	gotoxy(24,14);
	printf("[C] DISCIP. DETER. TERMO");
	gotoxy(24,16);
	printf("[D] MEDIA ACIMA 6.0");
	gotoxy(24,18);
	printf("[E] MEDIA ABAIXO 6.0");
	gotoxy(24,20);
	printf("[F] RELATORIO COMPLETO");
	gotoxy(24,22);
	printf("[ESC] ENCERRAR PROGRAMA");
	op=toupper(getch());
	Clear_Mensagem();
	Borda_Menu();
	Preenchimento_Menu();
}

void Ordenacao_Aluno(_Aluno Aluno[TFAluno], int &TLRA, char RAaux[13], char Nomeaux[20]){
	int i, j, inseriu = 0;
    if(TLRA > 0) {
        for(i=0;i<TLRA && inseriu==0;i++){
            if(stricmp(Nomeaux, Aluno[i].Nome) <0){
                for(j=TLRA;j>i;j--){
                    strcpy(Aluno[j].Nome, Aluno[j-1].Nome);
                    strcpy(Aluno[j].RA, Aluno[j-1].RA);
                }
                strcpy(Aluno[i].Nome, Nomeaux);
                strcpy(Aluno[i].RA, RAaux);
                inseriu = 1;
            }
        }
        if(inseriu == 0){
			strcpy(Aluno[TLRA].Nome, Nomeaux);
	        strcpy(Aluno[TLRA].RA, RAaux);
	    }
    }
	else{
        strcpy(Aluno[0].Nome, Nomeaux);
        strcpy(Aluno[0].RA, RAaux);
    }
    TLRA++;
}

void Ordenacao_Disciplina(_Disciplina Disciplina[TFDisciplina], int &TLCOD, int CODaux, char Disciplinaaux[30]){
	int i, j, inseriu = 0;
    if (TLCOD > 0){
        for(i=0;i<TLCOD&&inseriu==0;i++){
            if(CODaux < Disciplina[i].CodDisciplina){
                for(j=TLCOD;j>i;j--){
                	Disciplina[j].CodDisciplina = Disciplina[j-1].CodDisciplina;
                    strcpy(Disciplina[j].Disciplina, Disciplina[j-1].Disciplina);
                }
                Disciplina[i].CodDisciplina = CODaux;
                strcpy(Disciplina[i].Disciplina, Disciplinaaux);
                inseriu = 1;
            }
        }
        if(inseriu == 0){
			Disciplina[i].CodDisciplina = CODaux;
            strcpy(Disciplina[i].Disciplina, Disciplinaaux);
	    }
    }
	else{
        Disciplina[0].CodDisciplina = CODaux;
        strcpy(Disciplina[0].Disciplina, Disciplinaaux);
    }
    TLCOD++;
}

void Ordenacao_Nota(_Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota], int &TLRA, int &TLCOD, int &TLNOTA, char RAaux[13], int CODaux, float Notaaux) {
    int i, j, inseriu = 0;
    char Nomeaux[20], NomeNota[20];

    Busca_Nome_Com_RA(Aluno, TLRA, Nomeaux, RAaux);
    if (TLNOTA > 0) {
        for (i = 0; i < TLNOTA && inseriu == 0; i++) {
            Busca_Nome_Com_RA(Aluno, TLRA, NomeNota, Nota[i].RA);
            
            if (stricmp(Nomeaux, NomeNota) < 0) {
                for (j = TLNOTA; j > i; j--) {
                    strcpy(Nota[j].RA, Nota[j - 1].RA);
                    Nota[j].Nota = Nota[j - 1].Nota;
                    Nota[j].CodDisciplina = Nota[j - 1].CodDisciplina;
                }
                strcpy(Nota[i].RA, RAaux);
                Nota[i].Nota = Notaaux;
                Nota[i].CodDisciplina = CODaux;
                inseriu = 1;
            }
            else if (stricmp(Nomeaux, NomeNota) == 0) {
                if (CODaux < Nota[i].CodDisciplina) {
                    for (j = TLNOTA; j > i; j--) {
                        strcpy(Nota[j].RA, Nota[j - 1].RA);
                        Nota[j].Nota = Nota[j - 1].Nota;
                        Nota[j].CodDisciplina = Nota[j - 1].CodDisciplina;
                    }
                    strcpy(Nota[i].RA, RAaux);
                    Nota[i].Nota = Notaaux;
                    Nota[i].CodDisciplina = CODaux;
                    inseriu = 1;
                }
            }
        }
        if (inseriu == 0) {
            strcpy(Nota[TLNOTA].RA, RAaux);
            Nota[TLNOTA].Nota = Notaaux;
            Nota[TLNOTA].CodDisciplina = CODaux;
        }
    } else {
        strcpy(Nota[0].RA, RAaux);
        Nota[0].Nota = Notaaux;
        Nota[0].CodDisciplina = CODaux;
    }
    TLNOTA++;
}

void Relatorios(int &TLRA, int &TLCOD, int &TLNOTA, _Aluno Aluno[TFAluno], _Disciplina Disciplina[TFDisciplina], _Nota Nota[TFNota]){
	char op;
	Menu_Relatorios(op);
	while(op != 27){
		switch(op){
			case'A':{ Consulta_Reprovados(Nota, Aluno, TLNOTA, TLRA); break;}
			case'B':{ Consulta_Alunos_Por_Letra(Aluno, TLRA); break;}
			case'C':{ Consulta_Disciplinas_Por_Termo(Disciplina, TLCOD); break;}
			case'D':{ Consulta_Disciplinas_Media_Alta(Disciplina, Nota, TLCOD, TLNOTA); break;}
			case'E':{ Consulta_Disciplinas_Media_Baixa(Disciplina, Nota, TLCOD, TLNOTA);break;}
			case'F':{ Exibir_Alunos_Completo(Nota, Aluno, Disciplina, TLNOTA, TLRA, TLCOD); break;}
			default:{ 
				gotoxy(52,25);
				textcolor(YELLOW);
				printf("Mensagem: Escolha invalida");
				break;
			}
		}
		Menu_Relatorios(op);
	}
	
}

void TabASCII(){
	srand(time(NULL));
	int x, y, i;
	int xinicial = 3, xfinal;
	int yinicial = 1, yfinal;
	int numero_aleatorio;

	x = 3;
	y = yinicial = 1;
	yfinal = yinicial+30;
	i=0;
	while(i<256) {
		xinicial = x;
		xfinal = xinicial+8;

		for(; x <= xfinal; x++) {
			if(i>=232) {
				if(x==xinicial) {
					gotoxy(x,yinicial);
					printf("%c", 201);
					gotoxy(x,25);
					printf("%c", 200);
				} else if(x==xfinal) {
					gotoxy(x,yinicial);
					printf("%c", 187);
					gotoxy(x,25);
					printf("%c", 188);
				} else {
					gotoxy(x,yinicial);
					printf("%c", 205);
					gotoxy(x,25);
					printf("%c", 205);
				}
			} else {
				if(x==xinicial) {
					gotoxy(x,yinicial);
					printf("%c", 201);
					gotoxy(x,yfinal);
					printf("%c", 200);
				} else if(x==xfinal) {
					gotoxy(x,yinicial);
					printf("%c", 187);
					gotoxy(x,yfinal);
					printf("%c", 188);
				} else {
					gotoxy(x,yinicial);
					printf("%c", 205);
					gotoxy(x,yfinal);
					printf("%c", 205);
				}
			}
		}
		for(y=yinicial+1; y < 31 && i<256; y++, i++) {
			numero_aleatorio = rand() % 15 + 1 ;
			textcolor(numero_aleatorio);
			gotoxy(xinicial,y);
			printf("%c", 186);
			gotoxy(xfinal,y);
			printf("%c", 186);
			gotoxy(xinicial+1,y);
			printf("%d %u", i, i);
		}
		x += 4;
		if(i%29 == 0) {
			i++;
		}
	}
}

void Todas_Disciplinas(int &TLCOD, _Disciplina Disciplina[TFDisciplina]){
	int i, y = 7, x, j;
	
	if(TLCOD > 0){
		textcolor(YELLOW);
		gotoxy(53,5);
		printf("Tabela Disciplinas");
		textcolor(WHITE);
		
		if(TLCOD>0){
			for(i=0, j=1;i<TLCOD;i++, j++){
				gotoxy(52,y++);
				printf("Disciplina: %s", Disciplina[i].Disciplina);
				gotoxy(52,y++);
				printf("Codigo: %d", Disciplina[i].CodDisciplina);
				gotoxy(52,y++);
				if(j%5 != 0){
				for(x=51;x<97 && y < 21;x++){
						printf("%c", 196);
					}
				}
				if(j != TLCOD && j%5 == 0){
					gotoxy(52,23);
					textcolor(YELLOW);
					printf("Pressione enter para avancar a proxima tabela");
					getch();
					Clear_Display();
					Clear_Mensagem();
					y=7;
					textcolor(WHITE);
				}
			}
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Pressione ENTER para voltar ao menu");
			getch();
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Nao ha dados para consultar");
		}
		Clear_Mensagem();
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Nao ha disciplinas cadastradas");
	}
}

void Todas_Notas(int &TLNOTA, _Nota Nota[TFNota]){
	int i, y = 7, x, j;
	if(TLNOTA > 0)
	{
		textcolor(YELLOW);
		gotoxy(54,5);
		printf("Tabela Notas");
		textcolor(WHITE);
		
		if(TLNOTA>0){
			for(i=0, j=1;i<TLNOTA;i++, j++){
				gotoxy(52,y++);
				printf("RA: %s", Nota[i].RA);
				gotoxy(52,y++);
				printf("Codigo: %d", Nota[i].CodDisciplina);
				gotoxy(52,y++);
				printf("Nota: %.2f", Nota[i].Nota);
				gotoxy(52,y++);
				for(x=51;x<97 && y < 21;x++){
					printf("%c", 196);
				}
				if(j%3 == 0 && j != TLNOTA){
					if(TLNOTA>5){
						gotoxy(52,23);
						textcolor(YELLOW);
						printf("Pressione enter para avancar a proxima tabela");
						getch();
						Clear_Display();
						Clear_Mensagem();
						y=7;
						textcolor(WHITE);
					}
				}
			}
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Pressione ENTER para voltar ao menu");
			getch();
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Nao ha dados para consultar");
		}
		Clear_Mensagem();
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Nao ha notas cadastradas");
	}
}

void Todos_Alunos(int &TLRA, _Aluno Aluno[TFAluno]){
	int i, y = 7, x, j;
	
	if(TLRA > 0){
		textcolor(YELLOW);
		gotoxy(54,5);
		printf("Tabela Alunos");
		textcolor(WHITE);
		if(TLRA>0){
			for(i=0, j=1;i<TLRA;i++, j++){
				gotoxy(52,y++);
				printf("RA: %s", Aluno[i].RA);
				gotoxy(52,y++);
				printf("Nome: %s", Aluno[i].Nome);
				gotoxy(52,y++);
				if(j%5 != 0){
				for(x=51;x<97 && y < 21;x++){
						printf("%c", 196);
					}
				}
				if(j != TLRA && j%5 == 0){
					gotoxy(52,23);
					textcolor(YELLOW);
					printf("Pressione enter para avancar a proxima tabela");
					getch();
					Clear_Display();
					Clear_Mensagem();
					y=7;
					textcolor(WHITE);
				}
			}
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Pressione ENTER para voltar ao menu");
			getch();
		}
		else{
			gotoxy(52,25);
			textcolor(YELLOW);
			printf("Mensagem: Nao ha dados para consultar");
		}
		Clear_Mensagem();
	}
	else{
		gotoxy(52,25);
		textcolor(YELLOW);
		printf("Mensagem: Nao ha alunos cadastradas");
	}
}
