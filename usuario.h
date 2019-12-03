#ifndef USUARIO
#define USUARIO

typedef struct usuario Usuario;
typedef struct playlist Playlist;
typedef struct midia Midia;

Usuario* CriaUsuario();
void PrencheUsuarionome(Usuario* usuario,char* entrada);
void PrencheQuantPlayusuario(Usuario* usuario,int entrada);
void PrencheUsuarioSenha(Usuario* usuario,char* entrada);
void PrencheUsuarioLogin(Usuario* usuario,char* entrada);
void PrencheQuantPlayusuario(Usuario* usuario,int entrada);
void ApagaPLaylistdousuario(Usuario *usuario, int identificador);
void TrocaPlaylistPosUsuario(Usuario *usuario,int pos1,int pos2);
void ImprimiLogin(Usuario*usuario);
void AdicionaPlaylistnoUsuario(Usuario* usuario,Playlist* playlist,int posicao);
void ImprimeNomedasPlaylistdousuario(Usuario* usuario);
void ImprimePlayDosuario(Usuario* usuario,int posicao);
int RecuperaQuantPlay(Usuario* usuario);
void AdicionaPlaylistnoUsuario(Usuario* usuario,Playlist* playlist,int posicao);
void ImprimiLogin(Usuario*usuario);
void AdicionaMidiaNaPlayDoUser(Usuario* usuario,Midia*midia,int IDdaplay);
void TrocaPosiMidiaPlaylistnoUser(Usuario* usuario,int IDdaPlay,int pos1,int pos2);
void ApagaMidiaDaPlaylistdoUser(Usuario* usuario,int identificador,int IDdaPlay);
void ImprimeNomedasPlaylistPublicasdousuario(Usuario* usuario);
int RecuperaQuantdePlaylistPublicasdousuario(Usuario* usuario);
char* RecuperaLogindoUser(Usuario* usuario);
int RecuperaQuantDeDonosDaPlayDoUsuario(Usuario* usuario,int IDdaplay);
void AdicionaPLayFavoritasnoUsuario(Usuario* usuario,Playlist* playlist);
void ImprimePlayDosuarioFavoritas(Usuario* usuario);
void ApagaMidiaDaPlaylistFavoritosdoUser(Usuario* usuario,int identificador);
void AdicionaMidiaNaPlayFavoritaDoUser(Usuario* usuario,Midia*midia);
void PrencheQuantPlaySeguindousuario(Usuario* usuario,int entrada);
void ImprimeNomePlayDosuarioSeguindo(Usuario* usuario);
int RecuperaQuantSeguindoDoUsuario(Usuario* usuario);
void AdicionaPlaylistnoUsuarioseguindo(Usuario* usuario,Playlist* playlist,int posicao);
void IMprimiPlayQueUsuarioEstaSeguindo(Usuario* usuario,int IDplay);
void IMprimiNomedasPlaysqueUsuarioEstaSeguindo(Usuario* usuario);
void CopiaplaylistDeOutroUserSeguindo(Usuario* original,Usuario* copia,int poscopia,int IDdaplay);
#endif 


