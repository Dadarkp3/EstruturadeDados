// Nome completo do aluno:Daiane Mascarenhas Lauro da Silva
// Data da última modificação:
#include <curses.h>
#include <stdlib.h>	/* malloc */
#include <string.h>	/* memcpy */
#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "snake.h"

#define KEY_ESC	27
#define SCORES_FN	".snakescores"

// Variáveis globais
int CHAR_TYPE  = 0;
int show_comprimento = 0;
int insere_unico = 0;
struct segmento *cabeca;

/*
 pick up a collision between a cabeca and a food
 */
#define collision(a, b)\
(abs(a->x - b.x)<=1 && abs(a->y - b.y)<1)

/*
 calculate position within array from x y position
 */
#define arraypos(y, x)\
(61 * (y) + (x))

/*
 draw a coordchar object
 */
void draw_coordchar(struct segmento* m)
{
    #ifdef LOG
        move(17,1);
        printw("(%d,%d)",m->y, m->x);
    #endif
    move(m->y, m->x);
    addch(m->c);
}

void printCorpo(struct segmento* m){
    int x = 1, y = 16;
    move(y, x);
    printw("Intestino: ");
    struct segmento* temp;
    temp=m->next;
    x+=10;
    move(y, x);
    while(temp!=NULL){
        move(y, x++);
        addch(temp->c);
        temp=temp->next;
        
    }
    if(show_comprimento){
        int x = 1, y = 17;
        move(y, x);
        printw("Comprimento: %d",contaSegmentos(m));
    }
    move(y, x);
}

#define draw_food(xyc)\
{\
    move(xyc.y, xyc.x);\
    addch(xyc.c);\
}

static char background[] =
{
    "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
};


static char foreground[] =
{
    "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "|                                                          |\n"
    "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
};

int slowdown=0;
/*
 function declarations
 */
//coordchar boundries(coordchar xy);
int randint(int min, int max);
char randchar();
void display_scores();
void save_score(int score, char * name);

/*
 save score
 */
void save_score(int score, char * name)
{
    FILE* scores = fopen(SCORES_FN,"a+b");
    fseek(scores, feof(scores), SEEK_SET);
    fprintf(scores,"%s - %i points.\n",name,score);
    fclose(scores);
}

/*
 Show scores
 */

void display_scores()
{
    char * bytes;
    size_t sz;
    FILE* scores = fopen(SCORES_FN,"r");
    if(scores != NULL){
        fseek(scores, 0L, SEEK_END);
        bytes = malloc(sz = ftell(scores));
        rewind(scores);
        fread(bytes, sz, 1, scores);
        fclose(scores);
        
        printf("Previous scores:\n%s\n", bytes);
    }
    else
        printf("No previous scores\n");
}

/*
 random integer
 */
int randint(int min, int max)
{
    int n = rand()%(max-min-1)+min+1;
    if(n%2) 
        return n-1;
    else
        return n;
}

char randchar()
{
    // imprime os caracteres visíveis
    if(CHAR_TYPE == 0) 
        return (char)('!'+rand()%93);
    else
    // imprime dígitos
    if(CHAR_TYPE == 1) 
        return (char)('0'+rand()%10);
    else
    // imprime letras minusculas
    if(CHAR_TYPE == 2) 
        return (char)('a'+rand()%26);
    else
    // imprime letras maiusculas
    if(CHAR_TYPE == 3) 
        return (char)('A'+rand()%26);
    else
        return '=';
}

void keep_going(){
    if(cabeca->c == '>')
            cabeca->x+=1;
    if(cabeca->c == '<')
            cabeca->x-=1;
    if(cabeca->c == '^')
            cabeca->y--;
    if(cabeca->c == 'v')
            cabeca->y++;
}

