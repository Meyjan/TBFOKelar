#include "kalkulator.c"
#include <stdio.h>
#include <stdlib.h>

//KAMUS
    char CC;

int main(){
    printf(" __    __            __  __                  __              __                         \n");
    printf("/  |  /  |          /  |/  |                /  |            /  |                        \n");
    printf("$$ | /$$/   ______  $$ |$$ |   __  __    __ $$ |  ______   _$$ |_     ______    ______  \n");
    printf("$$ |/$$/   /      \\ $$ |$$ |  /  |/  |  /  |$$ | /      \\ / $$   |   /      \\  /      \\ \n");
    printf("$$  $$<    $$$$$$  |$$ |$$ |_/$$/ $$ |  $$ |$$ | $$$$$$  |$$$$$$/   /$$$$$$  |/$$$$$$  |\n");
    printf("$$$$$  \\   /    $$ |$$ |$$   $$<  $$ |  $$ |$$ | /    $$ |  $$ | __ $$ |  $$ |$$ |  $$/ \n");
    printf("$$ |$$  \\ /$$$$$$$ |$$ |$$$$$$  \\ $$ \\__$$ |$$ |/$$$$$$$ |  $$ |/  |$$ \\__$$ |$$ |      \n");
    printf("$$ | $$  |$$    $$ |$$ |$$ | $$  |$$    $$/ $$ |$$    $$ |  $$  $$/ $$    $$/ $$ |      \n");
    printf("$$/   $$/  $$$$$$$/ $$/ $$/   $$/  $$$$$$/  $$/  $$$$$$$/    $$$$/   $$$$$$/  $$/       \n");

    printf("------------------------Gunakanlah seperti kalkulator biasa-----------------------------\n");
    printf(">> Contoh masukkan :\n");
    printf("Penjumlahan >> 2+3 \n");
    printf("Pengurangan >> 2-3 \n");
    printf("Perkalian >> 2*3 \n");
    printf("Pembagian >> 2/3 \n");
    printf("Perpangkatan >> 2^3 \n");
    printf("Perkurungan >> 2*(3+2) \n");

    utama();
    printf("\nMau hitung lagi? (Y/N)\n");
    scanf("%s", &CC);
    while ((CC != 'N') && (CC != 'n')){
        utama();
        printf("\nMau hitung lagi? (Y/N)\n");
        scanf("%s", &CC);
    }

    printf("\n- C O N T R I B U T O R S -\n");
    printf("1. T. Andra Oksidian Tafly / 13517020\n");
    printf("2. Andrian Cedric / 13517065\n");
    printf("3. Jan Meyer Saragih / 13517131\n");
    printf(" KALKULATOR. c. 2018\n");

    return 0;
}
