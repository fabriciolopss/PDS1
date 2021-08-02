#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int quantJogos, ladotab, quantJogadas, jogadax, jogaday;
    int bomba_nearby = 0;
    scanf ("%d", &quantJogos);
    for (int z = 0; z < quantJogos; z++){
        int jogo_status = 1;
        scanf("%d", &ladotab);
        char tabuleiro[ladotab][ladotab];
        for (int x = 0; x < ladotab; x++){
            for (int y = 0; y < ladotab; y++){
                scanf(" %c", &tabuleiro[x][y]);
            }
        }
        scanf ("%d ",&quantJogadas);
        for (int k = 0; k < quantJogadas; k++){
            scanf(" %d %d", &jogadax, &jogaday);
            if (tabuleiro[jogadax][jogaday] == 'b'){
                jogo_status = 0;
            }else if(tabuleiro[jogadax][jogaday] == 'x' && jogo_status != 0){
                tabuleiro[jogadax][jogaday] = 'd';
                if (tabuleiro[jogadax + 1][jogaday] == 'b' || tabuleiro[jogadax][jogaday + 1] == 'b' || tabuleiro[jogadax - 1][jogaday] == 'b'){
                    bomba_nearby = 1;
                }else if (tabuleiro[jogadax][jogaday - 1] == 'b' || tabuleiro[jogadax + 1][jogaday + 1] == 'b' || tabuleiro[jogadax + 1][jogaday - 1] == 'b'){
                    bomba_nearby = 1;
                }else if (tabuleiro[jogadax - 1][jogaday + 1] == 'b' || tabuleiro[jogadax - 1][jogaday - 1] == 'b'){
                    bomba_nearby = 1;
                }
                if (bomba_nearby == 0){
                    if (tabuleiro[jogadax + 1][jogaday] != 'b'){
                      tabuleiro[jogadax + 1][jogaday] = 'd';
                    }
                    if (tabuleiro[jogadax - 1][jogaday] != 'b'){
                      tabuleiro[jogadax - 1][jogaday] = 'd';
                    }
                    if (tabuleiro[jogadax][jogaday + 1] != 'b'){
                      tabuleiro[jogadax][jogaday + 1] = 'd';
                    }
                    if (tabuleiro[jogadax][jogaday - 1] != 'b'){
                      tabuleiro[jogadax][jogaday - 1] = 'd';
                    }
                    if (tabuleiro[jogadax + 1][jogaday + 1] != 'b'){
                      tabuleiro[jogadax + 1][jogaday + 1] = 'd';
                    }
                    if (tabuleiro[jogadax + 1][jogaday - 1] != 'b'){
                      tabuleiro[jogadax + 1][jogaday - 1] = 'd';
                    }
                    if (tabuleiro[jogadax - 1][jogaday - 1] != 'b'){
                      tabuleiro[jogadax - 1][jogaday - 1] = 'd';
                    }
                    if (tabuleiro[jogadax - 1][jogaday + 1] != 'b'){
                      tabuleiro[jogadax - 1][jogaday + 1] = 'd';
                    }
            }
            }
        }
      if (jogo_status != 0){
        for (int c = 0; c < ladotab; c++){
            for (int f = 0; f < ladotab; f++){
                if(tabuleiro[c][f] == 'x'){
                  jogo_status = 2;
                }
            }
        }
    }
      if (jogo_status == 1){
        printf("GANHOU \n");
      }else if (jogo_status == 2){
        printf("FALTOU TERMINAR \n");
      }else if (jogo_status == 0){
        printf("PERDEU \n");
      }
    }
}
