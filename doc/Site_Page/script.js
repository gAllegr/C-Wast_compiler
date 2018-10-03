function startWasm()
{
    // memory will have one page (64KB)
    var memory = new WebAssembly.Memory({ initial: 1 });

    // integer printf function to import in WebAssembly code
    function consoleIntLog(intNumber)
    {
        var paragraph = document.createElement("p");
        paragraph.innerHTML = intNumber;
        document.getElementById("output").appendChild(paragraph);
    }

    // float printf function to import in WebAssembly code
    function consoleFloatLog(floatNumber)
    {
        var paragraph = document.createElement("p");
        paragraph.innerHTML = floatNumber;
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
            float_log: consoleFloatLog,
            str_log: consoleLogString,
        },
        js: {
            mem: memory
        }
    };

    // show div element
    document.getElementById("output").style.visibility = 'visible';
    
    // instantiate a WebAssembly instance
    WebAssembly.instantiateStreaming(fetch('code.wasm'), importObject)
        .then(obj => {
            obj.instance.exports.main();
        });
}