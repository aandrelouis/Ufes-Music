#ifndef SERVER
#define SERVER

typedef struct server Server;
typedef struct album Album;
typedef struct usuario Usuario;
typedef struct playlist Playlist;


//Essa função não recebe argumentos 
//Ela cria um ponteiro server novo
//aloca o ponteiro
//e retorna o ponteiro server alocado
Server* CriaServer();


//Essa função recebe um ponteiro server e um int ID
//vai atribuir o int ID para dentro do idusuario dentro do ponteiro server
//Não retorna nada por tratarmos de ponteiro
void PrencheIDLogado(Server* server,int ID);

//Essa função recebe um ponteiro server e um int ID
//vai atribuir o int ID para dentro do quantidade de usuarios criados dentro do ponteiro server
//Não retorna nada por tratarmos de ponteiro
void PrencheQuantUsuarioscriados(Server* server,int entrada);

//Essa função recebe um ponteiro server e um int ID
//vai atribuir o int ID para dentro do quantidade album dentro do ponteiro server
//Não retorna nada por tratarmos de ponteiro
void PrencheQuantdeAlbum(Server* server,int entrada);

//Essa função ira receber um ponteiro server,int id1 e int id2
//Ela vai trocar a posição dos albuns do server com ajuda de uma auxiliar
//trocando de posição os albuns identificados com o int id2 e o int id2
//Não retorna nada por tratarmos de ponteiro
void TrocaAlbumPosID(Server* server,int id1,int id2);

//Essa função recebe um ponteiro server,um ponteiro album e um int posição
//Ela vai atuibuir o ponteiro album para dentro do lista de albuns dentro do server na posição int pos
//depois vai somar 1 na quantidade de albuns dentro do server,atualizando a quantidade de albuns
//Não retorna nada por tratarmos de ponteiro
void AdicionaAlbumServer(Server* server,Album* album,int pos);

//Essa função vai receber um ponteiro server e um int pos
//vai chamar a função de imprimir album 
//pasando como argumento o album de dentro do vetor de albuns do server identificado pelo int pos   
void ImprimiAlbumdoServer(Server* server,int pos);

//Recebe um ponteiro server
//vai retornar um int quantidade de albuns de dentro do server
int RecuperaQuantAlbum(Server* server);

//Essa função vai receber um ponteiro server
//vai passar  todos os albuns do server identificados pelo int i dentro da repetição
//para a função de imprimir o nome dos albuns com o id
void ImprimiNomeAlbumComID(Server * server);

//Essa função vai receber um ponteiro server e um int ID
//vai chamar a função de imprimir o album
//passando como argumento o album do server identificado pelo int int ID   
void ImprimiAlbumdoServercomID(Server * server,int ID);

//Essa função recebe um ponteiro server
//vai retornar um int idusuario de dentro do server que diz qual id esta logada
int RecuperaIdLogada(Server* server);

//Essa função vai receber um ponteiro server,um ponteiro usuario, e um int ID
//vai atuibuir o ponteiro usuario para dentro do vetor de ponteiros usuario dentro do server identificado pelo Int ID  
//Não retorna nada nada por tratarmos de ponteiro
void PrencheUsuarionoServer(Server*server,Usuario* usuario,int ID);

//Essa função vai receber um ponteiro server e um int ID
//Vai chamar a função de imprimir login 
//passando o usuario De dentro do server identificado pelo int ID  
void ImprimiLogindoServer(Server* server, int ID);

//Essa função vai receber um ponteiro server, um ponteiro playlist,um int posição e um int ID
//vai chamar a função de adiconar playlist no usuario Passando o usuario dentro do server identificado pelo int id
//passando tambem o ponteiro playlist e o int posicao  
void PrenchePlaylistUsuarioNoServer(Server* server,Playlist* playlist,int posicao,int id);
    
//Essa função vai receber um ponteiro server, um int ID e um int posição
//Vai chamar a função de imprimir playlist do usuario passando como argumento o usuario de dentro do server identificado pelo int ID
//passando tambem o int posição
void ImprimiPlaydouserNoServer(Server* server,int ID,int posicao);


//Essa função vai receber um ponteiro server, um int ID
//Vai chamar a função de imprimir nome das playlists do usuario passando como argumento o usuario de dentro do server identificado pelo int ID    
void ImprimiPlaylistsDoUsuarioNoServer(Server* server,int ID);

//Essa função vai receber um ponteiro server e um int id
//vai retornar a quantidade de de playlists criadas daquele usuario
int RecuperaQuantPlayUsuariodoServer(Server* server,int id);

//Essa função vai receber um ponteiro server
//vai chamar a funçãod e imprimir album
//passando todos albuns do server
//nao retorna nada
void ImprimiTodosAlbunsdoServer(Server* server);

