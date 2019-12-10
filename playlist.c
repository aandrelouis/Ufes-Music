#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "midia.h"
#include <string.h>

struct playlist{    //Struct Playlist 
    char *nomePlaylist; //ponteiro char  para nome da playlist
    int privacidade; //int que defini privacidade da playlist/1-publica/2-privada
    char *donoPlaylist[2];//vetor de ponteiros char para o dono da playlist//MAX:2
    int quantDeDonos;     //int quant de donos para ter controle sobre donos da playlist(ler e imprimir)  
    int quantDeMidias;    //int quantidade de midias para ter controle sobre midias(ler e imprimir)  
    Midia *midias[50];
    int seguida[3];      //Um vetor de ponteiro Midia que são as midias da playlist  
};


Playlist* CriaPlaylist(){   //Essa função não recebe nenhum argumento
    Playlist* playlist;         //Ela vai Criar um ponteiro do tipo playlist
    playlist=(Playlist*)malloc(sizeof(Playlist));  //vai alocar esse endereço  
    return playlist;    //e vai retorna o novo endereço alocado
}

void PrenchePlaylistNome(Playlist* playlist,char* entrada){
    //Essa função vai receber um ponteiro playlist e um ponteiro char
    //vai atribuir o ponteiro char entrada para playlist nome dentro da struct playlist
    //Não vai retorna nada por tratarmos de ponteiro
    playlist->nomePlaylist=entrada;
}
void PrenchePlaylistNomeDonos(Playlist* playlist,char*entrada,int id){
    //Essa função vai receber um ponteiro playlist,um ponteiro chare um int id
    //vai atribuir o ponteiro char entrada para nome do dono na posição do ID dentro da struct playlist
    //Não vai retorna nada por tratarmos de ponteiro
    playlist->donoPlaylist[id]=entrada;
}

void PrenchePlaylistQuantmidias(Playlist* playlist,int entrada){
    //Essa função vai receber um ponteiro playliste um int entrada
    //vai atribuir o int entrada para a quant de midias dentro da playlist
    //Não vai retorna nada por tratarmos de ponteiro
    playlist->quantDeMidias=entrada;
}
void PrenchePlaylistQuantdedonos(Playlist* playlist,int entrada){
    //Essa função vai receber um ponteiro playlist e um int entrada
    //vai atribuir o int entrada para a quant de donos dentro da playlist
    //Não vai retorna nada por tratarmos de ponteiro
    playlist->quantDeDonos=entrada;
}
void PrenchePlaylistPrivacidade(Playlist* playlist,int entrada){
    //Essa função vai receber um ponteiro playlist e um int entrada
    //vai atribuir o int entrada para privacidade dentro da playlist
    //Não vai retorna nada por tratarmos de ponteiro 
    playlist->privacidade=entrada;
}


void AlocaMidiaNAPlaylist(Playlist* playlist){  //Essa função recebe um ponteiro playlist
    for(int roda=0;roda<50;roda++){             //dentro do ponteiro aloca as 50 midias que possuem na playlist    
        playlist->midias[roda]=CriaMidia();     //função cria midia esta alocando a midia
    }                                           //não retorna nada por ser ponteiro
}

void AdicionaMidiaPlaylist(Playlist *play,Midia *midia){  
    //Essa função recebe um ponteiro playlist e um ponteiro Midia
    //A função vai atruibuir a midia para dentro da playlist nas midias na posição quantdemidias 
    //logo depois vai somar 1 nas quantdemidias ,atualizando a quantidade e a posição onde entrara a proxima midia
    //Não vai retorna nada por tratarmos de ponteiro
    play->midias[play->quantDeMidias]=midia;
    play->quantDeMidias++;
    
}

void ImprimePlaylist(Playlist* playlist){   //Função recebe um ponteiro playlist 
    printf("|--------------[PlayList]-------------------|\n\n");    
    printf("Nome Playlist: [%s]\n",playlist->nomePlaylist);     //imprimi o nome da playlist que esta dentro do ponteiro
    for(int i=0 ;i<playlist->quantDeDonos; i++){        
        printf("Dono [%d]: [%s]\n",i+1,playlist->donoPlaylist[i]);//imprimi o nome dos donos de acordo com a quantidade
        }
    for(int roda=0;roda < playlist->quantDeMidias; roda++){
        printf("------[%02d]-------\n",roda);  //printa um ID na midia em ordem crescente de 1 a 50   
        ImprimeMidia(playlist->midias[roda]);   //Chama a função IMprimiMidia para as midias de acordo com a quantidade
        printf("\n");
        }
}


void ImprimenomePlaylistcomid(Playlist* playlist,int id){ //Recebe um ponteiro playlist e um ID  
    printf("(%02d):",id);                                 //printa o id recebido  
    printf("%s\n",playlist->nomePlaylist);                //printa o nome da playlist
}                                                         //não retorna nada      



void TrocaPosiMidiaPlaylist(Playlist *playlist,int pos1,int pos2 ){
    //Essa função  ira receber um ponteiro playlist e dois int ,pos1 e pos2;
    //Ela vai trocar a midia na posicao 1 com a midia na pos2
    //Usando uma variavel auxiliar(reserva) criada e alocada so para fazer a troca
    //não retorna nada por tratarmos de ponteiro
    Midia* reserva;
    reserva=CriaMidia();//aloca a variavel reserva
    reserva=playlist->midias[pos1];
    playlist->midias[pos1]=playlist->midias[pos2];
    playlist->midias[pos2]=reserva;
}

void ApagaMidiaDaPlaylist(Playlist *playlist,int identificador){
    //Essa funçao vai receber um ponterio playlist e um int identificador
    //Apartir da posicao da midia pelo int identificador 
    //Usando a função troca posição ela troca de lugar a midia escolhida com a proxima e faz isso em uma repetição com a quantidade de midias da playlist
    //E no final decrementa 1 da quantidade de midias , atualizando a quantidade de midias da playlist
    //Não retorna nada
    for(int i=identificador;i<playlist->quantDeMidias;i++){
        TrocaPosiMidiaPlaylist(playlist,i,i+1);
    }
    playlist->quantDeMidias=playlist->quantDeMidias-1;
}

int RecuperaPrivacidadeDaPlaylist(Playlist *playlist){
    //Essa função recebe um ponteiro playlist 
    //retorna o int privacidade 
    return playlist->privacidade;
}

int RecuperaQuantDeDonos(Playlist* playlist){
    //Essa função recebe um ponteiro playlist 
    //retorna o int quantidade de donos da playlist
    return playlist->quantDeDonos;
}

void PrenchePlaylist2NomeDono(Playlist* playlist,char*entrada){
   //Essa função recebe um ponteiro playlist e um ponteiro char entrada  
    //a função ira atribuir o char entrada para a posição 1 do vetor de dono da playlist
    //prenchendo o nome do 2 dono da play
    //Não retorna nada
    playlist->donoPlaylist[1]=entrada;
}

void CopiaPlaylist(Playlist*original,Playlist* copia){
    //Essa função recebe dois ponteiros playlist
    //a função ira alocar todos os elemntos da playlist copia
    //então ira atribuir todos elementos da playlist original para a playlist copia
    //ira copiar as strings dos ponteiros da playlist original para a playlist copia
    copia->nomePlaylist=(char*)malloc(50);
    copia->donoPlaylist[0]=(char*)malloc(50);
    copia->donoPlaylist[1]=(char*)malloc(50);
    copia->privacidade=original->privacidade;
    copia->quantDeDonos=original->quantDeDonos;
    copia->quantDeMidias=original->quantDeMidias;
    strcpy(copia->nomePlaylist,original->nomePlaylist);
    
    for(int i=0;i<original->quantDeDonos;i++){
    strcpy(copia->donoPlaylist[i],original->donoPlaylist[i]);
    }
    
    
    for(int j=0;j<original->quantDeMidias;j++){    
        copia->midias[j]=CriaMidia();               //aloca as midias que vão receber a copia
        CopiaMidia(original->midias[j],copia->midias[j]);//chama a função de copiar as midias de acordo com a quantidade de midias
    }

}

void PrenchePlaylistestasendoseguida(Playlist* playlist,int entrada,int idquemsegue){
    playlist->seguida[idquemsegue]=entrada;
}


void ImprimiasplaylistsSeguidas(Playlist* playlist,int ID){
    if(playlist->seguida[ID]==1){
        ImprimePlaylist(playlist);
        printf("\n");
    }
}


void ImprimePlaylistArquivo(Playlist* playlist,FILE*arquivo){   
    fprintf(arquivo,playlist->nomePlaylist,"%s");
    fprintf(arquivo,"\n");
    fprintf(arquivo,"%d",playlist->privacidade);
    fprintf(arquivo,"\n");
    
    fprintf(arquivo,"%d",playlist->quantDeDonos);
    fprintf(arquivo,"\n");
    
    for(int i=0 ;i<playlist->quantDeDonos; i++){        
        fprintf(arquivo,playlist->donoPlaylist[i],"%s");
        fprintf(arquivo,"\n");
        }
    
    fprintf(arquivo,"%d",playlist->quantDeMidias);
    fprintf(arquivo,"\n");
    for(int roda=0;roda < playlist->quantDeMidias; roda++){
        ImprimeMidiaArquivo(playlist->midias[roda],arquivo);
        fprintf(arquivo,"\n");
        }
}


void ImprimiasplaylistsSeguidasArquivo(Playlist* playlist,int IDdoseguidor,FILE*arquivo){
    if(playlist->seguida[IDdoseguidor]==1){
        ImprimePlaylistArquivo(playlist,arquivo);
        printf("\n");
    }
}

void AlocaTudoPlaylist(Playlist*nova){
    nova->donoPlaylist[0]=(char*)malloc(50);
    nova->donoPlaylist[1]=(char*)malloc(50);
    nova->nomePlaylist=(char*)malloc(50);
    
}

void LerPlaylistArquivo(Playlist* playlist,FILE*arquivo){   
    AlocaTudoPlaylist(playlist);
    fscanf(arquivo,"%[^\n]s",playlist->nomePlaylist);
    fscanf(arquivo,"\n");
    fscanf(arquivo,"%d",&playlist->privacidade);
    fscanf(arquivo,"\n");
    fscanf(arquivo,"%d",&playlist->quantDeDonos);
    fscanf(arquivo,"\n");
    for(int i=0 ;i<playlist->quantDeDonos; i++){        
        fscanf(arquivo,"%[^\n]s",playlist->donoPlaylist[i]);
        fscanf(arquivo,"\n");
        }
    
    fscanf(arquivo,"%d",&playlist->quantDeMidias);
    for(int roda=0;roda < playlist->quantDeMidias; roda++){
            playlist->midias[roda]=AlocaTudoMidia();
            playlist->midias[roda]=LeituraMidiarquivo(arquivo);
            fscanf(arquivo,"\n");
        }
}


