#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "playlist.h"
#include "midia.h"

struct usuario{ //Struct Usuario
    char* nome; //ponteiro char para o nome do usuario
    char* login;//ponteiro char para o login do usuario
    char* senha;//ponteiro char para a senha
    Playlist* listaplay[20];//vetor de ponteiro playlist com tamamho 20--indicano playlists do usuario
    Playlist* favoritas;    //ponteiro de playlist --indicando playlist das midias favoritas
    int quantPlay;          //int quantidade de playlist usada para ter controle das playlist
};


Usuario* CriaUsuario(){    //Função nao recebe nenhum argumento
    Usuario* nova;         //Cria um ponteiro usuario
    nova=(Usuario*)malloc(sizeof(Usuario));//aloca o ponteiro usuario
    return nova;            //retorna o ponteiro alocado
}

void PrencheUsuarionome(Usuario* usuario,char* entrada){
    //Essa função ira receber um ponteiro usuario e um ponteiro char entrada
    //ira atribuir o ponteiro char para o nome do usuairo dentro da struct usuario
    //não ira retornar nada por estarmos tratando de ponteiro
    usuario->nome=entrada;
}
void PrencheUsuarioLogin(Usuario* usuario,char* entrada){
    //Essa função ira receber um ponteiro usuario e um ponteiro char entrada
    //ira atribuir o ponteiro char para o Login dentro da struct usuario
    //não ira retornar nada por estarmos tratando de ponteiro
    usuario->login=entrada;
}
void PrencheUsuarioSenha(Usuario* usuario,char* entrada){
    //Essa função ira receber um ponteiro usuario e um ponteiro char entrada
    //ira atribuir o ponteiro char para A senha dentro da struct usuario
    //não ira retornar nada por estarmos tratando de ponteiro
    usuario->senha=entrada;
}

void PrencheQuantPlayusuario(Usuario* usuario,int entrada){
    //Essa função ira receber um ponteiro usuario e um int entrada
    //ira atribuir o int entrada para a quantidade de playlist dentro da struct usuario
    //não ira retornar nada por estarmos tratando de ponteiro
    usuario->quantPlay=entrada;
}

void ApagaPLaylistdousuario(Usuario *usuario, int identificador){
    //Essa função ira receber um ponteiro usuario e um int ID
    //Na lista de Playlists na posicao igual ao int ID
    //vai chamar a função de trocar de lugar essa playlist com a proxima
    //e vai trocar de lugar todas a playlist que vem depois da playlist no ID sinalizado
    //e depois vai subtrair 1 da quantidade de playlists daquele usaurio-atualizando o valor atual
    //Não retorna nada
    for(int i=identificador;i<usuario->quantPlay;i++){
        TrocaPlaylistPosUsuario(usuario,i,i+1);
    }   
    usuario->quantPlay--;
}

void TrocaPlaylistPosUsuario(Usuario *usuario,int pos1,int pos2){
    //Essa função ira receber um ponteiro usuario e dois int ,pos1 e pos2
    //Essa função ira trocar de lugar a playlist dentro do usuario 
    //ira trocar playlist na posição 1 com a posição 2 com ajuda de uma auxiliar 
    //não ira retornar nada
    Playlist* aux;
    aux=CriaPlaylist();         //alocando auxiliar
    aux=usuario->listaplay[pos1];
    usuario->listaplay[pos1]=usuario->listaplay[pos2];
    usuario->listaplay[pos2]=aux;
}


void ImprimiLogin(Usuario*usuario){//essa função ira receber um ponteiro usuario
    printf("%s\n",usuario->login);  //ira imprimir o login dentro daquele usuario
                                    //não retorna nada
}


void AdicionaPlaylistnoUsuario(Usuario* usuario,Playlist* playlist,int posicao){
    //Essa função ira receber um ponteiro usuario,um ponteiro playlist,e um int posição
    //Essa função ira atribuir o a playlist para dentro do usuario na posição do int posição
    //e depois ira somar 1 na quantidade de playlists do usuario
    //atualizando a quantidade e a posição da proxima
    usuario->listaplay[posicao]=playlist;
    usuario->quantPlay++;
}


