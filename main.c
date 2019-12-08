#include <stdio.h>
#include <stdlib.h>
#include "midia.h"  
#include "album.h"  
#include "playlist.h"
#include "usuario.h"
#include "server.h"
#include "menu.h"
#include <string.h>



char* PrencheElementos();
int EntradaTipodeMidia();
void EntradaMusica(Midia* midia);
void EntradaCriaMidia(Midia* midia);
void EntradaPodCast(Midia* midia);
void EntradaVideo(Midia* midia);
void EntradaAlbum(Album* album);
void EntradaPlaylist(Playlist* playlist);
void EntradaUsuario(Usuario* usuario);
void InicializaServidor(Server* server);
void MenuLer(Server* server);
void  menucriar(Server* server);
void EdicaoMenu(Server* server);
void MenuSairdaContaconfirmacao(Server* server);
void MenuRemover(Server* server);
void MenuSairdaConta(Server* server);
void Pesquisar(Server* server);
void IniciaFavoritas(Playlist* playlist);
void FinalizaPrograma(Server*server);
void RecuperaSistema(Server* server);




int main(int argc, char** argv) {
    Server* server;
    Album* album;Usuario*usuario;Midia*midia;
    int valido=1; int escolha;int nova;
    Playlist*favoritas;int quant=0;Playlist*play;Playlist*v;
    FILE* arquivo;int reinicia=0;
    server=CriaServer();   
    
    PrencheIDLogado(server,0);  
    PrencheQuantUsuarioscriados(server,0);  
    PrencheQuantdeAlbum(server,0);
    
    arquivo=fopen("album1.txt","r");
        if(!arquivo){
        printf("Problema na abertura do arquivo");
        return 1;
    }
   album=LeituraAlbumArquivo(arquivo);
   quant=RecuperaQuantAlbum(server);
   AdicionaAlbumServer(server,album,quant); 
   fclose(arquivo);
    
   arquivo=fopen("album2.txt","r");
    if(!arquivo){
        printf("Problema na abertura do arquivo");
        return 1;
    }
   album=LeituraAlbumArquivo(arquivo);
   quant=RecuperaQuantAlbum(server);
   AdicionaAlbumServer(server,album,quant); 
   fclose(arquivo);
    
   
   
    printf("Deseja Recuperar servidor anterior:(1-sim/2-não)\n");
    scanf("%d",&reinicia);
    
    if(reinicia==1){
        RecuperaSistema(server);
    }
    else{
        printf("O ID desse usuario Administrador sera [0]\n\n");
        usuario=CriaUsuario();      //alocando uma auxiliar usuario
        EntradaUsuario(usuario);    //criando o usuario 
        PrencheUsuarionoServer(server,usuario,0);   //prenchendo o usuario no servidor
        ImprimiLogindoServer(server,0); //imprimindo o login do usuario criado
    
    
        favoritas=CriaPlaylist();       //alocando palylist favorita do usuario logado
        IniciaFavoritas(favoritas);     //inicializando a playlist favoritas     
        PrenchePlaylistFavoritosUsuarioNoServer(server,favoritas,0);//preenchendo a playlist favorita do usuairo logado no server
    }
   
    
    
    while(valido){
        MostrarMenu();          //mostrar na tela o menu principal
        scanf("%d",&escolha);
        if(escolha==1){         //opção de criar
            menucriar(server);
        }
    
        else if(escolha==2){    //opção de editar
            EdicaoMenu(server);
        }
        else if(escolha==3){    //opção de ler
            MenuLer(server);
        }
        else if(escolha==4){    //opção de remover
            MenuRemover(server);
        }
        else if(escolha==5){    //opção de sair da conta
            MenuSairdaContaconfirmacao(server);
        }
        else if(escolha==6){    //opção de pesquisar
            Pesquisar(server);
        }  
        else if(escolha==9){    //opção de sair do programa
          FinalizaPrograma(server);
            Sair(); //mensagem de despedida
            exit(1);
        }
    }
    
    
    return (EXIT_SUCCESS);
}


void RecuperaSistema(Server* server){
    FILE*arquivo;
    Usuario*usuario;int users=0;
    printf("Recupera quantos usuarios do servidor:?");
    scanf("%d",&users);
    
    
    arquivo=fopen("usuario1.txt","r");
    if(!arquivo){
        printf("Problema na abertura do arquivo");
    }
    usuario=CriaUsuario();
    PrencheUsuarionoServer(server,usuario,0);
    LeUsuarioArquivoNoServer(server,0,arquivo);  
    fclose(arquivo);

    
    if(users>1){
    arquivo=fopen("usuario2.txt","r");
        if(!arquivo){
            printf("Problema na abertura do arquivo");
        }
        usuario=CriaUsuario();
        PrencheUsuarionoServer(server,usuario,1);
        LeUsuarioArquivoNoServer(server,1,arquivo);  
        fclose(arquivo);
    PrencheQuantUsuarioscriados(server,1);
    }
    
    if(users>2){
       arquivo=fopen("usuario3.txt","r");
        if(!arquivo){
            printf("Problema na abertura do arquivo");
        }
        usuario=CriaUsuario();
        PrencheUsuarionoServer(server,usuario,2);
        LeUsuarioArquivoNoServer(server,2,arquivo);  
        fclose(arquivo);
    PrencheQuantUsuarioscriados(server,2);
    }
    
}

