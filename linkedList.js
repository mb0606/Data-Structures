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
            while(currentNode.next || current.element  === element){
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
        return index;
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
    this.insertNode = function(index, element){
        var node = new Node(element);
        var currentNode = head;
        var previousNode;
        var currentIndex = 0;

        if(index < 0 || index >=length){
            return false;
        }
        if(index === 0){
            node.next = currentNode;
        } else {
            while(currentInex < index){
                previousNode = currentNode;
                currentNode = currentNode.next
                currentIndex++
            }
            previousNode.next = node;
            node.next = currentNode;

        };

        length++

    }


}