int RecuperaQuantPlay(Usuario* usuario){
    //Essa função ira receber um ponteiro usuario
    //ira retornar um int que contem a quantidade de playlist do usuario
    return usuario->quantPlay;
}

void ImprimePlayDosuario(Usuario* usuario,int posicao){
    //Essa função ira receber um ponteiro usuario, e um int posição
    //ira chamar a a função de imprimir playlist para a playlist na posição indicada pelo int posição
    ImprimePlaylist(usuario->listaplay[posicao]);
}


void ImprimeNomedasPlaylistdousuario(Usuario* usuario){
    //Essa função irar receber um ponnteiro usuario
    //Ela ira fazer uma repetição com a quantidade de playlists do usuario
    //durante a repetição ira imprimir o Nome das Playlist que aquele usuario possui com um ID
    //não retorna nada
    for(int i=0;i<usuario->quantPlay;i++){
    ImprimenomePlaylistcomid(usuario->listaplay[i],i);
    }

}


void AdicionaMidiaNaPlayDoUser(Usuario* usuario,Midia*midia,int IDdaplay){
    //Essa função ira receber um ponteiro usuario,um ponteiro midia,um int IDdaplay
    //essa função ira chamar a função de adicionar a midia na playlist 
    //passando como argumentos a playlist identificada pelo IDdaplay dentro das Playlists do Usuario
    //ira passar como argumento tambem a midia
    AdicionaMidiaPlaylist(usuario->listaplay[IDdaplay],midia);
}



void TrocaPosiMidiaPlaylistnoUser(Usuario* usuario,int IDdaPlay,int pos1,int pos2){
    //Essa função ira receber um ponteiro usuario,int IDdaplay,int pos1 e pos2
    //Ela ira chamar a função de trocar posição da midia dentro da playlist
    //passando como argumento a playlist identificada pelo IDdaplay dentro do usuario
    //passando tambem as duas posições das midias a serem trocadas de lugar(pos1 e pos2)
    TrocaPosiMidiaPlaylist(usuario->listaplay[IDdaPlay],pos1,pos2);
}


void ApagaMidiaDaPlaylistdoUser(Usuario* usuario,int identificador,int IDdaPlay){
    //Essa função ira receber um ponteiro usuario,um int ID, e um int IDdaPlay
    //ela ira chamar a função Apaga midia da playlist 
    //passando como argumento a playlist identificada pelo IDdaplay dentro do usuario
    //passando tambem o ID da midia a ser apagada   
    ApagaMidiaDaPlaylist(usuario->listaplay[IDdaPlay],identificador);
}


void ImprimeNomedasPlaylistPublicasdousuario(Usuario* usuario){
    //Essa função ira receber um ponteiro usuario
    //Ela irar pecorrer todas playlists do usuario 
    //chamando a função Recupera Privacidade da Play que retorna a privacidade
    //se a privacidade for igual a 1--Ela é publica
    //então ele imprimi o nome da playlist se for publica
    for(int i=0;i<usuario->quantPlay;i++){
        int j=0;    
        j=RecuperaPrivacidadeDaPlaylist(usuario->listaplay[i]);
            if(j==1){
                ImprimenomePlaylistcomid(usuario->listaplay[i],i);
            }
    }
}


int RecuperaQuantdePlaylistPublicasdousuario(Usuario* usuario){
    //Essa função ira receber um ponteiro usuario
    //Ela irar pecorrer todas playlists do usuario 
    //chamando a função Recupera Privacidade da Play que retorna a privacidade
    //se a privacidade for igual a 1--Ela é publica
    //então ele conta quantas playlits publicas o usuario possui
    //então retorna o contador
    int cont=0;
    for(int i=0;i<usuario->quantPlay;i++){
        int j=0;    
        j=RecuperaPrivacidadeDaPlaylist(usuario->listaplay[i]);
            if(j==1){
                cont++;
            }
        }
    return cont;
}

int RecuperaQuantDeDonosDaPlayDoUsuario(Usuario* usuario,int IDdaplay){
    //Essa função ira receber um ponteiro usuario e um int IDdaplay
    //Então ela chama a função recupera a quant de donos 
    //passando como argumento a playlist identificada pelo IDdaplay dentro  do usuaro
    //retorna a quantidade 
    return RecuperaQuantDeDonos(usuario->listaplay[IDdaplay]);
}


