#ifndef MIDIA
#define MIDIA

typedef struct midia Midia;

Midia* CriaMidia();
void ImprimiMidiacomIDtipo(Midia* midia,int ID);
void ImprimeMidia(Midia* midia);
void ImprimeVideo(Midia *midia);
void ImprimePodCast(Midia* midia);
void ImprimeMusica(Midia* midia);
void PrencheMidiaNome(Midia* midia,char* entrada);
void PrencheMidiaArtistaID(Midia* midia,char* entrada,int id);
void PrencheMidiaGravadora(Midia* midia,char* entrada);
void PrencheMidiaTipo(Midia* midia,int tipo);
void PrencheMidiaCompositorid(Midia* midia,char* entrada,int id);
void PrencheDuracao(Midia* midia,float dura);
void PrencheGenero(Midia* midia,char* entrada);
void PreencheQuantArtistas(Midia* midia,int quant);
void PreencheQuantComp(Midia* midia,int quant);
void Imprimioopcaomidia();
void DestroiMidia(Midia* midia);
int PesquisaacomNomeMidia(Midia* midia,char* entrada);
int PesquisaacomNomeArtista(Midia* midia,char* entrada);
int PesquisaacomNomeCompositor(Midia* midia,char* entrada);
int PesquisaacomGenero(Midia* midia,char* entrada);
int PesquisaacomGravadora(Midia* midia,char* entrada);
void CopiaMidia(Midia*original,Midia*copia);
#endif