//Essa função vai receber um ponteiro server,um int IDuser,um int IDdoalbum,um int IDdamidia e um int IDdaplay
//Esa função tem o objetivo de adicionar midia na playlist de um usuario 
//primeiro ela cria uma midia auxiliar e aloca
//Depois chama a função de recuperar midia do album passando o album identificado pelo IDdoalbum, e o id da midia 
//a função auxiliar vai receber a midia escolhida
//Depois Chama a função adicionar midia na play do user passando o usuario identificado pelo int IDuser,passando a midia auxiliar e o int ID da play 
void AdicionaMidiaNAPlayuserDoSERVE(Server* server,int IDuser,int IDdoalbum,int IDdamidia,int IDdaPlay);

//Essa função recebe um ponteiro server, um int IDuser,um int IDdaplaye um int identificador
//Ela vai chamar a função de Apagar midia da Playlist do user
//passando como argumento o usuario de dentro do server identificado pelo IDuser, o int identificador,e o int iDdaplay 
void ApagaMidiaDaPlaylistdoUserdentroServer(Server* server,int IDuser,int identificador,int IDdaPlay);

//Essa função recebe um ponteiro server, um int IDuser,um int IDdaplay,dois int pos1 e pos2
//Ela vai chamar a função de trocar posição playlist no user
//passando como argumento o usuario de dentro do server identificado pelo IDuser, o IDdaply,e as duas posições 
void TrocaPosiMidiaPlaylistnoUserdentroServer(Server* server,int IDuser,int IDdaPlay,int pos1,int pos2);

//Essa função recebe um ponteiro server, um int IDuser,um int identificador
//Ela vai chamar a função de Apagar PLaylist do user
//passando como argumento o usuario de dentro do server identificado pelo IDuser e  o int identificador
void ApagaPLaylistdousuariodentroServer(Server* server ,int identificador,int IDuser);

//Essa função recebe um ponteiro server
//Vai retornar um int quant de usuarios criados de dentro do server
int RecuperaQuantDeUsuariosCriados(Server* server);

//Essa função vai receber um ponteiro server
//vai passar atraves de uma repetição todos os usuarios do server
//para a função de imprimir login,imprimindo tambem o id
void ImprimeLogindosUsuarioseID(Server*server);

//Essa função vai receber um ponteiro server e um int ID
//O Objetivo dessa função é apagar uma album do server
//A partir do album identificado pelo int ID na lista de albuns dentro do server
//vai chamar a função para trocar o album de lugar
//trocando o album identificado pelo que esta depois no vetor
//fazendo isso para todos albuns que vem depois
//depois subtraindo 1 da quantidade de albuns dentro do server para atualizar a quantidade
void ApagaAlbumdoServer(Server* server,int identificador);

//Essa funçao vai receber um ponteiro server,um int IDalbum e int identificador
//Essa função vai chamar a função Imprimi mida no album
//passando como argumento o album de dentro da lista de albuns do server identificado pelo IDalbum
//e o int identificador
void ImprimeMidiaNoAlbumDentroServer(Server* server,int IDalbum,int identificador);

//Essa funçao vai receber um ponteiro server,um int IDalbum e int posição
//Essa função vai chamar a função de destroir midia album  
//passando como argumento o album de dentro da lista de albuns do server identificado pelo IDalbum
//e o int posição
void DestroiMidiaNoAlbumDentroServer(Server* server,int IDalbum,int posicao);

//Essa funçao vai receber um ponteiro server,um int id1,um int id2,int IDdoalbu,
//Essa função vai chamar a função de trocar posição de midia no album 
//passando como argumento o album de dentro da lista de albuns do server identificado pelo IDdoabum
//e os dois int id
void TrocaPosicaoMidiaNoAlbumdentroServer(Server* server,int id1,int id2,int IDdoalbum);

//Essa funçao vai receber um ponteiro server e um ponteiro char entrada
//Essa função vai chamar a função Pesquisa Nome midia no album
//passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
//passando tambem o ponteiro char entrada
void PesquisaacomNomeMidiaNoAlbumDentroServer(Server* server,char*entrada);

//Essa funçao vai receber um ponteiro server e um ponteiro char entrada
//Essa função vai chamar a função Pesquisa Artista midia No Album
//passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
//passando tambem o ponteiro char entrada
void PesquisaacomNomeArtistaNoAlbumDentroServer(Server* server,char*entrada);

//Essa funçao vai receber um ponteiro server e um ponteiro char entrada
//Essa função vai chamar a função Pesquisa Compositor Midia no Album
//passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
//passando tambem o ponteiro char entrada
void PesquisaacomCompositorNoAlbumDentroServer(Server* server,char*entrada);

//Essa funçao vai receber um ponteiro server e um ponteiro char entrada
//Essa função vai chamar a função Pesquisa Genero no Album
//passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
//passando tambem o ponteiro char entrada
void PesquisaacomGeneroNoAlbumDentroServer(Server* server,char*entrada);

//Essa funçao vai receber um ponteiro server e um ponteiro char entrada
//Essa função vai chamar a função Pesquisa Gravadora no Album
//passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
//passando tambem o ponteiro char entrada
void PesquisaacomGravadoraNoAlbumDentroServer(Server* server,char*entrada);

//Essa funçao vai receber um ponteiro server e um ponteiro char entrada
//Essa função vai chamar a função Pesqusa o album pelo nome
//passando como argumento os albuns de dentro da lista de albuns do server identificado pelo int i
//passando tambem o ponteiro char entrada
void PesquisaaOAlbumDentroServer(Server* server,char*entrada);

