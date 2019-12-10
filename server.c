#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "playlist.h"
#include "album.h"
#include "usuario.h"
#include "midia.h"


struct server{          //struct server(servidor)
    Album* listalbum[20];   //vai possuir um vetor de ponteiro album /max:20
    Usuario* usuario[3];    //vai possuir um vetor de ponteiro usuario /max:3
    int idusuario;          //int idusuario para controle do usuario que esta logado no momento
    int quantusuarioscriados;   //int quantidade de usuarios criados para controle do vetor de usuario
    int quantAlbum;             //int quantidade de album para controle do vetor de albuns 
};



Server* CriaServer(){       //Essa função não recebe argumentos 
    Server* novo;           //Ela cria um ponteiro server novo
    novo=(Server*)malloc(sizeof(Server));   //aloca o ponteiro
    return novo;            //e retorna o ponteiro server alocado
}

void PrencheIDLogado(Server* server,int ID){
    //Essa função recebe um ponteiro server e um int ID
    //vai atribuir o int ID para dentro do idusuario dentro do ponteiro server
    //Não retorna nada por tratarmos de ponteiro
    server->idusuario=ID;
}


void PrencheQuantdeAlbum(Server* server,int entrada){
    //Essa função recebe um ponteiro server e um int ID
    //vai atribuir o int ID para dentro do quantidade album dentro do ponteiro server
    //Não retorna nada por tratarmos de ponteiro
    server->quantAlbum=entrada;
}

void PrencheQuantUsuarioscriados(Server* server,int entrada){
    //Essa função recebe um ponteiro server e um int ID
    //vai atribuir o int ID para dentro do quantidade de usuarios criados dentro do ponteiro server
    //Não retorna nada por tratarmos de ponteiro
    server->quantusuarioscriados=entrada;
}

void TrocaAlbumPosID(Server* server,int id1,int id2){
    //Essa função ira receber um ponteiro server,int id1 e int id2
    //Ela vai trocar a posição dos albuns do server com ajuda de uma auxiliar
    //trocando de posição os albuns identificados com o int id2 e o int id2
    //Não retorna nada por tratarmos de ponteiro
    Album* aux;
    aux=CriaAlbum();
    aux=server->listalbum[id1];
    server->listalbum[id1]=server->listalbum[id2];
    server->listalbum[id2]=aux;

}

void AdicionaAlbumServer(Server* server,Album* album,int pos){
    //Essa função recebe um ponteiro server,um ponteiro album e um int posição
    //Ela vai atuibuir o ponteiro album para dentro do lista de albuns dentro do server na posição int pos
    //depois vai somar 1 na quantidade de albuns dentro do server,atualizando a quantidade de albuns
    //Não retorna nada por tratarmos de ponteiro
    server->listalbum[pos]=album;
    server->quantAlbum++;
}

void ImprimiAlbumdoServer(Server* server,int pos){
   //Essa função vai receber um ponteiro server e um int pos
   //vai chamar a função de imprimir album pasando como argumento o album de dentro do vetor de albuns do server identificado pelo int pos 
    ImprimeAlbum(server->listalbum[pos]);
}

void ImprimiTodosAlbunsdoServer(Server* server){
    //Essa função vai um ponteiro server
    //vai pecorrer todos os albuns do server chamando a função de imprimir album
    //Imprimindo tambem um ID nos albuns
    for(int i=0;i<server->quantAlbum;i++){
        ImprimenomeAlbumcomId(server->listalbum[i],i);
    }
}


int RecuperaQuantAlbum(Server* server){
    //Recebe um ponteiro server
    //vai retornar um int quantidade de albuns de dentro do server
    return server->quantAlbum;
} 

int RecuperaQuantPlayUsuariodoServer(Server* server,int id){
    //Essa função recebe um ponteiro server, e um int id
    //Ela vai chamar a função de recupera quantidade de plays passando o usuario identificado com o int id
    //e vai retornar o int que a função recupera quantidade de plays retornar
    int i;
    i=RecuperaQuantPlay(server->usuario[id]);
    return i; 
}

