var read = require("./build/Release/addon.node");

var some_obj = {
    a: 1,
    b: "B",
    c: [1,2,3],
    d: {e: "hello", f:true},
}

read.readObject(some_obj);
