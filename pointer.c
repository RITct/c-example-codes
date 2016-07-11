// Edited:



/*
 *
 * This sample is just for a reference and not to used as a replacement for Homeworks, assignments etc.
 * This is a sample program intented for educational purposes only. Everyone is free to use it and make any neccessary changes to it.
 *
 * Author: SIDHIN S THOMAS
 * Property of Build-RIT
 *
 * Copyright : © 2016 Build-RIT Kottayam.
 *
 */




/*

    The program being created duplicates String library functions strlen,strcpy,strcat
    using pointers.
    comments are provided for easy understanding

*/
#include <stdio.h>

/*prototypes of functions */
int strlen(char *);
void strcat(char *, char *);
void strcpy(char *, char *);

void main(){
  /* Pointers and arrays can be used in a simillar fashion.
  The main diffrernce between then is the declaration and the way memory
  is used and reserved. */
  char *s = (char *) malloc(sizeof(char)*100);
  /* The statement dynmically allocates space to store 100 character variables
     and returnes the address of first location to s. Which is a pointer.
     essentially the above statement creates an array dynamicaly in heap. */

  /* The explicit cast of int* is needed as by default malloc returns void* */

  /* The above statement is equivalent to :
     char s[100];
  */
  char p[100] , testCpy[100];
   /* character array used to show the similarity to pointer */
  printf("Please enter the string:\nEnter string 1 :");
  scanf("%[^\n]%*c",s);
  printf("Enter string 2: ");
  scanf("%[^\n]%*c",p);
  /*
    > The above syntax is a better alternative to gets() due to its stability.
     It directs scanf to read evrything from console and store it to the given location.
     In the string format.
    > "%*c" is used because %[^\n] read only upto '\n' but not the '\n' hence
      one extra character remains in console so it needs to be removed.
      %*c is a special syntax which takes the variable for user in this case '\n'
      and consumes it. That is doesn't assign it to any variable.
  */
  printf("The length of string 1 :%d\nLength of string 2:%d\n",strlen(s),strlen(p));
  /* array variables like p are also pointers and can be handled as one. It points
     to the start of continous memory location reserved for array. */
  strcpy(testCpy,p);
  printf("The copying was successfull : %s\n",testCpy);

  strcat(p,s);
  printf("The string 1 is concatenated to string 2 :%s\n",p );
}


int strlen(char *s){
  /* Since array variables are also pointers, variables declared as pointers
     works with the same syntax used for arrays ie, s[3] is a valid reference. */
  int i ;
  for(i=0;s[i]!='\0';++i);
  return i ;
}

void strcpy(char *p, char *s){
  int i ;
  for(i=0;s[i]!='\0';++i){
    p[i] = s[i];
    /* As can be observed from the above statement, pointer operations can be done
      just like an array. */
  }
  p[i] = '\0';
  /* Explicitly giving the value of '\0' in the end is important as if its not given
  garbage value may enter in the string */
}

void strcat(char *p,char *s){
  int i , j;
  for(i=0;p[i]!='\0';++i);
  for(j=0;s[j]!='\0';++j,++i){
    p[i] = s[j];
  }
  p[i] = '\0';
}