void ImprimiNomeAlbumComID(Server * server){
    //Essa função vai receber um ponteiro server
    //vai passar  todos os albuns do server identificados pelo int i dentro da repetição
    //para a função de imprimir o nome dos albuns com o id
    for(int i=0;i<server->quantAlbum;i++){
      ImprimenomeAlbumcomId(server->listalbum[i],i);
    }
}
void ImprimiAlbumdoServercomID(Server * server,int ID){
   //Essa função vai receber um ponteiro server e um int ID
   //vai chamar a função de imprimir o album passando como argumento o album do server identificado pelo int int ID
    ImprimeAlbum(server->listalbum[ID]);
}


int RecuperaIdLogada(Server* server){
    //Essa função recebe um ponteiro server
    //vai retornar um int idusuario de dentro do server que diz qual id esta logada
    return server->idusuario;
}

void PrencheUsuarionoServer(Server*server,Usuario* usuario,int ID){
    //Essa função vai receber um ponteiro server,um ponteiro usuario, e um int ID
    //vai atuibuir o ponteiro usuario para dentro do vetor de ponteiros usuario dentro do server identificado pelo Int ID  
    //Não retorna nada nada por tratarmos de ponteiro
    server->usuario[ID]=usuario;
}

void ImprimiLogindoServer(Server* server, int ID){
    //Essa função vai receber um ponteiro server e um int ID
    //Vai chamar a função de imprimir login passando o usuario De dentro do server identificado pelo int ID
    ImprimiLogin(server->usuario[ID]);
}


void PrenchePlaylistUsuarioNoServer(Server* server,Playlist* playlist,int posicao,int id){
    //Essa função vai receber um ponteiro server, um ponteiro playlist,um int posição e um int ID
    //vai chamar a função de adiconar playlist no usuario Passando o usuario dentro do server identificado pelo int id
    //passando tambem o ponteiro playlist e o int posicao    
    AdicionaPlaylistnoUsuario(server->usuario[id],playlist,posicao);
}

void ImprimiPlaydouserNoServer(Server* server,int ID,int posicao){
    //Essa função vai receber um ponteiro server, um int ID e um int posição
    //Vai chamar a função de imprimir playlist do usuario passando como argumento o usuario de dentro do server identificado pelo int ID
    //passando tambem o int posição
    ImprimePlayDosuario(server->usuario[ID],posicao);
}


void ImprimiPlaylistsDoUsuarioNoServer(Server* server,int ID){
    //Essa função vai receber um ponteiro server, um int ID
    //Vai chamar a função de imprimir nome das playlists do usuario passando como argumento o usuario de dentro do server identificado pelo int ID
    ImprimeNomedasPlaylistdousuario(server->usuario[ID]);
}


void AdicionaMidiaNAPlayuserDoSERVE(Server* server,int IDuser,int IDdoalbum,int IDdamidia,int IDdaPlay){
   //Essa função vai receber um ponteiro server,um int IDuser,um int IDdoalbum,um int IDdamidia e um int IDdaplay
   //Esa função tem o objetivo de adicionar midia na playlist de um usuario 
   //primeiro ela cria uma midia auxiliar e aloca
   //Depois chama a função de recuperar midia do album passando o album identificado pelo IDdoalbum, e o id da midia 
    //a função auxiliar vai receber a midia escolhida
    //Depois Chama a função adicionar midia na play do user passando o usuario identificado pelo int IDuser,passando a midia auxiliar e o int ID da play 
    Midia*aux;
    aux=CriaMidia();
    aux=RecuperaMidiadoAlbum(server->listalbum[IDdoalbum],IDdamidia);
    AdicionaMidiaNaPlayDoUser(server->usuario[IDuser],aux,IDdaPlay);
}


void TrocaPosiMidiaPlaylistnoUserdentroServer(Server* server,int IDuser,int IDdaPlay,int pos1,int pos2){
    //Essa função recebe um ponteiro server, um int IDuser,um int IDdaplay,dois int pos1 e pos2
    //Ela vai chamar a função de trocar posição playlist no user
    //passando como argumento o usuario de dentro do server identificado pelo IDuser, o IDdaply,e as duas posições 
    TrocaPosiMidiaPlaylistnoUser(server->usuario[IDuser],IDdaPlay,pos1,pos2);   
}

