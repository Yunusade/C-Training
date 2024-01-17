#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void get_sky_team_name(char* name)
{
  char* ptr = (char*) malloc(10);
  
  // Potential buffer overflow issue: the string "Home Comms SW Team" is longer than 9 characters (+1 for the null terminator)
  strcpy(ptr, "Home Comms SW Team");
  
  // This assignment only modifies the local copy of the pointer
  name = ptr; // *name = ptr;

  // Memory is freed here, but based on my understanding of the code, the pointer is still being used in the main function so i should probably be freed there
  free(ptr); 
}

int main(void)
{
  char name[10];
  char* pTeamName = NULL;    
  
  // No issues with this strcpy as "Sky UK" fits into 'name' including the null terminator
  strcpy(name, "Sky UK");     
  
  while(1)
  {
    // pTeamName is passed, but it isn't going to work due to pass-by-value semantics
    get_sky_team_name(pTeamName); // get_sky_team_name(&pTeamName);
    
    // Undefined behavior due to using uninitialized pointer pTeamName, and skyName is undeclared
    printf("%s: %s\n", skyName, pTeamName); // printf("%s: %s\n", name, pTeamName);
    
    sleep(1);
  }
  
      // free(pTeamName);
return 0;
}
