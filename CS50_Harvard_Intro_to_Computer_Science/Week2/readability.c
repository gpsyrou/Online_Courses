# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>
# include <math.h>

// Function that counts the number of letters in a string
// Note: Count only uppercase/lowercase a-z, A-Z
int count_letters(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            count += 1;
        }
    }
    return count;
}


// Function that counts the number of words (words end with a space)
int count_words(string s)
{
    int count = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isspace(s[i]))
        {
            count += 1;
        }
    }
    return count;
}

// Function that counts the number of sentences in a text
int count_sentences(string s)
{
    int count = 0;
    for (int i = 1; i < strlen(s); i++)
    {
        if (s[i] == '!' || s[i] == '.' || s[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}

// Function to compute the averages L and S
// L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text
float compute_average(value, words)
{
    float avg = (value * 100) / (float) words;

    return avg;
}


int main(void)
{
    // Get input string from the user
    string text = get_string("Text:");

    // Return the number of the characters from the input string
    int character_cnt = count_letters(text);
    int word_cnt = count_words(text);
    int sentences_cnt = count_sentences(text);
    //printf("%d letter(s)\n%d word(s)\n%d sentence(s)", character_cnt, word_cnt, sentences_cnt);

    // Retrieve the averages
    float L = compute_average(character_cnt, word_cnt);
    float S = compute_average(sentences_cnt, word_cnt);

    // Creating the Coleman-Liau index to find the Grade
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}