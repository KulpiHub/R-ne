const square = document.createElement('div');
document.body.appendChild(square);
document.body.style.height = 10000 + "px";

let counter = true;
let size = 10;

square.style.width = 100 + "%";
square.style.position = "fixed";
square.style.left = "0";
square.style.top = "0";
square.style.backgroundColor = "green";
square.style.height = size + "px";


window.addEventListener("scroll", function() {
    if (counter){
        size += 5;
        square.style.height = size + "px";
        square.style.backgroundColor = "green";
    }
    else {
        size -= 5;
        square.style.height = size + "px";
        square.style.backgroundColor = "red";
    }
    if (size >= window.innerHeight * 0.5){
        counter = !counter
    }
    else if (size <= 0){
        counter = !counter
    }
    // if (counter == false){
    //     square.style.backgroundColor = "red";
    // }
    // else {
    //     square.style.backgroundColor = "green";
    // }

})