void ApagaMidiaDaPlaylistdoUserdentroServer(Server* server,int IDuser,int identificador,int IDdaPlay){
    //Essa função recebe um ponteiro server, um int IDuser,um int IDdaplaye um int identificador
    //Ela vai chamar a função de Apagar midia da Playlist do user
    //passando como argumento o usuario de dentro do server identificado pelo IDuser, o int identificador,e o int iDdaplay
    ApagaMidiaDaPlaylistdoUser(server->usuario[IDuser],identificador,IDdaPlay);
}

void ApagaPLaylistdousuariodentroServer(Server* server ,int identificador,int IDuser){
    //Essa função recebe um ponteiro server, um int IDuser,um int identificador
    //Ela vai chamar a função de Apagar PLaylist do user
    //passando como argumento o usuario de dentro do server identificado pelo IDuser e  o int identificador
    ApagaPLaylistdousuario(server->usuario[IDuser],identificador);
}

int RecuperaQuantDeUsuariosCriados(Server* server){
    //Essa função recebe um ponteiro server
    //Vai retornar um int quant de usuarios criados de dentro do server
    return server->quantusuarioscriados;
}

void ImprimeLogindosUsuarioseID(Server*server){
    //Essa função vai receber um ponteiro server
    //vai passar atraves de uma repetição todos os usuarios do server
    //para a função de imprimir login,imprimindo tambem o id
    for(int i=0;i<=server->quantusuarioscriados;i++){
        printf("ID:[%02d]",i);
        ImprimiLogin(server->usuario[i]);
    }
        
}


void ApagaAlbumdoServer(Server* server,int identificador){
    //Essa função vai receber um ponteiro server e um int ID
    //O Objetivo dessa função é apagar uma album do server
    //A partir do album identificado pelo int ID na lista de albuns dentro do server
    //vai chamar a função para trocar o album de lugar
    //trocando o album identificado pelo que esta depois no vetor
    //fazendo isso para todos albuns que vem depois
    //depois subtraindo 1 da quantidade de albuns dentro do server para atualizar a quantidade
    for(int i=identificador;i<server->quantAlbum;i++){
        TrocaAlbumPosID(server,i,i+1);
    }
    server->quantAlbum--;
}


void TrocaPosicaoMidiaNoAlbumdentroServer(Server* server,int id1,int id2,int IDdoalbum){
    //Essa funçao vai receber um ponteiro server,um int id1,um int id2,int IDdoalbu,
    //Essa função vai chamar a função de trocar posição de midia no album 
    //passando como argumento o album de dentro da lista de albuns do server identificado pelo IDdoabum
    //e os dois int id
    TrocaPosicaoMidiaNoAlbum(server->listalbum[IDdoalbum],id1,id2); 
}

void DestroiMidiaNoAlbumDentroServer(Server* server,int IDalbum,int posicao){
    //Essa funçao vai receber um ponteiro server,um int IDalbum e int posição
    //Essa função vai chamar a função de destroir midia album  
    //passando como argumento o album de dentro da lista de albuns do server identificado pelo IDalbum
    //e o int posição
    DestroiMidiaNoAlbum(server->listalbum[IDalbum],posicao);
}

void ImprimeMidiaNoAlbumDentroServer(Server* server,int IDalbum,int identificador){
    //Essa funçao vai receber um ponteiro server,um int IDalbum e int identificador
    //Essa função vai chamar a função Imprimi mida no album
    //passando como argumento o album de dentro da lista de albuns do server identificado pelo IDalbum
    //e o int identificador
    ImprimeMidiaNoAlbum(server->listalbum[IDalbum],identificador);
}

