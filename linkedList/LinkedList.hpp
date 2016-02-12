/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/


//// VICTOR BERGER -- KUID 2770737
//// EECS 448 - FEB 11, 2016

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)          // constructor
{

}

template <typename T>
LinkedList<T>::~LinkedList()   // destructor
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const            // returns true if list is empty, false otherwise
{
	return(m_size == 0);
}

template <typename T> 			// returns size of list
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const  	// performs search for a value 
{
	Node<T>* temp = m_front;
	bool isFound = 0;

	while(temp != nullptr)
	{
		if(temp->getValue() == value)  // means value was found on list
			{
				isFound = 1;
				break;		// breaks out of loop since value was found
			}
		temp = temp->getNext();	
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)       // adds item to back of list
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)       // adds item to front of list
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()        // removes item from back of list
{
	bool isRemoved = 0;
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	if(m_size == 0)
		return isRemoved;		// list is empty therefore item cannot be removed

	else 	{	
			lastNode = m_front;
			secondintoLast = m_front;
			for (int i = 0; i < m_size - 1; i++)
				{
					secondintoLast = lastNode;
					lastNode = lastNode->getNext();
				}
			delete lastNode;
			secondintoLast->setNext(nullptr);
			isRemoved = 1;
			m_size--;  // decrease size of list by 1
		}

	return(isRemoved);	
	
}	

template <typename T>
bool LinkedList<T>::removeFront()		// removes item from front of list
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
