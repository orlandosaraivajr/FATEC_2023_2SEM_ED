#include <stdio.h>

int square( int y )
{
   return y * y;
}

int main( void )
{
   int x;
   for ( x = 1; x <= 10; x++ ) {
      printf( "%d  ", square( x ) );
   }
   printf( "\n" );

   return 0;
}
