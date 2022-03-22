#include "cpp_list.h"
#include "config.h"
#include <string.h>


/*--------------------------FUNCTION----------------------------------------- */
CListElem::CListElem( const char* word ):
	word_ ( NULL ),
	frequency_( 0 ),

	next_ ( NULL ),
	prev_ ( NULL )
{
	assert( word );

	word_ = strdup( word );
}


/*--------------------------FUNCTION----------------------------------------- */
CListElem::~CListElem()
{

}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CListElem::insert_after( const char* word )
{
	CListElem* new_elem = new CListElem( word );

	new_elem->next_ = next_;
	new_elem->prev_ = this;

	next_->prev_ = new_elem;
	next_ = new_elem;

	return new_elem;
}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CListElem::insert_before( const char* word )
{
	CListElem* new_elem = new CListElem( word );

	new_elem->next_ = this;
	new_elem->prev_ = prev_;

	prev_->next_ = new_elem;
	prev_ = new_elem;

	return new_elem;
}


/*--------------------------FUNCTION----------------------------------------- */
int CListElem::pop()
{
	prev_->next_ = next_;
	next_->prev_ = prev_;

	int return_value = this->frequency_;
	free( word_ );
	delete this;

	return return_value;
}

/*--------------------------FUNCTION----------------------------------------- */
int CListElem::pop_before()
{
	return prev_->pop();
}


/*--------------------------FUNCTION----------------------------------------- */
int CListElem::pop_after()
{
	return next_->pop();
}


/*--------------------------FUNCTION----------------------------------------- */
CList::CList():
	fictional_ ( new CListElem( FICTIONAL_ELEM_DATA ) )
{
	fictional_->next_ = fictional_;
	fictional_->prev_ = fictional_;
}


/*--------------------------FUNCTION----------------------------------------- */
CList::~CList()
{
	CListElem* current_elem = fictional_->next_;
	CListElem* delete_elem = NULL;

	while( current_elem && ( current_elem->next_ != current_elem ) ) //первая проверка создана на случай изменения связей извне
	{
		delete_elem = current_elem; //можно без этой строки, но так понятнее
		current_elem = current_elem->next_;

		delete_elem->pop();
	}

	delete fictional_;
}


/*--------------------------FUNCTION----------------------------------------- */
int CList::pop_back()
{
	return fictional_->prev_->pop();
}


/*--------------------------FUNCTION----------------------------------------- */
int CList::pop_front()
{
	return fictional_->next_->pop();
}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CList::insert_back( const char* word )
{
	fictional_->insert_before( word ); //не логическая ошибка, т.к. tail и head указывают на фиктивный элемент
	return fictional_->prev_;
}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CList::insert_front( const char* word )
{
	fictional_->insert_after( word );
	return fictional_->next_;
}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CList::fictional() const
{
	return fictional_;
}