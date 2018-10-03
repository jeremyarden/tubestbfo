//TICTACTOE NIGGAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playervbot.c"

int main()
{
  char inp, playagain;
  FILE *statelist;
  Move CurrentMove, TempMove, NextMove, PrevMove;
  int GameInput, i, j, k, l;
  Move arrOfMove[10];
  MATRIKS state;
  boolean Play;

  Play = true;
  Menu();
  while (Play == true)
  {
    printf("MAU LO JALAN DULUAN? JAWAB Y/N : ");
    scanf(" %c", &inp);
    while (inp != 'Y' && inp != 'N' && inp != 'y' && inp != 'n')
    {
      if (inp != 'Y' && inp != 'N' && inp != 'y' && inp != 'n')
      {
        printf("SALAH, GABISA BACA YA? MASUKIN LAGI : ");
        scanf(" %c", &inp);
      }
    }
    printf("\n");

    if (inp == 'Y' || inp == 'y')
    {
      statelist = fopen("Player1st.txt", "r");
      strcpy(CurrentMove.m, "o234x6789");
    }
    else if (inp == 'N' || inp == 'n')
    {
      statelist = fopen("CPU1st.txt", "r");
      strcpy(CurrentMove.m, "1234o6789");
    }

    state = TextToState(statelist);
    fclose(statelist);

    i = 1;
    TempMove = CurrentMove;
    arrOfMove[i] = TempMove;
    DisplayState(TempMove.m);
    while (!CheckWin(TempMove.m) && !CheckDraw(TempMove.m))
    {
      i++;
      PrevMove = TempMove;
      printf("Your turn my friend : ");
      scanf("%d", &GameInput);
      printf("\n");
      while(GameInput < 1 || GameInput > 9)
      {
        printf("ULANG DONG CUMAN 1-9 : ");
        scanf("%d", &GameInput);
      }
      StateTransition(state, TempMove,  &NextMove, GameInput);
      TempMove = NextMove;
      if (CheckSpot(PrevMove, TempMove))
      {
        printf("SAMA DAH KAYAK SEBELOMNYA\n");
        printf("\n");
      }
      else
      {
        DisplayState(TempMove.m);
        arrOfMove[i] = TempMove;
      }
    }

    if (CheckWin(TempMove.m))
    {
      printf("DIH KALAH SAMA BOT DAH\n");
    }
    else if (CheckDraw(TempMove.m))
    {
      printf("DIH HOKI SERI SAMA BOT\n");
    }

    printf("STATE YANG DILEWATIN INI NIH : ");
    for (j = 1; j <= i; j++)
    {
      printf("%s ", arrOfMove[j].m);
    }
    printf("\n");

    printf("MAIN LAGI GAK? JAWABNYA PAKE Y/N LAH: ");
    scanf(" %c", &playagain);
    while (playagain != 'Y' && playagain != 'N' && playagain != 'y' && playagain != 'n')
    {
      printf("MASUKIN YANG BENER LAH : ");
      scanf(" %c", &playagain);
    }
    if (playagain == 'Y' || playagain == 'y')
    {
      Play = true;
    }
    else if (playagain == 'N' || playagain == 'n')
    {
      Play = false;
    }
  }

  return 0;
}
