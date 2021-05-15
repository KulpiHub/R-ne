const button = document.querySelector("button");
let li = document.querySelectorAll("li");

let size = 10;

button.addEventListener("click", increaseSize);

function increaseSize () {
size += 2;
 li.forEach((li) => {
    li.style.display = "block";
    li.style.fontSize = `${size}px`;
})
}