#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS

struct Queue {
    int number;
    char * queue;
};

void Print(struct Queue * q, int * flag)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0; i < q -> number; i++){
        if(flag[i] == 0){
            printf("#include ");
            SetConsoleTextAttribute(hConsole,  ((0 << 4) | 12));
            printf("%s%c", q -> queue + 30 * i, 10);
        }

        if(flag[i] == 1){
            printf("#define ");
            SetConsoleTextAttribute(hConsole, ((0 << 4) | 5));
            printf("%s%c", q -> queue + 30 * i, 10);
        }
        SetConsoleTextAttribute(hConsole, ((0 << 4) | 7));
    }
}

void Add(struct Queue * q, char * str, int size)
{
    strncpy(q -> queue + size * (q -> number), str, size);
    q->number++;
}

void Draw(struct Queue pr, int * num, int temp)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i = 0; i < temp; i++){
        SetConsoleTextAttribute(hConsole, ((0 << 4) | num[i]));
        printf("%s", pr.queue + i * 100);
    }

    for(int i = 0; i < temp; i++){
        printf("num[temp] = %d;\t\t\ttemp++;\n\tAdd(&pr, ", num[i]);
        SetConsoleTextAttribute(hConsole, ((0 << 4) | 12));
        printf("\"");
        for(int j = 0; j < strlen(pr.queue + i * 100); j++){
            switch(*(pr.queue + i * 100 + j)){
                case 10:
                    printf("\\n");
                    continue;
                case 9:
                    printf("\\t");
                    continue;
                case 34:
                    printf("\"");
                    continue;
                case 92:
                    printf("\\");
                    continue;
                default:
                    printf("%c", *(pr.queue + i * 100 + j));
            }
        }
        printf("\"");
        SetConsoleTextAttribute(hConsole, ((0 << 4) | 7));
        printf(", 100);\n\n\t");
    }

    printf("Draw(pr, num, temp);\n}");
}

