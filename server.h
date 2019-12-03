#ifndef SERVER
#define SERVER

typedef struct server Server;
typedef struct album Album;
typedef struct usuario Usuario;
typedef struct playlist Playlist;

Server* CriaServer();
void PrencheIDLogado(Server* server,int ID);
void PrencheQuantUsuarioscriados(Server* server,int entrada);
void PrencheQuantdeAlbum(Server* server,int entrada);
void TrocaAlbumPosID(Server* server,int id1,int id2);
void AdicionaAlbumServer(Server* server,Album* album,int pos);
void ImprimiAlbumdoServer(Server* server,int pos);
int RecuperaQuantAlbum(Server* server);
void ImprimiNomeAlbumComID(Server * server);
void ImprimiAlbumdoServercomID(Server * server,int ID);
int RecuperaIdLogada(Server* server);
void PrencheUsuarionoServer(Server*server,Usuario* usuario,int ID);
void ImprimiLogindoServer(Server* server, int ID);
void PrenchePlaylistUsuarioNoServer(Server* server,Playlist* playlist,int posicao,int id);
void ImprimiPlaydouserNoServer(Server* server,int ID,int posicao);
void ImprimiPlaylistsDoUsuarioNoServer(Server* server,int ID);
int RecuperaQuantPlayUsuariodoServer(Server* server,int id);
void ImprimiTodosAlbunsdoServer(Server* server);
void AdicionaMidiaNAPlayuserDoSERVE(Server* server,int IDuser,int IDdoalbum,int IDdamidia,int IDdaPlay);
void ApagaMidiaDaPlaylistdoUserdentroServer(Server* server,int IDuser,int identificador,int IDdaPlay);
void TrocaPosiMidiaPlaylistnoUserdentroServer(Server* server,int IDuser,int IDdaPlay,int pos1,int pos2);
void ApagaPLaylistdousuariodentroServer(Server* server ,int identificador,int IDuser);
int RecuperaQuantDeUsuariosCriados(Server* server);
void ImprimeLogindosUsuarioseID(Server*server);
void ApagaAlbumdoServer(Server* server,int identificador);
void ImprimeMidiaNoAlbumDentroServer(Server* server,int IDalbum,int identificador);
void DestroiMidiaNoAlbumDentroServer(Server* server,int IDalbum,int posicao);
void TrocaPosicaoMidiaNoAlbumdentroServer(Server* server,int id1,int id2,int IDdoalbum);
void PesquisaacomNomeMidiaNoAlbumDentroServer(Server* server,char*entrada);
void PesquisaacomNomeArtistaNoAlbumDentroServer(Server* server,char*entrada);
void PesquisaacomCompositorNoAlbumDentroServer(Server* server,char*entrada);
void PesquisaacomGeneroNoAlbumDentroServer(Server* server,char*entrada);
void PesquisaacomGravadoraNoAlbumDentroServer(Server* server,char*entrada);
void PesquisaaOAlbumDentroServer(Server* server,char*entrada);
void MostraLoginDeOutrosUsuarioSemIDlogado(Server*server,int IDlogada);
void ImprimiPlaylistsPublicasDoUsuarioNoServer(Server* server,int ID);
int RecuperaquantDePlaylistsPublicasdoID(Server* server,int ID);
int RecuperaQuantDeDonosnaPlaylistDentroServer(Server* server,int ID,int IDdaplay);
int RecuperaquantDePlaylistsPublicasdoID(Server* server,int ID);
void PrenchePlaylistFavoritosUsuarioNoServer(Server* server,Playlist* playlist,int id);
void ApagaMidiaDaPlaylistFavoritosdoUserdentroServer(Server* server,int IDuser,int identificador);
void AdicionaMidiaNAPlayFavoritauserDoSERVE(Server* server,int IDuser,int IDdoalbum,int IDdamidia);
void ImprimiPlayFavoritadouserNoServer(Server* server,int ID);
int RecuperaQuantSeguindoDoUsuariodentroServer(Server* server,int ID);
void IMprimiPlayQueUsuarioEstaSeguindoNoServer(Server* server,int IDuser,int IDplay);
void IMprimiNomedasPlaysqueUsuarioEstaSeguindonoServer(Server* server,int ID);
void CopiaPlaylistdeOutroUsernoServer(Server*server,int original,int copia,int poscopia,int IDdaplay);
#endif 


