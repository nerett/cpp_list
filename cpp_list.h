#ifndef CPP_LIST_H_INCLUDED
#define CPP_LIST_H_INCLUDED


#include "config.h"
#include <stdlib.h>
#include <stdio.h>


/*--------------------------CLASS-----------------------------------------*/
class CListElem
{
	public: //нужно ли делать private?

		list_element_t data_;

		CListElem* next_;
		CListElem* prev_;

	public:

		explicit CListElem( list_element_t data = 0 ); //!TODO константа для инициализации
		~CListElem();

		CListElem* insert_after( list_element_t data = 0 );
		CListElem* insert_before( list_element_t data = 0 );

		list_element_t pop();
		list_element_t pop_before();
		list_element_t pop_after();

};


/*--------------------------CLASS-----------------------------------------*/
class CList
{
	private:

		CListElem* fictional_;

	public:

		explicit CList();
		~CList();

		list_element_t pop_back();
		list_element_t pop_front();

		CListElem* insert_back( list_element_t data = 0 );
		CListElem* insert_front( list_element_t data = 0 );

		CListElem* fictional();
};


#endif //CPP_LIST_H_INCLUDED