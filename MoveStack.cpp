// Filename MoveStack.cpp
// Author: Nathan Carlson
// Date: 04/29/24
// Assignment Number: 4
// Instructor: Xiaomin Li
//
// MoveStack A regular stack that stores instances of the Move structure. 
// A Move records the coordinates of the 'x' or 'o' token placed on the game board. 
// All past moves are stored here. The stack is required in order to be able to undo moves.


#include <cassert>
#include <iostream>
using namespace std;

#include "MoveStack.h"


MoveStack::MoveStack() { 
    topOfStack = nullptr;
}


MoveStack::~MoveStack() {
    while (getSize() != 0)
    {
        Node* temp = topOfStack->next;
        delete topOfStack;
        topOfStack = temp;
    }
}

//****************************************************
// Member function getsize returns a count of the    *
// number of elements on the stack.                  *
//****************************************************
int MoveStack::getSize() {
    if (topOfStack == nullptr)
    {
        return 0;
    }
    else
    {
        Node* cursor = topOfStack;
        int size = 0;
        while (cursor != nullptr)
        {
            size++;
            cursor = cursor->next;
        }
        return size;
    }
 }

//****************************************************
// Member function top returns the value at the top  *
// of the stack (does not remove it).                *
//****************************************************
Move MoveStack::top() {
    return topOfStack->move;
}
//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
// move: the Move item to be pushed               *
//*************************************************
void MoveStack::push(Move move) {
    Node* newMove = new Node;
    newMove->move = move;
    newMove->next = nullptr;

    if (getSize() == 0)
    {
        topOfStack = newMove;
    }
    else
    {
        newMove->next = topOfStack;
        topOfStack = newMove;
    }
};
//****************************************************
// Member function pop removes the value at the top  *
// of the stack, but returns nothing.                *
//****************************************************
void MoveStack::pop() {
    if (getSize() == 0)
    {
        cout << "No moves have been made." << endl;
        return;
    }

    Node* temp = topOfStack->next;
    delete topOfStack;
    topOfStack = temp;
}
