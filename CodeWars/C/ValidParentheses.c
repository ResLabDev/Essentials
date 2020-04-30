/*
Write a function called that takes a string of parentheses, and determines if the order of the parentheses is valid.
The function should return true if the string is valid, and false if it's invalid.

Examples
"()"              =>  true
")(()))"          =>  false
"("               =>  false
"(())((()())())"  =>  true
Constraints
0 <= input.length <= 100

Along with opening (() and closing ()) parenthesis, input may contain any valid ASCII characters. Furthermore, the input string may be empty and/or not contain any parentheses at all.
Do not treat other forms of brackets as parentheses (e.g. [], {}, <>).
*/

#include <stdio.h>
#include <stdbool.h>

bool validParentheses(const char* strin)
{
    int par = 0;
    while (*strin)
    {
        if ( *strin == '(' ) par++;
        if ( *strin == ')' ) par--;
        if ( par < 0 ) return false;
        strin++;
    }

    return ( (!par) ? true : false );
}

int main ( void )
  {
    printf( validParentheses( "  (" ) ? "True\n" : "False\n");
    printf( validParentheses( ")test" ) ? "True\n" : "False\n");
    printf( validParentheses( "" ) ? "True\n" : "False\n");
    printf( validParentheses( "hi())(" )? "True\n" : "False\n");
    printf( validParentheses( "hi(hi)()" )? "True\n" : "False\n");

      return 0;
  }
