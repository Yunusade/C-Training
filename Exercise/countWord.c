#include <stdio.h>
#include <string.h>

int countWord(const char* phrase, const char* word) {
  int count = 0;
  int phraseLen = strlen(phrase);
  int wordLen = strlen(word);

  for (int i = 0; i <= phraseLen - wordLen; i++) {
    int j;
    for (j = 0; j < wordLen; j++) {
      if (phrase[i + j] != word[j]) {
        break;
      }
    }
    if (j == wordLen) {
      count++;
    }
  }

  return count;
}

int main() {
  const char* phrase = "I'm Programming. Programming is not fun!";
  const char* word = "Programming";

  int wordCount = countWord(phrase, word);

  printf("The word '%s' appears %d times in the phrase.\n", word, wordCount);

  return 0;
}
