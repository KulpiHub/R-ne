
const h1 = document.querySelector("h1")
document.body.addEventListener("click", function(e) {
    const x = e.clientX;
    const y = e.clientY;
    const width = window.innerWidth;
    const height = window.innerHeight;
    h1.textContent = x + ", " + y;

    const red = (x / width) * 100;
    const green = (y / height) * 100;
    const blue = ((x / width) / (y / height) * 100);

    document.body.style.backgroundColor = `rgb(${red}%, ${green}%, ${blue}%)`

    /*let r = (x / width) * 100%;
    let g = (y / height) * 100%;
    let b = (((x / width) / (y / height)) * 100%);

    document.body.style.backgroundColor = `rgb(${r}, ${g}, ${b})`*/
})
