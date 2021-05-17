let size = 10;
let orderElement = 1;

const init = () => {
    const button = document.createElement('button');
    button.style.fontSize = 28 + "px";
    button.textContent = "Dodaj 10 elementów";
    document.body.appendChild(button);
    const reset = document.createElement("button");
    reset.style.fontSize = 18 + "px";
    reset.textContent = "Wyczyść listę";
    document.body.appendChild(reset)
    const ul = document.createElement('ul');
    ul.style.listStyle = "none";
    document.body.appendChild(ul);
    button.addEventListener ('click', createLiElements);
    reset.addEventListener('click', resetLiElements);
}

const createLiElements = () => {
for (let i = 0; i < 10; i++){
    const li = document.createElement('li');
    li.textContent = `Element nr ${orderElement}`;
    li.style.fontSize = size + "px";
    document.querySelector('ul').appendChild(li);
    orderElement++;
    size++;
}
orderElement += 10
}
const resetLiElements = () => {
   let removeLi = document.querySelector('ul');
   while (removeLi.firstChild){
       removeLi.removeChild(removeLi.firstChild);
       orderElement = 1;
       size = 10;
   }
}

init()