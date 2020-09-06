#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    // printf("Text: %s\n", text);
    int letters = 0;
    int words = 1;
    int sentences = 0;
    float index = 0;
    // Count each character except spaces
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        int ascii = (int) text[i];
        // Count each sentence divided by periods, Exclamation and Question Mark.
        if (ascii == 33 || ascii == 46 || ascii == 63)
        {
            sentences++;
        }
        // Count words divided by spaces
        if (ascii == 32)
        {
            words++;
        }
        // Count each character only Small and Caps, no space and special characters
        if ((ascii > 64 && ascii < 91) || (ascii > 96 && ascii < 123))
        {
            letters++;
        }
    }
    // Calculating the Coleman-Liau index
    float avg_letters = 100 * (float) letters / (float) words;
    float avg_sentences = 100 * (float) sentences / (float) words;
    index = (0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8;
    if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
    // printf("%i letter(s)\n", letters);
    // printf("%i letter(s)\n", words);
    // printf("%i sentence(s)\n", sentences);
}
