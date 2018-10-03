#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playervbot.h"

MATRIKS TextToState(FILE *fp) //mengisi matriks dengan isi file eksternal
{
  int i, j;
  MATRIKS state;

  for (i = 1; i <= 25; i++)
  {
    for (j = 1; j <= 10; j++)
    {
      fscanf(fp, " %s", &Elmt(state, i, j).m);
    }
  }

  return state;
}

boolean CheckWin(char x[10]) //memeriksa apakah game sekarang hasilnya CPU menang
{
  return (x[9] == 'L');
}

boolean CheckDraw(char x[10]) //memeriksa apakah game sekarang hasilnya draw
{
  return (x[9] == 'D');
}

void Menu() //kata pengantar doang ini mah
{
  printf("                           KATA PENGANTAR                        \n");
  printf("Puji syukur saya panjatkan ke hadirat Tuhan Yang Maha Esa karena \n");
  printf("hanya atas rahmat dan petunjuk-Nya saya dapat menyelesaikan tugas \n");
  printf("besar IF2220 Teori Bahasa Formal dan Otomata ini dengan baik dan benar.\n");
  printf("Tidak lupa juga saya ucapkan terima kasih kepada Ayah, Ibu, dan Adik\n");
  printf("yang telah mendukung saya dalam menjalankan studi saya ini.\n");
  printf("\n");
  printf("Sumber dari tugas besar ini berupa buku-buku yang ditambah dengan informasi\n");
  printf("yang telah saya peroleh dan terima dengan jelas dari perkuliahan yang telah\n");
  printf("saya ikuti selama 2 bulan terakhir ini. Dalam pembuatan tugas besar ini\n");
  printf("pastilah ada banyak kendala yang saya temui namun saya berhasil menghadapinya\n");
  printf("dan menyelesaikan tugas besar ini tepat waktu. Akhir kata jika ada sesuatu pada\n");
  printf("khususnya kata-kata yang tidak berkenan pada hati pembaca mohon dimaklumi.\n");
  printf("Semoga tugas besar ini dapat bermanfaat bagi pembaca.\n");
  printf("\n");
  printf("                                                    Hormat saya,\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("                                                Jeremy Arden Hartono\n");
  printf("                                                      13517101\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Selamat datang...\n");
  printf("di hati yang penuh penderitaan.\n");
  printf("\n");
}

void StateTransition(MATRIKS state, Move PrevState, Move *NextState, int i) //Pindah state dari PrevState ke NextState
{
  int j;
  boolean Found;

  j = 1;
  Found = false;
  while ((j < 25) && Found == false)
  {
    if (strcmp(Elmt(state,j,1).m,PrevState.m) == 0)
    {
      *NextState = Elmt(state, j, i+1);
      Found = true;
    }
    else
    {
      j++;
    }
  }
}

void DisplayState(char x[10]) //mencetak state sekarang
{
  int i;

  for (i = 0; i < 9; i++)
  {
    if (i == 0 || i == 3 || i == 6)
    {
      if (x[i] == 'o')
      {
        printf(" O |");
      }
      else if (x[i] == 'x')
      {
        printf(" X |");
      }
      else
      {
        printf("   |");
      }
    }
    else if (i == 2 || i == 5)
    {
      if (x[i] == 'o')
      {
        printf("| O \n");
        printf("-----------\n");
      }
      else if (x[i] == 'x')
      {
        printf("| X \n");
        printf("-----------\n");
      }
      else
      {
        printf("|   \n");
        printf("-----------\n");
      }
    }
    else if (i == 1 || i == 4 || i == 7)
    {
      if (x[i] == 'o')
      {
        printf(" O ");
      }
      else if (x[i] == 'x')
      {
        printf(" X ");
      }
      else
      {
        printf("   ");
      }
    }
    else if (i == 8)
    {
      if (x[i] == 'o')
      {
        printf("| O \n");
      }
      else if (x[i] == 'x')
      {
        printf("| X \n");
      }
      else
      {
        printf("|   \n");
      }
    }
  }

  printf("\n");
  printf("\n");
}

boolean CheckSpot(Move x, Move y) //memeriksa apakah state sebelumnya sama dengan state sekarang
{
  return (strcmp(x.m, y.m) == 0);
}
