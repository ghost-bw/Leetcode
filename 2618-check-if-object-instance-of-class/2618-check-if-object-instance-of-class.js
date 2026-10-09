/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if (obj === null || obj === undefined || typeof classFunction !== 'function') {
        return false;
    }
    let prototype=Object(obj).__proto__;
    while(prototype!=null){
        if(prototype===classFunction.prototype){
            return true;
        }
        prototype=prototype.__proto__;
    }
    return false;

};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */