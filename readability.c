//
//  ReadAbility
//  A tool that determines the corresponding US school grade for a text. 
//


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    int count_letter = 0;
    int count_space = 1; //começa em 1 para converter o numero de espaços em numero de palavras
    int count_sentence = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]) != 0) //função retorna qualquer valor numerico para quando o caracter e letrer
        {
            count_letter = count_letter + 1;
        }
        if (isblank(text[i]) != 0)
        {
            count_space = count_space + 1;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') //diferentes maneiras de terminar uma frase
        {
            count_sentence = count_sentence + 1;
        }
    }
    

    float L = (float) count_letter * 100 / count_space; //colocando aqui os valores com (float) para nao truncar na divisao
    float S = (float) count_sentence * 100 / count_space;
    
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index); //arredondando, mas nao sei pq rs
    

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}