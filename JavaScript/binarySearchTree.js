var BinarySearchTree = function(value){

  var searchTree = {};

  searchTree.left = null; // always left than
  searchTree.right = null;
  searchTree.value = value;

  _.extend(searchTree, searchTreeMethods);

  return searchTree;

};


var searchTreeMethods = {
  insert: function(value) {
      // checking if value of child is less than or greater than parent
      //push(BinarySearchTree(value))

      var traverse = function(tree){
        if(tree.value > value){
          if(!tree.left){
            tree.left = BinarySearchTree(value);
          } else {
            traverse(tree.left);
          }
        }

        if(tree.value < value){
          if(!tree.right){
            tree.right = BinarySearchTree(value);
          } else {
            traverse(tree.right);
          }
        }
      }

      traverse(this);
      console.log(this);

  },
  contains: function(target) {

    var result = false;

    var traverse = function(tree){
      if(tree.value === target){
        result = true;
      }
      if(tree.value > target && tree.left){
        traverse(tree.left);
      }
      if(tree.value < target && tree.right){
        traverse(tree.right);
      }

    }

    traverse(this);
    return result;



  },
  depthFirstLog: function(callback){

    var traverse = function(tree){
      if(tree){
        console.log('callback', tree.value);


        callback(tree.value);
        traverse(tree.left);
        traverse(tree.right);

      }


    }
    traverse(this);
  }
};

/*
 * Complexity: What is the time complexity of the above functions?
 */