void PesquisaacomNomeMidiaNoAlbumDentroServer(Server* server,char*entrada){
    //Essa funçao vai receber um ponteiro server e um ponteiro char entrada
    //Essa função vai chamar a função Pesquisa Nome midia no album
    //passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
    //passando tambem o ponteiro char entrada
    for(int i=0;i<server->quantAlbum;i++){
        PesquisaacomNomeMidiaNoAlbum(server->listalbum[i],entrada);
    }
}
void PesquisaacomNomeArtistaNoAlbumDentroServer(Server* server,char*entrada){
    //Essa funçao vai receber um ponteiro server e um ponteiro char entrada
    //Essa função vai chamar a função Pesquisa Artista midia No Album
    //passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
    //passando tambem o ponteiro char entrada
    for(int i=0;i<server->quantAlbum;i++){
        PesquisaacomArtistaMidiaNoAlbum(server->listalbum[i],entrada);
    }
}

void PesquisaacomCompositorNoAlbumDentroServer(Server* server,char*entrada){
    //Essa funçao vai receber um ponteiro server e um ponteiro char entrada
    //Essa função vai chamar a função Pesquisa Compositor Midia no Album
    //passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
    //passando tambem o ponteiro char entrada
    for(int i=0;i<server->quantAlbum;i++){
        PesquisaacomCompositorMidiaNoAlbum(server->listalbum[i],entrada);
    }
}

void PesquisaacomGeneroNoAlbumDentroServer(Server* server,char*entrada){
    //Essa funçao vai receber um ponteiro server e um ponteiro char entrada
    //Essa função vai chamar a função Pesquisa Genero no Album
    //passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
    //passando tambem o ponteiro char entrada
    for(int i=0;i<server->quantAlbum;i++){
        PesquisaacomGeneroNoAlbum(server->listalbum[i],entrada);
    }
}

void PesquisaacomGravadoraNoAlbumDentroServer(Server* server,char*entrada){
    //Essa funçao vai receber um ponteiro server e um ponteiro char entrada
    //Essa função vai chamar a função Pesquisa Gravadora no Album
    //passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
    //passando tambem o ponteiro char entrada
    for(int i=0;i<server->quantAlbum;i++){
        PesquisaacomGravadoraNoAlbum(server->listalbum[i],entrada);
    }
}


void PesquisaaOAlbumDentroServer(Server* server,char*entrada){
    //Essa funçao vai receber um ponteiro server e um ponteiro char entrada
    //Essa função vai chamar a função Pesqusa o album pelo nome
    //passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
    //passando tambem o ponteiro char entrada
    for(int i=0;i<server->quantAlbum;i++){
        PesquisaOAlbumPeloNome(server->listalbum[i],entrada);
    }
}



void MostraLoginDeOutrosUsuarioSemIDlogado(Server*server,int IDlogada){
    //Essa função vai receber um ponteiro char  e um int IDlogada
    //objetivo dessa função e imprimir os outros logins sem ser da id logada
    //vai fazer uma repetição com a quantidade de usuarios criados
    //o i que for diferente da int IDlogada vai chamar a função de imprimir aquele usuario
    //imprimindo o I e o login daquele usuario identificado pelo int I
    for(int i=0;i<=server->quantusuarioscriados;i++){
        if(i!=IDlogada){
            printf("[%02d]:",i);
            ImprimiLogin(server->usuario[i]);
        }
    }
}

void ImprimiPlaylistsPublicasDoUsuarioNoServer(Server* server,int ID){
    //Essa função recebe um ponteiro server e um int ID  
    //Ela chama a função Imprimi nome das playlists publicas do usuario
    //passando o usuario de dentro do vetor de usuarios do server identificado pelo Int ID
    ImprimeNomedasPlaylistPublicasdousuario(server->usuario[ID]);
}


int RecuperaquantDePlaylistsPublicasdoID(Server* server,int ID){
    //Essa função recebe um ponteiro server e um int ID  
    //Ela chama a função Recupe quant de playlist publicas dp usuario
    //passando o usuario de dentro do vetor de usuarios do server identificado pelo Int ID
    //e retorna o int que essa função chamada retornou
    return RecuperaQuantdePlaylistPublicasdousuario(server->usuario[ID]);
}

