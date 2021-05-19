const body = document.querySelector('body');

let red = 255;
let green = 255;
let blue = 255;

const changeColor = (e) => {
    console.log(e.keyCode, e.which);
    let arrow = e.keyCode
    if (arrow === 38){
        red += 5;
        green += 5;
        blue += 5;
        body.style.backgroundColor = `rgb(${red}, ${green}, ${blue})`;
    }
    else if (arrow === 40){
        red -= 5;
        green -= 5;
        blue -= 5;
        body.style.backgroundColor = `rgb(${red}, ${green}, ${blue})`;
    }
}

window.addEventListener('keydown', changeColor);
body.style.backgroundColor = `rgb(${red}, ${green}, ${blue})`;
