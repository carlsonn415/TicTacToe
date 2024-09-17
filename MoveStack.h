

#ifndef MOVESTACK_H
#define MOVESTACK_H

struct Move{
    int x;
    int y;
    Move(){ x=0; y=0; }
    Move(int a, int b) { x=a, y=b;}
};

class MoveStack{
private:
    // define variables used to create stack 
    struct Node
    {
        Move move;
        Node* next;
    };
    Node* topOfStack;
public:
    MoveStack();
    ~MoveStack();
    int getSize();
    Move top();
    void push(Move move);
    void pop();
};

#endif //MOVESTACK_H



