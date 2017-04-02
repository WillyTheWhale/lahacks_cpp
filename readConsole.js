var exec = require('child_process').execFile;

var fun =function(){
   console.log("fun() start");
   exec('GestureMyo.exe', function(err, data) {  
        console.log(err)
        console.log(data.toString());                       
    });  
}
fun();


/*
var stdin = process.openStdin();

stdin.addListener("data", function(d) {
    // note:  d is an object, and when converted to a string it will
    // end with a linefeed.  so we (rather crudely) account for that  
    // with toString() and then trim() 
    console.log("you entered: [" + 
        d.toString().trim() + "]");
  });*/