int main(int argc, char *argv[])
{
    srand(time(0));
    if (argc > 1) {
        if(!strcmp(argv[1], "-scores")){
            display_scores();
            exit(EXIT_SUCCESS);
        }
        
        /* initialize variables */
        int i;
        int keypress;
        int lastkey=0;
        int lastlastkey=0;
        int pellets=0;
        int lives=3;
        int slowdown=0;
        int counter=3;
        int score=0;
        insere_unico = 0;
        show_comprimento = 0;
        struct segmento cabecaold;
        
        /* set up */
        initscr();
        refresh();
        
        noecho();
        raw();
        cbreak();
        
        timeout(0);
        
        keypad(stdscr, TRUE);
        
        for(;;
            /* stuff to do each session */
            refresh(),
            lastkey = 0,	/* set keypress */
            lastlastkey = 0,
            counter = 3		/* timer */
            )
        {
            cabeca = malloc(sizeof(struct segmento));
            cabeca->y = 7;
            cabeca->x = 30;
            cabeca->c = 'o';
            cabeca->next = NULL; 
            
            struct segmento food = {randint(2,58),randint(1,13), randchar()};
            
            /* main gameplay loop */
            for(;;
                /* stuff to do each loop */
                clear(),			/* clear screen */
                move(0,0),
                printw("%s", foreground),	/* draw foreground */
                cabecaold.x = cabeca->x,
                cabecaold.y = cabeca->y,
                slowdown = !slowdown,		/* toggle slowdown */
                keypress = getch()		/* current key */
                )
            {
                
                if (keypress >  0)
                    lastkey = keypress;
                
                switch(lastkey)
                {
                    case 'c':
                    case 'C':
                        show_comprimento = 20;
                        keep_going();
                        break;

                    case 'd':
                    case 'D':
                        CHAR_TYPE = 1;
                        keep_going();
                        break;

                    case 'a':
                    case 'A':
                        CHAR_TYPE = 2;
                        keep_going();
                        break;

                    case 'q':
                    case 'Q':
                        CHAR_TYPE = 3;
                        keep_going();
                        break;

                    case 'g':
                    case 'G':
                        CHAR_TYPE = 0;
                        keep_going();
                        break;

                    case 'u':
                    case 'U':
                        if(insere_unico)
                            insere_unico = 0;
                        else
                            insere_unico = 1;
                        keep_going();
                        break;

                    case KEY_RIGHT:
                        if(cabeca->c != '<'){
                            cabeca->c = '>';
                            if(slowdown)
                                cabeca->x+=2;
                        }else
                            if(slowdown)
                                cabeca->x-=2;
                        break;
                    case KEY_LEFT:
                        if(cabeca->c != '>'){
                            cabeca->c = '<';
                            if(slowdown)
                                cabeca->x-=2;
                        }else
                            if(slowdown)
                                cabeca->x+=2;
                        break;
                    case KEY_DOWN:
                        if(cabeca->c != '^'){
                            cabeca->c = 'v';
                            if(slowdown)
                                cabeca->y++;
                        }else
                            if(slowdown)
                                cabeca->y--;
                        break;
                    case KEY_UP:
                        if(cabeca->c != 'v'){
                            cabeca->c = '^';
                            if(slowdown)
                                cabeca->y--;
                        }else
                            if(slowdown)
                                cabeca->y++;
                        break;
                    case KEY_ESC:
                        save_score(score, argv[1]);
                        refresh();
                        endwin();
                        exit(EXIT_SUCCESS);
                    //default:
                      //                              cabeca->c = 'o';
                        break;
                }
                
                //keeping the cabeca within the borders
                if ( background[ arraypos(cabeca->y,cabeca->x) ] != ' ' ){
                    cabeca->x = cabecaold.x;
                    cabeca->y = cabecaold.y;
                    if(lastkey != lastlastkey){
                        lastkey = lastlastkey;
                    }
                    lastkey = lastlastkey;
                    popPrimeiroSegmento(cabeca);
                    score--;
                }
                else
                    lastlastkey = lastkey;
                
                if(show_comprimento>0){
                    show_comprimento--;
                }

                draw_coordchar(cabeca);
                
                draw_food(food);
                
                //Score
                move( 15,1 );
                printw("Pontuacao: %i",score);
                printCorpo(cabeca);
                
                if(collision(cabeca, food)){
                    score++;
                    food.y = randint(1,13);
                    food.x = randint(2,58);
                    if(insere_unico){
                        struct segmento* s = searchSegmento(cabeca,food.c);
                        if(s==NULL)
                            insereSegmentoFinal(cabeca,food.c);
                    }
                    else
                        insereSegmentoFinal(cabeca,food.c);
                    food.c = randchar();
                }
                
                //Game over. man, game over
                if (score<0)
                {
                    save_score(score, argv[1]);
                    score = 0;
                    move(11,10);
                    printw( "Game over... salvando o placar. " );
                    refresh();
                    sleep(2);
                    break;
                }
                refresh();
                usleep(100000);
            }
        }
        refresh();
        endwin();
    }
    else {
        printf("Uso: snake [login] ou snake -scores\n");
        exit(EXIT_SUCCESS);
    }
}
