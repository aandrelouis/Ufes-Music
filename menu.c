#include <stdio.h>
#include <stdlib.h>


void MostrarMenu(){
    //Printa na tela o Menu Principal
    //função com objetivo apenas de printar na tela
    
    printf("|-----------------------[Ufes Music]---------------------------|\n");
    printf("|--------------------------------------------------------------|\n");
    printf("|Oque deseja Fazer:                                            |\n");
    printf("|Criar(1)   Editar (2)  Ler(3)  Remover(4)  Sair dessa conta(5)|\n");
    printf("|pesquisar(6)                                                  |\n");
    printf("|Sair(9)                                                       |\n");
    printf("|Digite sua escolha:");

} 

void Criar(){
    //Printa na tela as opção de criar do menu
    //função com objetivo apenas de printar na tela
    printf("|---------||-----------------Criar---------||------------------|\n");
    printf("|--------------------------------------------------------------|\n");
    printf("|Oque deseja Criar:                                            |\n");
    printf("|Playlist(1)  album(2)                                         |\n");
    printf("|voltar(9)|\n");
    printf("|Digite sua escolha:");

}


void Sair(){
    //printa na tela a despedida do usuario
    //função com objetivo apenas de printar na tela
    printf("Volte Sempre\n");
}


void Lerobjeto(){
    //printa na tela as opções de ler
    //função com objetivo apenas de printar na tela
    printf("Qual dos itens abaixo gostaria de ler:\n");
    printf("Playlist(1) Midia(2)  album(3)  Favoritas(4)\n");
    printf("Playlist Seguidas(5)\n");
    printf("voltar(9)\n");
}

void Imprimiopcaoalbum(){
    //Printa mensagem para escolha dos albuns
    //função com objetivo apenas de printar na tela
    printf("Qual desses albuns deseja Ler:\n");

}
void Imprimiopcaoplay(){
    //Printa mensagem para escolha das Playlist
    //função com objetivo apenas de printar na tela
printf("Qual dessas Playlists deseja Ler:\n");
}


void MenuEditar(){
    //Printa na tela o MENU editar
    //função com objetivo apenas de printar na tela
    printf("Oque deseja Editar:\n");
    printf("Playlist(1) album(2) Favoritas(3) \n");
    printf("voltar(9)\n");
}

void MenuEditarAlbum(){
    //Printa na tela o MENU editar do album
    //função com objetivo apenas de printar na tela
    printf("Oque deseja Modificar:\n");
    printf("Trocar posição(1)\n");
    printf("Apagar(2)\n");
    printf("Destruir Midia(3)\n");
    
}
void MenuEditarPlaylist(){
    //Printa na tela o MENU editar da PLaylist
    //função com objetivo apenas de printar na tela
    printf("Oque deseja Modificar:\n");
    printf("Adiconar Musica(1)\n");
    printf("Trocar posição de musica(2)\n");
    printf("Apagar(3)\n");
    
    
}

void MenuSairdouser(){
    //printa na tela opçoes para sair do usuario
    //função com objetivo apenas de printar na tela
    printf("Criar outro usuario(1)\n");
    printf("Entrar como outro usuario(2)\n");
}



void MaxuserCadastrados(){
    //printa mensagem de capacidade maxima atingida
    //função com objetivo apenas de printar na tela
    printf("|-------------------------------------|\n");
    printf("|Numero Max de Usuarios já cadastrados|\n");
    
}

void NumeroMaxaalcancado(){
    //printa mensagem de capacidade maxima atingida
    //função com objetivo apenas de printar na tela
    printf("\n\n\n");
    printf("----------------------\n");
    printf("Numero Maximo Atingido\n");
    printf("----------------------\n");
}

void opcoesdePesquisa(){
    //Mostra na tela as opçoes de pesquisa para o usuario
    //função com objetivo apenas de printar na tela
    printf("Pesquisar Midia:\n");
    printf("Nome(1) Artista(2) Compositor(3)  Genêro(4)\n");
    printf("Gravadora(5) Album(6) \n");
    printf("Pesquisar Usuario(7)\n");
    printf("voltar(9)\n");

}

void EditarFavoritas(){
    //mostra natela as opções para a playlit favoritas
    //função com objetivo apenas de printar na tela
    printf("1-Adicionar Midia\n");
    printf("2-Retirar Midia\n");
}