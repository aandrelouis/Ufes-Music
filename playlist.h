#ifndef PLAYLIST
#define PLAYLIST

typedef struct playlist Playlist;
typedef struct midia Midia;
typedef struct album Album;

Playlist* CriaPlaylist();
void PrenchePlaylistNome(Playlist* playlist,char* entrada);
void PrenchePlaylistNomeDonos(Playlist* playlist,char*entrada,int id);
void PrenchePlaylistQuantmidias(Playlist* playlist,int entrada);
void PrenchePlaylistQuantdedonos(Playlist* playlist,int entrada);
void PrenchePlaylistPrivacidade(Playlist* playlist,int entrada);
void ImprimePlaylist(Playlist* playlist);
void AlocaMidiaNAPlaylist(Playlist* playlist);
void AdicionaMidiaPlaylist(Playlist *play,Midia *midia);
void ImprimenomePlaylistcomid(Playlist* playlist,int id);
void TrocaPosiMidiaPlaylist(Playlist *playlist,int pos1,int pos2);
void ApagaMidiaDaPlaylist(Playlist *playlist,int identificador);
int RecuperaPrivacidadeDaPlaylist(Playlist *playlist);
int RecuperaQuantDeDonos(Playlist* playlist);
void PrenchePlaylist2NomeDono(Playlist* playlist,char*entrada);
void CopiaPlaylist(Playlist*original,Playlist* copia);
#endif 
