const button = document.querySelector("button");
let number = 1;
const dodajElement = function(){
    const li = document.createElement("li");
    li.textContent = number;

    if (number % 3 == 0){
        li.classList.add("big")
    }
document.body.appendChild(li);
number += 2;
}
button.addEventListener("click", dodajElement)