//Essa função vai receber um ponteiro char  e um int IDlogada
//objetivo dessa função e imprimir os outros logins sem ser da id logada
//vai fazer uma repetição com a quantidade de usuarios criados
//o i que for diferente da int IDlogada vai chamar a função de imprimir aquele usuario
//imprimindo o I e o login daquele usuario identificado pelo int I
void MostraLoginDeOutrosUsuarioSemIDlogado(Server*server,int IDlogada);

//Essa função recebe um ponteiro server e um int ID  
//Ela chama a função Imprimi nome das playlists publicas do usuario
//passando o usuario de dentro do vetor de usuarios do server identificado pelo Int ID
void ImprimiPlaylistsPublicasDoUsuarioNoServer(Server* server,int ID);

//Essa função recebe um ponteiro server e um int ID  
//Ela chama a função Recupe quant de playlist publicas dp usuario
//passando o usuario de dentro do vetor de usuarios do server identificado pelo Int ID
//e retorna o int que essa função chamada retornou
int RecuperaquantDePlaylistsPublicasdoID(Server* server,int ID);

//Essa função recebe um ponteiro server,um int ID e um int IDdaplay 
//Ela chama a função Recupe quant de Donos da playlist do usuario
//passando o usuario de dentro do vetor de usuarios do server identificado pelo Int ID
//passando tambem o int IDdaplay
//e retorna o int que essa função chamada retornou
int RecuperaQuantDeDonosnaPlaylistDentroServer(Server* server,int ID,int IDdaplay);

//Essa função vai receber um ponteiro server, um ponteiro playlist e um int ID
//vai chamar a função de adiconar playlist favorita no usuario Passando o usuario dentro do server identificado pelo int id
//passando tambem o ponteiro playlist   
void PrenchePlaylistFavoritosUsuarioNoServer(Server* server,Playlist* playlist,int id);

//Essa função recebe um ponteiro server, um int IDuser e um int identificador
//Ela vai chamar a função de Apagar midia da Playlist Favorita do user
//passando como argumento o usuario de dentro do server identificado pelo IDuser e o int identificador
void ApagaMidiaDaPlaylistFavoritosdoUserdentroServer(Server* server,int IDuser,int identificador);

//Essa função vai receber um ponteiro server,um int IDuser,um int IDdoalbum,um int IDdamidia
//Esa função tem o objetivo de adicionar midia na playlist Favorita de um usuario 
//primeiro ela cria uma midia auxiliar e aloca
//Depois chama a função de recuperar midia do album passando o album identificado pelo IDdoalbum, e o id da midia 
//a função auxiliar vai receber a midia escolhida
//Depois Chama a função adicionar midia na play Favorita do user passando o usuario identificado pelo int IDuser,passando a midia auxiliar
void AdicionaMidiaNAPlayFavoritauserDoSERVE(Server* server,int IDuser,int IDdoalbum,int IDdamidia);

//Essa função vai receber um ponteiro server e um int ID
//vai chamar a função de Imprimi playlist do usuario favorita
//passando como argumento o usuario do vetor de usuarios do server identificado pelo ID
void ImprimiPlayFavoritadouserNoServer(Server* server,int ID);

//Essa função vai receber um ponteiro server e um int id
//vai fazer um repetição com a quantidade de usuarios existentes
//vai mandar para a função de imprimir playlists seguidas do usuairo, os usuarios identificados pelo id que seja difrentes do IDseguidor recebido
//vai mandar tambem o IDseguidor
void ImprimiasplaylistsSeguidasdoUsuarioDentroServer(Server* server,int IDseguidor);

//Essa função vai receber um ponteiro server ,um int IDdono,int IDdapaly,int entrada,int IDdequemsegue
//vai chamar a função de prencher playlist sendo seguida passando a playlist identificada pelo IDdaplay
//passar tambem os outros ints como argumento
//não retorna nada
void PrenchePlaylistestasendoseguidaDouserdoServer(Server* server,int IDdoDono,int IDdaplay,int entrada,int idquemsegue);

//Essa função recebe um ponteiro server,um int IDuser,e um FILE arquivo
//Vai Chamar a função de imprimir o usuario no arquivo passando o usuairo identificado pelo IDuser
//vai chamar tambem a f unção de imprimir as playlist seguidas daquele usuario
//não retorna nada
void ImprimiUsuarioServerArquivo(Server*server,int IDuser,FILE*arquivo);

//Essa função vai receber u, ponteiro server,um INT ID,File arquivo
//vai chamar a função de ler usuario
//passando o usuario identificado pelo INT ID
//passando tambem o file arquivo
void LeUsuarioArquivoNoServer(Server* server,int ID,FILE* arquivo);

//Essa função vai receber um ponteiro server e um FIle arquivo
//vai chamar a função de imprimir album para todos albuns do server
//imprimindo os albuns no arquivo
void ImprimiTodosalbunsAlbumdoServerarquivo(Server* server,FILE*arquivo);
#endif 


