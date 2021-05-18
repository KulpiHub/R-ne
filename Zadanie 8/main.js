const div = document.querySelector('div');
const square = document.createElement('div');

let divX = 150;
let divY = 50;
let drawingActive = false;
let insetDivX;
let insetDivY;

square.style.left = divX + "px";
square.style.top = divY + "px";
document.body.appendChild(square);

square.addEventListener('mousedown', (e) => {
    square.style.backgroundColor = "gray";
    drawingActive = !drawingActive;
    insetDivX = e.offsetX;
    insetDivY = e.offsetY;
})

square.addEventListener('mousemove', (e) => {
    if (drawingActive){
    divX = e.clientX - insetDivX;
    divY = e.clientY - insetDivY;
    square.style.left = divX + "px";
    square.style.top = divY + "px";
    }
})

square.addEventListener('mouseup', () => {
    square.style.backgroundColor = "black";
    drawingActive = !drawingActive;

})