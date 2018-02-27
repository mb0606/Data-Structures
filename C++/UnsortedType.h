class UnsortedType
{
    public: 
        UnsortedType();
        void makeEmpty();
        bool isFull() const;
        int getLength() const;
        void insertItem(int item);
        void deleteItem(int item);
        void show();
    private:
        int length;
        int info[100];
        void resize();


};