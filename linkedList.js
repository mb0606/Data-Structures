// This is the implementation of a linked list 

function LinkedList(){
    var length = 0;
    var head = null;

    var Node = function(element){
        this.element = element;
        this.next = null;
    }

    this.size = function(){
        return length;
    }

    this.head = function(){
        return head;
    }

    this.printList = function(){
        var currentNode = head;
        var currentIndex = 0;
        while(currentIndex <= length){
            console.log(currentIndex , "--",currentNode.element)
            currentNode = currentNode.next;
            currentIndex++
        }
    }

    this.add = function(element){
        var node = new Node(element);
        if(head === null){
            head = node;
        } else {
            var currentNode = head;
            while(currentNode.next){
                currentNode = currentNode.next;
            }
            currentNode.next = node;
            length++;
        }

    }

    this.remove = function(element){
        var currentNode = head;
        var previousNode;
        
        if(currentNode.element === element){
            head = currentNode.next
            length--;
        } else {
            while(currentNode.next || currentNode.element  === element){
                previousNode = currentNode;
                currentNode = currentNode.next;
            }
            previousNode.next = currentNode.next;
            length--;
        }
        
    }

    this.isEmpty = function(){
        return length === 0;
    }


    this.indexOf = function(element){
        var currentNode = head;
        var index = -1;
        while(currentNode.next){
            index++
            if(currentNode.element === element){
                return index;
            }
            currentNode = currentNode.next;
        }
        return -1;
    }
    this.elementAt = function(index){
        var currentNode = head;
        var count = 0;
        if(index < 0 || index >=length){
            return null;
        }
        while(count < index){
            currentNode = currentNode.next;
            count++
        }
        return currentNode.element;
    }
    this.insertAt = function(index, element){
        var node = new Node(element);
        var currentNode = head;
        var previousNode;
        var currentIndex = 0;

        if(index < 0 || index >= length){
            return false;
        }
        if(index === 0){
            node.next = currentNode;
            head = node;
        } else {
            while(currentIndex < index){
                previousNode = currentNode;
                currentNode = currentNode.next
                currentIndex++
            }
            previousNode.next = node;
            node.next = currentNode;

        };
        length++
        return node.element;
    }
    this.removeAt = function(index){
        var currentNode = head;
        var previousNode;
        var currentIndex = 0;

        if(index < 0 || index >= length){
            return false;
        }
        if(index === 0 ){
            head = currentNode.next;
        } else {
            while(currentIndex < index){
                previousNode = currentNode;
                currentNode = currentNode.next;
                currentIndex++
            }
            previousNode.next = currentNode.next;
        }
        length--;
        return currentNode.element;
    }


}

var myList = new LinkedList();
myList.add("0");
myList.add("1");
myList.add("2");
myList.add("3");
myList.add("4");
console.log(myList.size());
myList.removeAt(1);
console.log(myList.size());
myList.insertAt(0,"beginning")
myList.remove();
console.log(myList.elementAt(0));
myList.insertAt(2,"4");
myList.printList()
console.log("Size before added",myList.size());
myList.add("end");
console.log("Size after added",myList.size());
myList.printList()
console.log(myList.indexOf("new endding"));
console.log(myList.elementAt(4));




