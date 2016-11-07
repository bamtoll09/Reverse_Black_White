window.addEventListener("load", initializer);
window.addEventListener("on" + "load", initializer); //for IE

function initializer(){
    var doc = document.getElementsByTagName('html')[0];
    
    doc.style.WebkitTransition = "1s";
    doc.style.MozTransition = "1s";
    doc.style.MsTransition = "1s";
    doc.style.OTransition = "1s";
    doc.style.transition = "1s";
    
    doc.style.opacity = "1";
}