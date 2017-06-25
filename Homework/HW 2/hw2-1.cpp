#include <iostream> 
#include "RationalNumber.h"
using namespace std;

int main()
{
   RationalNumber c( 7, 3 ), d( 3, 9 ), x;

   cout << c << " + " << d << " = ";
   x = c + d; // test overloaded operators + and =
   cout << x << '\n';

   cout << c << " - " << d << " = ";
   x = c - d; // test overloaded operators - and =
   cout << x << '\n';

   cout << c << " * " << d << " = ";
   x = c * d; // test overloaded operators * and =
   cout << x << '\n';

   cout << c << " / " << d << " = ";
   x = c / d; // test overloaded operators / and =
   cout << x << '\n';

   cout << c << " is:\n";
   // test overloaded greater than operator
   cout << ( ( c > d ) ? "  > " : "  <= " );
   cout << d << " according to the overloaded > operator\n";

   // test overloaded less than operator
   cout << ( ( c < d ) ? "  < " : "  >= " );
   cout << d << " according to the overloaded < operator\n";

   // test overloaded greater than or equal to operator
   cout << ( ( c >= d ) ? "  >= " : "  < " );
   cout << d <<" according to the overloaded >= operator\n";

   // test overloaded less than or equal to operator
   cout << ( ( c <= d ) ? "  <= " : "  > " );
   cout << d << " according to the overloaded <= operator\n";
   
   // test overloaded equality operator
   cout << ( ( c == d ) ? "  == " : "  != " );
   cout << d << " according to the overloaded == operator\n";

   // test overloaded inequality operator
   cout << ( ( c != d ) ? "  != " : "  == " );
   cout << d << " according to the overloaded != operator" << endl;
} // end main