void main()
{
    int Qsize = 20, * flag, * num, temp = 0;
    struct Queue q;

    q.queue = (char *) malloc(sizeof(char) * Qsize * 30);
    q.number = 0;
    flag = (int *) malloc(sizeof(int) * Qsize);
    num = (int *) malloc(sizeof(int) * 200);

    memset(q.queue, 0, Qsize * 30);

    Add(&q, "<stdio.h>", 30);
    Add(&q, "<string.h>", 30);
    Add(&q, "<malloc.h>", 30);
    Add(&q, "<Windows.h>", 30);
    Add(&q, "_CRT_SECURE_NO_WARNINGS", 30);

    flag[0] = 0;
    flag[1] = 0;
    flag[2] = 0;
    flag[3] = 0;
    flag[4] = 1;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Print(&q, flag);

    struct Queue pr;
    pr.queue = (char * ) malloc(sizeof(char) * 200 * 100);
    memset(pr.queue, 0, 200 * 100 * sizeof(char));
    pr.number = 0;

    num[temp] = 9;          temp++;
    Add(&pr, "\nstruct ", 100);

    num[temp] = 10;         temp++;
    Add(&pr, "Queue ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "{\n\t", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "number;\n\t", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "char ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "* queue;\n}\n\n", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "void ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "Print(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "struct ", 100);

    num[temp] = 10;         temp++;
    Add(&pr, "Queue", 100);

    num[temp] = 7;          temp++;
    Add(&pr, " * q, ", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int", 100);

    num[temp] = 7;          temp++;
    Add(&pr, " * flag)\n{\n\t", 100);

    num[temp] = 10;         temp++;
    Add(&pr, "HANDLE ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "hConsole = GetStdHandle(", 100);

    num[temp] = 5;          temp++;
    Add(&pr, "STD_OUTPUT_HANDLE", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ");\n\t", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "for ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "i = 0; i < q->number; i++) {\n\t\t", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "if ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "(flag[i] == 0) {\n\t\t\tprintf(", 100);

    num[temp] = 12;         temp++;
    Add(&pr, "\"#include \"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ");\n\t\t\tSetConsoleTextAttribute(hConsole, ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "((0 << 4) | 12));\n\t\t\tprintf(", 100);

    num[temp] = 12;         temp++;
    Add(&pr, "\"%s%c\"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ", q->queue + 30 * i, 10);\n\t\t}\n\n\t\t", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "if", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "(flag[i] == 1) {\n\t\t\tprintf(", 100);

    num[temp] = 12;         temp++;
    Add(&pr, "\"#define \"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ");\n\t\t\tSetConsoleTextAttribute(hConsole, ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "((0 << 4) | 5));\n\t\t\tprintf(", 100);

    num[temp] = 12;         temp++;
    Add(&pr, "\"%s%c\"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ", q->queue + 30 * i, 10);\n\t\t}\n\t\t", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "SetConsoleTextAttribute(hConsole, ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "((0 << 4) | 7));\n\t}\n}\n\n", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "void ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "Add(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "struct ", 100);

    num[temp] = 10;         temp++;
    Add(&pr, "Queue", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "* q, ", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "char", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "* str, ", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "size", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ")\n{\n\t", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "strncpy(q->queue + size * (q->number), str, size);\n\tq->number++;\n}\n\n", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "void ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "Draw(", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "struct ", 100);

    num[temp] = 10;           temp++;
    Add(&pr, "Queue ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "pr, ", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "* num, ", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "temp)\n{\n\t", 100);

    num[temp] = 10;           temp++;
    Add(&pr, "HANDLE ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "hConsole = GetStdHandle(", 100);

    num[temp] = 5;           temp++;
    Add(&pr, "STD_OUTPUT_HANDLE", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n\n\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "for ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "i = 0; i < temp; i++) {\n\t\tSetConsoleTextAttribute(hConsole, ((0 << 4) | num[i]));", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "\n\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"%s\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ", pr.queue + i * 100);\n\t}\n\n\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "for ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "i = 0; i < temp; i++) {\n\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"num[temp] = %d;\\t\\t\\ttemp++;\\n\\tAdd(&pr, \"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ", num[i]);\n\t\tSetConsoleTextAttribute(hConsole, ((0 << 4) | 12));", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "\n\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"\\\"\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "for ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "j = 0; j < strlen(pr.queue + i * 100); j++) {\n\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "switch ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "(*(pr.queue + i * 100 + j)) {\n\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "case ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "10:\n\t\t\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"\\\\n\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n\t\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "continue", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ";\n\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "case ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "9:\n\t\t\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"\\\\t\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n\t\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "continue", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ";\n\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "case ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "34:\n\t\t\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"\\\"\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n\t\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "continue", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ";\n\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "case ", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "92:\n\t\t\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"\\\\\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n\t\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "continue", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ";\n\t\t\t", 100);

    num[temp] = 9;           temp++;
    Add(&pr, "default", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ":\n\t\t\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"%c\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ", *(pr.queue + i * 100 + j));\n\t\t\t}\n\t\t}\n\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"\\\"\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n\t\tSetConsoleTextAttribute(hConsole, ((0 << 4) | 7));", 100);

    num[temp] = 7;           temp++;
    Add(&pr, "\n\t\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\", 100);\\n\\n\\t\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n\t}\n\n\tprintf(", 100);

    num[temp] = 12;           temp++;
    Add(&pr, "\"Draw(pr, num, temp);\\n}\"", 100);

    num[temp] = 7;           temp++;
    Add(&pr, ");\n}\n\n", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "void ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "main()\n{\n\t", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "Qsize = 20, * flag, * num, temp = 0;\n\t", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "struct ", 100);

    num[temp] = 10;         temp++;
    Add(&pr, "Queue ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "q;\n\n\tq.queue = (", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "char", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "*)malloc(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "sizeof", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "char", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ") * Qsize * 30);\n\t", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "q.number = 0;\n\tflag = (", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "*)malloc(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "sizeof", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ") * Qsize);\n\tnum = (", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "*)malloc(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "sizeof", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "int", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ") * 200);\n\n\tmemset(q.queue, 0, Qsize * 30);\n\n\tAdd(&q, ", 100);

    num[temp] = 12;         temp++;
    Add(&pr, "\"<stdio.h>\"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ", 30);\n\tAdd(&q, ", 100);

        num[temp] = 12;     temp++;
    Add(&pr, "\"<string.h>\"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ", 30);\n\tAdd(&q, ", 100);

    num[temp] = 12;         temp++;
    Add(&pr, "\"<stdio.h>\"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ", 30);\n\tAdd(&q, ", 100);

    num[temp] = 12;         temp++;
    Add(&pr, "\"<malloc.h>\"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ", 30);\n\tAdd(&q, ", 100);

    num[temp] = 12;         temp++;
    Add(&pr, "\"_CRT_SECURE_NO_WARNINGS\"", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ", 30);\n\n\tflag[0] = 0;\n\tflag[1] = 0;\n\tflag[2] = 0;\n\tflag[3] = 0;\n\tflag[4] = 1;\n\t", 100);

    num[temp] = 10;         temp++;
    Add(&pr, "\n\tHANDLE ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "hConsole = GetStdHandle(", 100);

    num[temp] = 5;          temp++;
    Add(&pr, "STD_OUTPUT_HANDLE", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ");\n\n\tPrint(&q, flag);\n\n\t", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "struct ", 100);

    num[temp] = 10;         temp++;
    Add(&pr, "Queue ", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "pr;\n\tpr.queue = (", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "char", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "*)malloc(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "sizeof", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "char", 100);

    num[temp] = 7;          temp++;
    Add(&pr, ") * 200 * 100);\n\tmemset(pr.queue, 0, 200 * 100 * ", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "sizeof", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "(", 100);

    num[temp] = 9;          temp++;
    Add(&pr, "char", 100);

    num[temp] = 7;          temp++;
    Add(&pr, "));\n\tpr.number = 0;\n\n\t", 100);

    Draw(pr, num, temp);
}
