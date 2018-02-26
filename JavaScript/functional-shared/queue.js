var Queue = function() {
  // Hey! Rewrite in the new style. Your code will wind up looking very similar,
  // but try not not reference your old code in writing the new style.
  var queue = {};
  queue.storage = {};
  queue.head = 0;
  queue.tail = 0;

  _.extend(queue,queueMethods);
  return queue;
};

var queueMethods = {
  enqueue : function(value){
    this.storage[this.tail] = value;
    this.tail++
  },
  dequeue : function(){
    var result = this.storage[this.head];
    if(this.size()){
      delete this.storage[this.head];
      this.head++;
    }
    return result;
  },
  size : function(){
    return this.tail - this.head;
  }
};
