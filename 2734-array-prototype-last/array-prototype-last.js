/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    var num = -1;
    this.forEach((ele)=>{
    num = ele
    });
    return num;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */