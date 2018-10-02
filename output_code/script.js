function startWasm()
{
    // memory will have one page (64KB)
    var memory = new WebAssembly.Memory({ initial: 1 });

    // define functions to import in WebAssembly code
    function consoleIntLog(intNumber)
    {       // console.log(intNumber);
        var paragraph = document.createElement("p");
        paragraph.innerHTML = intNumber;
        document.getElementById("output").appendChild(paragraph);
    }

    function consoleFloatLog(floatNumber)
    {
        var paragraph = document.createElement("p");
        paragraph.innerHTML = floatNumber;
        document.getElementById("output").appendChild(paragraph);
    }

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

    // instantiate a WebAssembly instance
    WebAssembly.instantiateStreaming(fetch('code.wasm'), importObject)
        .then(obj => {
            obj.instance.exports.main();
        });
}