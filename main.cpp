#include "cpp_list.h"


			#define BACK
			#define BACKWARDS

int main()
{
	CList test_list;

#ifndef BACK
	test_list.insert_front( 1 );
	test_list.insert_front( 2 );
	test_list.insert_front( 3 );
#endif
#ifdef BACK
	test_list.insert_back( 1 );
	test_list.insert_back( 2 );
	test_list.insert_back( 3 );
#endif

	CListElem* current_elem = test_list.fictional_;
	for( int i = 0; i < 10; i++ )
	{
		printf( "\n-------------------------------------------\n" );
		printf( "current_elem = %p\n", current_elem );
		printf( "current_elem next = %p\n", current_elem->next_ );
		printf( "current_elem prev = %p\n", current_elem->prev_ );

		printf( "current_elem data = %d\n", current_elem->data_ );

#ifndef BACKWARDS
		current_elem = current_elem->next_;
#endif
#ifdef BACKWARDS
		current_elem = current_elem->prev_;
#endif
	}

	printf( "\nPOP:\n" );
	//test_list.pop_back();

	current_elem = test_list.fictional_;
	for( int i = 0; i < 10; i++ )
	{
		printf( "\n-------------------------------------------\n" );
		printf( "current_elem = %p\n", current_elem );
		printf( "current_elem next = %p\n", current_elem->next_ );
		printf( "current_elem prev = %p\n", current_elem->prev_ );

		printf( "current_elem data = %d\n", current_elem->data_ );

#ifndef BACKWARDS
		current_elem = current_elem->next_;
#endif
#ifdef BACKWARDS
		current_elem = current_elem->prev_;
#endif
	}

	printf( "\n\n" );
	printf( "DTORS:\n\n" );

	return 0;
}