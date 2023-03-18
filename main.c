#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LOCALIZACAO "C:\\Users\\Tarcyo\\Desktop\\matriz.txt"
#define TIPOCONSULTA "r+"

float laplace(int tamanho,float matriz[tamanho][tamanho]);
float calculaDeterminanteDaMatriz(int tamanho,float matriz[tamanho][tamanho]);


float converteTextoEmNumero(char *texto)
{
  float numero=0;
  int temPonto=0;
  for(int i;texto[i]!='\0';i++){
    if(texto[i]=='.'){
        temPonto++;
    }
  }
  if(temPonto>1){
    printf("Numero Errado!!!");
    exit(0);
  }
  float parteInteira=0;
  float parteDecimal=0;
  int posPonto;
  for(posPonto=0;texto[posPonto]!='.'&&posPonto<strlen(texto);posPonto++){
  }
  for(int mult=1, i=posPonto-1;i>=0;i--,mult=mult*10){
     int a=0;
     if(texto[i]=='1'){
        a=1;
     }
     if(texto[i]=='2'){
        a=2;
     }
     if(texto[i]=='3'){
        a=3;
     }
     if(texto[i]=='4'){
        a=4;
     }
     if(texto[i]=='5'){
        a=5;
     }
     if(texto[i]=='6'){
        a=6;
     }
     if(texto[i]=='7'){
        a=7;
     }
     if(texto[i]=='8'){
        a=8;
     }
     if(texto[i]=='9'){
        a=9;
     }
     parteInteira=parteInteira+a*mult;

  }
  float mult=0.1;
  for(int i=posPonto+1;i<strlen(texto);i++){
     int a=0;
     if(texto[i]=='1'){
        a=1;
     }
     if(texto[i]=='2'){
        a=2;
     }
     if(texto[i]=='3'){
        a=3;
     }
     if(texto[i]=='3'){
        a=3;
     }
     if(texto[i]=='4'){
        a=4;
     }
     if(texto[i]=='5'){
        a=5;
     }
     if(texto[i]=='6'){
        a=6;
     }
     if(texto[i]=='7'){
        a=7;
     }
     if(texto[i]=='8'){
        a=8;
     }
     if(texto[i]=='9'){
        a=9;
     }
     parteDecimal=parteDecimal+a*mult;
     mult=mult*0.1;
  }
  if(temPonto==1){
      numero=parteInteira+parteDecimal;
  }else{
       numero=parteInteira+0.0;
  }

  //printf("%.4f",numero);

  return numero;
}
void mostraMensagemDeErro(char mensagem[555]){
    printf("%s",mensagem);
    exit(0);
}

FILE *leArquivo(char localizacao[500], char tipoConsulta[500])
{
    FILE *arquivo;
    arquivo = fopen(localizacao, tipoConsulta);
    verificaArquivo(arquivo);
    return arquivo;
}

void verificaArquivo(FILE *arquivo)
{
    if (arquivo == NULL)
    {
        mostraMensagemDeErro("ARQUIVO NÃO EXISTE!!!!!!!!!!!");
    }
}
void mostraMatriz(int tamanho,float matriz[tamanho][tamanho]){
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            printf(" %.0f ",matriz[i][j]);
        }
        printf("\n");
    }
}
void defineSubMatriz(int tamanho,float matriz[tamanho][tamanho],float subMatriz[tamanho-1][tamanho-1],int linha,int coluna){
    int linhaAtual=0;
    int colunaAtual=0;
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(coluna!=j&&linha!=i){
                subMatriz[linhaAtual][colunaAtual]=matriz[i][j];
                colunaAtual++;
            }
            if(colunaAtual==tamanho-1){
                colunaAtual=0;
                linhaAtual++;
            }
            if(linhaAtual==tamanho-1){
                return;
            }
        }
    }
}
float calculaDeterminanteDaMatriz(int tamanho,float matriz[tamanho][tamanho]){
    if(tamanho==1){
        return matriz[0][0];
    }
    return laplace(tamanho,matriz);
}
float laplace(int tamanho,float matriz[tamanho][tamanho]){
    float somatorio=0;
    int fator=1;
    for(int i=0;i<tamanho;i++){
       float subMatiz[tamanho-1][tamanho-1];
       defineSubMatriz(tamanho,matriz,subMatiz,0,i);
       somatorio=somatorio+(fator*matriz[0][i])*calculaDeterminanteDaMatriz(tamanho-1,subMatiz);
       fator=fator*(-1);
    }
    return somatorio;
}
int main(){
   float determinante=0;
   FILE *arquivo=leArquivo(LOCALIZACAO,TIPOCONSULTA);
   char linha[5000];
   fflush(arquivo);
   int linhas=0;
   for(int i=1; fgets(linha,5000,arquivo)!=NULL;i++){
      char caracter=linha[0];
      if(caracter!='1'&&caracter!='0'&&caracter!='2'&&caracter!='3'&&caracter!='4'&&caracter!='5'&&caracter!='6'&&caracter!='7'&&caracter!='8'&&caracter!='9'){
         mostraMensagemDeErro("A MATRIZ ESTÁ INCORRETA!!!");
      }else{
          linhas++;
      }
    }

   rewind(arquivo);
   for(int i=1; fgets(linha,5000,arquivo)!=NULL;i++){
       int quantEspacosNaLinha=0;
       for(int j=0;j<strlen(linha);j++){
          if(linha[j]==' '){
            quantEspacosNaLinha++;

          }

       }
       if(quantEspacosNaLinha!=linhas-1){
            mostraMensagemDeErro("A QUANTIDADE DE LINHAS É DIFERENTE DA QUANTIDADE DE COLUNAS.");
        }

   }
   rewind(arquivo);
   char caracter;
   int a=1;
   while(a==1){
        caracter=fgetc(arquivo);
        if(caracter==EOF){
            a=0;
        }else{
           if(caracter!='.'&&caracter!='1'&&caracter!='0'&&caracter!='2'&&caracter!='3'&&caracter!='4'&&caracter!='5'&&caracter!='6'&&caracter!='7'&&caracter!='8'&&caracter!='9'&&caracter!='.'&&caracter!='\n'&&caracter!=' '){
             mostraMensagemDeErro("A MATRIZ SÓ PODE CONTER NÚMEROS!");
           }

        }
   }
   rewind(arquivo);
   float matriz[linhas][linhas];
   int coluna=0;
   int pos=0;
   for(int i=0;i<linhas;i++){
    fgets(linha,5000,arquivo);
    for(int j=0;j<strlen(linha);j++){
        char numeroString[500]="";
        for(j=j;linha[j]!='\n'&&linha[j]!=' '&&linha[j]!=EOF&&linha[j]!='\0'&&j<strlen(linha);j++){
                numeroString[pos]=linha[j];
                pos++;

        }
        pos=0;
        printf(" %s",numeroString);
        matriz[i][coluna]=converteTextoEmNumero(numeroString);
        coluna++;
    }
    coluna=0;
    printf("\n");
   }
   printf("\n");
   printf("O determinante da matriz e: %.2f",calculaDeterminanteDaMatriz(linhas,matriz));
   return 0;
}
