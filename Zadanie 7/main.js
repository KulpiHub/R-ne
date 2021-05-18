document.body.addEventListener("click" , function(clickColorChange) {
    document.querySelector('body');
    const x = clickColorChange.clientX;
    const y = clickColorChange.clientY;
    
    if (x % 2 == 0 && y % 2 == 0){
        document.body.style.backgroundColor = "red";
    }
    else if (x % 2 == 0 || y % 2 == 0){
        document.body.style.backgroundColor = "blue";
    }
    else {
        document.body.style.backgroundColor = "green";
    }
    console.log(clickColorChange.clientX, clickColorChange.clientY)
})