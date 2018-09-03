//swal('hola mundo','amikos');

document.getElementById('generar').addEventListener("click",generar);
var texto_residuos = [];
function generar(){
    texto_residuos = [];
    var msg = document.getElementById('mensaje').value;
    var pol = document.getElementById('polinomio').value;
    var msg_binario = mensajeToBinario(msg);   /* te_de_x = parseInt(mensajeToBinario(msg) ,2);
                                            te_de_x = numToBinario(te_de_x << pol.length);*/
    //msg_binario = "101110110000110010100110111";
    var te_de_x = msg_binario;
    for(var i = 0; i < pol.length-1; i++)
        te_de_x += "0";
    
    var residuo = obtenerResiduo(te_de_x, pol);
    var nuevoPolinomio = restarPolinomios(te_de_x, residuo);
    var residuo_compro = obtenerResiduo(nuevoPolinomio, pol);
    
    alert(residuo+" residuo");
    alert("nuevo pol: "+nuevoPolinomio+" residuo: "+residuo_compro+""); 
    


    document.getElementById('log').innerHTML ="Residuos:<br>";
    for(var i = 0; i < texto_residuos.length; i++)
        document.getElementById('log').innerHTML += texto_residuos[i];
    swal("Mensaje: " + msg_binario + "\n\nT(x): "+ te_de_x + "\n\nP(x): "+ pol +"");
}
function obtenerResiduo(te_de_x, pol) {
    if(te_de_x.length < pol.length)
        return "-1";
    
    var residue = "", residue2 = "";
    var index = pol.length;

    var ceros = 0;
    for(var i = 0; i < pol.length; i++)
        residue2 += te_de_x.charAt(i);
    
   
    while(true)
    {
        if(index >= te_de_x.length) break;
        var residue = restarPolinomios(residue2, pol);
        texto_residuos.push(residue2+" / "+ pol +" = "+residue+"<br>");
        ceros = 0;
        for(var j = 0; j < residue.length && residue.charAt(j) =='0'; j++)
            ceros++;
        residue2 = "";
        for(var k = ceros; k < residue.length; k++ )
            residue2 += residue.charAt(k);
        for(var k = index; k < index + ceros; k++)
            residue2 += te_de_x.charAt(k);
        index += ceros;
    }

    return residue;
}
function residuoCero(polinomio) {
    for(var i = 0; i < polinomio.length; i++)
        if(polinomio.charAt(i) != '0')
            return false;
    return true;
}
function restarPolinomios(polinomioA, polinomioB) {
    //if(polinomioA.length != polinomioB.length) return "-";
    /*if(polinomioA.charAt(polinomioA.charAt(polinomioA.length-1)) == '0' || polinomioB.charAt(polinomioB.charAt(polinomioB.length-1)) == '0' )
        return "--";*/
    
    var resta = "";
    var T = polinomioA.length;
    var P = polinomioB.length;
    var ind = 0;
    for (var i = 0; i < T-P; i++)
        resta += polinomioA.charAt(i);
    console.log(T+" "+P);
    for(var i = T-P; i < T; i++) {
        if(polinomioA.charAt(i) == polinomioB.charAt(ind++))
            resta += "0";
        else resta += "1";
    }
    return resta;
}
function mensajeToBinario(mensaje) {
    var mensaje_binario = "";
    for(var i = 0; i < mensaje.length; i++)
        mensaje_binario += numToBinario(mensaje.charCodeAt(i));
    return mensaje_binario;
}
function numToBinario(numero) {
    var binario = "";
    numero = Number(numero);
    while(numero > 0)
    {
        binario += numero%2;
        numero = numero >> 1;
    }
    var splitString = binario.split("");
    var reverseBinario = splitString.reverse(); 
    return reverseBinario.join("");
}
