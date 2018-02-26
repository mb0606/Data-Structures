var HashTable = function(){
  this._limit = 8;
  this._bucketMax = 1;
  this._tupleCounter = 0;
  this._storageMax= this._limit * this._bucketMax;
  this._storage = LimitedArray(this._limit);

};

HashTable.prototype.insert = function(k, v){
  // this generates the index for the given key
  var i = getIndexBelowMaxForKey(k, this._limit);

  var bucket = this._storage.get(i) ;

  if(!bucket){
    bucket = [];
    this._storage.set(i, bucket);

  };

  var alreadyExists = false;

  for(var pos = 0;  pos < bucket.length;  pos++){
    var positionInBucket = bucket[pos];

    if( k === positionInBucket[0]){
      positionInBucket[1] = v;
      alreadyExists = true;
    }
  }

  if(!alreadyExists){
    bucket.push([k,v]);
    // somecount of tup
    this._tupleCounter++;

  }

  this.checkStorageDouble();
};



HashTable.prototype.retrieve = function(k){
  var i = getIndexBelowMaxForKey(k, this._limit);
  var bucket = this._storage.get(i)

  var doesExist = false;
  if(!bucket){
    return null;
  }
  for(var pos = 0; pos < bucket.length; pos++){
    var positionInBucket = bucket[pos]
    if( k === positionInBucket[0]){
      doesExist = true;
      return positionInBucket[1];


    }
  }
  if(!doesExist){
    return null;
  }

};

HashTable.prototype.remove = function(k){
  var i = getIndexBelowMaxForKey(k, this._limit);
  var bucket = this._storage.get(i)

  if(!bucket){
    return null;
  }
   for(var pos = 0; pos < bucket.length; pos++){
    var positionInBucket = bucket[pos]
    if( k === positionInBucket[0]){
      console.log("This is inside the IF",positionInBucket)


      bucket.splice(pos, 1);
      this._tupleCounter--;





    }

  }
  this.checkStorageHalf();

};

HashTable.prototype.checkStorageDouble = function(){
 console.log("Check Tuple CotupleCounter",this._tupleCounter)

  if(this._tupleCounter >= this._storageMax * .75){
    this._limit *= 2;

     console.log("Limit is doubled",this._limit)
  }


};

HashTable.prototype.checkStorageHalf = function(){
  console.log("Check Storage half",this._tupleCounter)


  if(this._tupleCounter <= this._storageMax * .25){
  console.log("Check Storage half: IN IF",this._tupleCounter)
    this._limit /= 2;

  console.log("After divide:",this._limit)

  }


};

HashTable.prototype.reHash = function(currentStorage){
  var tempStorage =[];
    this.each = function(callback){
    for(var i = 0; i < storage.length; i++){
      for(var j = 0; j < )
    }
  };


};



/*
 * Complexity: What is the time complexity of the above functions?
 */
