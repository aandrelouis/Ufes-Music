#ifndef ALBUM
#define ALBUM

typedef struct album Album;
typedef struct midia Midia;

Album* CriaAlbum();
void PrencheAlbumNome(Album* album,char*entrada);
void PrencheAlbumArtista(Album* album,char*entrada);
void PrencheAlbumGenero(Album* album,char*entrada);
void PrencheAlbumcompositID(Album* album,char*entrada,int id);
void PrencheAlbumAno(Album* album,int entrada);
void PrenchealbumQuantmidias(Album* album,int entrada);
void PrencheAlbumQuantComp(Album* album,int entrada);
void AdicionaMidiaNoAlbumID(Album* album,Midia*midia,int posicao);
void ImprimeAlbum(Album *a);
void ImprimenomeAlbumcomId(Album* album,int id);
Midia* RecuperaMidiadoAlbum(Album* album , int posicao);
void ImprimeMidiaNoAlbum(Album* album,int identificador);
void TrocaPosicaoMidiaNoAlbum(Album* album,int id1,int id2);
void DestroiMidiaNoAlbum(Album* album,int posicao);
void PesquisaacomNomeMidiaNoAlbum(Album* album,char* entrada);
void PesquisaacomArtistaMidiaNoAlbum(Album* album,char* entrada);
void PesquisaacomCompositorMidiaNoAlbum(Album* album,char* entrada);
void PesquisaacomGeneroNoAlbum(Album* album,char* entrada);
void PesquisaacomGravadoraNoAlbum(Album* album,char* entrada);
void PesquisaOAlbumPeloNome(Album* album,char* entrada);
Album* AlocaTudoAlbum();
Album* LeituraAlbumArquivo(FILE *arquivo);
void ImprimeAlbumArquivo(Album* album,FILE*arquivo);
#endif 



