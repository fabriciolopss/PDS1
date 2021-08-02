#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct emojis{
    char emoji[6];
};


int emojis_check(char* string){
    int reacao = 0;
    int subemoji = 0, subemoji1 = 0, subemoji2 = 0;
    char *contain;
    struct emojis c[21];
    strcpy(c[0].emoji, ">:)");
    strcpy(c[1].emoji, ":-)");
    strcpy(c[2].emoji, ">:(");
    strcpy(c[3].emoji, ":-(");
    strcpy(c[4].emoji, ":D");
    strcpy(c[5].emoji, ":P");
    strcpy(c[6].emoji, "XD");
    strcpy(c[7].emoji, "<3");
    strcpy(c[8].emoji, ":*(");
    strcpy(c[9].emoji, ":'(");
    strcpy(c[10].emoji, "^-^");
    strcpy(c[11].emoji, ":3");
    strcpy(c[12].emoji,":S");
    strcpy(c[13].emoji, ":\\");
    strcpy(c[14].emoji, ":(");
    strcpy(c[15].emoji, ":)");
    strcpy(c[16].emoji, "<:-");
    strcpy(c[17].emoji, "O_o");
    strcpy(c[18].emoji, "\\o/");
    strcpy(c[19].emoji, ";)");
    strcpy(c[20].emoji, ":*");
    for (int x = 0; x <= 20; x++){
        contain = strstr(string,c[x].emoji);
        if (contain){
            if (x ==  1 || x == 4 || x ==  6 || x ==  7){
                reacao += 1;
            }else if (x == 10 || x == 11 || x == 18 || x == 19){
                reacao += 1;
            }else if (x == 3 || x == 5  || x == 9 || x == 12){
                reacao -= 1;
            }else if (x == 13 || x == 16 || x == 17){
                reacao -= 1;
            }else if (x == 8){
                subemoji = 1;
                reacao -= 1;
            }else if (x == 20 && subemoji != 1){
                reacao += 1;
            }else if (x == 0){
                subemoji1 = 1;
                reacao -= 1;
            }else if (x == 15 && subemoji1 == 0){
                reacao += 1;
            }else if (x == 2){
                reacao -= 1;
                subemoji2 = 1;
            }else if (x == 14 && subemoji2 == 0){
                reacao -= 1;
            }
        }
    }
    return reacao;


}

int main(){
    char main_string[600];
    fgets(main_string, 50, stdin);
    int resultado = 0;
    resultado = emojis_check(main_string);
    if (resultado > 0){
        printf("Positiva \n");
    }else if (resultado < 0){
        printf("Negativa \n");
    }else if (resultado == 0){
        printf("Neutra \n");
    }
}
