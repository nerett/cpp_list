#ifndef CPP_LIST_H_INCLUDED
#define CPP_LIST_H_INCLUDED


#include "config.h"


class CListElem
{
	private:

		list_element_t data;

		CListElem* next;
		CListElem* prev;

	private:

	public:

		explicit CListElem();
		~CListElem();

		CListElem* insert_after();
		CListElem* insert_before();

		list_element_t pop();

};

class CList
{
	private:

		int capacity;

		CListElem* head;
		CListElem* tail;

	private:

	public:

		explicit CList();
		~CList();

		list_element_t pop_back();
		list_element_t pop_front();

		CListElem* insert_back();
		CListElem* insert_front();
};


#endif //CPP_LIST_H_INCLUDED