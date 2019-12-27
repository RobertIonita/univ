const LogFolder = './Logs/',
  fs = require('fs'),
  readline = require('readline'),
  fetch = require("node-fetch");
var makePost = (msg) => {
  fetch(url, {
    headers: { 'Content-Type': 'application/json' },
    method: "POST",
    body: JSON.stringify({ message: msg })
  })
},
  url = window.location.hostname+":3000/light",
  rd;

fs.readdir(LogFolder, (dirReadErr, files) => {
  if (dirReadErr) throw dirReadErr;
  files.forEach(file => {
    if (file.includes("log")) {
      rd = readline.createInterface({
        input: fs.createReadStream(LogFolder + file),
        output: process.stdout,
        console: false
      });
      rd.on('line', function (line) {
        makePost(line.toString())
      });
    }
  });
});