#include "cpp_list.h"


//#define BACK
//#define BACKWARDS


int main()
{
	CList test_list;




#ifndef BACK
	test_list.insert_front( "word1" );
	test_list.insert_front( "word2" );
	test_list.insert_front( "word3" );
#endif
#ifdef BACK
	test_list.insert_back( "word1" );
	test_list.insert_back( "word2" );
	test_list.insert_back( "word3" );
#endif

	CListElem* current_elem = test_list.fictional();
	for( int i = 0; i < 10; i++ )
	{
		printf( "\n-------------------------------------------\n" );
		printf( "current_elem = %p\n", current_elem );
		printf( "current_elem next = %p\n", current_elem->next_ );
		printf( "current_elem prev = %p\n", current_elem->prev_ );

		printf( "current_elem data = %s\n", current_elem->word_ );
		printf( "current_elem frequency = %d\n", current_elem->frequency_ );

#ifndef BACKWARDS
		current_elem = current_elem->next_;
#endif
#ifdef BACKWARDS
		current_elem = current_elem->prev_;
#endif
	}

	printf( "\nPOP:\n" );
	//test_list.pop_back();

	current_elem = test_list.fictional();
	for( int i = 0; i < 10; i++ )
	{
		printf( "\n-------------------------------------------\n" );
		printf( "current_elem = %p\n", current_elem );
		printf( "current_elem next = %p\n", current_elem->next_ );
		printf( "current_elem prev = %p\n", current_elem->prev_ );

		printf( "current_elem data = %s\n", current_elem->word_ );
		printf( "current_elem frequency = %d\n", current_elem->frequency_ );

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