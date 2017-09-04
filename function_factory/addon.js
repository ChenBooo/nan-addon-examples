var addon = require('./build/Release/addon.node');

var fn = addon();
console.log(fn()); // 'hello world'
