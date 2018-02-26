var DoubleLinkedList = function(){
  var list = {};
  list.head = null;
  list.tail = null;

  list.addToTail = function(value){
    // check if head exists or is null
    if(this.head === null){
      //if it doesn't we addd the node to the head;
      this.head = Node(value);
      // set tail equal to head since there is only one item
      this.tail = this.head;
    } else {
      // set value of next on current tail to the new NODE
      this.tail.next = Node(value);
      //this.tail.next is new node. Need to set previous prop
      this.tail.next.previous = this.tail;
      // set tail to the new NODE we created in next to be the tail
      this.tail = this.tail.next;
    }

  };

  list.removeFromTail = function(){
    var tail = this.tail.value;
    if(this.tail === null){
      throw error("you dont have a list");
    } else if (this.tail.previous === null){
      this.tail = null;
      this.head = null
    } else {
      this.tail = this.tail.previous;
      this.tail.next = null;
    }
    return tail;
  };

  list.addToHead = function(value){
    // find current head
    this.head.previous = Node(value);
    this.head.previous.next = this.head;
    this.head = this.head.previous;



  };

  list.removeHead = function(){
    // set current next of current head
    var head = this.head.value;
    if(this.head === null){
      throw error("You don't have a list")
    } else if (this.head.next === null){
      this.head = null;
      this.tail = null;
    } else {

      this.head = this.head.next;
      this.head.previous = null;
    }
    return head;

  };

  list.contains = function(target){
    var result = false;
    if(this.head.value === target){
      result = true;
    }
    for(var node = this.head.next ; node ; node = node.next){
      if(node.value === target) result = true;
    }

    return result;
  };

  return list;
};

var Node = function(value){
  var node = {};

  node.value = value;
  node.next = null;
  node.previous = null;

  return node;
};
