
var exec = require('cordova/exec');

exports.runPikkartRecognition = function (arg0, success, error) {
    exec(success, error, 'PikkartCordova', 'StartRecognition', [arg0]);
};
