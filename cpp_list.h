#ifndef CPP_LIST_H_INCLUDED
#define CPP_LIST_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>


/*--------------------------CLASS-----------------------------------------*/
class CListElem
{
	public: //нужно ли делать private?

		char* word_;
		int frequency_;

		CListElem* next_;
		CListElem* prev_;

	public:

		explicit CListElem( const char* word ); //!TODO константа для инициализации
		~CListElem();

		CListElem* insert_after( const char* word );
		CListElem* insert_before( const char* word );

		int pop();
		int pop_before();
		int pop_after();

};


/*--------------------------CLASS-----------------------------------------*/
class CList
{
	private:

		CListElem* fictional_;

	public:

		explicit CList();
		~CList();

		int pop_back();
		int pop_front();

		CListElem* insert_back( const char* word );
		CListElem* insert_front( const char* word );

		CListElem* fictional() const; //разобраться
};


#endif //CPP_LIST_H_INCLUDED