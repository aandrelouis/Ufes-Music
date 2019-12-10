#ifndef ALBUM
#define ALBUM

typedef struct album Album;
typedef struct midia Midia;


//Essa funçao não recebe argumentos
//Criar um novo ponteiro album 
//Vai alocar o ponteiro novo
//e retornar esse ponteiro alocado
Album* CriaAlbum();

//Essa função recebe um ponteiro album e um ponteiro char entrada
//ela vai passar o ponteiro entrada para nome do album dentro do ponteiro album
//Não vai retornar nada por tratarmos de ponteiro
void PrencheAlbumNome(Album* album,char*entrada);

//Essa função recebe um ponteiro album e um ponteiro char entrada
//ela vai passar o ponteiro entrada para o artista dentro do ponteiro album
//Não vai retornar nada por tratarmos de ponteiro
void PrencheAlbumArtista(Album* album,char*entrada);

 
//Essa função recebe um ponteiro album e um ponteiro char entrada
//ela vai atribuir o char entrada para o  genero dentro do ponteiro album
//Não vai retornar nada por tratarmos de ponteiro
void PrencheAlbumGenero(Album* album,char*entrada);

//Essa função recebe um ponteiro album,um ponteiro char entrada e um int id
//ela vai atribuir o char entrada para os compositores dentro do ponteiro album na posição int id
//Não vai retornar nada por tratarmos de ponteiro
void PrencheAlbumcompositID(Album* album,char*entrada,int id);


//Essa função recebe um ponteiro album e um int entrada
//ela vai atribuir o int entrada para o ano do album dentro do ponteiro album
//Não vai retornar nada por tratarmos de ponteiro
void PrencheAlbumAno(Album* album,int entrada);

//Essa função recebe um ponteiro album e um int entrada
//ela vai atribuir o int entrada para a quantidade de midias dentro do ponteiro album
//Não vai retornar nada por tratarmos de ponteiro
void PrenchealbumQuantmidias(Album* album,int entrada);

//Essa função recebe um ponteiro album e um int entrada
//ela vai atribuir o int entrada para a quantidade de compositores dentro do ponteiro album
//Não vai retornar nada por tratarmos de ponteiro
void PrencheAlbumQuantComp(Album* album,int entrada);

//Essa função vai receber um ponteiro album,um ponteiro midia,e um int posição
//Ela vai adicionar uma midia no album 
//vai atribuir o ponteiro midia para album na posição do int posição
//Não retorna nada por tratarmos de ponteiro
void AdicionaMidiaNoAlbumID(Album* album,Midia*midia,int posicao);

//Essa função vai receber um ponteiro album
//Vai imprimir na tela todas as informações que contem no album
//nao retorna nada
void ImprimeAlbum(Album *a);

//Essa função vai receber um ponteiro album
//Vai imprimir o nome do album e o ID recebido
//nao retorna nada
void ImprimenomeAlbumcomId(Album* album,int id);

//Essa função recebe um ponteiro album e um int posição
//a função vai entrar nas midias do album
//a midia na posição int posição vai ser retornada
//a função retorna um ponteiro midia
Midia* RecuperaMidiadoAlbum(Album* album , int posicao);

//Essa função recebe um ponteiro album e um int ID
//Ela vai imprimir a midia que esta no vetor de midias dentro album, identificada pelo int ID
//Chamando a função imprime midia
void ImprimeMidiaNoAlbum(Album* album,int identificador);

//Essa função vai receber um ponteiro album,um int id1 e int id2
//Vai trocar as midias de lugar com ajuda de uma midia auxiliar  
//ira trocar as midias identificadas no vetor de midias pelo id1 e id2
//Não retorna nada por tratarmos de ponteiro
void TrocaPosicaoMidiaNoAlbum(Album* album,int id1,int id2);

//Essa função vai receber um ponteiro album,e um int posição
//essa função vai destruir uma midia de forma definitiva  
//Ela cria uma auxiliar midia para receber a midia ser destruída identificada pelo int posição  
//depois chama a função troca posição midia no album para trocar a posição de todas midias que vem depois da midia escolhida passando as pra frente  
//subtrai 1 da quantidade de midias daquele album para atualizar o album
//E chama a função destroi midia no endereço que esta na auxiliar  
void DestroiMidiaNoAlbum(Album* album,int posicao);

//Essa função vai receber um ponteiro album e um ponteiro char entrada
//Ela vai pecorrer todas a midias do album chamando a função pesquisa nome midia(passando a midia e o char entrada)   
//Se a função retorna positiva,entrara no if
//e a função de imprimir midia é chamada para aquela midia
void PesquisaacomNomeMidiaNoAlbum(Album* album,char* entrada);

//Essa função vai receber um ponteiro album e um ponteiro char entrada
//Ela vai pecorrer todas a midias do album chamando a função pesquisa nome artista(passando a midia e o char entrada)   
//Se a função retorna positiva,entrara no if
//e a função de imprimir midia é chamada para aquela midia
void PesquisaacomArtistaMidiaNoAlbum(Album* album,char* entrada);


//Essa função vai receber um ponteiro album e um ponteiro char entrada
//Ela vai pecorrer todas a midias do album chamando a função pesquisa nome compositor(passando a midia e o char entrada)   
//Se a função retorna positiva,entrara no if
//e a função de imprimir midia é chamada para aquela midia
void PesquisaacomCompositorMidiaNoAlbum(Album* album,char* entrada);

//Essa função vai receber um ponteiro album e um ponteiro char entrada
//Ela vai pecorrer todas a midias do album chamando a função pesquisa Genero(passando a midia e o char entrada)   
//Se a função retorna positiva,entrara no if
//e a função de imprimir midia é chamada para aquela midia
void PesquisaacomGeneroNoAlbum(Album* album,char* entrada);

//Essa função vai receber um ponteiro album e um ponteiro char entrada
//Ela vai pecorrer todas a midias do album chamando a função pesquisa Gravadora(passando a midia e o char entrada)   
//Se a função retorna positiva,entrara no if
//e a função de imprimir midia é chamada para aquela midia
void PesquisaacomGravadoraNoAlbum(Album* album,char* entrada);

//Essa função recebe um ponteiro album e um char entrada
//Ela faz uma comparação usando o strcmp entre strings
//se o nome do album for igual ao char entrada 
//Ela chama a função de imprimir album
void PesquisaOAlbumPeloNome(Album* album,char* entrada);

//Essa função não recebe nenhum argumento
//vai criar um ponteiro album
//e alocar todos os ponteiros que existirem na struct album
//retorna ponteiro album novo
Album* AlocaTudoAlbum();

//Essa função vai receber um File arquivo
//vai criar um ponteiro album
//vai alocar o ponteiro album
//vai ler todas as infomações do arquivo e passar apara album
//vai retorna o ponteiro album
Album* LeituraAlbumArquivo(FILE *arquivo);

//essa função vai receber um ponteiro album e um FILe ARQUIVO
//vai imprimir todas as informações do album no arquivo
//não retorna nada
void ImprimeAlbumArquivo(Album* album,FILE*arquivo);
#endif 



