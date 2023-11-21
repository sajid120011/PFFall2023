#include <stdio.h>
#include <string.h>
void reverseWord(char* start, char* end) 
{
    while (start < end) 
	{
        *start ^= *end;
        *end ^= *start;
        *start ^= *end;
        start++;
        end--;
    }
}
void reverseWords(char* sentence) 
{
    char* start = sentence;
    char* end = sentence;
    while (*end != '\0') 
	{
        while (*end != ' ' && *end != '\0') 
		{
            end++;
        }
        reverseWord(start, end - 1);
        if (*end != '\0') 
		{
            start = ++end;
        }
    }
}
int main() 
{
    printf("Enter a sentence: ");
    char sentence[100];
    fgets(sentence, sizeof(sentence), stdin);
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') 
	{
        sentence[len - 1] = '\0';
    }
    reverseWords(sentence);
    printf("Modified sentence: %s\n", sentence);
    return 0;
}
