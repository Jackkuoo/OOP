#include <iostream>
#include <string>
#include "HugeInteger.h"
using namespace std;
int main()
{
    HugeInteger n1( 7654321 ); // HugeInteger object n1
    // HugeInteger object n2
    HugeInteger n2( "100000000000000" ); HugeInteger n4( 5 ); 
    // HugeInteger object n4
    HugeInteger n5; // HugeInteger object n5
    // outputs the sum of n1 and n2
    n5 = n1.add( n2 );
    n1.output();
    cout << " + ";
    n2.output();
    cout << " = ";
    n5.output();
    cout << endl;
    // assigns the difference of n2 and n4 to n5 then outputs n5
    n5 = n2.subtract( n4 );
    n2.output();
    cout<< " - ";
    n4.output();
    cout << " = ";
    n5.output();
    cout << endl;
    HugeInteger n3(n5); // call copy constructor
    // outputs the sum of n3 and n4
    n2 = n3.add ( n4 );
    n3.output();
    cout<< " + ";
    n4.output();
    cout << " = ";
    n2.output();
    cout << endl;
    // checks for equality between n2 and n2
    if ( n2.isEqualTo( n2 ) == true )
    {
        n2.output();
        cout << " is equal to ";
        n2.output();
        cout << endl;
    } // end if
    // checks for inequality between n1 and n2
    if ( n1.isNotEqualTo( n2 ) == true )
    {
    n1.output();
    cout << " is not equal to ";
    n2.output();
    cout << endl;
    } // end if
    // tests for smaller number between n4 and n2
    if ( n4.isLessThan( n2 ) == true )
    {
        n4.output();
        cout << " is less than ";
        n2.output();
        cout << endl;
    } // end if*/
    return 0;
}
