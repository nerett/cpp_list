#include "cpp_list.h"


/*--------------------------FUNCTION----------------------------------------- */
CListElem::CListElem( list_element_t data ):
	data_ ( data ),

	next_ ( NULL ),
	prev_ ( NULL )
{

}


/*--------------------------FUNCTION----------------------------------------- */
CListElem::~CListElem()
{

}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CListElem::insert_after( list_element_t data )
{
	CListElem* new_elem = new CListElem( data );
	new_elem->next_ = this->next_;
	new_elem->prev_ = this;
	this->next_ = new_elem;

	return new_elem;
}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CListElem::insert_before( list_element_t data )
{
	CListElem* new_elem = new CListElem( data );
	new_elem->next_ = this;
	new_elem->prev_ = this->prev_;
	this->prev_ = new_elem;

	return new_elem;
}


/*--------------------------FUNCTION----------------------------------------- */
list_element_t CListElem::pop()
{
	this->prev_->next_ = this->next_;
	this->next_->prev_ = this->prev_;

	list_element_t return_value = this->data_;
	delete this; //?

	return return_value;
}

/*--------------------------FUNCTION----------------------------------------- */
list_element_t CListElem::pop_before()
{
	return prev_->pop();
}


/*--------------------------FUNCTION----------------------------------------- */
list_element_t CListElem::pop_after()
{
	return next_->pop();
}


/*--------------------------FUNCTION----------------------------------------- */
CList::CList():
	capacity_ ( 0 ),

	head_ ( NULL ),
	tail_ ( NULL )
{
	CListElem* fictional_elem = new CListElem( FICTIONAL_ELEM_DATA );
	head_ = fictional_elem; //фиктивный элемент
	tail_ = fictional_elem;

	capacity_++;

	fictional_elem->next_ = fictional_elem;
	fictional_elem->prev_ = fictional_elem;
}


/*--------------------------FUNCTION----------------------------------------- */
CList::~CList()
{
	CListElem* current_elem = head_;
	CListElem* delete_elem = NULL;

	while( capacity_ )
	{
		if( current_elem )
		{
			delete_elem = current_elem;
			delete delete_elem;
			current_elem = current_elem->next_;
		}
	}

	delete head_;
}


/*--------------------------FUNCTION----------------------------------------- */
list_element_t CList::pop_back()
{
	capacity_--; //костыль
	return tail_->prev_->pop();
}


/*--------------------------FUNCTION----------------------------------------- */
list_element_t CList::pop_front()
{
	capacity_--; //костыль
	return head_->next_->pop();
}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CList::insert_back( list_element_t data )
{
	tail_->insert_before( data ); //не логическая ошибка, т.к. tail и head указывают на фиктивный элемент
	return tail_->prev_;
	capacity_++; //костыль
}


/*--------------------------FUNCTION----------------------------------------- */
CListElem* CList::insert_front( list_element_t data )
{
	head_->insert_after( data );
	return head_->next_;
	capacity_++; //костыль
}
