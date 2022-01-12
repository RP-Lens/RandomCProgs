#include <stdio.h>
#include <stdlib.h>

void printMain(FILE *out);
void printCalc(FILE *out);

int MAX;

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid arguments (1)\n");
    }
    MAX = atoi(argv[1]);

    char *path = "../calculator/calc.c";
    FILE *calc = fopen(path, "w");
    if (calc == NULL)
    {
        printf("Could not open path for writing\n");
        return 1;
    }

    printMain(calc);
}

void printMain(FILE *out)
{
    //includes
    fprintf(out, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <ctype.h>\n#include <conio.h>\n\n");

    //prototype
    fprintf(out, "int doCalc(int i, int j, char op);");

    //start main
    fprintf(out, "int main(int argc, char *argv[])\n{\n");

    //check inputs
    fprintf(out, "    if (argc != 4)\n    {\n");
    fprintf(out, "        printf(\"lol are u stoopid\\n Usage: ./calc number operator number (use x for multiplying)\\nError 1: incorrect numbers entered\\n\");\n");
    fprintf(out, "        return 1;\n    }\n");
    fprintf(out, "    for (int i = 0, n = strlen(argv[1]); i < n; i++)\n    {\n");
    fprintf(out, "        if (!isdigit(argv[1][i]))\n        {\n");            
    fprintf(out, "            printf(\"lol are u stoopid\\nUsage: ./calc number operator number\\nError 2: non-digit numbers entered\\n\");\n");
    fprintf(out, "            return 2;\n        }\n    }\n");
    fprintf(out, "    for (int i = 0, n = strlen(argv[3]); i < n; i++)\n    {\n");
    fprintf(out, "        if (!isdigit(argv[3][i]))\n        {\n");
    fprintf(out, "            printf(\"lol are u stoopid\\nUsage: ./calc number operator number\\nError 2: non-digit numbers entered\\n\");\n");
    fprintf(out, "            return 2;\n        }\n    }\n");
    fprintf(out, "     char op = argv[2][0];");
    fprintf(out, "    if (op != '+' && op != '-' && op != 'x' && op != '/')\n    {\n");
    fprintf(out, "        printf(\"lol are u stoopid\\nUsage: ./calc number operator number\\nError 3: incorrect operator entered\\n\");\n");
    fprintf(out, "        return 4;\n    }\n");

    //Setting variables and calling doCalc
    fprintf(out, "    int i = atoi(argv[1]);\n");
    fprintf(out, "    int j = atoi(argv[3]);\n");
    fprintf(out, "    int result = doCalc(i, j, op);\n");
    fprintf(out, "    if (result == -__INT32_MAX__)    {\n");
    fprintf(out, "        printf(\"Answer out of range, u divided by 0 like idiot, or %%i\\n\", -__INT32_MAX__);\n");
    fprintf(out, "        return 5;\n    }\n");
    fprintf(out, "    else\n    {\n");
    fprintf(out, "        printf(\"%%i\", result);\n");
    fprintf(out, "        return 0;\n    }\n");   
    fprintf(out, "    getch();\n}\n");

    printCalc(out);
}

void printCalc(FILE *out)
{
    fprintf(out, "int doCalc(int i, int j, char op)\n{\n");

    //if +
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            fprintf(out, "    if (i == %i && j == %i && op == '+')\n", i, j);
            fprintf(out, "        return %i;\n", i + j);
        }
    }
    //if -
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            fprintf(out, "    if (i == %i && j == %i && op == '-')\n", i, j);
            fprintf(out, "        return %i;\n", i - j);
        }
    }
    //if x
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            fprintf(out, "    if (i == %i && j == %i && op == 'x')\n", i, j);
            fprintf(out, "        return %i;\n", i * j);
        }
    }
    //if /
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            fprintf(out, "    if (i == %i && j == %i && op == '/')\n", i, j);
            fprintf(out, "        return %i;\n", i / j);
        }
    }
    //Closing if
    fprintf(out, "    else\n        return -__INT32_MAX__;\n}");
}