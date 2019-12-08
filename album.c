#include <stdio.h>
#include <stdlib.h>
#include "album.h"
#include "midia.h"
#include <string.h>

struct album{         //Struct Album
    char *nomeDoAlbum;  //ponteiro char para o nome do album
    char *artista;      //ponteiro cahr para o nome do artista
    int anoDoAlbum;     //int para o ano do album
    char *genero;       //ponteiro char para o genero
    char* compositores[3];  //vetor de ponteiro char para o nome dos compositores
    Midia *midia[20];       //vetor de ponteiro midia para as midias do album
    int qtdCompositores;    //int quantidade de compositores para ter controle sobre compositores(leitura e impressao)
    int qtdMidias;   //int quantidade de midias para ter controle sobre o vetor de midias
};


Album* CriaAlbum(){ //Essa funçao não recebe argumentos 
    Album* novo;    //Criar um novo ponteiro album 
    novo=(Album*)malloc(sizeof(Album)); //Vai alocar o ponteiro novo
    return novo;    //e retornar esse ponteiro alocado
}

void AlocaAlbum(Album* album){  //Essa função vai receber um ponteiro album
    album=(Album*)malloc(sizeof(Album));    //e vai alocar o ponteiro album recebido
                                            //Não retorna nada por tratarmos de ponteiro
}


void PrencheAlbumNome(Album* album,char*entrada){
    //Essa função recebe um ponteiro album e um ponteiro char entrada
    //ela vai passar o ponteiro entrada para nome do album dentro do ponteiro album
    //Não vai retornar nada por tratarmos de ponteiro
    album->nomeDoAlbum=entrada;
}
void PrencheAlbumArtista(Album* album,char*entrada){
    //Essa função recebe um ponteiro album e um ponteiro char entrada
    //ela vai passar o ponteiro entrada para o artista dentro do ponteiro album
    //Não vai retornar nada por tratarmos de ponteiro
    album->artista=entrada;
}
void PrencheAlbumGenero(Album* album,char*entrada){
    //Essa função recebe um ponteiro album e um ponteiro char entrada
    //ela vai atribuir o char entrada para o  artista dentro do ponteiro album
    //Não vai retornar nada por tratarmos de ponteiro
    album->genero=entrada;
}
void PrencheAlbumAno(Album* album,int entrada){
    //Essa função recebe um ponteiro album e um int entrada
    //ela vai atribuir o int entrada para o ano do album dentro do ponteiro album
    //Não vai retornar nada por tratarmos de ponteiro
    album->anoDoAlbum=entrada;
}
void PrencheAlbumcompositID(Album* album,char*entrada,int id){
    //Essa função recebe um ponteiro album,um ponteiro char entrada e um int id
    //ela vai atribuir o char entrada para os compositores dentro do ponteiro album na posição int id
    //Não vai retornar nada por tratarmos de ponteiro
    album->compositores[id]=entrada;
}

void PrenchealbumQuantmidias(Album* album,int entrada){
    //Essa função recebe um ponteiro album e um int entrada
    //ela vai atribuir o int entrada para a quantidade de midias dentro do ponteiro album
    //Não vai retornar nada por tratarmos de ponteiro
    album->qtdMidias=entrada;
}

void PrencheAlbumQuantComp(Album* album,int entrada){
    //Essa função recebe um ponteiro album e um int entrada
    //ela vai atribuir o int entrada para a quantidade de compositores dentro do ponteiro album
    //Não vai retornar nada por tratarmos de ponteiro
    album->qtdCompositores=entrada;
}


void AdicionaMidiaNoAlbumID(Album* album,Midia*midia,int posicao){
    //Essa função vai receber um ponteiro album,um ponteiro midia,e um int posição
    //Ela vai adicionar uma midia no album 
    //vai atribuir o ponteiro midia para album na posição do int posição
    //Não retorna nada por tratarmos de ponteiro
    album->midia[posicao]=midia;
}

