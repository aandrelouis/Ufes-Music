#ifndef MIDIA
#define MIDIA

typedef struct midia Midia;

/* Alocar o Ponteiro Struct Midia
* entradas: nenhum
* saída: ponteiro midia alocado
* pré-condição: nenhum
* pos-condicao: nenhuma */
Midia* CriaMidia();


/* Chamar a função de imprimir a midia de acordo com o tipo
* entradas: ponteiro midia,int ID
* saída: nenhuma*/
void ImprimiMidiacomIDtipo(Midia* midia,int ID);

//Essa função  recebe um ponteiro Midia
//E de acordo com o tipo da midia definido na hora de criar
//ela chama a função de imprimir aquele tipo de midia
//1-musica//2-PODcast//3-Video  
//Não retorna nada
void ImprimeMidia(Midia* midia);

//Recebe um ponteiro Midia
//se o ponteiro dor diferente NULL
//imprimi o tipo de midia
//imprimi o nome todas as caracteristicas da midia Video
//se o ponteiro for null printa que nao existe
void ImprimeVideo(Midia *midia);

//Recebe um ponteiro Midia
//se o ponteiro dor diferente NULL
//imprimi o tipo de midia
//imprimi o nome todas as caracteristicas da midia Podcast
//se o ponteiro for null printa que nao existe
void ImprimePodCast(Midia* midia);

//Recebe um ponteiro Midia
//se o ponteiro dor diferente NULL
//imprimi o tipo de midia
//imprimi o nome todas as caracteristicas da midia Musica
//se o ponteiro for null printa que nao existe
void ImprimeMusica(Midia* midia);

 //Recebe um ponteiro midia e um ponteiro char entrada
 //a função ira atribuir a entrada char para o nome da midia dentro da struct
 //e não retorna nada por estarmos tratando de ponteiro
void PrencheMidiaNome(Midia* midia,char* entrada);

//Recebe um ponteiro midia,ponteiro char entrada e um int id
//a função ira atribuir a entrada char para o artista dentro da struct na posicao do id
//e não retorna nada por estarmos tratando de ponteiro
void PrencheMidiaArtistaID(Midia* midia,char* entrada,int id);


//Recebe um ponteiro midia,ponteiro char entrada 
//a função ira atribuir a entrada char para a gravadora dentro da struct
//e não retorna nada por estarmos tratando de ponteiro
void PrencheMidiaGravadora(Midia* midia,char* entrada);

//Recebe um ponteiro midia e um int tipo
//a função ira atribuir o tipo int para dentro da struct(tipo)
//e não retorna nada por estarmos tratando de ponteiro
void PrencheMidiaTipo(Midia* midia,int tipo);


//Recebe um ponteiro midia,ponteiro char entrada e um int id
//a função ira atribuir a entrada char para o compositor dentro da struct na posicao do id
//e não retorna nada por estarmos tratando de ponteiro
void PrencheMidiaCompositorid(Midia* midia,char* entrada,int id);

//Recebe um ponteiro midia e um  float dura
//a função ira atribuir o tipo float para dentro da struct(duracao)
//e não retorna nada por estarmos tratando de ponteiro
void PrencheDuracao(Midia* midia,float dura);

//Recebe um ponteiro midia,ponteiro char entrada 
//a função ira atribuir a entrada char para o genero dentro da struct
//e não retorna nada por estarmos tratando de ponteiro 
void PrencheGenero(Midia* midia,char* entrada);

//Recebe um ponteiro midia e um int quant
//a função ira atribuir o tipo int para dentro da struct(quantartistas)
//e não retorna nada por estarmos tratando de ponteiro
void PreencheQuantArtistas(Midia* midia,int quant);

//Recebe um ponteiro midia e um int quant
//a função ira atribuir o tipo int para dentro da struct(quantcompositores)
//e não retorna nada por estarmos tratando de ponteiro
void PreencheQuantComp(Midia* midia,int quant);

//printa na tela as opções possiveis de midia para criar
//A função não recebe nada e nem retorna nada
void Imprimioopcaomidia();

//essa função recebe um ponteiro midia
//da free no endereço de memoria dentro do ponteiro midia
//vai liberando todos os ponteiros alocados dentro da struct
//e no final libera o ponteiro da struct midia    
void DestroiMidia(Midia* midia);

//essa função recebe ponteiro midia e um ponteiro char
//faz uma comparação entre os strings no ponteiro nome e entrada
//se forem iguais a função retorna 1
//se forem diferentes a função retorna zero    
int PesquisaacomNomeMidia(Midia* midia,char* entrada);

//essa função recebe ponteiro midia e um ponteiro char entrada
//faz uma comparação entre as strings no ponteiro char artista e entrada     
//a comparação é feita com todos artistas que possuem na midia
//se 1 for igual a função retorna 1
//se forem diferentes a função retorna zero      
int PesquisaacomNomeArtista(Midia* midia,char* entrada);

//essa função recebe ponteiro midia e um ponteiro char entrada
//faz uma comparação entre as strings no ponteiro char nomeCompositor e entrada 
//a comparação é feita com todos os Compositores que possuem na midia
//se 1 for igual a função retorna 1
//se forem diferentes a função retorna zero 
int PesquisaacomNomeCompositor(Midia* midia,char* entrada);

//essa função recebe ponteiro midia e um ponteiro char entrada
//faz uma comparação entre as strings no ponteiro char genero e entrada
//se for igual a função retorna 1   
//se forem diferentes a função retorna zero
int PesquisaacomGenero(Midia* midia,char* entrada);

//essa função recebe ponteiro midia e um ponteiro char entrada
//faz uma comparação entre as strings no ponteiro char gravadora e entrada
//se for igual a função retorna 1   
//se forem diferentes a função retorna zero
int PesquisaacomGravadora(Midia* midia,char* entrada);

//essa função recebe dois ponteiros Midia
//aloca todos o ponteiros da struct midia copia
//atriubui todos os valores da midia original para a copia
//e depois usando a função strcpy
//copia todos as strings da struct midia original para a midia copia  
void CopiaMidia(Midia*original,Midia*copia);


/* Alocar Todos os ponteiros da struct midia
* entradas: nenhum
* saída: strcut midia toda alocada */
Midia* AlocaTudoMidia();


/* Faz a leitura em um arquivo de uma midia
* entradas: o arquivo
* saída: Midia criada */
Midia* LeituraMidiarquivo(FILE *arquivo);

/* Imprime no arquivo a Midia do tipo Musica
* entradas: ponteiro midia e o arquivo
* saída: nenhuma */
void ImprimeMusicaArquivo(Midia* midia,FILE*arquivo);

/* Imprime no arquivo a Midia do tipo Podcast
* entradas: ponteiro midia e o arquivo
* saída: nenhuma */
void ImprimePodcastArquivo(Midia* midia,FILE*arquivo);

/* Imprime no arquivo a Midia do tipo Video
* entradas: ponteiro midia e o arquivo
* saída: nenhuma */
void ImprimeVideoArquivo(Midia* midia,FILE*arquivo);

/* Chama a função de imprimir a midia de acordo com o tipo
* entradas: ponteiro midia e o arquivo
* saída: nenhuma */
void ImprimeMidiaArquivo(Midia* midia,FILE*arquivo);
#endif

