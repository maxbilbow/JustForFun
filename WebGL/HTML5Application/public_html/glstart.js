/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



function glrun() {
    var F_SHADER =
            "precision mediump float;\n" +
            "void main()\n" +
            "{" +
            "    gl_FragColor = vec4(1.0,0.0,0.0,1.0);" +
            "}";

    var V_SHADER =
            "attribute vec4 aPosition;\n" +
            "void main()\n" +
            "{\n" +
            "gl_Position = aPosition;\n" +
            "}\n";

    var canvas = document.querySelector("canvas");
    canvas.width = 600 * window.devicePixelRatio;
    canvas.height = 400 * window.devicePixelRatio;
    var gl = canvas.getContext("webgl");

    var vertices = new Float32Array([
        -0.8, -0.3,
        0.7, -0.8,
        0.55, 0.75
    ]);

    var triangleBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, triangleBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, vertices, gl.STATIC_DRAW);
// ---- DRAWING ----
// Clear to black.
    gl.clearColor(0, 0, 0, 1);
    gl.clear(gl.COLOR_BUFFER_BIT);
// Bind the vertex attributes for the draw operation. We first make
// sure we're talking to the correct buffer, then we're going to
// associate that buffer with the vertex attribute from the program.
// Our buffer is an array of (x,y) points, so 2 floating point values
    // per vertex.
    var vertexShader = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vertexShader, V_SHADER);
    gl.compileShader(vertexShader);


    var fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fragmentShader, F_SHADER);
    gl.compileShader(fragmentShader);


    var program = gl.createProgram();
    gl.attachShader(program, vertexShader);
    gl.attachShader(program, fragmentShader);
    gl.linkProgram(program);
    gl.useProgram(program);

    var positionAttribute = gl.getAttribLocation(program, "aPosition");
    gl.enableVertexAttribArray(positionAttribute);
    gl.bindBuffer(gl.ARRAY_BUFFER, triangleBuffer);
    gl.vertexAttribPointer(positionAttribute, 2, gl.FLOAT, false, 0, 0);// xyxyxy 2 at  time

    gl.drawArrays(gl.TRIANGLES, 0, 3);
    var log = "\n   vertex: " + gl.getShaderInfoLog(vertexShader);
    log += "\n fragment: " + gl.getShaderInfoLog(fragmentShader);
    log += "\n  program: " + gl.getProgramInfoLog(program);
//    alert(log);
}