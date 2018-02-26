var Tree = function(value){
  var newTree = {};

  newTree.parent = null;
  newTree.value = value;
  newTree.children = [];  // fix me

  _.extend(newTree,treeMethods);

  return newTree;
};





var treeMethods = {};

treeMethods.addChild = function(value){
  var newNode = Tree(value)
  newNode.parent = this;
  this.children.push(newNode);

};

treeMethods.contains = function(target){
  var result = false;

  var traverse = function(node){
    if(node.value === target){
      result = true;
    }

    for(var i = 0; i < node.children.length; i++){
      traverse(node.children[i]);
    }
  };


  traverse(this);
  return result;
};
treeMethods.removeFromParent = function(value){

  var currentNode = this.getNode(value);
  var parentNode = this.getParentNode(currentNode);

   for( var i = 0; i < currentNode.length; i++){
     currentNode.children[i].parent = parentNode;
     parentNode.children.push(currentNode.children[i]);
   }
   delete currentNode;


}

treeMethods.getNode = function(value){
  var currentNode;
  var traverse = function(node){
       if(node.value === value){
         currentNode = node;
       }
       for(var i = 0; i < node.children.length; i++){
            traverse(node.children[i]);
       }

    };
    traverse(this);
    return currentNode;
};

treeMethods.getParentNode = function(currentNode){
    var parentNode;
    var traverse = function(node){
       if(currentNode.parent === node){
           parentNode = node;
       }
       for(var i = 0; i < node.children.length; i++){
            traverse(node.children[i]);
       }

    };
    traverse(this);
    return parentNode;

};







/*
 * Complexity: What is the time complexity of the above functions?
 */