void FinalizaPrograma(Server*server){       //função recebe um ponteiro server
    FILE*arquivo;int quant=0;               //vai gerar um arquivo vom todas informações colocadas no programa
                                                    
    quant=RecuperaQuantDeUsuariosCriados(server);//verifica a quatidade de usuarios para gerar os arquivos

    arquivo=fopen("usuario1.txt","w");
    if(!arquivo){
        printf("Problema na abertura do arquivo");
      
        }
        ImprimiUsuarioServerArquivo(server,0,arquivo); 
        fclose(arquivo);
    
    
    
    if(quant>0){
        arquivo=fopen("usuario2.txt","w");
        if(!arquivo){
            printf("Problema na abertura do arquivo");
            
        }
        ImprimiUsuarioServerArquivo(server,1,arquivo); 
        fclose(arquivo);
    }

    if(quant==2){
        arquivo=fopen("usuario3.txt","w");
        if(!arquivo){
            printf("Problema na abertura do arquivo");

        }
        ImprimiUsuarioServerArquivo(server,2,arquivo); 
        fclose(arquivo);
    }

        
        
        arquivo=fopen("Todosalbuns.txt","w");
        if(!arquivo){
            printf("Problema na abertura do arquivo");

        }
        ImprimiTodosalbunsAlbumdoServerarquivo(server,arquivo);
        fclose(arquivo);

}
void EntradaCriaMidia(Midia* midia){
   //essa função vai receber um ponteiro midia
   //o objetivo dessa função é controlar o tipo de midia que sera criada
   //chamando a função de criar a midia de acordo com o tipo 
    int escolha;
    Imprimioopcaomidia();//imprime opções de midia
    escolha=EntradaTipodeMidia();//entrada do tipo de midia
    if(escolha==1){ //musica
        EntradaMusica(midia);
    }
    else if(escolha==2){//podcast
        EntradaPodCast(midia);
    }
    else if(escolha==3){//video
        EntradaVideo(midia);
    }
    
    
}
void EntradaMusica(Midia* midia){
    //essa função recebe um ponteiro midia e não retorna nada
    //o objetivo dessa função é criar uma midia do tipo Musica
    //onde a entrada digitada e mandada para uma variavel
    //logo depois vem uma função que vai atribuindo as variaveis de cada categoria para dentro da midia
    char*nome;char*artista;char*comp;char*gravadora;char*genero;
    int quantartista;int quantcomp;float dura;
    printf("Digite o nome da Musica:");
    nome=PrencheElementos();
    PrencheMidiaNome(midia,nome);
    
    
    printf("Quantos artistas possuem na Musica:");
    scanf("%d",&quantartista);
    PreencheQuantArtistas(midia,quantartista);
    setbuf(stdin, NULL);
    
    for(int roda=0;roda<quantartista;roda++){
    printf("Digite o nome do artista[%02d]:",roda+1);
    artista=PrencheElementos();
    PrencheMidiaArtistaID(midia,artista,roda);
    }
    
    printf("Quantidade de compositores:\n");
    scanf("%d",&quantcomp);
    PreencheQuantComp(midia,quantcomp);
    setbuf(stdin, NULL);
   
    for(int roda2=0;roda2<quantcomp;roda2++){
     printf("Digite o nome do Compositor[%02d]:",roda2+1);
        comp=PrencheElementos();
        PrencheMidiaCompositorid(midia,comp,roda2);
    }
    
    printf("Digite o nome da Gravadora:");
    gravadora=PrencheElementos();
    PrencheMidiaGravadora(midia,gravadora);
    
    printf("Digite o genero da musica:");
    genero=PrencheElementos();
    PrencheGenero(midia,genero);
    
    printf("Digite a Duração da Musica:");
    scanf("%f",&dura);
    PrencheDuracao(midia,dura);
    
    
    PrencheMidiaTipo(midia,1);
    

}
void EntradaPodCast(Midia* midia){
    //essa função recebe um ponteiro midia e não retorna nada
    //o objetivo dessa função é criar uma midia do tipo Podcast
    //onde a entrada digitada e mandada para uma variavel
    //logo depois vem uma função que vai atribuindo as variaveis de cada categoria para dentro da midia
    char*nome;char*artista;char*comp;char*gravadora;char*genero;
    int quantartista;int quantcomp;float dura;
    printf("Digite o nome do Podcast:");
    nome=PrencheElementos();
    PrencheMidiaNome(midia,nome);
    
    
    printf("Quantos artistas possuem no PodCast:");
    scanf("%d",&quantartista);
    PreencheQuantArtistas(midia,quantartista);
    setbuf(stdin, NULL);
    
    for(int roda=0;roda<quantartista;roda++){
    printf("Digite o nome do artista[%02d]:",roda+1);
    artista=PrencheElementos();
    PrencheMidiaArtistaID(midia,artista,roda);
    }
    
    printf("Digite o nome da Gravadora:");
    gravadora=PrencheElementos();
    PrencheMidiaGravadora(midia,gravadora);
    
    
    
    printf("Digite a Duração do PodCast:");
    scanf("%f",&dura);
    PrencheDuracao(midia,dura);
    
    PrencheMidiaTipo(midia,2);
    

}
void EntradaVideo(Midia* midia){
    //essa função recebe um ponteiro midia e não retorna nada
    //o objetivo dessa função é criar uma midia do tipo video
    //onde a entrada digitada e mandada para uma variavel
    //logo depois vem uma função que vai atribuindo as variaveis de cada categoria para dentro da midia
    char*nome;char*artista;char*comp;char*gravadora;char*genero;
    int quantartista;int quantcomp;float dura;
    
    printf("Digite o nome do Video:");
    nome=PrencheElementos();
    PrencheMidiaNome(midia,nome);
    
    
    printf("Quantos artistas possuem no Video:");
    scanf("%d",&quantartista);
    PreencheQuantArtistas(midia,quantartista);
    setbuf(stdin, NULL);
    
    for(int roda=0;roda<quantartista;roda++){
    printf("Digite o nome do artista[%02d]:",roda+1);
    artista=PrencheElementos();
    PrencheMidiaArtistaID(midia,artista,roda);
    }
    
    printf("Digite o nome da Gravadora:");
    gravadora=PrencheElementos();
    PrencheMidiaGravadora(midia,gravadora);
    
    
    
    printf("Digite a Duração do Video:");
    scanf("%f",&dura);
    PrencheDuracao(midia,dura);
    

    PrencheMidiaTipo(midia,3);    //prenche na midia o tipo
}
int EntradaTipodeMidia(){   //função com entrada de int 
    int tipo=0;
    scanf("%d",&tipo);
    return tipo;            //retorna o int digitado
}
char* PrencheElementos(){   //função para prencher elementos char e retornar o ponteiro
    char* aux;
    setbuf(stdin, NULL);    //limpando o buffer
    aux=(char*)malloc(50);  //alocando o ponteiro
    scanf("%[^\n]s",aux);   //colocando o conteudo dentro da aux
    
    setbuf(stdin, NULL);
    return aux;             //retornado o ponteiro
}
void EntradaAlbum(Album* album){
    //Essa função recebe um ponteiro album e não retorna nada
    //O obejtivo dessa função e criar o album, recebendo a entrada e preenchendo o ponteiro album atraves de funções para album
    char*nome;char*artista;char*genero;char*comp;
    int quantcomp;int ano;int quantidade;
    Midia*adiciona=CriaMidia(); //aloca as midias que vão ser colocadas no album
 
    printf("Digite o nome do album:  ");
    nome=PrencheElementos();    //recebe a entrada char
    PrencheAlbumNome(album,nome);//chama a função de atribuir nome para dentro da album
    
    printf("Digite o nome do artista:  ");
    artista=PrencheElementos();//recebe a entrada char
    PrencheAlbumArtista(album,artista);//chama a função de atribuir Artista para dentro da album
             
    printf("Ano do Album:  ");
    scanf("%d",&ano);//recebe a entrada int 
    PrencheAlbumAno(album,ano); //chama a função de atribuir ano para dentro da album
    
    printf("Gênero do Album:");
    genero=PrencheElementos();//recebe a entrada char
    PrencheAlbumGenero(album,genero);//chama a função de atribuir genero para dentro da album
    
    
    printf("Quantos compositores ha nesse Album?: ");
    scanf("%d",&quantcomp);//recebe a entrada int
    PrencheAlbumQuantComp(album,quantcomp);//chama a função de atribuir quantidade de compositores para dentro de album
   
    for(int roda=0;roda<quantcomp;roda++){
        printf("Digite o nome dos compositores [%02d]:",roda); 
        comp=PrencheElementos();    //recebe a entrada char
        PrencheAlbumcompositID(album,comp,roda); //chama a função de atribuir compositor para dentro de album na posição int roda  
    }  
        
    printf("Quantas midias deseja incluir no Album?: ");
    scanf("%d",&quantidade);    //recebe a entrada int
    PrenchealbumQuantmidias(album,quantidade);//chama a função de atribuir quantidade de midias para dentro da album
   
    for(int i=0;i<quantidade;i++){
        adiciona=CriaMidia();   //aloca uma midia auxiliar
        EntradaCriaMidia(adiciona);//cria a midia auxiliar
        AdicionaMidiaNoAlbumID(album,adiciona,i);  //adiciona a midia criada dentro do album na posição int i     
    }
 

}
void EntradaPlaylist(Playlist* playlist){   
    //Essa função recebe um ponteiro playlist e não retorna nada
    //O obejtivo dessa função e criar a playlist, recebendo a entrada e preenchendo o ponteiro playlist atraves de funções para playlist
    char*nome;char*nomedono;char*nomedono2;
    int quantmidias=0;int quantdonos;int privacidade;
    
    printf("Nome da Playlist: ");
    nome=PrencheElementos(); //recebe a entrada char
    PrenchePlaylistNome(playlist,nome);//chama a função de atribuir nome para dentro da playlist
    
    
    printf("Quantos donos terá essa playlist?: ");
    scanf("%d",&quantdonos); //recebe a entrada int 
    PrenchePlaylistQuantdedonos(playlist,quantdonos);//chama a função de atribuir quantde donos para dentro de playlist
    
    
    printf("Digite o Seu Login(Dono):");        
    nomedono=PrencheElementos(); //recebe a entrada char
    PrenchePlaylistNomeDonos(playlist,nomedono,0);//chama a função de atribuir nome dono para dentro da playlist na posição 0
    
    
    printf("Essa playlist sera publica(1) ou privada(2)? ");
    scanf("%d",&privacidade); //recebe a entrada int 
    PrenchePlaylistPrivacidade(playlist,privacidade);//chama a função de atribuir privacidade para dentro de playlist

    
    PrenchePlaylistQuantmidias(playlist,0); //chama a função de atribuir quantidade de midia para dentro de playlist
    AlocaMidiaNAPlaylist(playlist);//chama a função para alocar as midias dentro da playlist
    PrenchePlaylistestasendoseguida(playlist,0,2);
    PrenchePlaylistestasendoseguida(playlist,0,1);
    PrenchePlaylistestasendoseguida(playlist,0,0);   
    
    
}
void EntradaUsuario(Usuario* usuario){
    //Essa função recebe um ponteiro usuario e não retorna nada
    //O obejtivo dessa função e criar o usuario, recebendo a entrada e preenchendo o ponteiro usuario atraves de funções para usuario
    char*nome;char*login;char*senha;
    
    printf("[Digite o seu Nome]:");
    nome=PrencheElementos();    //recebe a entrada char
    PrencheUsuarionome(usuario,nome);//chama a função de atribuir nome para dentro do usuario
    
    printf("[Digite o Login do Usuario]:\n");
    login=PrencheElementos();     //recebe a entrada char
    PrencheUsuarioLogin(usuario,login);//chama a função de atribuir login para dentro do usuario
   
    printf("[Digite o Senha]:");
    senha=PrencheElementos(); //recebe a entrada char
    PrencheUsuarioSenha(usuario,senha);//chama a função de atribuir senha para dentro do usuario
    
    PrencheQuantPlayusuario(usuario,0);//chama a função de atribuir quantidade de play para dentro do usuario


}
void  menucriar(Server* server){
    //Essa função ira receber um ponteiro server e não irar retornar nada por tratarmos de ponteiro
    //O obejtivo dessa função e controlar melhor as opções de criar do menu
    int escolha=0;int escolha2=0;
    Album* album;int quant=0;int playanterior=0;
    Playlist* playlist;int quantdedonos=0;
    int id;int quantplay;int idoutrodono=0;
    int quantplay2=0;int quantuser=0;
    char*aux;
    
    while(escolha!=9){
        Criar();    //imprime as opções de criar do menu
        scanf("%d",&escolha);

        if(escolha==1){ //Criar playlist
            id=RecuperaIdLogada(server);    //recupera a id do server
            quantplay=RecuperaQuantPlayUsuariodoServer(server,id);//recupera quant de play criadas daquele user
            if(quantplay<20){
                printf("criou playlist\n");
                playlist=CriaPlaylist();    //aloc playlist em uma auxiliar playlist
                EntradaPlaylist(playlist);  //cria a playlist 
                PrenchePlaylistUsuarioNoServer(server,playlist,quantplay,id);//chama função que vai colocar a playlist criada dentro das playlists do user no server
                playanterior=quantplay;     //salva o ID posição da playlist adiconada anteriormente 
                quantdedonos=RecuperaQuantDeDonosnaPlaylistDentroServer(server,id,playanterior);    //recupera quantidade de donos da playlist anterior
            
                if(quantdedonos==2){            //se for 2 donos ira adionar o segundo dono
                  quantuser=RecuperaQuantDeUsuariosCriados(server);//recupera quant de usuario
                  if(quantuser!=0){     //garante que exita mais donos para a playlist
                    printf("Adicionar 2 Dono:\n");
                    MostraLoginDeOutrosUsuarioSemIDlogado(server,id);//mostra na tela os logins disponiveis
                    printf("Digite o ID Do Segundo Dono:\n");
                    scanf("%d",&idoutrodono);                       //escolhe o id do doutro dono
                    quantplay2=RecuperaQuantPlayUsuariodoServer(server,idoutrodono);//recupera a quantidade de playlist do outro dono
                    
                    if(quantplay2<20){  //verifica se o outro dono pode ter uma nova playlist
                        PrenchePlaylistUsuarioNoServer(server,playlist,quantplay2,idoutrodono); //adiciona playlist nas playlists do outro dono
                        ImprimiLogindoServer(server,idoutrodono);   //Imprime o login do 2 dono
                        printf("Digite o Login Do Outro Dono:\n");
                        aux=PrencheElementos();     //escreve o nome em uma auxiliar que ira aparecer na playlist como 2 dono
                        PrenchePlaylistNomeDonos(playlist,aux,1);   //chama a função para atruibuir o ponteiro char auxiliar para  dono da playlist na posição 2
                    }
                    else{   //se esse segundo dono ja tem o numero maximo de playlist
                        NumeroMaxaalcancado();
                        PrenchePlaylistQuantdedonos(playlist,1);//remove 1 da quantidade de donos da playlist
                    }
                }
                  else{   //se não existirem outros usuarios criados
                    system("clear");
                    printf("Não existem outros usuarios\n");
                    PrenchePlaylistQuantdedonos(playlist,1);    //remove 1 da quantidaed de donos da playlist
                }
                }
            }
        else{ //se o usurio jã criou o maximo possivel
                NumeroMaxaalcancado();
            }
        }

        else if(escolha==2){    //Criar um album
            printf("Criar Album:\n");
            quant=RecuperaQuantAlbum(server);//recupera a quantidade de albuns criados
            if(quant<20){
                album=CriaAlbum();//aloca uma auxiliar album
                EntradaAlbum(album);//cria um novo album
                AdicionaAlbumServer(server,album,quant);//chama a função para adicionar esse album criado nos albuns do server
            }
            else{   //se o maximo de albuns ja foi criado
                NumeroMaxaalcancado();
            }
        }
    }
}
void MenuLer(Server* server){
    //Essa função recebe um ponteiro server e não retorna nada por tratarmos de ponteiro
    //o Obejtivo dessa função é controlar as opções de ler do menu
    int escolha=0;int escolha2=0;int idescolha=0;
    int i;int quant=0;int escolhaplay=0;
    int id=0;int quantplay=0;
    int escolhalbum=0;
    int quantplaypu=0;int quantseguidas=0;
    
    while(escolha!=9){          
        Lerobjeto();        //mostrar na tela as opções de ler do menu
        scanf("%d",&escolha);
        id=RecuperaIdLogada(server);    //recupera a id logada no server
    
        if(escolha==1){     //Ler uma playlist
            id=RecuperaIdLogada(server);
            quantplay=RecuperaQuantPlayUsuariodoServer(server,id);//recupera a quantidade de playlist criadas
                if(quantplay!=0){   
                ImprimiPlaylistsDoUsuarioNoServer(server,id);//IMprimir o nome das playlists do usuario logado
                printf("Qual PLaylist Deseja Ler:");
                scanf("%d",&escolha2);                  //escolhe a playlist
                ImprimiPlaydouserNoServer(server,id,escolha2);   //imprime a playlist escolhida do usuario logado
                }
                
                else{       //se não tiver nenhuma playlist criada  
                system("clear");
                printf("[Nenhuma Playlist Para Ler]\n");
                printf("\n\n");
                }
        }
    
    
        else if(escolha==2){//ler uma midia
            system("clear"); 
            printf("Digite o ID do album para Entra:");
            ImprimiTodosAlbunsdoServer(server);     //Imprime nome dos albuns do server           
            scanf("%d",&escolhalbum);               //escolhe um album
            ImprimiAlbumdoServercomID(server,escolhalbum);   //imprime o album esoclhido
            printf("\n");
            printf("Digite o ID da midia");
            scanf("%d",&id);        //escolhe a midia pelo id
        
            ImprimeMidiaNoAlbumDentroServer(server,escolhalbum,id); //imprime a midia escolhida
            printf("\n\n");
        }
    
        else if(escolha==3){    //ler um album
            quant=RecuperaQuantAlbum(server);
                if(quant!=0){
                    Imprimiopcaoalbum();
                    ImprimiNomeAlbumComID(server);  //imprime nome de todos os albuns do server
                    scanf("%d",&escolha2);          //escolhe o album
                    ImprimiAlbumdoServercomID(server,escolha2);  //imprime o album escolhido
                }
                else{   //se não existir album no server
                    system("clear");
                    printf("[Nenhum Album Para Ler]\n");
                    printf("\n\n");         
                }
        }
    
        else if(escolha==4){    //imprime playlist favoritas 
            printf("Favoritas:\n");
            id=RecuperaIdLogada(server);    //recupera o id logado
            ImprimiPlayFavoritadouserNoServer(server,id);//chama função para imprimir as playlist de midias favoritas do usuaario
        }
    
    
        else if(escolha==5){    //imprimir playlists seguidas pelo usuario
            id=RecuperaIdLogada(server);
            ImprimiasplaylistsSeguidasdoUsuarioDentroServer(server,id);
                      
        }
    }
}
void EdicaoMenu(Server* server){
    //Essa função recebe um ponteiro server e não retorna nada por tratarmos de ponteiro
    //O obejtivo dessa função e controlar as opções de edição do menu
    
    int escolha=0,escolha2=0;int escolhaplay=0,escolhalbum=0;
    int i=0;int idMidia;int IDuser;int quantplay=0;
    int IDdamidia=0;
    int id1=0,id2=0;
    int quant=0;
    
    IDuser=RecuperaIdLogada(server);    //Recupera a id logada no server 
    quantplay=RecuperaQuantPlayUsuariodoServer(server,IDuser);//Recupera quantas playlist criadas aquele Id possui
    quant=RecuperaQuantAlbum(server);   //Recupera quantos albuns criados o server possui
    
    
    while(escolha!=9){
        MenuEditar();                   //imprime as opções de edição do menu
        scanf("%d",&escolha);
    
        if(escolha==1){
            MenuEditarPlaylist();       //Imprimi menu de edição de playlists
            scanf("%d",&escolha2);
                   
            if(escolha2==1){               //Adicionar midia na playlist 
                ImprimiPlaylistsDoUsuarioNoServer(server,IDuser);    //imprimi as playlist do usuario logado
                printf("Digite o ID da Playlist a ser Editada:");
                scanf("%d",&escolhaplay);                       //Escolhe a playlist pelo ID
                        
                printf("Digite o ID do album para Entra:");
                ImprimiTodosAlbunsdoServer(server);       //Imprimi OS albuns disponiveis                
                scanf("%d",&escolhalbum);                  //escolhe o album
                ImprimiAlbumdoServercomID(server,escolhalbum);  //imprimi o album
                        
                printf("Digite o ID da Midia a ser adicionada");
                scanf("%d",&IDdamidia);     //escolhe a midia do album
                AdicionaMidiaNAPlayuserDoSERVE(server,IDuser,escolhalbum,IDdamidia,escolhaplay);//adiciona aquela midia na playlist escolhida passando para função todos elementos da escolha
            }
            
            else if(escolha2==2){   //Trocar posição de musica
                printf("Trocar posição de musica");
                
                ImprimiPlaylistsDoUsuarioNoServer(server,IDuser);    //Imprime as playlists disponiveis
                printf("Digite o ID da Playlist a ser Editada:");
                scanf("%d",&escolhaplay);                           //escolhe uma playlist
                ImprimiPlaydouserNoServer(server,IDuser,escolhaplay);//imprime as playlist
                printf("ID do primeira Musica:");
                scanf("%d",&id1);       //escolhe primeiro id
                printf("ID do segunda Musica:");
                scanf("%d",&id2);       //escolhe segundo id
                
                TrocaPosiMidiaPlaylistnoUserdentroServer(server,IDuser,escolhaplay,id1,id2);//função que vai trocar de posição as midias na playlist escolhida
                   
            }
    
            else if(escolha2==3){   //Apagar musica da playlist
                 printf("Apagar uma musica");
                 
                ImprimiPlaylistsDoUsuarioNoServer(server,IDuser);    //Imprimi as playlists do usuario logado
                printf("Digite o ID da Playlist a ser Editada:");
                scanf("%d",&escolhaplay);  //Esolhe a playlist
                
                ImprimiPlaydouserNoServer(server,IDuser,escolhaplay);   //imprime a playlist escolhida
                printf("ID da Musica que deseja Apagar:");
                scanf("%d",&id1);       //escolhe a midia da playlist a ser apagada
                
                ApagaMidiaDaPlaylistdoUserdentroServer(server,IDuser,id1,escolhaplay);//chama a função para apagar a midia escolhida da playlist escolhida do usuario logado
                
            }  
        }

        else if(escolha==2){  //Editar albuns
            MenuEditarAlbum();  //Imprime as opções de edição de album
            scanf("%d",&escolha2);
            if(escolha2==1){    //Trocar posição de album
                Imprimiopcaoalbum();    
                ImprimiNomeAlbumComID(server);  //Imprime o nome de todos os albuns adicionados no server                             
                 printf("ID do primeiro:");
                 scanf("%d",&id1);              //escolhe o id1
                 printf("ID do segundo:");
                 scanf("%d",&id2);              //escolhe o id2
                 TrocaAlbumPosID(server,id1,id2);   //chama função para trocar posição do album id1 com id2      
                }
     
            else if(escolha2==2){       //Apagar album
                ImprimiNomeAlbumComID(server);  //Imprime o nome de todos os albuns adicionados no server
            
                printf("ID do Album a ser removido:");
                scanf("%d",&id1);   //escolhe o album
            
                ApagaAlbumdoServer(server,id1); //chama a função para apagar album escolhido do server
            }    
            
            else if(escolha2==3){   //Destruir midia Do album(free)
                printf("Digite o ID do album para Entra:");
                ImprimiTodosAlbunsdoServer(server);    //Imprime o nome de todos os albuns adicionados no server            
                scanf("%d",&escolhalbum);               //escolhe o album 
                ImprimiAlbumdoServercomID(server,escolhalbum);  //imprimi o album
            
                printf("Posicão da Midia a ser destruída");
                scanf("%d",&id1);   //escolhe a posiçao da midia
                DestroiMidiaNoAlbumDentroServer(server,escolhalbum,id1);//destroi a midia escolhida do server (free)
            
            }
     
     }

        else if(escolha==3){    //Editar Favoritas
            printf("Favoritas\n");
            EditarFavoritas();  //opções de editar as favoritas
            scanf("%d",&escolha2);
        
            if(escolha2==1){    //Adicionar midias as favoritas
                if(quant!=0){
                    printf("Digite o ID do album para Entra:");
                    ImprimiTodosAlbunsdoServer(server); //imprimi os albuns disponiveis  com ID             
                    scanf("%d",&escolhalbum);   //escolhe o album
                    ImprimiAlbumdoServercomID(server,escolhalbum);    //Imprimi o album com as midias
                    printf("Digite o ID da Midia a ser adicionada");
                    scanf("%d",&IDdamidia); //escolhe uma midia do album
                    AdicionaMidiaNAPlayFavoritauserDoSERVE(server,IDuser,escolhalbum,IDdamidia);//chama a função para adicionar a midia escolhida nas Playlist favoritas
                }
            }
            
    
            else if(escolha2==2){   //remover uma midia da playlist Favoritas
                ImprimiPlayFavoritadouserNoServer(server,IDuser);//Imprime a playlist favoritas
                printf("Digite o ID Da Midia a ser removida:\n");
                scanf("%d",&IDdamidia); //escolhe o id da midia a ser removida
                ApagaMidiaDaPlaylistFavoritosdoUserdentroServer(server,IDuser,IDdamidia);//chama a função para apagar a midia esoclhida da playlist favoritas
            }   
        }          
    }
}
void MenuSairdaContaconfirmacao(Server* server){
    //Essa função recebe um ponteiro sever e não retorna nada
    //Realiza apenas uma verificação se o usuario deseja sair da conta
    int escolha=0,escolha2=0;
    system("clear");
    printf("Deseja Realmente Sair da Conta(1-sim/2-não)\n");
    scanf("%d",&escolha);
    if(escolha==1){
    MenuSairdaConta(server);//Chama a função sir da conta passando ponteiro server
    }
}
void MenuSairdaConta(Server* server){
    //Essa função recebe um ponteiro server e não retorna nada
    Playlist*favoritas;
    system("clear");
    int escolha=0,escolha2=0;int controleuser=0;int controlemax=0;
    int quantusu;int escolhaid=0;
    Usuario* usuario;
    MenuSairdouser();   //imprimi as opões de sair da conta para usuario logado
    scanf("%d",&escolha);
    
    
    if(escolha==1){
        quantusu=RecuperaQuantDeUsuariosCriados(server);    //recupera quantidade de usuarios que foram criados
        if(quantusu<2){                                     //verifica se a quantidade está dentro da permitida
        PrencheQuantUsuarioscriados(server,quantusu+1);     //prenche no server a nova quantidade de usuarios criados
        quantusu=RecuperaQuantDeUsuariosCriados(server);    //recupera a nova quantidade de usuarios criados
        PrencheIDLogado(server,quantusu);                   //altera o ID logado no server para o novo usuario criado
        
        
        printf("A ID desse usuario sera [%02d]",quantusu);   //printa o ID do novo usuario
        usuario=CriaUsuario();                               //função auxiliar usuario é alocado                   
        EntradaUsuario(usuario);                             //auxiliar usuario é modificado para o novo usuario               
        PrencheUsuarionoServer(server,usuario,quantusu);     //Manda para a função de prencher usuario no server o usuario criado e a posição que vai ocupar(ID)
        
        printf("Logado como :");
        ImprimiLogindoServer(server,quantusu);               //imprimi login do usuario   
        favoritas=CriaPlaylist();                            //aloca a playlist favorita do novo usuario
        IniciaFavoritas(favoritas);                          //inicia as favoritas                  
        PrenchePlaylistFavoritosUsuarioNoServer(server,favoritas,quantusu);// manda para prencher no server
        }
        else{
            MaxuserCadastrados();       //aviso de maxima quantidade de usuarios ja criados
            printf("\n");
            
        }
    
    }
    else if(escolha==2){                //Trocar o usuario logado
        ImprimeLogindosUsuarioseID(server); //imprimi usuarios disponiveis para logar
        printf("Digite o ID do usuario :\n");
        scanf("%d",&escolhaid);
        
        PrencheIDLogado(server,escolhaid);  //altera o ID logado para o ID do usuario escolhido
        ImprimiLogindoServer(server,escolhaid); //Imprimi o login do usuario logado
    }
    
    
    
}
void MenuRemover(Server* server){
    //Essa função ira receber um ponteiro server
    system("clear");
    int escolha,escolha2;int i,escolhaplay=0;
    int IDuser=0;int quantplay=0;
    printf("Deseja Remover uma Playlist(1-sim/2-não):\n");
    scanf("%d",&escolha);
    
    
    IDuser=RecuperaIdLogada(server);    //recuperar o id logado no server
    quantplay=RecuperaQuantPlayUsuariodoServer(server,IDuser);  //recuperar quantas playlists aquele usuario tem
    
    if(escolha==1){
            ImprimiPlaylistsDoUsuarioNoServer(server,IDuser);    //imprimir o nome das playlist daquele usuario
            printf("Digite o ID da Playlist a ser Editada:");
            scanf("%d",&escolhaplay);                           //definindo a playlist escolhida
    
            ApagaPLaylistdousuariodentroServer(server ,escolhaplay,IDuser); //função para apagar a playlist escolhida daquele usuario
 
    }
}
void Pesquisar(Server* server){
    //Essa função recebe um ponterio server 
    //O obejtivo dessa função e pesquisar no server categorias de midias,nome de albuns e outros usuarios
    //Não retorna nada por tratarmos de ponteiro
    
    int idescolha=0;int escolhaplay=0;int id=0;int quantplaypu=0;
    int escolha=0;char*pesquisa;
    int escolhaseguir=0;int quantsegue=0;
    Playlist* play;
    
    opcoesdePesquisa();                     //Imprimi opçoes para pesquisar
    scanf("%d",&escolha);                   //definindo categoria a pesquisar
    
    if(escolha==1){
       system("clear");
       printf("Digite o nome a pesquisar:\n");
       pesquisa=PrencheElementos();        //Atribui a string a pesquisar para pesquisa     
       PesquisaacomNomeMidiaNoAlbumDentroServer(server,pesquisa); //manda para a função de pesquisar o server e o ponteiro char
    }    

    else if(escolha==2){
       system("clear");
       printf("Digite o nome Do Artista:\n");
       pesquisa=PrencheElementos();         //Atribui a string a pesquisar para pesquisa 
       PesquisaacomNomeArtistaNoAlbumDentroServer(server,pesquisa); //manda para a função de pesquisar o server e o ponteiro char
    }

    else if(escolha==3){
       system("clear");
       printf("Digite o Compositor:\n");
       pesquisa=PrencheElementos();         //Atribui a string a pesquisar para pesquisa 
       PesquisaacomCompositorNoAlbumDentroServer(server,pesquisa);  //manda para a função de pesquisar o server e o ponteiro char
       
    }

    else if(escolha==4){
       system("clear");
       printf("Digite o Genero:\n");
       pesquisa=PrencheElementos();         //Atribui a string a pesquisar para pesquisa 
       PesquisaacomGeneroNoAlbumDentroServer(server,pesquisa);  //manda para a função de pesquisar o server e o ponteiro char
       
    }

    else if(escolha==5){
       system("clear");
       printf("Digite a Gravadora:\n");
       pesquisa=PrencheElementos();         //Atribui a string a pesquisar para pesquisa 
       PesquisaacomGravadoraNoAlbumDentroServer(server,pesquisa);   //manda para a função de pesquisar o server e o ponteiro char
    }

    else if(escolha==6){
       system("clear");
       printf("Digite o Nome do Album:\n");
       pesquisa=PrencheElementos();         //Atribui a string a pesquisar para pesquisa 
       PesquisaaOAlbumDentroServer(server,pesquisa);    //manda para a função de pesquisar o server e o ponteiro char
    }

    else if(escolha==7){
        printf("Pesquisar Outros Usuarios:\n");
        id=RecuperaIdLogada(server);            //recupera a id que esta logada
        MostraLoginDeOutrosUsuarioSemIDlogado(server,id);//imprimi o logins dos outros usuarios
        printf("Buscar Playlists de qual Usuario:\n");
        printf("Digite o ID:\n");
        scanf("%d",&idescolha);
        
        quantplaypu=RecuperaquantDePlaylistsPublicasdoID(server,idescolha); //recupera a quantidade de playlist publicas que o usuairo escolhido possui
            if(quantplaypu!=0){
                ImprimiPlaylistsPublicasDoUsuarioNoServer(server,idescolha);//imprimi as playlist publicas do usuario escolhido
                printf("Digite o ID da Playlist escolhida:\n");
                scanf("%d",&escolhaplay);
                ImprimiPlaydouserNoServer(server,idescolha,escolhaplay);    //imprimi a playlist publica escolhida do usuario escolhido
                printf("Deseja Seguir Essa Playlist(1-sim/2-não):\n");
                scanf("%d",&escolhaseguir);
             
                if(escolhaseguir==1){   
                PrenchePlaylistestasendoseguidaDouserdoServer(server,idescolha,escolhaplay,1,id);            
                               
                }
            
            }
            else{
                system("clear");
                printf("Nenhuma Playlist Publica"); //se o usuario eescolhido não tiver playlist publicas
                printf("\n\n");
            }
    }
}
void IniciaFavoritas(Playlist* playlist){
    //A função vai receber ponteiro playlist 
    //Essa função tem objetivo de configurar a playlist Favoritas do usuario
    char valor[10]="Favoritas";             
    char*nome;char*nomedono;char*nomedono2;
    int quantmidias=0;int quantdonos;int privacidade;
    nome=(char*)malloc(10); //aloca o nome
    strcpy(nome,valor);     //copia a string de valor para nome
    PrenchePlaylistNome(playlist,nome);     //usa a função para prencher o nome
    PrenchePlaylistQuantdedonos(playlist,0);//usa a função para prencher a quantidade de donos
    PrenchePlaylistPrivacidade(playlist,0);//usa a função para prencher a privacidade
    PrenchePlaylistQuantmidias(playlist,0);//usa a função para prencher a quantidade de midias
    AlocaMidiaNAPlaylist(playlist);        //Chama a função para alocar as midias na playlist     
}


