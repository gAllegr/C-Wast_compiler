function startWasm()
{
    // memory will have one page (64KB)
    var memory = new WebAssembly.Memory({ initial: 1 });

    var number = document.getElementById("number");
    var glob_number = new WebAssembly.Global({value:'i32', mutable:true}, number.value);

    var text = document.getElementById("text");
    var glob_text = new WebAssembly.Global({value:'i32', mutable:true}, 0);
    var text_length = text.textLength;
    var buffer = new ArrayBuffer(text_length);
    var data = new Uint8Array(buffer);

    for(var i=0; i<text_length;i=i+1)
    {
        data[i] = text.value.charCodeAt(i);
        memory[i] = data[i];
    }

    console.log(data);
    console.log(memory);

    // integer printf function to import in WebAssembly code
    function consoleIntLog(intNumber)
    {
        var paragraph = document.createElement("p");
        paragraph.innerHTML = intNumber;
        document.getElementById("output").appendChild(paragraph);
    }

    // string printf function to import in WebAssembly code
    function consoleLogString(offset, length) 
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
            int_log: consoleIntLog,
            str_log: consoleLogString,
        },
        js: {
            mem: memory,
            glob_number,
            glob_text,
            text_length,
        },
    };

    // show div element
    document.getElementById("output").style.visibility = 'visible';
    
    console.log("start");
    // instantiate a WebAssembly instance
    WebAssembly.instantiateStreaming(fetch('input_output.wasm'), importObject)
        .then(obj => {
            obj.instance.exports.main();
        });

    console.log("end");
}