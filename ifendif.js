#!/usr/local/bin/node
const FileSystem = require('fs');

for(var i = 0; i < process.argv.length; i++){
	var filename = process.argv[i];
	var file = FileSystem.readFileSync(filename,'utf8');
	var lines = file.split('\n');
	var ifs = 0;
	var endifs = 0;
	var depth = 0;
	var matching_lines = [];
	var depth_at_line = [];
	for(var j = 0; j < lines.length; j++){
		line = lines[j].match(/^#if/);
		if(line != null){
			ifs++;
			depth++;
			matching_lines.push(j.toString());
			depth_at_line.push(depth.toString());
		} else{
			line = lines[j].match(/^#endif/);
			if(line != null){
				endifs++;
				depth--;
				matching_lines.push(j.toString());
				depth_at_line.push(depth.toString());
			}
		}
	}
	console.log("File: %s", filename);
	for(var k = 0; k < matching_lines.length; k++){
		console.log("%d: %d %s", matching_lines[k], depth_at_line[k], lines[matching_lines[k]]);
	}
}

