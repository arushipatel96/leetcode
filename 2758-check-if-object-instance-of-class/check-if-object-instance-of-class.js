/**
* @param {Object} obj
* @param {Function} classFunction
* @param {boolean}
*/
var checkIfInstanceOf = function(obj, classFunction) {
    if (obj === null || obj ===undefined || typeof classFunction !== 'function'){
        return false;
         }
         let currPrototype = Object.getPrototypeOf(Object(obj));
         while (currPrototype !== null){
            if (currPrototype === classFunction.prototype){
                return true;
             }
              currPrototype = Object.getPrototypeOf(currPrototype);
             }
             return false;
};

