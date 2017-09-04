Example 1: Hello world

To get started let's make a small addon which is the C++ equivalent of the following JavaScript code:

module.exports.hello = function() { return 'world'; };

Step 1
First we need to install NAN. Run `npm install nan` to install NAN.

Step 2
All Node addons are compiled using the GYP build tool via node-gyp. Create a binding.gyp file. 

Step 3
Now write some code! Create a file hello.cc.

Step 4
Compile your addon: if you don't have node-gyp installed, use sudo npm install node-gyp -g to install it. then run 
$node-gyp configure

$node-gyp build

Step 5
Create a file called hello.js add run it!
