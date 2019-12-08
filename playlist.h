#ifndef PLAYLIST
#define PLAYLIST

typedef struct playlist Playlist;
typedef struct midia Midia;
typedef struct album Album;

//Essa função não recebe nenhum argumento
//Ela vai Criar um ponteiro do tipo playlist
//vai alocar esse endereço  
//e vai retorna o novo endereço alocado
Playlist* CriaPlaylist();

//Essa função vai receber um ponteiro playlist e um ponteiro char
//vai atribuir o ponteiro char entrada para playlist nome dentro da struct playlist
//Não vai retorna nada por tratarmos de ponteiro
void PrenchePlaylistNome(Playlist* playlist,char* entrada);

//Essa função vai receber um ponteiro playlist,um ponteiro chare um int id
//vai atribuir o ponteiro char entrada para nome do dono na posição do ID dentro da struct playlist
//Não vai retorna nada por tratarmos de ponteiro
void PrenchePlaylistNomeDonos(Playlist* playlist,char*entrada,int id);

//Essa função vai receber um ponteiro playliste um int entrada
//vai atribuir o int entrada para a quant de midias dentro da playlist
//Não vai retorna nada por tratarmos de ponteiro
void PrenchePlaylistQuantmidias(Playlist* playlist,int entrada);

//Essa função vai receber um ponteiro playlist e um int entrada
//vai atribuir o int entrada para a quant de donos dentro da playlist
//Não vai retorna nada por tratarmos de ponteiro
void PrenchePlaylistQuantdedonos(Playlist* playlist,int entrada);

//Essa função vai receber um ponteiro playlist e um int entrada
//vai atribuir o int entrada para privacidade dentro da playlist
//Não vai retorna nada por tratarmos de ponteiro 
void PrenchePlaylistPrivacidade(Playlist* playlist,int entrada);
 
//Essa função recebe um ponteiro playlist
//dentro do ponteiro aloca as 50 midias que possuem na playlist    
//função cria midia esta alocando a midia
//não retorna nada por ser ponteiro
void AlocaMidiaNAPlaylist(Playlist* playlist);

/* Função recebe um ponteiro playlist
 * Imprime todas as informações da playlist
 * Chama a função IMprimiMidia para as midias de acordo com a quantidade
 * Não retorna nada*/
void ImprimePlaylist(Playlist* playlist);

//Essa função recebe um ponteiro playlist e um ponteiro Midia
//A função vai atruibuir a midia para dentro da playlist nas midias na posição quantdemidias 
//logo depois vai somar 1 nas quantdemidias ,atualizando a quantidade e a posição onde entrara a proxima midia
//Não vai retorna nada por tratarmos de ponteiro
void AdicionaMidiaPlaylist(Playlist *play,Midia *midia);

//Recebe um ponteiro playlist e um ID 
//printa o id recebido  
//printa o nome da playlist
//não retorna nada   
void ImprimenomePlaylistcomid(Playlist* playlist,int id);

//Essa função  ira receber um ponteiro playlist e dois int ,pos1 e pos2;
//Ela vai trocar a midia na posicao 1 com a midia na pos2
//Usando uma variavel auxiliar(reserva) criada e alocada so para fazer a troca
//não retorna nada por tratarmos de ponteiro
void TrocaPosiMidiaPlaylist(Playlist *playlist,int pos1,int pos2);

//Essa funçao vai receber um ponterio playlist e um int identificador
//Apartir da posicao da midia pelo int identificador 
//Usando a função troca posição ela troca de lugar a midia escolhida com a proxima e faz isso em uma repetição com a quantidade de midias da playlist
//E no final decrementa 1 da quantidade de midias , atualizando a quantidade de midias da playlist
//Não retorna nada
void ApagaMidiaDaPlaylist(Playlist *playlist,int identificador);

//Essa função recebe um ponteiro playlist 
//retorna o int privacidade 
int RecuperaPrivacidadeDaPlaylist(Playlist *playlist);

//Essa função recebe um ponteiro playlist 
//retorna o int quantidade de donos da playlist
int RecuperaQuantDeDonos(Playlist* playlist);

//Essa função recebe um ponteiro playlist e um ponteiro char entrada  
//a função ira atribuir o char entrada para a posição 1 do vetor de dono da playlist
//prenchendo o nome do 2 dono da play
//Não retorna nada
void PrenchePlaylist2NomeDono(Playlist* playlist,char*entrada);

//Essa função recebe dois ponteiros playlist
//a função ira alocar todos os elemntos da playlist copia
//então ira atribuir todos elementos da playlist original para a playlist copia
//ira copiar as strings dos ponteiros da playlist original para a playlist copia
void CopiaPlaylist(Playlist*original,Playlist* copia);

/* Imprimir as playlist que no vetor seguindo no id indicado seja igual a 1
* entradas: ponteiro playlist e um int ID
* saída: Nenhuma*/
void ImprimiasplaylistsSeguidas(Playlist* playlist,int ID);

/*Vai atruibuir o int entrada para dentro do vetor seguindo da palylist na posição idquemsegue
* entradas: ponteiro playlist,int entrada,int idquemsegue
* saída: Nenhuma*/
void PrenchePlaylistestasendoseguida(Playlist* playlist,int entrada,int idquemsegue);


/*Vai Imprimir no arquivo a playlist
* entradas: ponteiro playliste e o FILE arquivo
* saída: Nenhuma*/
void ImprimePlaylistArquivo(Playlist* playlist,FILE*arquivo);

/*Vai Imprimir no arquivo as playlist que estão sendo seguidas
* identificadas pelo  vetor seguindo na posição int IDseguidor
* entradas: ponteiro playlist,int IDseguidor,FILE arquivo
* saída: Nenhuma*/
void ImprimiasplaylistsSeguidasArquivo(Playlist* playlist,int IDdoseguidor,FILE*arquivo);

//Vai receber um ponteiro playlist
//Vai alocar toddos ponteiros char dentro da palylist
//nao retorna nada
void AlocaTudoPlaylist(Playlist*nova);

//Vai receber um ponteiro playlist e um File arquivo
//vai ler todas a informações do file arquivo e passar para playlist
//leitura no mesmo padrão da impressão
//não retorna nada
void LerPlaylistArquivo(Playlist* playlist,FILE*arquivo);
#endif 
