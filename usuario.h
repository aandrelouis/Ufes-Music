#ifndef USUARIO
#define USUARIO

typedef struct usuario Usuario;
typedef struct playlist Playlist;
typedef struct midia Midia;


//Função nao recebe nenhum argumento
//Cria um ponteiro usuario
//aloca o ponteiro usuario
//retorna o ponteiro alocado
Usuario* CriaUsuario();

//Essa função ira receber um ponteiro usuario e um ponteiro char entrada
//ira atribuir o ponteiro char para o nome do usuairo dentro da struct usuario
//não ira retornar nada por estarmos tratando de ponteir
void PrencheUsuarionome(Usuario* usuario,char* entrada);


//Essa função ira receber um ponteiro usuario e um int entrada
//ira atribuir o int entrada para a quantidade de playlist dentro da struct usuario
//não ira retornar nada por estarmos tratando de ponteiro
void PrencheQuantPlayusuario(Usuario* usuario,int entrada);

//Essa função ira receber um ponteiro usuario e um ponteiro char entrada
//ira atribuir o ponteiro char para A senha dentro da struct usuario
//não ira retornar nada por estarmos tratando de ponteiro
void PrencheUsuarioSenha(Usuario* usuario,char* entrada);

//Essa função ira receber um ponteiro usuario e um ponteiro char entrada
//ira atribuir o ponteiro char para o Login dentro da struct usuario
//não ira retornar nada por estarmos tratando de ponteiro
void PrencheUsuarioLogin(Usuario* usuario,char* entrada);

//Essa função ira receber um ponteiro usuario e um int ID
//Na lista de Playlists na posicao igual ao int ID
//vai chamar a função de trocar de lugar essa playlist com a proxima
//e vai trocar de lugar todas a playlist que vem depois da playlist no ID sinalizado
//e depois vai subtrair 1 da quantidade de playlists daquele usaurio-atualizando o valor atual
//Não retorna nada
void ApagaPLaylistdousuario(Usuario *usuario, int identificador);

//Essa função ira receber um ponteiro usuario e dois int ,pos1 e pos2
//Essa função ira trocar de lugar a playlist dentro do usuario 
//ira trocar playlist na posição 1 com a posição 2 com ajuda de uma auxiliar 
//não ira retornar nada
void TrocaPlaylistPosUsuario(Usuario *usuario,int pos1,int pos2);

//essa função ira receber um ponteiro usuario
//ira imprimir o login dentro daquele usuario
//não retorna nada
void ImprimiLogin(Usuario*usuario);

//Essa função ira receber um ponteiro usuario,um ponteiro playlist,e um int posição
//Essa função ira atribuir o a playlist para dentro do usuario na posição do int posição
//e depois ira somar 1 na quantidade de playlists do usuario
//atualizando a quantidade e a posição da proxima
void AdicionaPlaylistnoUsuario(Usuario* usuario,Playlist* playlist,int posicao);


//Essa função irar receber um ponnteiro usuario
//Ela ira fazer uma repetição com a quantidade de playlists do usuario
//durante a repetição ira imprimir o Nome das Playlist que aquele usuario possui com um ID
//não retorna nada
void ImprimeNomedasPlaylistdousuario(Usuario* usuario);


//Essa função ira receber um ponteiro usuario, e um int posição
//ira chamar a a função de imprimir playlist para a playlist na posição indicada pelo int posição
//Nçao retorna nada
void ImprimePlayDosuario(Usuario* usuario,int posicao);

//Essa função ira receber um ponteiro usuario
//ira retornar um int que contem a quantidade de playlist do usuario
int RecuperaQuantPlay(Usuario* usuario);



//Essa função ira receber um ponteiro usuario,um ponteiro midia,um int IDdaplay
//essa função ira chamar a função de adicionar a midia na playlist 
//passando como argumentos a playlist identificada pelo IDdaplay dentro das Playlists do Usuario
//ira passar como argumento tambem a midia
void AdicionaMidiaNaPlayDoUser(Usuario* usuario,Midia*midia,int IDdaplay);


//Essa função ira receber um ponteiro usuario,int IDdaplay,int pos1 e pos2
//Ela ira chamar a função de trocar posição da midia dentro da playlist
//passando como argumento a playlist identificada pelo IDdaplay dentro do usuario
//passando tambem as duas posições das midias a serem trocadas de lugar(pos1 e pos2)
void TrocaPosiMidiaPlaylistnoUser(Usuario* usuario,int IDdaPlay,int pos1,int pos2);