int RecuperaQuantDeDonosnaPlaylistDentroServer(Server* server,int ID,int IDdaplay){
    //Essa função recebe um ponteiro server,um int ID e um int IDdaplay 
    //Ela chama a função Recupe quant de Donos da playlist do usuario
    //passando o usuario de dentro do vetor de usuarios do server identificado pelo Int ID
    //passando tambem o int IDdaplay
    //e retorna o int que essa função chamada retornou
    return RecuperaQuantDeDonosDaPlayDoUsuario(server->usuario[ID],IDdaplay);
}




void PrenchePlaylistFavoritosUsuarioNoServer(Server* server,Playlist* playlist,int id){
    //Essa função vai receber um ponteiro server, um ponteiro playlist e um int ID
    //vai chamar a função de adiconar playlist favorita no usuario Passando o usuario dentro do server identificado pelo int id
    //passando tambem o ponteiro playlist   
    AdicionaPLayFavoritasnoUsuario(server->usuario[id],playlist);
}

void ImprimiPlayFavoritadouserNoServer(Server* server,int ID){
    //Essa função vai receber um ponteiro server e um int ID
    //vai chamar a função de Imprimi playlist do usuario favorita
    //passando como argumento o usuario do vetor de usuarios do server identificado pelo ID
    ImprimePlayDosuarioFavoritas(server->usuario[ID]);
}

void AdicionaMidiaNAPlayFavoritauserDoSERVE(Server* server,int IDuser,int IDdoalbum,int IDdamidia){
    //Essa função vai receber um ponteiro server,um int IDuser,um int IDdoalbum,um int IDdamidia
    //Esa função tem o objetivo de adicionar midia na playlist Favorita de um usuario 
    //primeiro ela cria uma midia auxiliar e aloca
    //Depois chama a função de recuperar midia do album passando o album identificado pelo IDdoalbum, e o id da midia 
    //a função auxiliar vai receber a midia escolhida
    //Depois Chama a função adicionar midia na play Favorita do user passando o usuario identificado pelo int IDuser,passando a midia auxiliar
    Midia*aux;
    aux=CriaMidia();
    aux=RecuperaMidiadoAlbum(server->listalbum[IDdoalbum],IDdamidia);
    AdicionaMidiaNaPlayFavoritaDoUser(server->usuario[IDuser],aux);
}


void ApagaMidiaDaPlaylistFavoritosdoUserdentroServer(Server* server,int IDuser,int identificador){
    //Essa função recebe um ponteiro server, um int IDuser e um int identificador
    //Ela vai chamar a função de Apagar midia da Playlist Favorita do user
    //passando como argumento o usuario de dentro do server identificado pelo IDuser e o int identificador
    ApagaMidiaDaPlaylistFavoritosdoUser(server->usuario[IDuser],identificador);
}


void PrenchePlaylistestasendoseguidaDouserdoServer(Server* server,int IDdoDono,int IDdaplay,int entrada,int idquemsegue){
    PrenchePlaylistestasendoseguidaDouser(server->usuario[IDdoDono],IDdaplay,entrada,idquemsegue);
}

void ImprimiasplaylistsSeguidasdoUsuarioDentroServer(Server* server,int IDseguidor){
    for(int i=0;i<server->quantusuarioscriados;i++){
        if(i!=IDseguidor){
            ImprimiasplaylistsSeguidasdoUsuario(server->usuario[i],IDseguidor);
        }
    }
}


void ImprimiUsuarioServerArquivo(Server*server,int IDuser,FILE*arquivo){
    ImprimiUsuarioArquivo(server->usuario[IDuser],arquivo);
    fprintf(arquivo,"Playlists Seguidas\n");    
     
    for(int i=0;i<=server->quantusuarioscriados;i++){
        if(i!=IDuser){
         ImprimiasplaylistsSeguidasdoUsuarioArquivo(server->usuario[i],IDuser,arquivo);
        }
    }
    
}


void LeUsuarioArquivoNoServer(Server* server,int ID,FILE* arquivo){
    LeUsuarioArquivo(server->usuario[ID],arquivo);
}



void ImprimiTodosalbunsAlbumdoServerarquivo(Server* server,FILE*arquivo){
    for(int i=0;i<server->quantAlbum;i++){
        ImprimeAlbumArquivo(server->listalbum[i],arquivo);
    }

}