void ImprimeAlbum(Album *album){    //Essa função vai receber um ponteiro album
    printf("[Album]\n");            //vai printar que é um album    
    printf("-----[%s]-----\n",album->nomeDoAlbum);  //vai imprimir o nome do album 
    printf("Ano:[%d]\n",album->anoDoAlbum);         //vai imprimir o ano do album
    printf("Artista:[%s]\n",album->artista);        //vai imprimir o nome do artista do album
    printf("Gênero:[%s]\n",album->genero);          //vai imprimir o genero do album
    
   
    for(int i=0 ;i<album->qtdCompositores; i++){
        printf("Compositor:[%s]\n",album->compositores[i]);//vai imprimir o nome dos compositores de acordo com a quantidae
   }

    for(int roda=0;roda<album->qtdMidias;roda++){   
        printf("[%02d]\n",roda+1);    //vai imprimir um ID em ordem cresente oara as midias
        ImprimeMidia(album->midia[roda]);   //vai chamar a função de imprimir midia para imprimir as midias do album de acordo com a quantidade
        printf("\n");
    }
}

void ImprimenomeAlbumcomId(Album* album,int id){//Essa função vai receber um ponteiro album e um int id
     printf("(%02d):",id);                      //vai imprimir o int id
    printf("%s\n",album->nomeDoAlbum);          //vai imprimir o nome do album daquele ponteiro
 
}

Midia* RecuperaMidiadoAlbum(Album* album , int posicao){
    //Essa função recebe um ponteiro album e um int posição
    //a função vai entrar nas midias do album
    //a midia na posição int posição vai ser retornada
    //a função retorna um ponteiro midia
    return album->midia[posicao];
}


void DestroiMidiaNoAlbum(Album* album,int posicao){
  //Essa função vai receber um ponteiro album,e um int posição
  //essa função vai destruir uma midia de forma definitiva  
  //Ela cria uma auxiliar midia para receber a midia ser destruída identificada pelo int posição  
  //depois chama a função troca posição midia no album para trocar a posição de todas midias que vem depois da midia escolhida passando as pra frente  
  //subtrai 1 da quantidade de midias daquele album para atualizar o album
  //E chama a função destroi midia no endereço que esta na auxiliar  
  Midia*aux;
  aux=CriaMidia();

  aux=album->midia[posicao];
  for(int i=posicao;i<album->qtdMidias;i++){
      TrocaPosicaoMidiaNoAlbum(album,i,i+1);
  }
  album->qtdMidias=album->qtdMidias-1;
  DestroiMidia(aux);

}


void TrocaPosicaoMidiaNoAlbum(Album* album,int id1,int id2){
  //Essa função vai receber um ponteiro album,um int id1 e int id2
  //Vai trocar as midias de lugar com ajuda de uma midia auxiliar  
  //ira trocar as midias identificadas no vetor de midias pelo id1 e id2
  //Não retorna nada por tratarmos de ponteiro
  Midia*aux;
  aux=CriaMidia();

  aux=album->midia[id1];
  album->midia[id1]=album->midia[id2];
  album->midia[id2]=aux;
}


void ImprimeMidiaNoAlbum(Album* album,int identificador){
    //Essa função recebe um ponteiro album e um int ID
    //Ela vai imprimir a midia que esta no vetor de midias dentro album, identificada pelo int ID
    //Chamando a função imprime midia
    ImprimeMidia(album->midia[identificador]);
}


void PesquisaacomNomeMidiaNoAlbum(Album* album,char* entrada){
    //Essa função vai receber um ponteiro album e um ponteiro char entrada
    //Ela vai pecorrer todas a midias do album chamando a função pesquisa nome midia(passando a midia e o char entrada)   
    //Se a função retorna positiva,entrara no if
    //e a função de imprimir midia é chamada para aquela midia
    for(int i=0;i<album->qtdMidias;i++){
        if(PesquisaacomNomeMidia(album->midia[i],entrada)){
            ImprimeMidia(album->midia[i]);
            printf("\n");
        }
    }
}
void PesquisaacomArtistaMidiaNoAlbum(Album* album,char* entrada){
    //Essa função vai receber um ponteiro album e um ponteiro char entrada
    //Ela vai pecorrer todas a midias do album chamando a função pesquisa nome artista(passando a midia e o char entrada)   
    //Se a função retorna positiva,entrara no if
    //e a função de imprimir midia é chamada para aquela midia
    for(int i=0;i<album->qtdMidias;i++){
        if(PesquisaacomNomeArtista(album->midia[i],entrada)){
            ImprimeMidia(album->midia[i]);
            printf("\n");
        }
    }
}

