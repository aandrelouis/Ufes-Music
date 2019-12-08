#include <stdio.h>      
#include <stdlib.h>
#include "midia.h"          
#include <string.h>

struct midia{               //struct Midia
    char *nomeDaMidia;      //ponteiro char para o nome da midia
    char *artista[3];       //um vetor de 3 ponteiros char para os artistas//max:3
    char *nomeDoCompositor[3];  //um vetor de 3 ponteiros char para os compositores //max:3
    int qtdCompositores;        //um int de quantidade de compositores para ter controle na hora ler e imprimir
    int qtdArtistas;            //um int para ter controle sobre os artistas
    char *genero;               //ponteiro char para genero
    char *gravadora;            //ponteiro char para gravadora
    float duracao;              //float pra duração
    int tipo;       //int que representa o tipo da midia 1-musica//2-Podcast//3-Video                  
};


Midia* CriaMidia(){                     //Cria Midia não recebe argumentos
    Midia* midia;                       //Cria um novo endereço de Midia
        midia=(Midia*)malloc(sizeof(Midia));    //Aloca o endereço Criado

        return midia;                   //retorna o endereço alocado
}
void ImprimiMidiacomIDtipo(Midia* midia,int ID){ //Essa função recebe ponteiro Midia e um tipo    
    if(ID==1){                              //o tipo recebido ira decidir qual dos ifs entrara
        ImprimeMusica(midia);               //tendo tres funções de imprimi respectivas ao tipo de midia
    }
    else if(ID==3){
    ImprimePodCast(midia);
    }
    else if(ID==2){
    ImprimeVideo(midia);    
    }
}


void ImprimeMidia(Midia* midia){ //Essa função  recebe um ponteiro Midia
    if(midia->tipo == 1){        //E de acordo com o tipo da midia definido na hora de criar
        ImprimeMusica(midia);    //ela chama a função de imprimir aquele tipo de midia
    }                             //1-musica//2-PODcast//3-Video  
    else if(midia->tipo == 2){      //Não retorna nada
        ImprimePodCast(midia);
    }
    else if(midia->tipo == 3){
        ImprimeVideo(midia);
    }
    
}

void ImprimeMusica(Midia* midia){   //Essa função ira receber  ponteiro midia
    if(midia!=NULL){                //Entrara no if se o ponteiro foi criado e alocafo corretamente
    printf("[Musica]\n");           //printa o tipo de midia    
    printf("Nome: [%s]\n",midia->nomeDaMidia); //printa o nome da midia 
    for(int j=0;j<midia->qtdArtistas;j++){      
    printf("Artista [%s]:\n",midia->artista[j]); //printa o nome dos artistas
       }                                        //de acordo com a quantidade
    for(int i=0;i<midia->qtdCompositores;i++){      //printa o nome dos compositores de acordo com a quantidade
    printf("Compositor:[%s]\n",midia->nomeDoCompositor[i]);
    }
    printf("Gravadora:|%s|\n",midia->gravadora);    //printa a gravadora
    printf("Gênero:|%s| \n",midia->genero);         //printa o genero da midia
    printf("Duração:|%.2f| \n",midia->duracao);     //printa a duração da midia    
    }
    else{
        printf("Não tem musica\n");         //se o ponteiro for null printa não exite musica
    }
}

void ImprimePodCast(Midia* midia){  //Recebe um ponteiro Midia 
    if(midia!=NULL){                //se ele foi criado e alocado corretamente ele entra no if
    printf("[PodCast]\n");           //printa o tipo de midia   
    printf("Nome: [%s]\n",midia->nomeDaMidia);  //printa o nome da midia
    for(int j=0;j<midia->qtdArtistas;j++){      //printa o nome do artista de acordo com a quantidade
    printf("Artista:[%s]\n",midia->artista[j]); 
    }
    printf("Gravadora:|%s|\n",midia->gravadora);//printa a gravadora(Produtora)
    printf("Duração:|%.2f| \n",midia->duracao); //printa a duração da midia
    }
    else{
        printf("Não tem Podcast\n");    //se o ponteiro dor null printa que nao existe
    }

}
void ImprimeVideo(Midia *midia){//Recebe um ponteiro Midia
    if(midia!=NULL){            //se o ponteiro dor diferente NULL
    printf("[Video]\n");        //imprimi o tipo de midia
    printf("Nome: [%s]\n",midia->nomeDaMidia);  //imprimi o nome da midia
    for(int j=0;j<midia->qtdArtistas;j++){      //imprimi o nome do artista de acordo com a quantidade
    printf("Artista[%s]: \n",midia->artista[j]);
    }
    printf("Gravadora:|%s|\n",midia->gravadora);    //imprimi a gravadora(Produtora)
    printf("Duração:|%.2f| \n",midia->duracao);     //imprimi a duração
    }
    else{
        printf("Não tem Video\n");//se o ponteiro for null printa que nao existe
    }
}

void PrencheMidiaNome(Midia* midia,char* entrada){
    //Recebe um ponteiro midia e um ponteiro char entrada
    //a função ira atribuir a entrada char para o nome da midia dentro da struct
    //e não retorna nada por estarmos tratando de ponteiro
    midia->nomeDaMidia=entrada;
}
void PrencheMidiaArtistaID(Midia* midia,char* entrada,int id){
    //Recebe um ponteiro midia,ponteiro char entrada e um int id
    //a função ira atribuir a entrada char para o artista dentro da struct na posicao do id
    //e não retorna nada por estarmos tratando de ponteiro
    midia->artista[id]=entrada;    
}
void PrencheMidiaGravadora(Midia* midia,char* entrada){
    //Recebe um ponteiro midia,ponteiro char entrada 
    //a função ira atribuir a entrada char para a gravadora dentro da struct
    //e não retorna nada por estarmos tratando de ponteiro
    midia->gravadora=entrada;
}

void PrencheMidiaTipo(Midia* midia,int tipo){
    //Recebe um ponteiro midia e um int tipo
    //a função ira atribuir o tipo int para dentro da struct(tipo)
    //e não retorna nada por estarmos tratando de ponteiro
    midia->tipo=tipo;
}
void PrencheMidiaCompositorid(Midia* midia,char* entrada,int id){
    //Recebe um ponteiro midia,ponteiro char entrada e um int id
    //a função ira atribuir a entrada char para o compositor dentro da struct na posicao do id
    //e não retorna nada por estarmos tratando de ponteiro
    midia->nomeDoCompositor[id]=entrada;
}
void PrencheDuracao(Midia* midia,float dura){
    //Recebe um ponteiro midia e um  float dura
    //a função ira atribuir o tipo float para dentro da struct(duracao)
    //e não retorna nada por estarmos tratando de ponteiro
    midia->duracao=dura;
}

void PrencheGenero(Midia* midia,char* entrada){
    //Recebe um ponteiro midia,ponteiro char entrada 
    //a função ira atribuir a entrada char para o genero dentro da struct
    //e não retorna nada por estarmos tratando de ponteiro 
    midia->genero=entrada;
}


void PreencheQuantArtistas(Midia* midia,int quant){
    //Recebe um ponteiro midia e um int quant
    //a função ira atribuir o tipo int para dentro da struct(quantartistas)
    //e não retorna nada por estarmos tratando de ponteiro
    midia->qtdArtistas=quant;
}

void PreencheQuantComp(Midia* midia,int quant){
    //Recebe um ponteiro midia e um int quant
    //a função ira atribuir o tipo int para dentro da struct(quantcompositores)
    //e não retorna nada por estarmos tratando de ponteiro
    midia->qtdCompositores=quant;
}


void Imprimioopcaomidia(){//A função não recebe nada
    printf("1-Musica // 2-Podcast // 3-Video\n");//printa na tela as opções possiveis de midia para criar
}


void DestroiMidia(Midia* midia){    //essa função recebe um ponteiro midia
    free(midia->artista[0]);        //da free no endereço de memoria dentro do ponteiro midia
    free(midia->artista[2]);        //vai liberando todos os ponteiros alocados dentro da struct
    free(midia->artista[1]);        //e no final libera o ponteiro da struct midia    
    free(midia->genero);
    free(midia->gravadora);
    free(midia->nomeDaMidia);
    free(midia->nomeDoCompositor[1]);
    free(midia->nomeDoCompositor[0]);
    free(midia->nomeDoCompositor[2]);
    free(midia);
}


int PesquisaacomNomeMidia(Midia* midia,char* entrada){  //essa função recebe ponteiro midia e um ponteiro char
    if(strcmp(midia->nomeDaMidia,entrada)==0){          //faz uma comparação entre os strings no ponteiro nome e entrada     
        return 1;                                       //se forem iguais a função retorna 1            
    }                                                   //se forem diferentes a função retorna zero    
    else{
        return 0;
  }
    
    
}

int PesquisaacomNomeArtista(Midia* midia,char* entrada){     //essa função recebe ponteiro midia e um ponteiro char entrada
    for(int i=0;i<midia->qtdArtistas;i++){                   //faz uma comparação entre as strings no ponteiro char artista e entrada        
        if(strcmp(midia->artista[i],entrada)==0){            //a comparação é feita com todos artistas que possuem na midia
                                                              //se 1 for igual a função retorna 1
        return 1;                                             //se forem diferentes a função retorna zero      
        }
    }
    
    return 0;
  
}
int PesquisaacomNomeCompositor(Midia* midia,char* entrada){ //essa função recebe ponteiro midia e um ponteiro char entrada
    if(midia->tipo==1){
    for(int i=0;i<midia->qtdCompositores;i++){              //faz uma comparação entre as strings no ponteiro char nomeCompositor e entrada 
        if(strcmp(midia->nomeDoCompositor[i],entrada)==0){  //a comparação é feita com todos os Compositores que possuem na midia
        return 1;                                           //se 1 for igual a função retorna 1        
        }                                                    //se forem diferentes a função retorna zero 
      }
    }
    return 0;
}

int PesquisaacomGenero(Midia* midia,char* entrada){
    //essa função recebe ponteiro midia e um ponteiro char entrada
    //faz uma comparação entre as strings no ponteiro char genero e entrada
    //se for igual a função retorna 1   
    //se forem diferentes a função retorna zero
    if(midia->tipo==1){
        if(strcmp(midia->genero,entrada)==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int PesquisaacomGravadora(Midia* midia,char* entrada){
    //essa função recebe ponteiro midia e um ponteiro char entrada
    //faz uma comparação entre as strings no ponteiro char gravadora e entrada
    //se for igual a função retorna 1   
    //se forem diferentes a função retorna zero
    if(strcmp(midia->gravadora,entrada)==0){
        return 1;
    }
    else{
        return 0;
  }
}

void CopiaMidia(Midia*original,Midia*copia){    //essa função recebe dois ponteiros Midia
    copia->tipo=original->tipo;                 //aloca todos o ponteiros da struct midia copia    
                                                 //atriubui todos os valores da midia original para a copia       
    copia->nomeDaMidia=(char*)malloc(50);         //e depois usando a função strcpy  
    copia->artista[0]=(char*)malloc(50);          //copia todos as strings da struct midia original para a midia copia  
    copia->artista[1]=(char*)malloc(50);
    copia->artista[2]=(char*)malloc(50);
    copia->genero=(char*)malloc(50);;
    copia->gravadora=(char*)malloc(50);
    copia->nomeDoCompositor[0]=(char*)malloc(50);
    copia->nomeDoCompositor[1]=(char*)malloc(50);
    copia->nomeDoCompositor[2]=(char*)malloc(50);
    
    copia->qtdArtistas=original->qtdArtistas;
    copia->duracao=original->duracao;   
    strcpy(copia->nomeDaMidia,original->nomeDaMidia); 
    strcpy(copia->gravadora,original->gravadora);
    
    for(int i=0;i<original->qtdArtistas;i++){       //copia as strings para outra struct de acordo com a quantidade
        strcpy(copia->artista[i],original->artista[i]);
    }
    if(original->tipo==1){                      //se o tipo midia dor igual a 1--possui caracteristicas a mais que os outros tipos
        strcpy(copia->genero,original->genero); //entra no if e copia as informções a mais que possui de acordo com a quantidade
        copia->qtdCompositores=original->qtdCompositores;    
        
        for(int j=0;j<original->qtdCompositores;j++){
            strcpy(copia->nomeDoCompositor[j],original->nomeDoCompositor[j]);
        }    
    }
    
}
Midia* AlocaTudoMidia(){
  Midia* midia;  
  midia=(Midia*)malloc(sizeof(Midia));
  midia->nomeDaMidia=(char*)malloc(50);
  midia->genero=(char*)malloc(50);
  midia->gravadora=(char*)malloc(50);
  midia->artista[0]=(char*)malloc(50);
  midia->artista[1]=(char*)malloc(50);  
  midia->artista[2]=(char*)malloc(50);
  midia->nomeDoCompositor[0]=(char*)malloc(50);
  midia->nomeDoCompositor[1]=(char*)malloc(50); 
  midia->nomeDoCompositor[2]=(char*)malloc(50); 
  return midia;
} 




Midia* LeituraMidiarquivo(FILE *arquivo){   
    Midia* midia;
    midia=AlocaTudoMidia();
    
        fscanf(arquivo,"%d",&midia->tipo);
        fscanf(arquivo,"\n");
        
        
        fscanf(arquivo,"%[^\n]s",midia->nomeDaMidia);
        fscanf(arquivo,"\n");
        
        fscanf(arquivo,"%d",&midia->qtdArtistas);
        fscanf(arquivo,"\n");
        
        for(int i=0;i<midia->qtdArtistas;i++){
            fscanf(arquivo,"%[^\n]s",midia->artista[i]);
            fscanf(arquivo,"\n");
        }
        fscanf(arquivo,"%[^\n]s",midia->gravadora);
        fscanf(arquivo,"\n");
        
         
        fscanf(arquivo,"%f",&midia->duracao);
        fscanf(arquivo,"\n");
        
        
        if(midia->tipo==1){
            fscanf(arquivo,"%d",&midia->qtdCompositores);
            fscanf(arquivo,"\n");
        
            for(int i=0;i<midia->qtdCompositores;i++){
                fscanf(arquivo,"%[^\n]s",midia->nomeDoCompositor[i]);
                fscanf(arquivo,"\n");
            }
        
            fscanf(arquivo,"%[^\n]s",midia->genero);
            fscanf(arquivo,"\n");
        }
        return midia;
}



void ImprimeMusicaArquivo(Midia* midia,FILE*arquivo){  
    fprintf(arquivo,"%d",midia->tipo);
    fprintf(arquivo,"\n");
    fprintf(arquivo,midia->nomeDaMidia,"%s");
    fprintf(arquivo,"\n");
    
    
    fprintf(arquivo,"%d",midia->qtdArtistas);
    fprintf(arquivo,"\n");
    for(int j=0;j<midia->qtdArtistas;j++){      
        fprintf(arquivo,midia->artista[j],"%s"); 
        fprintf(arquivo,"\n");
    }
    
    fprintf(arquivo,midia->gravadora,"%s");
    fprintf(arquivo,"\n");
    
    fprintf(arquivo,"%.2f",midia->duracao);        
    fprintf(arquivo,"\n");
    
    
    fprintf(arquivo,"%d",midia->qtdCompositores);
    fprintf(arquivo,"\n");
    
    for(int i=0;i<midia->qtdCompositores;i++){      
        fprintf(arquivo,midia->nomeDoCompositor[i],"%s");
        fprintf(arquivo,"\n");
    }

    fprintf(arquivo,midia->genero,"%s"); 
    fprintf(arquivo,"\n");


}

void ImprimePodcastArquivo(Midia* midia,FILE*arquivo){  
    
    fprintf(arquivo,"%d",midia->tipo);
    fprintf(arquivo,"\n");
    
    fprintf(arquivo,midia->nomeDaMidia,"%s");
    fprintf(arquivo,"\n");
    
    
    fprintf(arquivo,"%d",midia->qtdArtistas);
    fprintf(arquivo,"\n");
    for(int j=0;j<midia->qtdArtistas;j++){      
        fprintf(arquivo,midia->artista[j],"%s"); 
        fprintf(arquivo,"\n");
    }
    
    fprintf(arquivo,midia->gravadora,"%s");
    fprintf(arquivo,"\n");
    
    fprintf(arquivo,"%.2f",midia->duracao);        
    fprintf(arquivo,"\n");
    
}

void ImprimeVideoArquivo(Midia* midia,FILE*arquivo){ 
    
    fprintf(arquivo,"%d",midia->tipo);
    fprintf(arquivo,"\n");
    
    fprintf(arquivo,midia->nomeDaMidia,"%s");
    fprintf(arquivo,"\n");
    
    
    fprintf(arquivo,"%d",midia->qtdArtistas);
    fprintf(arquivo,"\n");
    for(int j=0;j<midia->qtdArtistas;j++){      
        fprintf(arquivo,midia->artista[j],"%s"); 
        fprintf(arquivo,"\n");
    }
    
    fprintf(arquivo,midia->gravadora,"%s");
    fprintf(arquivo,"\n");
    
    fprintf(arquivo,"%.2f",midia->duracao);        
    fprintf(arquivo,"\n");
    
}



void ImprimeMidiaArquivo(Midia* midia,FILE*arquivo){ 
    if(midia->tipo == 1){       
        ImprimeMusicaArquivo(midia,arquivo);
    }                             
    else if(midia->tipo == 2){      
       ImprimePodcastArquivo(midia,arquivo);
    }
    else if(midia->tipo == 3){
       ImprimeVideoArquivo(midia,arquivo);
    }
    
}
