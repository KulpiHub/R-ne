const body = document.querySelector('body');
let red = 255;
let green = 255;
let blue = 255;
// const changeColor = (e) => {
//     console.log(e.keyCode, e.which);
//     let arrow = e.keyCode
//     if (arrow === 38){
//         red += 5;
//         green += 5;
//         blue += 5;
//         body.style.backgroundColor = `rgb(${red}, ${green}, ${blue})`;
//     }
//     else if (arrow === 40){
//         red -= 5;
//         green -= 5;
//         blue -= 5;
//         body.style.backgroundColor = `rgb(${red}, ${green}, ${blue})`;
//     }
// }
const changeColor = (e) => {
    switch (e.keyCode){
        case 38:
            document.body.style.backgroundColor = `rgb(${red < 255 ? red += 5 : red}, ${green < 255 ? green += 5 : green}, ${blue < 255 ? blue += 5 : blue})`;
            break;
        case 40: 
            document.body.style.backgroundColor = `rgb(${red > 0 ? red -= 5 : red}, ${green > 0 ? green -= 5 : green}, ${blue > 0 ? blue -= 5 : blue})`;
            break;   
    }
}
window.addEventListener('keydown', changeColor);
body.style.backgroundColor = `rgb(${red}, ${green}, ${blue})`;
