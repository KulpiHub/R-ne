const button = document.querySelector("button");
let li = document.querySelectorAll("li");

button.addEventListener("click", increaseSize);

let size = 10;
function increaseSize(){
    size += 2;
    for (let i = 0; i < li.length; i++){
        li[i].style.display = "block";
        li[i].style.fontSize = `${size}px`;
    }
}