//Essa função ira receber um ponteiro usuario,um int ID, e um int IDdaPlay
//ela ira chamar a função Apaga midia da playlist 
//passando como argumento a playlist identificada pelo IDdaplay dentro do usuario
//passando tambem o ID da midia a ser apagada   
void ApagaMidiaDaPlaylistdoUser(Usuario* usuario,int identificador,int IDdaPlay);

//Essa função ira receber um ponteiro usuario
//Ela irar pecorrer todas playlists do usuario 
//chamando a função Recupera Privacidade da Play que retorna a privacidade
//se a privacidade for igual a 1--Ela é publica
//então ele imprimi o nome da playlist se for publica
void ImprimeNomedasPlaylistPublicasdousuario(Usuario* usuario);


//Essa função ira receber um ponteiro usuario
//Ela irar pecorrer todas playlists do usuario 
//chamando a função Recupera Privacidade da Play que retorna a privacidade
//se a privacidade for igual a 1--Ela é publica
//então ele conta quantas playlits publicas o usuario possui
//então retorna o contador
int RecuperaQuantdePlaylistPublicasdousuario(Usuario* usuario);

//Recebe um ponteiro usuario
//retorna o ponteiro char referente ao login de dentro do usuario
char* RecuperaLogindoUser(Usuario* usuario);

//Essa função ira receber um ponteiro usuario e um int IDdaplay
//Então ela chama a função recupera a quant de donos 
//passando como argumento a playlist identificada pelo IDdaplay dentro  do usuaro
//retorna a quantidade 
int RecuperaQuantDeDonosDaPlayDoUsuario(Usuario* usuario,int IDdaplay);

//Recebe um ponteiro usuario, e um ponteiro playlist
//atribui a o ponteiro playlist para dentro do usuario,para playlist favoritas
//Não retorna nada por tratarmos de ponteiro
void AdicionaPLayFavoritasnoUsuario(Usuario* usuario,Playlist* playlist);

//Recebe um ponteiro Usuario
//ira Imprimir as playlists favoritas do usuario
//chamando a função imprimi palylist passando como argumento o ponteiro de playlists favoritas
void ImprimePlayDosuarioFavoritas(Usuario* usuario);

//Essa função ira receber  um ponteiro usuario,e um int ID
//Ela ira chamar a função de apagar midia da playlist
//passando como argumento o endereço da playlist favorita e o id da midia
void ApagaMidiaDaPlaylistFavoritosdoUser(Usuario* usuario,int identificador);

//Essa função ira receber um ponteiro usuario e um ponteiro midia
//Ela ira chamar a função de adicionar midia na playlist 
//passando como argumento o endereço da playlist favorita e o ponteiro da midia
void AdicionaMidiaNaPlayFavoritaDoUser(Usuario* usuario,Midia*midia);

/*Vai receber um ponteiro usuairo e um int ID
 * Vai chamar a função de imprimir playlists seguidas do usuario passando o usuario e i ID */
void ImprimiasplaylistsSeguidasdoUsuario(Usuario* usuario,int IDseguidor);

//Vai receber um ponteiro usuario,int IDdapaly,int entrada,int idquemsegue
//vai chamar a função de prencher playlist seguindo do usuario
//passando o usuario e os int recebidos
void PrenchePlaylistestasendoseguidaDouser(Usuario* usuario,int IDdaplay,int entrada,int idquemsegue);



//vai receber um ponteiro usuario e um File arquivo
//vai imprimir todas informações do usuario no arquivo
//nao retorna nada
void ImprimiUsuarioArquivo(Usuario* usuario,FILE* arquivo);

//Essa função vai receber um ponteiro usuario,int iD,e um File arquivo
//vai chamar a função de imprimir playlists seguidas no arquivo
//passando as playlist ,o ID,e o arquivo
//não retorna nada
void ImprimiasplaylistsSeguidasdoUsuarioArquivo(Usuario* usuario,int IDseguidor,FILE*arquivo);


//função vai receber um ponteiro usuario e o file arquivo
//vai ler todas as informações do arquivo e passar para usuario
//leitura vai ocorrer no memso padrão para IMpressão no arquivo
void LeUsuarioArquivo(Usuario* usuario,FILE* arquivo);
#endif 


