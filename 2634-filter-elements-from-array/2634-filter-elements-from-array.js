/**
 * Custom Filter Implementation
 * @param {Array} arr 
 * @param {Function} fn 
 * @returns {Array}
 */
function filter(arr, fn) {
  const result = [];
  for (let i = 0; i < arr.length; i++) {
    if (fn(arr[i], i)) {
      result.push(arr[i]);
    }
  }
  return result;
}

// Example usage:
// const arr = [10, 20, 30];
// const fn = (n, i) => n > 15;
// console.log(filter(arr, fn)); // [20, 30]