void PesquisaacomCompositorMidiaNoAlbum(Album* album,char* entrada){
    //Essa função vai receber um ponteiro album e um ponteiro char entrada
    //Ela vai pecorrer todas a midias do album chamando a função pesquisa nome compositor(passando a midia e o char entrada)   
    //Se a função retorna positiva,entrara no if
    //e a função de imprimir midia é chamada para aquela midia
    for(int i=0;i<album->qtdMidias;i++){
        if(PesquisaacomNomeCompositor(album->midia[i],entrada)){
            ImprimeMidia(album->midia[i]);
            printf("\n");
        }
    }
}
void PesquisaacomGeneroNoAlbum(Album* album,char* entrada){
    //Essa função vai receber um ponteiro album e um ponteiro char entrada
    //Ela vai pecorrer todas a midias do album chamando a função pesquisa Genero(passando a midia e o char entrada)   
    //Se a função retorna positiva,entrara no if
    //e a função de imprimir midia é chamada para aquela midia
    for(int i=0;i<album->qtdMidias;i++){
        if(PesquisaacomGenero(album->midia[i],entrada)){
            ImprimeMidia(album->midia[i]);
            printf("\n");
        }
    }
}

void PesquisaacomGravadoraNoAlbum(Album* album,char* entrada){
    //Essa função vai receber um ponteiro album e um ponteiro char entrada
    //Ela vai pecorrer todas a midias do album chamando a função pesquisa Gravadora(passando a midia e o char entrada)   
    //Se a função retorna positiva,entrara no if
    //e a função de imprimir midia é chamada para aquela midia
    for(int i=0;i<album->qtdMidias;i++){
        if(PesquisaacomGravadora(album->midia[i],entrada)){
            ImprimeMidia(album->midia[i]);
            printf("\n");
        }
    }
}

void PesquisaOAlbumPeloNome(Album* album,char* entrada){
    //Essa função recebe um ponteiro album e um char entrada
    //Ela faz uma comparação usando o strcmp entre strings
    //se o nome do album for igual ao char entrada 
    //Ela chama a função de imprimir album
    if(strcmp(album->nomeDoAlbum,entrada)==0){
        ImprimeAlbum(album);
    }
}


Album* AlocaTudoAlbum(){  
    Album*album;
    album=(Album*)malloc(sizeof(Album));    
    album->nomeDoAlbum=(char*)malloc(50);
    album->artista=(char*)malloc(50);
    album->genero=(char*)malloc(50);
    album->compositores[0]=(char*)malloc(50);
    album->compositores[1]=(char*)malloc(50);
    album->compositores[2]=(char*)malloc(50);
}

Album* LeituraAlbumArquivo(FILE *arquivo){
    Album* album;   
    album=AlocaTudoAlbum();
    
    fscanf(arquivo,"%[^\n]s",album->nomeDoAlbum);
    fscanf(arquivo,"\n");
    
    fscanf(arquivo,"%d",&album->anoDoAlbum);
    fscanf(arquivo,"\n");
    
    fscanf(arquivo,"%[^\n]s",album->artista);
    fscanf(arquivo,"\n");
    
    fscanf(arquivo,"%[^\n]s",album->genero);
    fscanf(arquivo,"\n");

    fscanf(arquivo,"%d",&album->qtdCompositores);
    fscanf(arquivo,"\n");
    
    for(int i=0;i<album->qtdCompositores;i++){
        fscanf(arquivo,"%[^\n]s",album->compositores[i]);
        fscanf(arquivo,"\n");
    }
    fscanf(arquivo,"%d",&album->qtdMidias);
    fscanf(arquivo,"\n");
    fscanf(arquivo,"\n");
    for(int i=0;i<album->qtdMidias;i++){
        album->midia[i]=LeituraMidiarquivo(arquivo);
        fscanf(arquivo,"\n");
    }

    
    return album;
}



void ImprimeAlbumArquivo(Album* album,FILE*arquivo){   
    fprintf(arquivo,album->nomeDoAlbum,"%s");
    fprintf(arquivo,"\n");
    fprintf(arquivo,"%d",album->anoDoAlbum);
    fprintf(arquivo,"\n");
    fprintf(arquivo,album->artista,"%s");
    fprintf(arquivo,"\n");
  
    for(int i=0 ;i<album->qtdCompositores; i++){        
        fprintf(arquivo,album->compositores[i],"%s");
        fprintf(arquivo,"\n");
        }
    

    for(int roda=0;roda<album->qtdMidias; roda++){
        ImprimeMidiaArquivo(album->midia[roda],arquivo);
        fprintf(arquivo,"\n");
        }
}