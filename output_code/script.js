function startWasm()
{
	// memory will have one page (64KB)
	var memory = new WebAssembly.Memory({ initial: 1 });



	// string printf function to import in WebAssembly code
	function consoleStringLog(offset, length)
	{
		var bytes = new Uint8Array(memory.buffer, offset, length);
		var string = new TextDecoder('utf8').decode(bytes);
		var paragraph = document.createElement("p");
		paragraph.innerHTML = string;
		document.getElementById("output").appendChild(paragraph);
	}

	// define importObject, to be passed to WebAssembly
	var importObject = {
		console: {

			str_log: consoleStringLog,
		},
		js: {
			mem: memory
		}
	};

	// show div element
	document.getElementById("output").style.visibility = 'visible';

	// instantiate a WebAssembly instance
	WebAssembly.instantiateStreaming(fetch('error4.wasm'), importObject)
		.then(obj => {
			obj.instance.exports.main();
		});
}