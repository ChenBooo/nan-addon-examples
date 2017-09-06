const createObject = require('./build/Release/addon.node');

var obj = createObject();
console.log(obj);		//>>MyObject {}
console.log(obj.say());		//>>hello world