char* RecuperaLogindoUser(Usuario* usuario){
   //Recebe um ponteiro usuario
   //retorna o ponteiro char referente ao login de dentro do usuario
    return usuario->login;
}


void AdicionaPLayFavoritasnoUsuario(Usuario* usuario,Playlist* playlist){
    //Recebe um ponteiro usuario, e um ponteiro playlist
    //atribui a o ponteiro playlist para dentro do usuario,para playlist favoritas
    //Não retorna nada por tratarmos de ponteiro
    usuario->favoritas=playlist;
}


void ImprimePlayDosuarioFavoritas(Usuario* usuario){
    //Recebe um ponteiro Usuario
    //ira Imprimir as playlists favoritas do usuario
    //chamando a função imprimi palylist passando como argumento o ponteiro de playlists favoritas
    ImprimePlaylist(usuario->favoritas);
}

void AdicionaMidiaNaPlayFavoritaDoUser(Usuario* usuario,Midia*midia){
    //Essa função ira receber um ponteiro usuario e um ponteiro midia
    //Ela ira chamar a função de adicionar midia na playlist 
    //passando como argumento o endereço da playlist favorita e o ponteiro da midia
    AdicionaMidiaPlaylist(usuario->favoritas,midia);
}

void ApagaMidiaDaPlaylistFavoritosdoUser(Usuario* usuario,int identificador){
    //Essa função ira receber  um ponteiro usuario,e um int ID
    //Ela ira chamar a função de apagar midia da playlist
    //passando como argumento o endereço da playlist favorita e o id da midia
    ApagaMidiaDaPlaylist(usuario->favoritas,identificador);
}

void PrenchePlaylistestasendoseguidaDouser(Usuario* usuario,int IDdaplay,int entrada,int idquemsegue){
        PrenchePlaylistestasendoseguida(usuario->listaplay[IDdaplay],entrada,idquemsegue);  
}


void ImprimiasplaylistsSeguidasdoUsuario(Usuario* usuario,int IDseguidor){
    for(int i=0;i<usuario->quantPlay;i++){
        ImprimiasplaylistsSeguidas(usuario->listaplay[i],IDseguidor);
    }
}

void ImprimiUsuarioArquivo(Usuario* usuario,FILE* arquivo){
    fprintf(arquivo,usuario->login,"%s");
    fprintf(arquivo,"\n");
    fprintf(arquivo,usuario->senha,"%s");
    fprintf(arquivo,"\n");
    fprintf(arquivo,"%d",usuario->quantPlay);
    fprintf(arquivo,"\n");
    
    for(int i=0;i<usuario->quantPlay;i++){
        ImprimePlaylistArquivo(usuario->listaplay[i],arquivo);
    }
    ImprimePlaylistArquivo(usuario->favoritas,arquivo);
}

void LeUsuarioArquivo(Usuario* usuario,FILE* arquivo){
    usuario->login=(char*)malloc(50);
    usuario->senha=(char*)malloc(50);
    usuario->nome=(char*)malloc(50);
    
    fscanf(arquivo,"%[^\n]s",usuario->login);
    fscanf(arquivo,"\n");
    fscanf(arquivo,"%[^\n]s",usuario->senha);
    fscanf(arquivo,"\n");
    
    fscanf(arquivo,"%d",&usuario->quantPlay);
    fscanf(arquivo,"\n");
    for(int i=0;i<usuario->quantPlay;i++){
        usuario->listaplay[i]=CriaPlaylist();    
        LerPlaylistArquivo(usuario->listaplay[i],arquivo);
        fscanf(arquivo,"\n");
    }
    
    usuario->favoritas=CriaPlaylist();
    LerPlaylistArquivo(usuario->favoritas,arquivo);
    
}


void ImprimiasplaylistsSeguidasdoUsuarioArquivo(Usuario* usuario,int IDseguidor,FILE*arquivo){
    for(int i=0;i<usuario->quantPlay;i++){
        ImprimiasplaylistsSeguidasArquivo(usuario->listaplay[i],IDseguidor,arquivo);
    }
}