var Myo = require('myo');

Myo.connect('com.stolksdorf.myAwesomeApp', require('ws'));

Myo.on('fist', function(){
	console.log('no fistingggg');
	this.vibrate();
});