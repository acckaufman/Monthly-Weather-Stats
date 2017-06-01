#pragma once
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
	struct ListItem
	{
		T value;				//The actual content of the node in the list
		struct ListItem *next;	//Pointer to the next node in the list
	};

	ListItem *head;				//Pointer to the start of the list
public:
	//#######################################################################################################
	//Default constructor which initializes head to nullptr.												#
	//No need to initialize ListItem values since no instance was created yet.								#
	//#######################################################################################################
	LinkedList()
	{
		head = nullptr;
	}

	//#######################################################################################################
	//Destructor which deletes all nodes in the list.														#
	//#######################################################################################################
	~LinkedList()
	{
		ListItem *itemPtr;		//Temporary ptr to traverse the list
		ListItem *nextItem;		//Temporary ptr to the next item to keep moving in the list

		//Initialize itemPtr to the head of the list
		itemPtr = head;

		//As long as the following loop is true (itemPtr has not reached the end of the list),
		//keep traversing the list and deleting nodes.
		while (itemPtr != nullptr)
		{
			//Save the pointer in the current item (pointing to the next item in the list), as nextItem
			//Next is the pointer to the next node defined in the structure ListItem
			nextItem = itemPtr->next;

			//Delete the node currently pointed to by itemPtr
			delete itemPtr;

			//Move itemPtr forward to the next node in the list to be deleted
			itemPtr = nextItem;
		}	//Loop continues until the end is reached, and all nodes are deleted
	}

	//#######################################################################################################
	//Append function, to append a node at the end of the list.												#
	//#######################################################################################################
	void appendItem(T val)
	{
		ListItem *newItem;		//To point to a new node
		ListItem *itemPtr;		//Temporary ptr used to traverse the list

		//Dynamically allocate a new node, storing the value in val passed to the function
		//in the new nodes "value" member variable
		newItem = new ListItem;
		newItem->value = val;
		newItem->next = nullptr;	//Set as nullptr so traversing function can find the end of the list

		//If head is still initialized to nullptr, meaning the list is empty, then make this node the first node.
		if (!head)
			head = newItem;
		else
		{
			//Begin traversing the list to append newItem at the end.
			//Start the temporary pointer at the head of the list
			itemPtr = head;

			//Traverse until the last node is found.
			while (itemPtr->next)
				itemPtr = itemPtr->next;

			//Once itemPtr->next points to nullptr, we have found the end of the list. Insert the new node here.
			itemPtr->next = newItem;	//newItem->next was already initialized to nullptr above
		}
	}

	//#######################################################################################################
	//Insert function, which assumes that values in the list are already sorted in order and adds a new		#
	//item in its appropriate place.																		#
	//#######################################################################################################
	void insertItem(T val)
	{
		ListItem *newItem;		//To point to a new node
		ListItem *itemPtr;		//Temporary ptr used to traverse the list
		ListItem *previousItem = nullptr;	//Temporary ptr to hold the location of the previous list item

		//Dynamically allocate a new node, storing the value in val passed to the function
		//in the new nodes "value" member variable
		newItem = new ListItem;
		newItem->value = val;

		//If there are no nodes in the list yet, then make this item the first one by initializing head to point to it.
		if (!head)
		{
			head = newItem;
			newItem->next = nullptr;	//Make sure this points to nullptr, since we didn't do that yet
		}
		//Otherwise, if there are already items in the list, traverse it and insert newItem in its appropriate place.
		else
		{
			//Initialize itemPtr to the head of the list
			itemPtr = head;

			//Initialize previousItem to nullptr
			previousItem = nullptr;

			//Traverse all the nodes until finding one that is greater than the value passed to the function.
			while (itemPtr != nullptr && itemPtr->value < val)
			{
				previousItem = itemPtr;		//Store the current node being looked at in previousItem...
				itemPtr = itemPtr->next;	//...and move on to the next item.
			}
			
			//When the while loop terminates, the current itemPtr is pointing to a node whose contents are greater than val.
			//If previousNode is still pointing to nullptr, this means that no items were traversed, and the new value is
			//to be the first on the list.
			if (previousItem == nullptr)
			{
				head = newItem;				//Change the head pointer to the new item we are adding
				newItem->next = itemPtr;	//Change the pointer of the new item to the value currently being pointed to by itemPtr,
											//which used to be the first item on the list.
			}
			//If some items were traversed, then insert the new node before the value that is greater (the item currently
			//pointed to by itemPtr)
			else
			{
				previousItem->next = newItem;	//Point the previous node to the new one instead of the greater value
				newItem->next = itemPtr;		//Point the new node to the greater value being held by itemPtr
			}
		}
	}

	//#######################################################################################################
	//Delete function to remove nodes from anywhere in the list.  Value of node to be deleted must be		#
	//passed as a parameter.																				#
	//#######################################################################################################
	void deleteItem(T deleteValue)
	{
		ListItem *itemPtr;		//Temporary ptr used to traverse the list
		ListItem *previousItem = nullptr;	//Temporary ptr to hold the location of the previous list item

		//The list could be empty.  In this case, head is still pointing to nullptr, and we don't want the function to do anything.
		if (!head)
			return;

		//Check the first value to see if it is equal to the value to be deleted.
		if (head->value == deleteValue)
		{
			itemPtr = head->next;		//Save the value of the second node in the list in itemPtr
			delete head;				//Clear the value stored in head
			head = itemPtr;				//Point head to what used to be the second item in the list
		}

		//Otherwise, traverse the list until we find the item to be deleted.
		else
		{
			//Initialize itemPtr to the head of the list
			itemPtr = head;

			//Traverse the list, looking for a value equal to deleteValue
			while (itemPtr != nullptr && itemPtr->value != deleteValue)
			{
				previousItem = itemPtr;		//If the values aren't equal, set the previous pointer to the current node...
				itemPtr = itemPtr->next;	//...and continue on to the next node to check it.
			}

			//Assuming a value was found that matches, itemPtr will now be pointing to that node in the list.
			if (itemPtr)
			{
				previousItem->next = itemPtr->next;			//Point the item before itemPtr to the one after itemPtr.
				delete itemPtr;								//Delete the item in itemPtr, which matched deleteValue
			}
		}
	}

	//#######################################################################################################
	//Display function, to display all the items in the list.												#
	//#######################################################################################################
	void displayList()
	{
		ListItem *itemPtr;		//Temporary ptr used to traverse the list
		itemPtr = head;			//Start the itemPtr at the beginning of the list
		int index = 0;			//*Note*: modification of LinkedList class for use with WeatherStats program

		cout << "Here are all of the items in the list:" << endl;

		//While itemPtr points to a valid item, display the contents of the node
		while (itemPtr != nullptr)
		{
			cout << "Month #" << (index + 1) << ": " << itemPtr->value << endl;		//Display the value stored in itemPtr
			itemPtr = itemPtr->next;												//Move itemPtr to the next node in the list
			index++;																//Increment the index variable for the next month
		}
	}

	//#######################################################################################################
	//Search function, to determine if a value passed as a parameter to the function was found in the list.	#
	//If the item is found, the index of the item is returned. If it is not found, the functino returns -1.	#
	//#######################################################################################################
	int searchItem(T searchValue)
	{
		int index = 0;			//Holder for the index of the value found

		ListItem *itemPtr;		//To search each value in the list

		//Initialize itemPtr to the head of the list.
		itemPtr = head;

		//As long as itemPtr is not pointing to nullptr (the end of the list has not been reached), and the value in the current
		//node is not equal to the search value, traverse the list and add 1 to index for each node skipped.
		while (itemPtr != nullptr && itemPtr->value != searchValue)
		{
			itemPtr = itemPtr->next;		//Move itemPtr to the next node in the list to check it
			index++;						//Add 1 to the index
		}

		//After the above while loop terminates, if itemPtr is pointing to nullptr, that means the value was not found.
		if (itemPtr == nullptr)
			return -1;			//Return -1, as per assignment requirements
		else
			return index;		//If the value was found, return the index of the matching value found by the function
	}

	//#######################################################################################################
	//Return function, to get an item from the list.  Needed for the WeatherStats program.					#
	//#######################################################################################################
	T getItem(int sub)
	{
		T tempItem;				//Temporary item to be returned

		ListItem *itemPtr;		//To traverse the list
		itemPtr = head;			//Start the itemPtr at the beginning of the list

		for (int index = 0; index < sub; index++)
		{
			//Traverse the number of nodes that was passed as a parameter to this getItem() function.
			itemPtr = itemPtr->next;		//Move itemPtr to the next item in the list
		}

		//itemPtr is currently pointing at the subscript number that was requested in the function call.
		//Return the item pointed to by itemPtr by dereferencing it.
		tempItem = itemPtr->value;
		return tempItem;
	}

};

