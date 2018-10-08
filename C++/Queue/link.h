
// Singly linked list node
template <typename itemType> class Link {
public:
	itemType element;      // Value for this node
	Link *next;        // Pointer to next node in list
					   // Constructors
	Link(const itemType& elemval, Link* nextval = NULL)
	{
		element = elemval;  
        next = nextval;
	}
	Link(Link* nextval = NULL) { 
		next = nextval;
	}
    ~Link(){
        delete next;
    }
};
