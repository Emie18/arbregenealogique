let time = 0;
let alpha = 1;
let x = 100;
let y = 150;
function draw() {

    var canvas = document.getElementById("bulle");

    time += 0.5;
    if (time == 40) {
        time = 0;
    }
    if (time == 20) {
        alpha = 0;
    } else {
        alpha += 0.01;
    }
    let a = entierAleatoire(10, 180);
    let b = entierAleatoire(0, 300);
    var ctx = canvas.getContext("2d");
    requestAnimationFrame(draw);
    ctx.clearRect(0, 0, 30000, 10000);

    ctx.beginPath();
    ctx.fillStyle = "rgba(122, 122, 184, 0.692)"
    ctx.strokeStyle = "white";
    ctx.arc(150, 150, 148, 0, 2 * Math.PI);
    ctx.fill();
    ctx.clip();
    ctx.stroke();



    console.log(time, alpha);

    ctx.beginPath();
    ctx.strokeStyle = "rgba(100,0,200," + alpha + ")";
    ctx.font = '30px Comic Sans MS';
    if ((time == 20)) {
        x = entierAleatoire(10, 250);
        y = entierAleatoire(0, 300);
    }
    ctx.strokeText('Inconnue', x, y);


} draw();
function entierAleatoire(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}
function propre() {

    var canvas = document.getElementById("propre");

    var ctx = canvas.getContext("2d");
    ctx.beginPath();
    
    ctx.strokeStyle = "rgba(205, 235, 215, 1)";
    ctx.arc(150, 150, 147, 0, 2 * Math.PI);
    ctx.lineWidth = 7;
 
    ctx.stroke();



} propre();