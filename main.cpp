#include "cpp_list.h"


int main()
{
	CList test_list;

	test_list.insert_back( 1 );
	test_list.insert_back( 2 );
	test_list.insert_back( 3 );

	CListElem* current_elem = test_list.fictional_;
	for( int i = 0; i < 10; i++ )
	{
		printf( "\n-------------------------------------------\n" );
		printf( "current_elem = %p\n", current_elem );
		printf( "current_elem next = %p\n", current_elem->next_ );
		printf( "current_elem prev = %p\n", current_elem->prev_ );

		printf( "current_elem data = %d\n", current_elem->data_ );

		current_elem = current_elem->next_;
	}
	return 0;
}