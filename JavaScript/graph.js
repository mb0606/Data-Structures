

var Graph = function(){


  this.node_list = {};


};

Graph.prototype.addNode = function(node){
  this.node_list[node] = {};
};

Graph.prototype.contains = function(node){
  var result = false;
  if(this.node_list[node]){
    result = true;
  }
  return result;
  // return true or false
};

Graph.prototype.removeNode = function(node){
  delete this.node_list[node];
};

Graph.prototype.hasEdge = function(fromNode, toNode){
  var result = false;
  if(this.node_list[fromNode][toNode] !== undefined){
    result = true;
  }

  return result;
};

Graph.prototype.addEdge = function(fromNode, toNode){
  this.node_list[fromNode][toNode] = toNode;
  this.node_list[toNode][fromNode] = fromNode;
};

Graph.prototype.removeEdge = function(fromNode, toNode){
  delete this.node_list[fromNode][toNode];
  delete this.node_list[toNode][fromNode];
};

Graph.prototype.forEachNode = function(cb){
  _.each(this.node_list, function(value, key){
        cb(key);
  });
};

/*
 * Complexity: What is the time complexity of the above functions?
 */


