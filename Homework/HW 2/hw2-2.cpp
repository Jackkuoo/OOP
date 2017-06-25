#include <iostream> 
#include "IntegerSet.h" // IntegerSet class definition
using namespace std;

int main()
{
   IntegerSet a;
   IntegerSet b;
   IntegerSet c;
   IntegerSet d;

   cout << "Enter set A:\n";
   cin >> a;
   cout << "\nEnter set B:\n";
   cin >> b;
   c = a.unionOfSets( b );
   d = a.intersectionOfSets( b );
   cout << "\nUnion of A and B is:\n";
   cout << c;
   cout << "Intersection of A and B is:\n";
   cout << d;

   if ( a.isEqualTo( b ) )
      cout << "Set A is equal to set B\n";
   else
      cout << "Set A is not equal to set B\n";

   cout << "\nInserting 77 into set A...\n";
   a.insertElement( 77 );
   cout << "Set A is now:\n";
   cout << a;

   cout << "\nDeleting 77 from set A...\n";
   a.deleteElement( 77 );
   cout << "Set A is now:\n";
   cout << a;

   const int arraySize = 10;
   int intArray[ arraySize ] = { 25, 67, 2, 9, 99, 105, 45, -5, 100, 1 };
   IntegerSet e( intArray, arraySize );

   cout << "\nSet E is:\n";
   cout << e;

   cout << endl;
} // end main


