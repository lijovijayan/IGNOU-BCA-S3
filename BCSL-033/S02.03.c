/*
Write a program in ‘C’ language to accept a paragraph of text as input. Make a
list of words and the number of occurrences of each word in the paragraph as
output. As part of the processing, an array and structure should be created
wherein each structure consists of two fields, namely, one for storing the word
and the other for storing the number of occurrences of that word.
*/

#include <stdio.h>
#include <string.h>

// Define the maximum number of words
#define MAX_WORDS 100

int main()
{
    // Declare the word array and the frequency array
    char words[MAX_WORDS][100];
    int frequencies[MAX_WORDS];

    // Initialize the frequency array to 0
    for (int i = 0; i < MAX_WORDS; i++)
    {
        frequencies[i] = 0;
    }

    // Prompt the user to enter a paragraph of text
    printf("Enter a paragraph of text:\n");
    char c = getchar();

    // Read the paragraph of text character by character
    int word_count = 0;
    int word_length = 0;
    while (c != '\n')
    {
        // Check if the current character is a space or a punctuation mark
        if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?')
        {
            // End the current word
            words[word_count][word_length] = '\0';
            word_count++;
            word_length = 0;
        }
        else
        {
            // Add the current character to the current word
            words[word_count][word_length] = c;
            word_length++;
        }

        // Read the next character
        c = getchar();
    }

    // End the last word
    words[word_count][word_length] = '\0';
    word_count++;

    // Make a list of words and their frequencies
    int num_unique_words = 0;
    for (int i = 0; i < word_count; i++)
    {
        // Check if the current word is already in the list
        int found = 0;
        for (int j = 0; j < num_unique_words; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                found = 1;
                break;
            }
        }

        // If the current word is not in the list, add it to the list
        if (!found)
        {
            strcpy(words[num_unique_words], words[i]);
            num_unique_words++;
        }
    }

    // Count the frequencies of the words in
    // the paragraph
    for (int i = 0; i < num_unique_words; i++)
    {
        for (int j = 0; j < word_count; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                frequencies[i]++;
            }
        }
    }

    // Print the list of words and their frequencies
    printf("List of words and their frequencies:\n");
    for (int i = 0; i < num_unique_words; i++)
    {
        printf("%s: %d\n", words[i], frequencies[i]);
    }

    return 0;
}
