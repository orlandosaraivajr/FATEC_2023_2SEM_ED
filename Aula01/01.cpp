#include <iostream>

using namespace std;

int square( int y )
{
   return y * y;
}

int main(int argc, char *argv[]){
   int x;
   for ( x = 1; x <= 10; x++ ) {
      cout << " " << square(x) << "  ";
   }
   cout << endl;

   return 0;
}
